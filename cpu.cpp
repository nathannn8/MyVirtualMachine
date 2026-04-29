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
                pc++;
                uint16_t regIdx = memory[pc];
                registers[regIdx] = value; 
                std::cout<< "LOAD instruction: Loaded value " << value << " into register. " << regIdx << std::endl;
                break;;
            }

            case 3:{ //ADD (add values to a register)
                pc++; 
                uint16_t regIdx = memory[pc];
                pc++; 
                uint16_t val = memory[pc];
                registers[regIdx] += val;
                std::cout<< "ADD instruction: Added value " << val << " to register " << regIdx << ". New value: " << registers[regIdx] << std::endl;
                break;

            }

            case 4:{ //PRINT (show register value)
                pc++; uint16_t regIdx = memory[pc];
                std::cout<< "PRINT instruction: Value in register " << regIdx << " is " << registers[regIdx] << std::endl;
                break;
                
            }

            case 5:{ //JUMP
                pc++; 
                uint16_t targetAddr = memory[pc]; 
                pc = targetAddr - 1; 
                std::cout << "JUMP: Jumping to address " << targetAddr << std::endl;
                break;
            }

            case 6:{ //SUB(Subtract)
                pc++;
                int subvalue = memory[pc];
                pc++;
                int regIdx = memory[pc];
                registers[regIdx] -= subvalue;
                std::cout<< "SUBTRACT instruction: Subtracted value " << subvalue << " from register " << regIdx << ". New value: " << registers[regIdx] << std::endl;
                break;}
            
            case 7:{ //MUL(Multiply)
                pc++;
                int mulvalue = memory[pc];
                pc++;
                int regIdx = memory[pc];
                registers[regIdx] *= mulvalue;
                std::cout<< "MULTIPLY instruction: Multiplied register " << regIdx << " by value " << mulvalue << ". New value: " << registers[regIdx] << std::endl;
                break;}
            
            case 8:{ //DIVIDE(Divide)
                pc++;
                int divvalue = memory[pc];
                pc++;
                int regIdx = memory[pc];
                if (divvalue != 0) {
                    registers[regIdx] /= divvalue;
                    std::cout<< "DIVIDE instruction: Divided register " << regIdx << " by value " << divvalue << ". New value: " << registers[regIdx] << std::endl;
                } else {
                    std::cout<< "DIVIDE instruction: Division by zero error. Register " << regIdx << " remains unchanged." << std::endl;
                }
                break;}

            
            case 9: { // JUMP IF NOT ZERO
                pc++;
                uint16_t targetAddr = memory[pc];
                pc++;
                uint16_t regIdx = memory[pc];
                if (registers[regIdx] != 0) {
                    pc = targetAddr - 1; 
                }
                break;
                }

            case 10: { // JUMP IF ZERO
                pc++;
                uint16_t targetAddr = memory[pc];
                pc++;
                uint16_t regIdx = memory[pc];
                if (registers[regIdx] == 0) {
                    pc = targetAddr - 1; 
                }
                break;
            }

            case 11: { // PUSH
                pc++;
                uint16_t regIdx = memory[pc];
                stack.push_back(registers[regIdx]);
                std::cout<< "PUSH instruction: Pushed value " << registers[regIdx] << " from register " << regIdx << " onto stack." << std::endl;
                break;
            }

            case 12: { // POP
                pc++;
                uint16_t regIdx = memory[pc];
                if (!stack.empty()) {
                    registers[regIdx] = stack.back();
                    stack.pop_back();
                    std::cout<< "POP instruction: Popped value " << registers[regIdx] << " from stack into register " << regIdx << "." << std::endl;
                } else {
                    std::cout<< "POP instruction: Stack underflow error. Register " << regIdx << " remains unchanged." << std::endl;
                }
                break;
            }

            case 13: { // ADD_REG: registers[regA] += registers[regB]
                pc++; 
                uint16_t regA = memory[pc];
                pc++; 
                uint16_t regB = memory[pc];
                registers[regA] += registers[regB];
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