# MyVirtualMachine

A custom virtual machine built in C++ from scratch to understand how CPUs actually work.

I started with the basics — a fetch-decode-execute cycle and 4 registers — and kept adding. Stack memory, conditional jumps, an assembler so I don't have to type raw opcodes.

---

## Architecture

- 4-register architecture (16-bit registers)
- 16-bit stack memory
- Custom bytecode instruction set
- Assembler for human-readable input

---

## Instruction Set

| Opcode | Instruction   | Description                                              |
|--------|---------------|----------------------------------------------------------|
| 1      | HALT          | Stops execution                                          |
| 2      | LOAD          | Loads a value into a register                            |
| 3      | ADD           | Adds a value to a register                               |
| 4      | PRINT         | Outputs the value of a register                          |
| 5      | JUMP          | Moves the program counter to a specific address          |
| 6      | SUB           | Subtracts a value from a register                        |
| 7      | MUL           | Multiplies a register by a value                         |
| 8      | DIV           | Divides a register by a value                            |
| 9      | JUMP_IF_NZ    | Jumps to address if register is not zero                 |
| 10     | JUMP_IF_Z     | Jumps to address if register is zero                     |
| 11     | PUSH          | Pushes register value onto stack                         |
| 12     | POP           | Pops stack value into register                           |
| 13     | ADD_REG       | Adds two registers together                              |

---

## How It Was Built

1. Initialised CPU with 4 registers (2 bytes each) and basic instructions
2. Expanded instruction set — arithmetic, print, halt
3. Built an assembler — typing raw opcodes is suboptimal
4. Added conditional jumps (JUMP_IF_Z, JUMP_IF_NZ)
5. Added 16-bit stack memory with PUSH/POP
6. Added ADD_REG for register-to-register operations
7. Added example programs for demo

---

## Build & Run

Requires `g++` on Windows.

```bash
# Compile
g++ main.cpp cpu.cpp -o MyVirtualMachine.exe

# Run
.\MyVirtualMachine.exe
```

---

*Part of a deeper exploration into systems programming and low-level architecture.*
