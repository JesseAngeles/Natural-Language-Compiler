#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "Instruction.h"

enum class Type
{
    Int,
    Float,
    Char
};

class Variable : public Instruction
{
private:
    Type type;
    std::string name;
    std::string initValue;

public:
    // Constructor
    Variable(Type type, std::string name, std::string initValue = "") : type(type), name(name), initValue(initValue) {}

    // Getters
    Type getType() const { return type; }
    std::string getName() const { return name; }

    // Setters
    void setType(Type type) { this->type = type; }
    void setName(std::string name) { this->name = name; }

    std::string get() override
    {
        // Convertir Type a string para la salida
        std::string typeName;
        switch (type)
        {
        case Type::Int:
            typeName = "int";
            break;
        case Type::Float:
            typeName = "float";
            break;
        case Type::Char:
            typeName = "char";
            break;
        }

        return typeName + ' ' + name + ((!initValue.empty()) ? " = " + initValue : "") + ';';
    }
};

#endif // VARIABLE_H
