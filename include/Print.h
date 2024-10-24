#ifndef PRINT_H
#define PRINT_H

#include "Instruction.h"
#include "Import.h"

class Print : public Instruction
{
private:
    std::string content;

public:
    // Constructor
    Print(std::string content) : content(content) {}

    // Método que devuelve una instancia de Import
    Import import() const { return Import("iostream"); }

    // Getters
    std::string getContent() const { return content; }

    // Setters
    void setContent(std::string content) { this->content = content; }

    
    std::string get() override { return "std::cout << \"" + content + "\" << std::endl;"; }
};

#endif // PRINT_H