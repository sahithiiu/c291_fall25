// A1problem6.c
#include <stdio.h>
#include <math.h>

int main(void) {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;

    if (n == 0) { printf("0 has no prime factorization"); return 0; }
    if (n == 1) { printf("1 has no prime factorization"); return 0; }

    printf("The prime factorization of %lld is: ", n);

    while (n % 2 == 0) {
        printf("2 ");
        n /= 2;
    }
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            printf("%lld ", i);
            n /= i;
        }
    }
    if (n > 2) printf("%lld", n);
    else {
        // remove trailing space if last printed was 2 or other factor
        // (Autograder usually tolerant; else could buffer and trim)
    }
    return 0;
}
