#ifndef CONDITION_H
#define CONDITION_H

#include "Instruction.h"

enum class Comparator
{
    Null,
    Equal,
    Different,
    MoreThan,
    MoreEqual,
    LessThan,
    LessEqual
};

class Condition : public Instruction
{
private:
    std::string first_operator;
    Comparator comparator;
    std::string second_operator;

public:
    // Constructor
    Condition(std::string first_operator, Comparator comparator = Comparator::Null, std::string second_operator = "")
        : first_operator(first_operator), comparator(comparator), second_operator(second_operator) {}

    // Getters
    std::string getFirsOperator() const { return first_operator; }
    Comparator getComparator() const { return comparator; }
    std::string getSecondOperator() const { return second_operator; }

    // Setters
    void setFirstOperator(std::string first_operator) { this->first_operator = first_operator; }
    void setComparator(Comparator comparator) { this->comparator = comparator; }
    void setSecondOperator(std::string second_operator) { this->second_operator = second_operator; }

    std::string get() override
    {
        // Convertir Comparator a string para la salida
        std::string comparator_name;
        switch (comparator)
        {
        case Comparator::Null:
            comparator_name = "";
            break;
        case Comparator::Equal:
            comparator_name = "==";
            break;
        case Comparator::Different:
            comparator_name = "!=";
            break;
        case Comparator::MoreThan:
            comparator_name = ">";
            break;
        case Comparator::MoreEqual:
            comparator_name = ">=";
            break;
        case Comparator::LessThan:
            comparator_name = "<";
            break;
        case Comparator::LessEqual:
            comparator_name = "<=";
            break;
        }

        return first_operator + (!comparator_name.empty() ? " " + comparator_name + " " + second_operator : "");
    }
};

#endif // CONDITION_H