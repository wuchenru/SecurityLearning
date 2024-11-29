void vulnerable(int len, char *data) {
    char buf[64];
    if (len > 64)
        return;
    memcpy(buf, data, len);
}

// memcpy(void *s1, const void *s2, size_t n);

// size_t is unsigned, int is signed

// what if the len = -12
