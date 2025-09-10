// A1problem8.c
#include <stdio.h>

int main(void) {
    unsigned int n;
    if (scanf("%u", &n) != 1) return 0;
    if ((int)n <= 0) { printf("Error: Number must be a positive integer"); return 0; }

    while (n > 0) {
        printf("%u", n & 1u);
        n >>= 1u;
    }
    return 0;
}
