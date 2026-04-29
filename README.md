# MyVirtualMachine (Ongoing)

This is a personal project to learn C++ by building a custom Virtual Machine from scratch. I'm exploring how CPUs work, specifically the Fetch-Decode-Execute cycle.

## Features
- Custom bytecode instruction set as mentioned below and I am still adding more things.
- 4-register architecture.
- 16-bit register memory.
- 16-bit stack memory.

## Instruction set
| Opcode | Instruction | Description |
| :--- | :--- | :--- |
| 1 | HALT | Stops execution. |
| 2 | LOAD | Loads a value into Register of choice. |
| 3 | ADD | Adds a value to a specified register. |
| 4 | PRINT | Outputs the value of a register. |
| 5 | JUMP | Moves the program counter to a specific address. |
| 6 | SUB | Subtracts a value from a register. |
| 7 | MUL | Multiplies a register by a value. |
| 8 | DIV | Divides a register by a value. |
| 9 | JUMP_IF_NZ | Jumps to an address only if Register of choice is not zero. |
| 10 | JUMP_IF_NZ | Jumps to an address only if Register of choice is zero. |
| 11 | PUSH | Pushes register value to stack. |
| 12 | POP| Pops value in stack and puts it into register. |


## Quick Documentation
- Started with a CPU --> initialised 4 registers each 2 bytes, added some basic instructions.
- Added more instructions.
- Typing out numbers to run code is suboptimal so I built an assembler.
- added jump if zero and a stack memory system.

## How to Build & Run
I am currently using `g++` on Windows to build the project.

1. Open your terminal in the project folder.
2. Compile the source files:
   ```bash
   g++ main.cpp cpu.cpp -o MyVirtualMachine.exe
3. Run the VM:
   ```bash
   .\MyVirtualMachine.exe
