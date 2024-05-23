//MOS 6502 Emulation Project

// Resources :
    //  http://www.obelisk.me.uk/6502/
// C64 Memory Map:
    // https://sta.c64.org/cbm64mem.html

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// Creating a struct to represent the 6502 CPU

struct CPU {
	// Defining byte size for 16 bit architecture
    using Byte = unsigned char;
    using Word = unsigned short;

    // Program Counter
    Word PC;    

    // Stack Pointer
    Word SP;

    // Accumulator Register
    Byte A, X, Y;

     // Status Flags
    Byte C : 1; // Carry Flag
    Byte Z : 1; // Zero Flag
    Byte I : 1; // Interrupt Disable
    Byte D : 1; // Decimal Mode
    Byte B : 1; // Break Command
    Byte V : 1; // Overflow Flag
    Byte N : 1; // Negative Flag
     
};

int main()
{
    return 0;
}


