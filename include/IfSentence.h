#ifndef IF_SENTENCE_H
#define IF_SENTENCE_H

#include <vector>
#include <memory>
#include "Instruction.h"

class IfSentence : public Instruction
{
private:
    std::string condition;
    std::vector<std::unique_ptr<Instruction>> if_instructions;
    std::vector<std::unique_ptr<Instruction>> else_instructions;

public:
    // Constructor usando std::move para instrucciones
    IfSentence(std::string condition,
               std::vector<std::unique_ptr<Instruction>> if_instructions = {},
               std::vector<std::unique_ptr<Instruction>> else_instructions = {})
        : condition(condition), if_instructions(std::move(if_instructions)), else_instructions(std::move(else_instructions)) {}

    // Getters
    std::string getCondition() const { return condition; }
    const std::vector<std::unique_ptr<Instruction>> &getIfInstructions() const { return if_instructions; }
    const std::vector<std::unique_ptr<Instruction>> &getElseInstructions() const { return else_instructions; }

    // Setters con std::move
    void setCondition(std::string condition) { this->condition = condition; }
    void setIfInstructions(std::vector<std::unique_ptr<Instruction>> if_instructions) { this->if_instructions = std::move(if_instructions); }
    void setElseInstructions(std::vector<std::unique_ptr<Instruction>> else_instructions) { this->else_instructions = std::move(else_instructions); }

    // Insertar una nueva instrucción
    void insertInstruction(std::unique_ptr<Instruction> instruction)
    {
        if_instructions.push_back(std::move(instruction));
    }

    // Implementación del método get
    std::string get() override
    {
        std::string newString = "if (" + condition + ") {\n";

        for (const auto &instruction : if_instructions)
            newString += "  " + instruction->get() + "\n";

        newString += "} else {\n";

        for (const auto &instruction : else_instructions)
            newString += "  " + instruction->get() + "\n";

        newString += "}";

        return newString;
    }
};

#endif // IF_SENTENCE_H