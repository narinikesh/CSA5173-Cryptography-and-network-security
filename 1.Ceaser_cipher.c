#include <stdio.h>
#include <string.h>
#include <ctype.h> 
void caesarCipher(char *plaintext, int key) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            plaintext[i] = (ch - base + key) % 26 + base;
        }
    }
}
int main() {
    char plaintext[100];
    int key;
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter the shift key (1-25): ");
    scanf("%d", &key);
    if (key < 1 || key > 25) {
        printf("Invalid key! Please enter a value between 1 and 25.\n");
        return 1;
    }
    caesarCipher(plaintext, key);
    printf("Encrypted message: %s\n", plaintext);
    return 0;
}
