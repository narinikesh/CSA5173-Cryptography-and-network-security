
#include <stdio.h>
#define MOD 26

int main() {
    int plaintext1[2] = {1, 3};    
    int ciphertext1[2] = {2, 3};   
    int plaintext2[2] = {1, 2};    
    int ciphertext2[2] = {1, 4};   

    int key[2][2];    

    key[0][0] = (ciphertext1[0] - ciphertext2[0] + MOD) % MOD;    
    key[0][1] = (ciphertext1[1] - ciphertext2[1] + MOD) % MOD;

    key[1][0] = (plaintext1[0] * key[0][0] + plaintext1[1] * key[0][1]) % MOD;
    key[1][1] = (plaintext2[0] * key[0][0] + plaintext2[1] * key[0][1]) % MOD;

    if (key[1][0] < 0) key[1][0] += MOD;
    if (key[1][1] < 0) key[1][1] += MOD;

    printf("Recovered key:\n");
    printf("%d %d\n", key[0][0], key[0][1]);
    printf("%d %d\n", key[1][0], key[1][1]);

    return 0;
}
