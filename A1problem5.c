// A1problem5.c
#include <stdio.h>

int main(void) {
    for (char a = 'a'; a <= 'z'; ++a) {
        for (char b = 'a'; b <= 'z'; ++b) {
            printf("www.%c%c.com\n", a, b);
        }
    }
    return 0;
}
