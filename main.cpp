#include "cpu.hpp"

int main(){
    CPU myVM;
    std::vector<uint16_t> program ={2, 5,       // LOAD 5
                                    6, 1, 0,    // SUB 1, R0
                                    4, 0,       // PRINT R0
                                    9, 2,       // JUMP_IF_NZ to address 2
                                    1
                                    };
    myVM.loadProgram(program);
    myVM.run();

    return 0;
}