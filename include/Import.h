#ifndef IMPORT_H
#define IMPORT_H

#include <iostream>
#include <string> 

class Import
{
private:
    std::string library;

public:
    // Constructor
    Import(std::string library) : library(library) {}

    // Getters
    std::string getLibrary() const { return library; }

    // Setters
    void setLibrary(std::string library) { this->library = library; }

    // Método que imprime la línea de inclusión
    std::string get() const { return "#include <" + library + ">"; }

    // Operador de comparación para std::set
    bool operator<(const Import& other) const {
        return library < other.library;
    }
};

#endif // IMPORT_H