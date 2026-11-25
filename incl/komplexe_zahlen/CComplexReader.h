#ifndef OOP_HAUSAUFGABE_CCOMPLEXREADER_H
#define OOP_HAUSAUFGABE_CCOMPLEXREADER_H

#include "komplexe_zahlen/CComplex.h"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

class CComplexReader {
    std::vector<CComplex> komplexe_zahlen;

public:
    std::vector<CComplex>& get_komplexe_zahlen();
    void constant_reader(std::istream& stream = std::cin);

    std::pair<std::vector<CComplex>::iterator, std::vector<CComplex>::iterator> finde_minmax();
    std::vector<CComplex>::iterator finde_kleinstes_element();
    std::vector<CComplex>::iterator finde_groesstes_element();

    std::vector<CComplex>::iterator finde_komplexe_zahl(const CComplex& zahl);
    std::vector<CComplex>::iterator finde_komplexe_zahl(double real, double imaginaer);
    std::vector<CComplex>::iterator finde_komplexe_zahl(const std::string& zahl);

    void sortiere_vektor(bool aufsteigend = true);
    std::vector<CComplex> verschiebe_komplexe_zahlen();
};

#endif // OOP_HAUSAUFGABE_CCOMPLEXREADER_H
