#include "komplexe_zahlen/CComplexReader.h"

#include <algorithm>
#include <cassert>
#include <sstream>
#include <stdexcept>

using std::invalid_argument;
using std::istringstream;
using std::ranges::is_sorted;

void test_suche(CComplexReader& reader) {
    const auto& zahlen = reader.get_komplexe_zahlen();

    // Überladungen

    auto it1 = reader.finde_komplexe_zahl(CComplex(3, 4));
    auto it2 = reader.finde_komplexe_zahl(3, 4);
    auto it3 = reader.finde_komplexe_zahl("3+4i");

    assert(it1 == zahlen.begin());
    assert(it1 == it2);
    assert(it2 == it3);

    // nicht vorhandenes Element

    bool exc = false;
    try {
        reader.finde_komplexe_zahl(99, 99);
    }
    catch (const invalid_argument&) {
        exc = true;
    }
    assert(exc);
}

void test_minmax(CComplexReader& reader) {
    const auto& zahlen = reader.get_komplexe_zahlen();
    auto [min, max] = reader.finde_minmax();
    auto minimum = reader.finde_kleinstes_element();
    auto maximum = reader.finde_groesstes_element();

    assert(minimum != zahlen.end());
    assert(maximum != zahlen.end());
    assert(*minimum == CComplex(-2, 0));
    assert(*maximum == CComplex(6, -8));
    assert(min == minimum);
    assert(max == maximum);
}

void test_sortieren(CComplexReader& reader) {
    const auto& zahlen = reader.get_komplexe_zahlen();

    bool aufsteigend = true;
    auto lambda = [&aufsteigend](const CComplex& a, const CComplex& b) {
        return (aufsteigend ? a < b : a > b);
    };

    // aufsteigend

    reader.sortiere_vektor();
    assert(is_sorted(zahlen, lambda ));

    // absteigend

    aufsteigend = false;
    reader.sortiere_vektor(false);
    assert(is_sorted(zahlen, lambda));
}

void test_kopieren_und_verschieben(CComplexReader& reader) {
    const auto& zahlen = reader.get_komplexe_zahlen();
    const auto kopie = reader.get_komplexe_zahlen();
    assert(kopie.size() == 6);
    assert(kopie == zahlen);

    const auto verschoben = reader.verschiebe_komplexe_zahlen();
    assert(verschoben == kopie);
}

int main() {
    istringstream eingabe(
        "3+4i\n"
        "-1-2i\n"
        "6-8i\n"
        "-2+0i\n"
        "0+3i\n"
        "3+4i\n"
    );

    CComplexReader reader;
    reader.constant_reader(eingabe);
    assert(reader.get_komplexe_zahlen().size() == 6);

    test_suche(reader);
    test_minmax(reader);
    test_sortieren(reader);
    test_kopieren_und_verschieben(reader);

    return 0;
}