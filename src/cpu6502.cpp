#include "cpu6502.hpp"

using namespace mulator;

namespace mulator::cpu6502
{
    void CPU6502::reset()
    {
        A = X = Y = 0;                 // Clear registers
        C = Z = I = D = B = V = S = 0; // Clear all flags

        SP = 0x0100; // Setup stack pointer
        PC = 0xFFFC; // Set PC to reset vector
    }
}