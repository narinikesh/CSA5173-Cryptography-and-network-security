#include <stdio.h>
#include <math.h>
int main() {
    int n = 25;
    unsigned long long fact = 1;
    double log2_fact;
    unsigned long long approx_power_of_2;

    for (int i = 2; i <= n; i++) {
        fact *= i; 
    }

    log2_fact = log2(fact);

    approx_power_of_2 = round(log2_fact);

    printf("The number of possible keys expressed as an approximate power of 2 is 2^%llu.\n", approx_power_of_2);

    return 0;  
}