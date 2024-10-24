#ifndef DO_WHILE_SENTENCE_H
#define DO_WHILE_sENTENCE_H

#include <vector>
#include <memory>

#include "Instruction.h"
#include "Condition.h"

class DoWhileSentence : public Instruction
{
private:
    Condition condition;
    std::vector<std::unique_ptr<Instruction>> instructions;

public:
    // Constructor
    DoWhileSentence(Condition condition,
                    std::vector<std::unique_ptr<Instruction>> instructions)
        : condition(condition), instructions(std::move(instructions)) {}

    // Getters
    Condition getCondition() const { return condition; }
    const std::vector<std::unique_ptr<Instruction>> &getInstructions() const { return instructions; }

    // Setters
    void setCondition(Condition condition) { this->condition = condition; }
    void setInstructions(std::vector<std::unique_ptr<Instruction>> instructions) { this->instructions = (std::move(instructions)); }

    // Add Instruction
    void insertInstruction(std::unique_ptr<Instruction> instruction) { this->instructions.push_back(std::move(instruction)); }

    std::string get() override
    {
        std::string newString = "do {\n";

        for (const auto &instruction : instructions)
            newString += "  " + instruction->get() + "\n";

        newString += "} while (" + condition.get() + ");";

        return newString;
    }
};

#endif // DO_WHILE_SENTENCE