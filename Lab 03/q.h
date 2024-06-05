#ifndef Q_H
#define Q_H
#define ENCRYPT 0

#define ASCII_COUNT 128

// TODO2: your clients will be given this header file since they
// will have no access to the definitions of functions
// encrypt and decrypt - therefore, provide header documentation
// for function encrypt
int can_open(FILE* file);

int text_length(FILE* file);

char* make_space(int length);

void text_content(int length, char* content, FILE* file);

void encrypt(char* letter, char* keytext, int letter_length, int key_length);

void decrypt(char* letter, char keytext);

#endif // Q_H
