#include "MyString.h"

void String::SetStr(const char* inStr)
{
	int size = 0;
	const char* p = inStr;

	while (*p != '\0')
	{
		size++;
		p++;
	}

	//inStr is size long (without the '\0' char)

	if (str != nullptr)
		delete[] str;

	//allocate memory for it
	str = new char[size + 1];

	//copy all values
	for (int i = 0; i < size; i++)
	{
		str[i] = inStr[i];
	}
	//Set null character
	str[size] = '\0';
}

String::String(): str(nullptr)
{
	str = new char[1];
	str[0] = '\0';

	std::cout << "DEFAULT CONSTRUCTOR called" << std::endl;
	std::cout << "\t\t" << str << std::endl;
}

String::String(const char* inStr) : str(nullptr)
{
	//check how long the inStr is
		//Iterate until p == '\0'
	
	SetStr(inStr);

	std::cout << "CONVERSION CONSTRUCTOR called" << std::endl;
	std::cout << "\t\t" << str << std::endl;
}

String::String(const String& otherS): str(nullptr)
{
	//this->str = otherS.str;		// WHAT THE DEFAULT VERSION DID!
									//	VERY DANGEROUS!

	SetStr(otherS.str);
	std::cout << "COPY CONSTRUCTOR called" << std::endl;
	std::cout << "\t\t" << str << std::endl;
}

String::~String()
{
	std::cout << "DESTRUCTOR called" << std::endl;
	std::cout << "\t\t" << str << std::endl;
	delete[] str;
}

String& String::operator=(const String& otherString)
{
	//str = otherString.str;	//The default behaviour by the compiler
								//BIG problem. Mem leeks and potential crash on
								//delete mem

	if (this == &otherString)
		return *this;

	SetStr(otherString.str);

	return *this;
}

int String::Length() const
{
	//Iterate until '\0'
	
	int size = 0;
	const char* p = str;

	if (p == nullptr)
		return -1;

	while (*p != '\0')
	{
		size++;
		p++;
	}

	//Return count
	return size;
}

char& String::operator[](int index)
{
	int size = Length();

	//What if index is invalid?

	if (index < 0)
	{
		//less than 0
		return str[0];
	}

	if (index >= size)
	{
		//more than my size
		return str[size - 1];
	}


	return str[index];
}

void String::ToUpper()
{
	char* p = str;

	//Sanity check
	if (p == nullptr)
		return;

	//Iterate the string
	while (*p != '\0')
	{
		//if the char is a lowercase letter, make it capital case
		if (*p >= 'a' && *p <= 'z')
		{
			*p += 'A' - 'a';
		}

		p++;
	}
}

void String::ToLower()
{
	char* p = str;

	while (*p != '\0')
	{

		//If im capital, lower it
		if (*p >= 'A' && *p <= 'Z')
		{
			*p += 'a' - 'A';
		}

		p++;
	}

}

String String::operator+(const String& rhs) const
{
	//Get my own string
	int size1 = this->Length();
	//Get the other string
	int size2 = rhs.Length();

	//Create a new string with both sizes combined
	char* resStr = new char[size1 + size2 + 1];

	//Copy me
	for (int i = 0; i < size1; i++)
	{
		resStr[i] = this->str[i];
	}
	//Copy other
	for (int i = 0; i < size2; i++)
	{
		resStr[size1 + i] = rhs.str[i];
	}

	resStr[size1 + size2] = '\0';

	String res(resStr);

	delete[] resStr;

	return res;
}

String& String::operator+=(const String& rhs)
{
	//Get my own string
	int size1 = this->Length();
	//Get the other string
	int size2 = rhs.Length();

	//Create a new string with both sizes combined
	char* resStr = new char[size1 + size2 + 1];

	//Copy me
	for (int i = 0; i < size1; i++)
	{
		resStr[i] = this->str[i];
	}
	//Copy other
	for (int i = 0; i < size2; i++)
	{
		resStr[size1 + i] = rhs.str[i];
	}

	resStr[size1 + size2] = '\0';

	this->SetStr(resStr);

	delete[] resStr;

	return *this;
}

String& String::operator<<(const String& rhs)
{
	*this += rhs;

	return *this;
}

bool String::operator==(const String& otherS) const
{
	//return this->str == otherS.str;	//MISTAKE! str and other.str are DIFFERENT 
										//	pointers, but the CONTENTS could be the same

	//Check special cases
	if (this->str == nullptr || otherS.str == nullptr)
	{
		//if we both are nullptr, return true, 
		//else, false

		return this->str == otherS.str;
	}

	//Both are valid

	//Check lengths
	int size1 = this->Length();
	int size2 = otherS.Length();

	//If lengths are different, return false
	if (size1 != size2)
		return false;

	//Iterate on both, checking chars, if any is different, return false
	for (int i = 0; i < size1; i++)
	{
		if (this->str[i] != otherS.str[i])
		{
			return false;
		}
	}

	//If we finished iterating and did no find any differences, return true
	return true;
}

bool String::operator!=(const String& otherS) const
{
	return !(*this == otherS);
}

bool String::operator<(const String& otherS) const
{
	//If we are equal, return false. I am NOT lesser than the other
	if (*this == otherS)
	{
		return false;
	}
	//If we are different size, return the lower size
	int size1 = this->Length();
	int size2 = otherS.Length();

	if (size1 < size2)
		return true;
	if (size1 > size2)
		return false;

	//size1 == size2
	//If we are the same size, return the result of the first different char comparison
	for (int i = 0; i < size1; i++)
	{
		if (this->str[i] != otherS.str[i])
		{
			return this->str[i] < otherS.str[i];
		}
	}

	return false;
}

bool String::operator>(const String& otherS) const
{

	//If we are equal, return false. I am NOT greater than the other
	if (*this == otherS)
	{
		return false;
	}
	//If we are different size, return the highest size
	int size1 = this->Length();
	int size2 = otherS.Length();

	if (size1 > size2)
		return true;
	if (size1 < size2)
		return false;

	//size1 == size2
	//If we are the same size, return the result of the first different char comparison
	for (int i = 0; i < size1; i++)
	{
		if (this->str[i] != otherS.str[i])
		{
			return this->str[i] > otherS.str[i];
		}
	}

	return false;

}

bool String::operator<=(const String& otherS) const
{
	return !(*this > otherS);
}

bool String::operator>=(const String& otherS) const
{
	return !(*this < otherS);
}

String::operator bool() const
{
	if (Length() <= 0)
		return false;

	return true;
}

void String::RemoveAll()
{
	//Deletes mem if needed
	if (str != nullptr)
		delete[] str;

	//It creates an size 1 buffer
	str = new char[1];
	str[0] = '\0';
}

String& String::operator-()
{
	RemoveAll();
	return *this;
}

String& String::operator++()
{
	ToUpper();

	return *this;
}

String& String::operator--()
{
	ToLower();

	return *this;
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
	os << s.str;

	return os;
}

std::istream& operator>>(std::istream& is,  String& s)
{
	//the input will be a string

	//Create a buffer
	char buffer[255];

	is >> buffer;

	//Call SetStr

	s.SetStr(buffer);

	return is;
}
