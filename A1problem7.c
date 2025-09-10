// A1problem7.c
#include <stdio.h>

static void print_token(int v) {
    if (v % 15 == 0) printf("Fizz-Buzz");
    else if (v % 3 == 0) printf("Fizz");
    else if (v % 5 == 0) printf("Buzz");
    else printf("%d", v);
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0) { printf("Error: Cannot compute Fizz Buzz of %d", n); return 0; }

    int count = 0;
    for (int i = n; i >= 1; --i) {
        if (count > 0) printf(" ");
        print_token(i);
        count++;
        if (count == 4 && i != 1) { printf("\n"); count = 0; }
    }
    return 0;
}
