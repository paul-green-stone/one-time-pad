#include "one-time.h"

int main(int argc, char** argv) {
    char* plaintext = "Start at 7AM!";

    char* key = NULL;
    char* ciphertext = NULL;

    if ((key = otpkeygen(plaintext)) == NULL)
        return EXIT_FAILURE;

    if ((ciphertext = otpencode(plaintext, key)) != NULL)
        printf("%s\n", ciphertext);
    else
        return EXIT_FAILURE;

    printf("%s\n", otpdecrypt(ciphertext, key));

    return EXIT_SUCCESS;
}
