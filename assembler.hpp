#pragma once
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <cstdint>

class Assembler{
public:
    static std::vector<uint16_t> assemble(std::string code){
        std::map<std::string, uint16_t> opcodes = {
            {"HALT", 1}, {"LOAD", 2}, {"ADD", 3}, {"PRINT", 4},
            {"JUMP", 5}, {"SUB", 6}, {"MUL", 7}, {"DIV", 8}, {"JNZ", 9}, {"JZ", 10},
            {"PUSH", 11}, {"POP", 12}, {"ADD_REG", 13}
        };
        std::vector<uint16_t> machineCode;
        std::stringstream ss(code);
        std::string(token);

        while (ss >> token){
            if (opcodes.count(token)){
                machineCode.push_back(opcodes[token]);
            } else {
                machineCode.push_back((uint16_t)std::stoi(token));
            }
        }
        return machineCode;

    }
};