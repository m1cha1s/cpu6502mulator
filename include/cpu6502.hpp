#pragma once

#include <inttypes.h>
#include <mem.hpp>

using namespace mulator;

namespace mulator::cpu6502
{
    using Byte = uint8_t;
    using Word = uint16_t;

    class CPU6502
    {
    private:
        Byte A;    // Accumulator
        Byte X, Y; // Indexing registers
        Word SP;   // Stack pointer
        Word PC;   // Program counter

        Byte C : 1; // Carry flag
        Byte Z : 1; // Zero flag
        Byte I : 1; // Interrupt disable flag
        Byte D : 1; // Decimal mode flag
        Byte B : 1; // Break flag
        Byte V : 1; // Overflow flag
        Byte S : 1; // Sign flag

        Byte Reset : 1; // Reset flag for init puroses only

    public:
        CPU6502()
        {
            Reset = 1;
            A = X = Y = 0;                 // Clear registers
            C = Z = I = D = B = V = S = 0; // Clear all flags

            SP = 0x0100; // Setup stack pointer
            PC = 0xFFFC; // Set PC to reset vector
        }
        ~CPU6502() {}

        std::string dumpRegs();

        void reset();
        int execute(mem::Mem &memory); // Returns cycle count
    };

    enum
    {
        LDA_IMM = 0xA9,
    } OpCodes;

}