#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <memory>

#include "./include/Import.h"
#include "./include/Print.h"
#include "./include/Variable.h"
#include "./include/Condition.h"
#include "./include/IfSentence.h"
#include "./include/DoWhileSentence.h"
#include "./include/WhileSentence.h"

#include "./src/Middleware/Normalize.cpp"

using namespace std;

// Lectura
string getPrompt();

// Construir el codigo
vector<string> buildCode1(set<Import>, vector<Print>);
vector<string> buildCode(set<Import>, const vector<unique_ptr<Instruction>> &);

// Impresiones
void printCode(const vector<string> &);

int main()
{
    // Arreglos de estructuras
    std::set<Import> imports;

    // Arreglo de instrucciones
    std::vector<std::unique_ptr<Instruction>> instructions;

    std::vector<std::unique_ptr<Instruction>> if_instructions;
    std::vector<std::unique_ptr<Instruction>> else_instructions;
    std::vector<std::unique_ptr<Instruction>> do_while_instructions;

    Condition condition("1", Comparator::Different, "2");

    // Sentencia if
    if_instructions.push_back(std::make_unique<Print>("Hola"));
    else_instructions.push_back(std::make_unique<Print>("Adios"));
    IfSentence ifSentence(condition, std::move(if_instructions), std::move(else_instructions));

    // Sentencias do_while
    do_while_instructions.push_back(std::make_unique<Print>("ciclo do while 1"));
    do_while_instructions.push_back(std::make_unique<Print>("ciclo do while 2"));
    WhileSentence doWhileSentence(condition, std::move(do_while_instructions));    

    instructions.push_back(std::make_unique<Variable>(Type::Int, "var1"));
    instructions.push_back(std::make_unique<Variable>(Type::Int, "var2", "21"));
    instructions.push_back(std::make_unique<Print>("Hola mundo"));
    instructions.push_back(std::make_unique<IfSentence>(std::move(ifSentence)));
    instructions.push_back(std::make_unique<WhileSentence>(std::move(doWhileSentence)));

    // Puedes añadir otras instrucciones aquí

    // Construir el código
    auto code = buildCode(imports, instructions);

    // Imprimir el código
    for (const auto &line : code)
    {
        std::cout << line << std::endl;
    }

    return 0;
}

// Lectura
string getPrompt()
{
    string prompt;

    cout << "Ingresar prompt: \n";
    getline(cin, prompt);

    return clean(prompt);
}

// Construir código
vector<string> buildCode1(set<Import> imports, vector<Print> prints)
{
    if (!prints.empty())
        imports.insert(prints[0].import());

    vector<string> code;
    for (const Import &import : imports)
        code.push_back(import.get());

    code.push_back("int main() {");

    for (const Print &print : prints)
        // code.push_back(printget());

        code.push_back("return 0;");
    code.push_back("}");

    return code;
}

vector<string> buildCode(set<Import> imports, const vector<unique_ptr<Instruction>> &instructions)
{
    for (const auto &instruction : instructions)
        if (typeid(*instruction) == typeid(Print))
        {
            imports.insert(Import("iostream"));
            break;
        }

    vector<string> code;

    // Agregar imports al código
    for (const Import &import : imports)
    {
        code.push_back(import.get());
    }

    code.push_back("int main() {");

    // Agregar las instrucciones al código
    for (const auto &instruction : instructions)
    {
        code.push_back(instruction->get());
    }

    code.push_back("return 0;");
    code.push_back("}");

    return code;
}

// Impresiones
void printCode(const vector<string> &code)
{
    for (const string &line : code)
        cout << line << endl;
}
