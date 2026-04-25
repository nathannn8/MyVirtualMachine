# MyVirtualMachine (Ongoing)

This is a personal project to learn C++ by building a custom Virtual Machine from scratch. I'm exploring how CPUs work, specifically the Fetch-Decode-Execute cycle.

## Features
- Custom bytecode instruction set (LOAD, ADD, PRINT, HALT) (still adding more instructions).
- 4-register architecture.
- 16-bit register memory.

## How to Build & Run
I am currently using `g++` on Windows to build the project.

1. Open your terminal in the project folder.
2. Compile the source files:
   ```bash
   g++ main.cpp cpu.cpp -o MyVirtualMachine.exe
3. Run the VM:
   ```bash
   .\MyVirtualMachine.exe