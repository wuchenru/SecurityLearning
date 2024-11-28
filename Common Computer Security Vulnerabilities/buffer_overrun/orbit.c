#include <stdio.h>

// vulnerable code

void orbit(void) {
    char buf[8];
    gets(buf);
}

int main(void) {
    orbit();
    return 0;
}