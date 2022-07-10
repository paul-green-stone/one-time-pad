#include "one-time.h"

char* otpkeygen(char* plaintext) {
    char* key = NULL;
    size_t numchar;
    time_t t;

    /* Intializes random number generator */
    srand((unsigned) time(&t));

    if (plaintext != NULL) {
        numchar = strlen(plaintext);

        if ((key = (char*) malloc(sizeof(char) * numchar)) != NULL) {
            for (size_t i = 0; i < numchar; i++)
                *(key + i) = 1 + rand() % 127;

            *(key + numchar) = '\0';
        }
    }

    return key;
}

char* otpencode(char* plaintext, char* key) {
     char* ciphertext = NULL;
     size_t numchar;

     if (plaintext != NULL && key != NULL) {
         numchar = strlen(plaintext);

         if ((ciphertext = (char*) malloc(sizeof(char) * numchar)) != NULL) {
             for (size_t i = 0; *(plaintext + i) != '\0'; i++)
                 *(ciphertext + i) = *(plaintext + i) ^ *(key + i);

             *(ciphertext + numchar) = '\0';
         }
     }

     return ciphertext;
}

char* otpdecrypt(char* ciphertext, char* key) {
    char* plaintext = NULL;
    size_t numchar;

    if (ciphertext != NULL && key != NULL) {
        numchar = strlen(ciphertext);

        if ((plaintext = (char*) malloc(sizeof(char) * numchar)) != NULL) {
            for (size_t i = 0; *(ciphertext + i) != '\0'; i++)
                *(plaintext + i) = *(ciphertext + i) ^ *(key + i);

            *(plaintext + numchar) = '\0';
        }
    }

    return plaintext;
}
