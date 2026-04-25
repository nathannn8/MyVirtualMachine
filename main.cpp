#include "cpu.hpp"

int main(){
    CPU myVM;
    std::vector<uint16_t> program ={2, 50,
                                    3, 0, 5,
                                    4, 0,
                                    1};
    myVM.loadProgram(program);
    myVM.run();

    return 0;
}