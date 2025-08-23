// ! Topic: Recursive counting with 1D array DP approach

#include <stdio.h>

int main() {
    int arr[10];
    arr[0] = 1, arr[1] = 3;

    // ? Let n = 2i, and arr[i] = a_n = a_2i = # of ways to tile 3*2i
    // ? a_n = 4a_n-2 - a_n-4
    // ? a_2i = 4a_2(i-1) - a_2(i-2)
    // ? a[i] = 4*arr[i-1] - arr[i-2]

    for(int i=2; i<10; i++) {
        int n= 2*i;
        arr[i] = 4*arr[i-1] - arr[i-2];
        printf("%d: %d\n", 2*i, arr[i]);
    }
}