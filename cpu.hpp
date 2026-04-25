#ifndef CPU_HPP
#define CPU_HPP

#include <vector>
#include <cstdint>

class CPU{
private:
    //Registers
    uint16_t registers[4];

    //Program Counter
    uint16_t pc;

    //RAM
    std::vector<uint16_t> memory;

public:
    CPU(); //Constructor to initialize the CPU
    void loadProgram(const std::vector<uint16_t>& program);
    void run();
};

#endif



