#include <stdio.h>
#include <stdlib.h>

void PrintError()
{
	//Incorrect use
	//Expected use is: 
	//exefile input_file out_file

	fprintf(stderr, "Incorrect use of the program \n");
	fprintf(stderr, "Expected use is:\n");
	fprintf(stderr, "./ExeName InputFile.ppm OutputFile.ppm\n");
}

enum PFormat
{
	Invalid = -1,
	P3 = 3,
	P6 = 6
};


enum Sizes
{
	STRSize = 512
};

enum PFormat HandleHeader(FILE* inFile, FILE* outFile, unsigned char** buffer, int* px, int* py)
{
	int i = 0;
	enum PFormat format = Invalid;

	char str[STRSize] = { '\0' };

	for (i = 0; i < 3; i++)
	{
		fgets(str, STRSize, inFile);

		char c = str[0];

		if (c == '#')
			i--;
		if (c == 'P' && format == Invalid)
		{
			format = str[1] - '0';
		}

		//Line "2" (without comments) is my sizeX sizeY
		if (i == 1)
		{
			sscanf(str, " %d %d", px, py);
		}

		//write to the other file
		fprintf(outFile, "%s", str);
	}

	printf("My X is : %d \n", *px);
	printf("My Y is : %d \n", *py);

	*buffer = malloc((*px) * (*py) * 3);

	return format;
}

enum RGB
{
	Red = 0,
	Green = 1,
	Blue = 2,
	InvalidCol = -1
};

void BlackAndWhite(unsigned char color[3])
{
	//Sum all the color together
	//Divide by 3
	char total = (color[Red] + color[Green] + color[Blue]) / 3;

	//Assign the color to all of them
	for (int i = 0; i < 3; i++)
		color[i] = total;
}

void InvertColor(unsigned char color[3])
{
	//Assign the color to all of them
	for (int i = 0; i < 3; i++)
		color[i] = 0xFF - color[i];
}

void RemoveChannel(unsigned char color[3], enum RGB channel)
{
	if (channel < 0 || channel > Blue)
		return;

	color[channel] = 0;
}

void AverageColors(unsigned char color[3], enum RGB channel1, enum RGB channel2)
{
	if (channel1 < 0 || channel1 > Blue)
		return;
	if (channel2 < 0 || channel2 > Blue)
		return;

	char res = (color[channel1] + color[channel2]) / 2;
	color[channel1] = res;
	color[channel2] = res;
}

void HandleColors(FILE* inFile, enum PFormat format, unsigned char* AllPixelsBuffer, int SizeX, int SizeY)
{
	//Red Green Blue
	unsigned int colors[3] = { 0 };
	unsigned char binaryColor[3] = { 0 };
	int read = 0;

	int x = 0;
	int y = 0;

	//Depending on the format, the read and write change
	//P3 - text -> fscanf / fprintf 
	//P6 - binary -> fread / fwrite 
	if (format == P3)
	{
		read = fscanf(inFile, " %d %d %d", &colors[Red], &colors[Green], &colors[Blue]);
		for (int i = 0; i < 3; i++)
			binaryColor[i] = colors[i];
	}
	else if (format == P6)
	{
		read = fread(binaryColor, 1, 3, inFile);
	}
	//Iterate until the end of the file
	while (read > 0)
	{
		//Write to the AllPixelsBuffer
		for (int i = 0; i < 3; i++)
		{
			AllPixelsBuffer[(y * SizeX + x) * 3 + i] = binaryColor[i];
		}

		//Read the next colors from the inFile
		if (format == P3)
		{
			read = fscanf(inFile, " %d %d %d", &colors[Red], &colors[Green], &colors[Blue]);

			for (int i = 0; i < 3; i++)
				binaryColor[i] = colors[i];
		}
		else if (format == P6)
		{
			read = fread(binaryColor, 1, 3, inFile);
		}

		x++;
		if (x >= SizeX)
		{
			y++;
			x = 0;
		}
	}
}

void CopyAllPixelsToFile(FILE* outFile, enum PFormat format, unsigned char* AllPixelsRGB, int SizeX, int SizeY)
{
	//Red Green Blue
	unsigned int colors[3] = { 0 };

	//Iterate on the buffer
	for (int y = 0; y < SizeY; y++)
	{
		for (int x = 0; x < SizeX; x++)
		{
			//Write to the file depending on format
			if (format == P3)
			{
				//Convert this to ints
				for (int i = 0; i < 3; i++)
				{
					colors[i] = AllPixelsRGB[(y * SizeX + x) * 3 + i];
				}
				//fprintf to the file
				fprintf(outFile, "%d %d %d ", colors[Red], colors[Green], colors[Blue]);
			}
			else if (format == P6)
			{
				//fwrite
				fwrite(&(AllPixelsRGB[(y * SizeX + x) * 3]), 1, 3, outFile);
			}
		}
	}
}

void FlipY(unsigned char pixel[3], char* AllPixelsBuffer, int x, int y, int sizeX, int sizeY)
{
	int newY = sizeY - y - 1;

	for (int i = 0; i < 3; i++)
	{
		pixel[i] = AllPixelsBuffer[(newY * sizeX + x) * 3 + i];
	}
}

void FlipX(unsigned char pixel[3], char* AllPixelsBuffer, int x, int y, int sizeX, int sizeY)
{
	int newX = sizeX - x - 1;

	for (int i = 0; i < 3; i++)
	{
		pixel[i] = AllPixelsBuffer[(y * sizeX + newX) * 3 + i];
	}
}

void FlipXY(unsigned char pixel[3], char* AllPixelsBuffer, int x, int y, int sizeX, int sizeY)
{
	int newY = sizeY - y - 1;
	int newX = sizeX - x - 1;

	for (int i = 0; i < 3; i++)
	{
		pixel[i] = AllPixelsBuffer[(newY * sizeX + newX) * 3 + i];
	}
}

void GradientChannel(unsigned char pixel[3], int x, int y, int sizeX, int sizeY, enum RGB channelx, enum RGB channely)
{
	//Depending on the x or y add more of the channel color
	float xratio = x / (float)sizeX;
	float yratio = y / (float)sizeY;

	if (channelx != InvalidCol)
	{
		pixel[channelx] = xratio * 0xFF;
	}
	if (channely != InvalidCol)
	{
		pixel[channely] = yratio * 0xFF;
	}
}

void DrawOnlyCircle(unsigned char pixel[3], int x, int y, int r, int centerX, int centerY)
{
	//Point is inside if 
	//Lenght of CA <= R
	//L*L <= R*R

	int CAx = (x - centerX);
	int CAy = (y - centerY);

	if (CAx * CAx + CAy * CAy <= r * r)
	{
		return;
	}
	//If the point is outside

	//Set color to black
	for (int i = 0; i < 3; i++)
		pixel[i] = 0;
}

void AveragePixel(unsigned char pixel[3], char* AllPixelsBuffer, int x, int y, int sizeX, int sizeY)
{
	int total[3] = { 0 };
	int checkedPixels = 0;

	for (int currentX = -1; currentX <= 1; currentX++)
	{
		if (x + currentX < 0 || x + currentX >= sizeX)
			continue;

		for (int currentY = -1; currentY <= 1; currentY++)
		{
			if (y + currentY < 0 || y + currentY >= sizeY)
				continue;

			for (int i = 0; i < 3; i++)
			{
				total[i] +=
					AllPixelsBuffer[((y + currentY) * sizeX + (x + currentX)) * 3 + i];
			}
			checkedPixels++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		pixel[i] = total[i] / checkedPixels;
	}
}

void Modify(unsigned char* AllPixelsBuffer, int sizeX, int sizeY)
{
	//Modify All the pixels
	//Iterate pixel by pixel
	unsigned char pixel[3] = { '\0' };

	char* TempPixels = malloc(sizeY * sizeX * 3);

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			//Copy this pixel to the small array
			for (int i = 0; i < 3; i++)
			{
				pixel[i] = AllPixelsBuffer[(y * sizeX + x) * 3 + i];
			}

			//DrawOnlyCircle(pixel, x,y, sizeY/3, -100 ,-100);

			//RemoveChannel(binaryColor, Red);
			//RemoveChannel(binaryColor, Green);
			//RemoveChannel(binaryColor, Blue);

			dotted();
			//AverageColors(binaryColor, Red, Green);

			//BlackAndWhite(pixel);
			//InvertColor(binaryColor);

			//Copy the modified color back

			//Copy this pixel to the small array

			//FlipY(pixel, AllPixelsBuffer, x, y, sizeX, sizeY);
			//FlipX(pixel, AllPixelsBuffer, x, y, sizeX, sizeY);
			//FlipXY(pixel, AllPixelsBuffer, x, y, sizeX, sizeY);

			//GradientChannel(pixel, x, y, sizeX, sizeY, Red, Red);

			AveragePixel(pixel, AllPixelsBuffer, x, y, sizeX, sizeY);

			for (int i = 0; i < 3; i++)
			{
				TempPixels[(y * sizeX + x) * 3 + i] = pixel[i];
			}

		}
	}

	//Copy back to original
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			for (int i = 0; i < 3; i++)
			{
				AllPixelsBuffer[(y * sizeX + x) * 3 + i] = TempPixels[(y * sizeX + x) * 3 + i];
			}
		}
	}

	free(TempPixels);
}

int main(int argc, char** argv)
{
	if (argc < 3)
	{
		PrintError();
		return 0;
	}

	FILE* inFile = fopen(argv[1], "rb");


	if (inFile == NULL)
	{
		fclose(inFile);

		PrintError();
		return 0;
	}

	FILE* outFile = fopen(argv[2], "wb");

	if (outFile == NULL)
	{
		fclose(inFile);
		fclose(outFile);

		PrintError();
		return 0;
	}

	unsigned char* AllPixelsRGB = NULL;
	int x = 0;
	int y = 0;

	//Read the header of the InFile and Copy to the OutFile
	enum PFormat format = HandleHeader(inFile, outFile, &AllPixelsRGB, &x, &y);

	if (AllPixelsRGB == NULL)
	{
		fclose(inFile);
		fclose(outFile);

		PrintError();
		return 0;
	}

	//Read the colors of the InFile and copy them to the AllPixels
	HandleColors(inFile, format, AllPixelsRGB, x, y);

	//ModifyColors
	Modify(AllPixelsRGB, x, y);

	//WriteToFile
	CopyAllPixelsToFile(outFile, format, AllPixelsRGB, x, y);

	free(AllPixelsRGB);

	return 0;
}