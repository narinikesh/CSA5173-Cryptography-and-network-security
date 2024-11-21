#include <stdio.h>
#include <string.h>
#include <ctype.h>

void monoalphabeticCipher(char *plaintext, char *ciphertextAlphabet) {
    const char *plaintextAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        if (isalpha(ch)) {
            char isLower = islower(ch);
            ch = toupper(ch);
            for (int j = 0; j < 26; j++) {
                if (plaintextAlphabet[j] == ch) {
                    plaintext[i] = isLower ? tolower(ciphertextAlphabet[j]) : ciphertextAlphabet[j];
                    break;
                }
            }
        }
    }
}

int main() {
    char plaintext[100];
    char ciphertextAlphabet[27];

    // Input plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove trailing newline character
    plaintext[strcspn(plaintext, "\n")] = '\0';

    // Input ciphertext alphabet
    printf("Enter the 26-character ciphertext alphabet: ");
    fgets(ciphertextAlphabet, sizeof(ciphertextAlphabet), stdin);

    // Remove trailing newline character
    ciphertextAlphabet[strcspn(ciphertextAlphabet, "\n")] = '\0';

    // Validate the ciphertext alphabet
    if (strlen(ciphertextAlphabet) != 26) {
        printf("Error: The ciphertext alphabet must contain exactly 26 characters.\n");
        return 1;
    }

    // Encrypt the plaintext
    monoalphabeticCipher(plaintext, ciphertextAlphabet);

    // Output the encrypted message
    printf("Encrypted message: %s\n", plaintext);

    return 0;
}
