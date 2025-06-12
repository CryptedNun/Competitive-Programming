// https://cses.fi/problemset/task/1618
 
#include <stdio.h>
 
int main() {
    int inputNumber, numberOfZeros = 0, divisor = 5;
    scanf("%d", &inputNumber);
    while(inputNumber/divisor) {
        numberOfZeros += inputNumber/divisor;
        divisor *= 5;
    }
    printf("%d\n", numberOfZeros);
    return 0;
}