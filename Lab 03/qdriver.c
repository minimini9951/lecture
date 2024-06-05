#include <stdio.h>
#include "q.h"

int main(void) {
#ifdef ENCRYPT

	char* plain_content = 0;
	char* key_content = 0;
	int key_len = 0;
	int plain_len = 0;
	FILE* plain_text = fopen("plain.txt", "r");
	if (can_open(plain_text))
	{
		plain_len = text_length(plain_text);

		plain_content = make_space(plain_len);

		text_content(plain_len, plain_content, plain_text);
	}
	FILE* key_text = fopen("key.txt", "r");
	if (can_open(key_text))
	{
		key_len = text_length(key_text);

		key_content = make_space(key_len);

		text_content(key_len, key_content, key_text);
	}
	encrypt(plain_content, key_content, plain_len, key_len);

	FILE* cipher_text = fopen("cipher.txt", "w");
	if (can_open(cipher_text))
	{
		char ch = 0;
		while (ch = fgetc(plain_text) != EOF) {
			fputs("%c", ch);
		}
	}

	fclose(plain_text);
	free(plain_content);
	fclose(key_text);
	free(key_content);
#else
	int cipher_len = 0;
	char* cipher_content = 0;
	FILE* cipher_text = fopen("cipher.txt", "r");
	if (can_open(cipher_text))
	{
		cipher_len = text_length(cipher_text);

		cipher_content = make_space(cipher_len);

		text_content(cipher_len, cipher_content, cipher_text);
	}
	// corresponding decrypted characters to output file out-plain.txt
	FILE* key_text = fopen("key.txt", "r");
	if (can_open(key_text))
	{
		key_len = text_length(key_text);

		key_content = make_space(key_len);

		text_content(key_len, key_content, key_text);
}
	// using the keyword in file key.txt
	decrypt(cipher_content, key_content, cipher_len, key_len);

	FILE* out_plain_text = fopen("out-plain.txt", "w");
	if (can_open(out_plain_text))
	{
		char ch = 0;
		while (ch = fgetc(cipher_text) != EOF) {
			fputs("%c", ch);
		}
	}
	// TODO5: write count of words into stderr
	fprintf(stderr, "words: %d", cipher_len);

#endif

	return 0;
}
