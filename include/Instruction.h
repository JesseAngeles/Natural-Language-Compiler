#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <string>

class Instruction
{
private:

public:
    Instruction() = default;

    virtual std::string get() = 0; 
};

#endif // INSTRUCTION_H