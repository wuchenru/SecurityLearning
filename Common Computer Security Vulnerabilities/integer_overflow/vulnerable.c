#include <string.h>  // For memcpy()

// Function that copies data into a buffer
// This function has a vulnerability that can lead to buffer overflow if len is not properly validated.
void vulnerable(int len, char *data) {
    char buf[64];  // A fixed-size buffer of 64 bytes
    
    // Check if the length is greater than the buffer size (64). If so, return early.
    // However, this is not sufficient for preventing overflows from other types of invalid input.
    if (len > 64)
        return;
    
    // The memcpy function copies len bytes from data to buf.
    // If len is negative, it may cause undefined behavior due to incorrect size calculations.
    memcpy(buf, data, len);  // Potential buffer overflow if len is incorrectly set
}

// The vulnerability lies in the fact that 'len' is passed as a signed integer (int),
// but 'len' is treated as an unsigned size (size_t) in memcpy.
// If len = -12, it would be implicitly converted to an unsigned value (size_t).
// This causes the memcpy function to copy an unexpectedly large number of bytes, leading to a buffer overflow.
