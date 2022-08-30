#include "cpu6502.hpp"

#include <string>

using namespace mulator;

namespace mulator::cpu6502
{
    std::string CPU6502::dumpRegs()
    {
        std::string result;

        result += "==== Reg dump ====\n";
        result += "A:  " + std::to_string(A) + "\n";
        result += "X:  " + std::to_string(X) + "\n";
        result += "Y:  " + std::to_string(Y) + "\n";
        result += "SP: " + std::to_string(SP) + "\n";
        result += "PC: " + std::to_string(PC) + "\n";
        result += "C: " + std::to_string(C);
        result += " Z: " + std::to_string(Z);
        result += " I: " + std::to_string(I);
        result += " D: " + std::to_string(D) + "\n";
        result += "B: " + std::to_string(B);
        result += " V: " + std::to_string(V);
        result += " S: " + std::to_string(S) + "\n";
        result += "Reset: " + std::to_string(Reset) + "\n";

        return result;
    }

    void CPU6502::reset()
    {
        Reset = 1;
        A = X = Y = 0;                 // Clear registers
        C = Z = I = D = B = V = S = 0; // Clear all flags

        SP = 0x0100; // Setup stack pointer
        PC = 0xFFFC; // Set PC to reset vector
    }

    int CPU6502::execute(mem::Mem &memory)
    {
        // Handling reset
        if (Reset)
        {
            Word resetVector;

            resetVector = (Word)memory.get(PC++);
            resetVector |= (Word)(memory.get(PC) << 8);

            PC = resetVector;

            Reset = 0;

            return 9;
        }

        Byte opc = memory.get(PC++);

        switch (opc)
        {
        case LDA_IMM:
            A = memory.get(PC++);
            return 2;
        default:
            return 1;
        }
    }

}