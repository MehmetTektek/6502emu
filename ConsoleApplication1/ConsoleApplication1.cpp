//MOS 6502 Emulation Project

// Resources :
    //  http://www.obelisk.me.uk/6502/
// C64 Memory Map:
    // https://sta.c64.org/cbm64mem.html

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include </repos/App/App/ConsoleApplication1/cpu.cpp>




// Creating a struct to represent the 6502 Memory


int main()
{
    // Creating an instance of the CPU struct
    CPU cpu;
    Memory memory;
    // Resetting the CPU
    cpu.Reset(memory);

    // Test the memory
    memory[0xFFFC] = CPU::INS_LDA_IM;
    memory[0xFFFD] = 0x42;
    // Executing the CPU
    cpu.Execute(2, memory);
    return 0;
}


