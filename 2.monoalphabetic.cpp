#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void vigenereEncrypt(char *plaintext, const char *key) {
    int keyLength = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < strlen(plaintext); i++) {
        char currentChar = plaintext[i];

        if (isalpha(currentChar)) {
            char base = (isupper(currentChar)) ? 'A' : 'a';
            char encryptedChar = ((currentChar - base) + (key[j % keyLength] - 'A')) % 26 + base;
            j++;

            printf("%c", encryptedChar);
        } else {
            printf("%c", currentChar);
        }
    }
}

int main() {
    char plaintext[1000];
    char key[100];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 
    for (int i = 0; i < strlen(plaintext); i++) {
        if (!isalpha(plaintext[i])) {
            printf("Error: Plaintext should only contain alphabetic characters.\n");
            return 1;
        }
    }
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 
    for (int i = 0; i < strlen(key); i++) {
        if (!isalpha(key[i])) {
            printf("Error: Key should only contain alphabetic characters.\n");
            return 1;
        }
    }
    printf("Ciphertext: ");
    vigenereEncrypt(plaintext, key);
    printf("\n");
    return 0;
}

