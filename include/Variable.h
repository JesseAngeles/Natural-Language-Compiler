#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "Instruction.h"

enum class Type
{
    Bool,
    Int,
    Float,
    Char
};

class Variable : public Instruction
{
private:
    Type type;
    std::string name;
    std::string value;

public:
    // Constructor
    Variable(Type type, std::string name, std::string value = "") : type(type), name(name), value(value) {}

    // Getters
    Type getType() const { return type; }
    std::string getName() const { return name; }

    // Setters
    void setType(Type type) { this->type = type; }
    void setName(std::string name) { this->name = name; }

    std::string get() override
    {
        // Convertir Type a string para la salida
        std::string type_name;
        switch (type)
        {
        case Type::Int:
            type_name = "int";
            break;
        case Type::Float:
            type_name = "float";
            break;
        case Type::Char:
            type_name = "char";
            break;
        }

        return type_name + ' ' + name + ((!value.empty()) ? " = " + value : "") + ';';
    }
};

#endif // VARIABLE_H
