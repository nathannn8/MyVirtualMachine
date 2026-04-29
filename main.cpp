#include "cpu.hpp"
#include "assembler.hpp"

int main(){
    CPU myCPU;
    std::string program ="LOAD 42 0 PUSH 0 LOAD 99 0 POP 0 PRINT 0 HALT";

    std::vector<uint16_t> machineCode = Assembler::assemble(program);

    myCPU.loadProgram(machineCode);
    myCPU.run();

    return 0;
}