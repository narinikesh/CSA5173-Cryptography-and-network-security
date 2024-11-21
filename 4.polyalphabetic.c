#include <stdio.h>
#include <string.h>
#include <ctype.h>

void preprocessText(char *text) {
    int len = strlen(text), j = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            text[j++] = toupper(text[i]);
        }
    }
    text[j] = '\0';
}

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int textLen = strlen(plaintext);
    int keyLen = strlen(key);

    for (int i = 0; i < textLen; i++) {
        char plainChar = plaintext[i];
        char keyChar = key[i % keyLen];
        ciphertext[i] = ((plainChar - 'A') + (keyChar - 'A')) % 26 + 'A';
    }
    ciphertext[textLen] = '\0'; // Null-terminate the ciphertext
}

// Function to decrypt ciphertext using Vigenère Cipher
void decrypt(char *ciphertext, char *key, char *plaintext) {
    int textLen = strlen(ciphertext);
    int keyLen = strlen(key);

    for (int i = 0; i < textLen; i++) {
        char cipherChar = ciphertext[i];
        char keyChar = key[i % keyLen];
        // Decrypt: reverse the shift of the ciphertext character by the key character
        plaintext[i] = ((cipherChar - 'A') - (keyChar - 'A') + 26) % 26 + 'A';
    }
    plaintext[textLen] = '\0'; // Null-terminate the plaintext
}

int main() {
    char plaintext[200], key[100], ciphertext[200];

    // Input plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove trailing newline

    // Input key
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove trailing newline

    // Preprocess plaintext and key
    preprocessText(plaintext);
    preprocessText(key);

    // Encrypt plaintext
    encrypt(plaintext, key, ciphertext);
    printf("\nEncrypted message: %s\n", ciphertext);

    // Decrypt ciphertext
    char decryptedText[200];
    decrypt(ciphertext, key, decryptedText);
    printf("Decrypted message: %s\n", decryptedText);

    return 0;
}
