// A1problem10.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static void leftpad4(char *s) {
    int len = (int)strlen(s);
    if (len >= 4) return;
    char tmp[8] = "0000";
    memcpy(tmp + (4 - len), s, (size_t)len + 1);
    strcpy(s, tmp);
}

int main(void) {
    char num[8] = {0};
    char mode;
    if (scanf(" %7s %c", num, &mode) != 2) return 0;
    mode = tolower((unsigned char)mode);
    leftpad4(num);

    int d[4];
    for (int i = 0; i < 4; ++i) d[i] = num[i] - '0';

    if (mode == 'e') {
        for (int i = 0; i < 4; ++i) d[i] = (d[i] + 7) % 10;
        // swap 1<->3 (0<->2), 2<->4 (1<->3)
        int t = d[0]; d[0] = d[2]; d[2] = t;
        t = d[1]; d[1] = d[3]; d[3] = t;
    } else if (mode == 'd') {
        // reverse swaps first
        int t = d[0]; d[0] = d[2]; d[2] = t;
        t = d[1]; d[1] = d[3]; d[3] = t;
        // reverse (x+7)%10 => (x+10-7)%10
        for (int i = 0; i < 4; ++i) d[i] = (d[i] + 10 - 7) % 10;
    } else {
        return 0;
    }

    printf("%d%d%d%d", d[0], d[1], d[2], d[3]);
    return 0;
}
