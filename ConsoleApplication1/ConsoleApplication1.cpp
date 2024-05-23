//MOS 6502 Emulation Project

// Resources :
    //  http://www.obelisk.me.uk/6502/
// C64 Memory Map:
    // https://sta.c64.org/cbm64mem.html

#include <iostream>
#include <stdio.h>
#include <stdlib.h>


// Defining 16 bit data types
using Byte = unsigned char;
using Word = unsigned short;

using u32 = unsigned int;

// Creating a struct to represent the 6502 CPU
struct Memory {

    // 64 KB of memory
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte Data[MAX_MEM];

    // Initializing the memory
    void Initialise() {
        // Setting all memory locations to 0
        for (u32 i = 0; i < MAX_MEM; i++) {
            Data[i] = 0;
        }
    }
    // Overloading the [] operator to read/write to memory
    Byte operator[](u32 Address) const {
        return Data[Address];
    }
};

struct CPU {
    // Program Counter
        // 16 bit register that holds the memory address of the next instruction to be executed
    Word PC;

    // Stack Pointer
        // 8 bit register that holds the memory address of the next free location on the stack
    Word SP;

    // Accumulator Register
        // 8 bit register that holds the results of all arithmetic and logic operations
    Byte A, X, Y;

    // Status Flags
    Byte C : 1; // Carry Flag - 1 if last operation caused overflow from bit 7
    Byte Z : 1; // Zero Flag - 1 if last operation resulted in a 0 value
    Byte I : 1; // Interrupt Disable - 1 if interrupts are disabled
    Byte D : 1; // Decimal Mode - 1 if CPU is in BCD mode
    Byte B : 1; // Break Command - 1 if an interrupt was caused by a BRK command
    Byte V : 1; // Overflow Flag - 1 if the last operation caused an overflow  
    Byte N : 1; // Negative Flag - 1 if the last operation resulted in a negative value

    // Reset Function
    void Reset(Memory& memory) {

        // Resetting the CPU to its initial state
        PC = 0xFFFC; // Program Counter starts at 0xFFFC
        SP = 0x0100; // Stack Pointer starts at 0x0100
        C = Z = I = D = B = V = N = 0; // Resetting all flags to 0
        A = X = Y = 0;

        // Initializing the memory
        memory.Initialise();
    }
    // Opcode read
    Byte getByte(u32 ics, Memory& memory) {
        // Fetching the instruction
        Byte Ins = memory[PC];
        PC++;
        ics--;
        return Ins;
    }
    //  Execute Function
    void Execute(u32 ics, Memory& memory) {

        // Instruction Cycle
        while (ics > 0) {
            // Fetching the instruction
            Byte Ins = getByte(ics, memory);
        }
    }

};

// Creating a struct to represent the 6502 Memory


int main()
{
    // Creating an instance of the CPU struct
    CPU cpu;
    Memory memory;
    // Resetting the CPU
    cpu.Reset(memory);
    // Executing the CPU
    cpu.Execute(2, memory);
    return 0;
}


