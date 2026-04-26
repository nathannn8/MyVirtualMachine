#include "cpu.hpp"
#include "assembler.hpp"

int main(){
    CPU myCPU;
    std::string program ="LOAD 5 SUB 1 0 PRINT 0 JNZ 2 HALT";

    std::vector<uint16_t> machineCode = Assembler::assemble(program);

    myCPU.loadProgram(machineCode);
    myCPU.run();

    return 0;
}