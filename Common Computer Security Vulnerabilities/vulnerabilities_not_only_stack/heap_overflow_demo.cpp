#include <iostream>
#include <cstring> // For memcpy()

// A simple victim class with a virtual function
class Victim {
public:
    virtual void vulnerable() {
        std::cout << "Safe function executed." << std::endl;
    }
};

// A malicious function that we will execute by exploiting the vulnerability
void malicious() {
    std::cout << "Malicious code executed!" << std::endl;
}

int main() {
    // Step 1: Allocate a heap buffer that we will overflow
    char* buffer = new char[16]; // Allocate a small buffer of 16 bytes on the heap
    // Allocate a small buffer of 16 bytes on the heap
    // This buffer is used for the heap overflow attack. We will intentionally write beyond the buffer's allocated space.
    // In this case, the `Victim` object is allocated immediately after the buffer in memory (for simplicity in this example).
    // When we overflow the buffer, we are writing data past the 16-byte buffer, which can potentially overwrite
    // adjacent memory locations. These locations may include the `Victim` object itself, and specifically its vtable pointer.
    // The vtable pointer controls which virtual function gets executed, and by overwriting this pointer, we can hijack
    // the program's control flow by pointing it to malicious code.
    // In a heap overflow, when we write past one object's allocated memory, we can overwrite the vtable pointer of
    // another object placed adjacent to it in the heap. This is a typical scenario where we exploit the heap layout
    // and take advantage of the vtable to redirect function calls to attacker-controlled functions.


    // Step 2: Allocate a victim object that will be targeted by the overflow
    Victim* victim = new Victim();

    /*
    Knowledge:
    - The Victim object has a virtual function table pointer (vtable pointer) at the start of its memory layout.
    - This vtable pointer points to the table of virtual functions for the class.
    - Overwriting the vtable pointer allows us to control which function gets executed when a virtual function is called.
    */

    // Debugging Information
    std::cout << "Victim object address: " << (void*)victim << std::endl;

    // Step 3: Create a fake vtable that points to the malicious function
    void** fakeVtable = new void*[1]; // Create a fake vtable with one function pointer
    fakeVtable[0] = (void*)&malicious; // Point it to the malicious function

    // Step 4: Overflow the buffer and overwrite the victim object's vtable pointer
    /*
    Vulnerability:
    - `buffer` is only 16 bytes long, but here we write beyond its bounds.
    - The memory layout on the heap (predictable during exploitation):
      [ buffer (16 bytes) ][ victim object (vtable pointer) ]
    - By overflowing the buffer, we overwrite the victim's vtable pointer.
    */
    std::memcpy(buffer + 16, &fakeVtable, sizeof(void*)); // Write the fake vtable pointer

    // Step 5: Trigger the virtual function call
    /*
    Exploit:
    - When victim->vulnerable() is called, the program looks up the vtable pointer for the Victim object.
    - Since the vtable pointer was overwritten, it now points to the fake vtable we created.
    - The malicious function gets executed instead of the intended function.
    */
    victim->vulnerable(); // Output: "Malicious code executed!"

    // Step 6: Clean up (in a real exploit, this step wouldn't exist)
    delete[] buffer;
    delete[] fakeVtable;
    delete victim;

    return 0;
}
