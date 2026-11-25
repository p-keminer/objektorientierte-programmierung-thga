#ifndef OOP_HAUSAUFGABE_MAIN_5_3_H
#define OOP_HAUSAUFGABE_MAIN_5_3_H

#include <iostream>
#include <vector>
#include <array>
#include <cstddef>
#include <iomanip>
#include <list>
#include <iterator>
#include <stdexcept>


/// Strukturen

/// Struktur 1D

template<typename T>
struct data {
    T iterator;
    int index;
};

/// Strukturen 2D

struct data2 {
    int index_aussen;
    int index_innen;
};

template<typename T>
struct data3 {
    T iterator;
    int index_aussen;
    int index_innen;
};

/// Struktur Testdaten

struct erzeugen1 {
    int array[5];
    std::vector<int> vektor;
    std::array<int, 8> stl_array;
    std::list<int> liste;
    std::vector<double> dezimalzahlen;
    std::list<std::string> texte;
    std::vector<int> negative_zahlen;
    std::vector<int> duplikate;
    std::vector<int> leer;
    std::array<int, 1> einzelwert;
};

struct erzeugen2 {
    int array_2D[3][3];
    std::vector<std::vector<int>> vektor_2D;
    std::list<std::list<int>> liste_2D;
    std::vector<std::list<double>> vektor_liste;
    std::list<std::vector<int>> liste_vektor;
    std::array<std::array<int, 3>, 2> stl_array_2D;
    std::vector<std::vector<int>> leer;
};

/// Funktionsdeklarationen

template<typename T1, typename T2>
auto suche(const T1& container, T2 element);

template<typename T1, typename T2>
auto suche_2D(const T1& container, T2 element);

template<typename T1, typename T2>
std::size_t ersetze(T1& container, T2 zu_ersetzen, T2 ersetzen_durch);

void ausgabe(const auto& container, auto element);
void ausgabe_2D(const auto& container, auto element);

erzeugen1 erzeuge_1D_container();
erzeugen2 erzeuge_2D_container();

#endif //OOP_HAUSAUFGABE_MAIN_5_3_H
