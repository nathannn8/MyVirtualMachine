#include "cpu.hpp"
#include <iostream>

//Constructor to initialize the CPU
CPU::CPU() {
    // Initialize registers to 0
    for (int i = 0; i < 4; i++) {
        registers[i] = 0;
    }
    // Set program counter to 0
    pc = 0;
}

// Load program into memory
void CPU::loadProgram(const std::vector<uint16_t>& program) {
    memory = program;
}

void CPU::run(){
    bool running = true;

    while (running){
        //1) FETCH (get the instruction from memory)
        uint16_t instruction = memory[pc];
        std::cout<< "Executing instruction: " << instruction << " at address "<< pc << std::endl;

        //2) DECODE (determine the opcode and operands)
        switch (instruction){
            case 1:{ //HALT
                std::cout << "HALT instruction encountered. Stopping execution." << std::endl;
                running = false;
                break;
            }
            case 2:{ //LOAD
                pc++;
                uint16_t value = memory[pc];
                registers[0] = value; 
                std::cout<< "LOAD instruction: Loaded value " << value << " into register 0." << std::endl;
                break;
            }

            case 3:{ //ADD (add values to a register)
                pc++; uint16_t regIdx = memory[pc];
                pc++; uint16_t val = memory[pc];
                registers[regIdx] += val;
                std::cout<< "ADD instruction: Added value " << val << " to register " << regIdx << ". New value: " << registers[regIdx] << std::endl;
                break;

            }

            case 4:{ //PRINT (show register value)
                pc++; uint16_t regIdx = memory[pc];
                std::cout<< "PRINT instruction: Value in register " << regIdx << " is " << registers[regIdx] << std::endl;
                break;
                
            }


            default:{
                std::cout<<"Uknown instruction"<< std::endl;
                break;
            }
        }

        //3) EXECUTE (perform the operation, in a real CPU this is where the math happens, but in this case I shall just move the pc forward)
        pc++;
    }
    std::cout<<"VM Halted."<< std::endl;

}