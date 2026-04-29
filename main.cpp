#include "cpu.hpp"
#include "assembler.hpp"

int main(){
    CPU myCPU;
    std::string program ="LOAD 1 0 LOAD 1 1 PRINT 0 PRINT 1 LOAD 5 3 PUSH 0 ADD_REG 0 1 PRINT 0 POP 1 PUSH 1 SUB 1 3 JNZ 13 3 HALT";

    std::vector<uint16_t> machineCode = Assembler::assemble(program);

    myCPU.loadProgram(machineCode);
    myCPU.run();

    return 0;
}