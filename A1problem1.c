// A1problem1.c

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int cm, cMom, cSleep;
    if (scanf(" %c %c %c", (char*)&cm, (char*)&cMom, (char*)&cSleep) != 3) return 0;
    cm = tolower(cm);
    cMom = tolower(cMom);
    cSleep = tolower(cSleep);

    int morning = (cm == 'y');
    int mom = (cMom == 'y');
    int sleeping = (cSleep == 'y');

    int answer = !sleeping && (!morning || mom);

    if (answer) {
        printf("Answer phone");
    } else {
        printf("Don't answer phone");
    }
    return 0;
}
