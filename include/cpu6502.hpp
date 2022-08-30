#pragma once

#include <inttypes.h>
#include <mem.hpp>

using namespace mulator;

namespace mulator::cpu6502
{

    class CPU6502
    {
    private:
        uint8_t A;    // Accumulator
        uint8_t X, Y; // Indexing registers
        uint16_t SP;  // Stack pointer
        uint16_t PC;  // Program counter

        uint8_t C : 1; // Carry flag
        uint8_t Z : 1; // Zero flag
        uint8_t I : 1; // Interrupt disable flag
        uint8_t D : 1; // Decimal mode flag
        uint8_t B : 1; // Break flag
        uint8_t V : 1; // Overflow flag
        uint8_t S : 1; // Sign flag

        mem::Mem memory; // The memory of the processor

    public:
        CPU6502() {}
        CPU6502(mem::MemMap memMap)
        {
            memory = mem::Mem(memMap);

            A = X = Y = 0;                 // Clear registers
            C = Z = I = D = B = V = S = 0; // Clear all flags

            SP = 0x0100; // Setup stack pointer
            PC = 0xFFFC; // Set PC to reset vector
        }
        ~CPU6502() {}

        void reset();
    };

}