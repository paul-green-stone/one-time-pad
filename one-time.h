#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

char* otpkeygen(char* plaintext);

char* otpencode(char* plaintext, char* key);

char* otpdecrypt(char* ciphertext, char* key);
