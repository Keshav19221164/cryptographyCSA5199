#include <stdio.h>
#include<ctype.h>
#include<string.h>
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
}
   
void decryptAffineCipher(char *ciphertext, int a, int b) {
    int aInverse = modInverse(a, 26);

    if (aInverse == -1) {
        printf("Error: Modular inverse does not exist for the given 'a' value.\n");
        return;
    }

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            char decryptedChar = (aInverse * (ciphertext[i] - base - b + 26)) % 26 + base;
            printf("%c", decryptedChar);
        } else {
            printf("%c", ciphertext[i]); 
        }
    }
}


int main() 

{
    char ciphertext[1000];
    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strcspn(ciphertext, "\n")] = '\0'; 
    int frequency[26] = {0};
    for (int i = 0; ciphertext[i] != '\0'; i++) 
        if (isalpha(ciphertext[i])) {
            frequency[toupper(ciphertext[i]) - 'A']++;
        }
    char mostFrequent = 'A';
    char secondMostFrequent = 'A';

    for (int i = 0; i < 26; i++) {
        if (frequency[i] > frequency[mostFrequent - 'A']) {
            secondMostFrequent = mostFrequent;
            mostFrequent = 'A' + i;
        } else if (frequency[i] > frequency[secondMostFrequent - 'A']) {
            secondMostFrequent = 'A' + i;
        }
    }
    int aGuess = ((secondMostFrequent - mostFrequent + 26) % 26);
    int bGuess = ((mostFrequent - 'A') * modInverse(aGuess, 26)) % 26;

    printf("Possible key values (a, b): (%d, %d)\n", aGuess, bGuess);
    printf("Decrypted text:\n");
    decryptAffineCipher(ciphertext, aGuess, bGuess);
    printf("\n");

    return 0;
}

