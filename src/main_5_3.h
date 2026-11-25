#ifndef OOP_HAUSAUFGABE_MAIN_5_3_H
#define OOP_HAUSAUFGABE_MAIN_5_3_H

#include <iostream>
#include <vector>
#include <array>
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



/// Suchfunktionen

/// Suche 1D

template<typename T1, typename T2>
auto suche(const T1& container, const T2 element) {

    int index = 0;
    constexpr bool indexzugriff = requires { container[0]; };

    for (auto it = std::begin(container); it != std::end(container); it++) {
        if (*it == element) {
            if constexpr (indexzugriff) return index;
            else return data{it, index};
        }
        index++;
    }

    throw std::invalid_argument("Element nicht gefunden!");
}


/// Suche 2D

template<typename T1, typename T2>
auto suche_2D(const T1& container, const T2 element) {

    int index_aussen = 0;
    int index_innen = 0;
    constexpr bool indexzugriff = requires { container[0]; };

    for (auto it_aussen = std::begin(container); it_aussen != std::end(container); ++it_aussen) {
        for (auto it_innen = std::begin(*it_aussen); it_innen != std::end(*it_aussen); ++it_innen) {
            if (*it_innen == element) {
                if constexpr (indexzugriff) return data2{index_aussen, index_innen};
                else return data3{it_innen, index_aussen, index_innen};
            }
            index_innen++;
        }

        index_innen = 0;
        index_aussen++;
    }

    throw std::invalid_argument("Element nicht gefunden!");
}


/// Ersetzungsfunktion

template<typename T1, typename T2>
size_t ersetze(T1& container, T2 zu_ersetzen, T2 ersetzen_durch) {

    size_t anzahl = 0;

    for (auto p = std::begin(container); p != std::end(container); p++) {
        if (*p == zu_ersetzen) {
            *p = ersetzen_durch;
            anzahl++;
        }
    }

    return anzahl;
}


/// Ausgabefunktionen

void ausgabe(const auto& container, const auto element) {

    try {
        auto ergebnis = suche(container, element);

        std::cout << "Suche " << element << " - Index: [";

        if constexpr (requires { ergebnis.index; }) {
            std::cout << ergebnis.index;
        }
        else {
            std::cout << ergebnis;
        }

        std::cout << "]" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}


void ausgabe_2D(const auto& container, const auto element) {

    try {
        auto ergebnis = suche_2D(container, element);

        std::cout << "Suche " << element
                  << " - Index: ["
                  << ergebnis.index_aussen << "]["
                  << ergebnis.index_innen << "]"
                  << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}


/// Testdaten

erzeugen1 erzeuge_1D_container() {
    return {
        // array
        {5, 4, 3, 2, 1},

        // vektor
        {5, 4, 3, 2, 1, 2, 2, 2, 2, 2},

        // stl_array
        {5, 4, 3, 2, 1, 2, 2, 2},

        // liste
        {5, 4, 3, 2, 1, 2},

        // dezimalzahlen
        {1.5, 2.5, 3.5, 4.5, 2.5},

        // texte
        {"SSH", "HTTP", "DNS", "FTP", "SSH"},

        // negative_zahlen
        {-10, -5, 0, 5, 10},

        // duplikate
        {3, 3, 3, 3, 3},

        // leer
        {},

        // einzelwert
        {42}
    };
}

erzeugen2 erzeuge_2D_container() {

    return {
        // array_2D
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },

        // vektor_2D
        {
            {10, 20, 30},
            {40, 50},
            {60, 70, 80, 90}
        },

        // liste_2D
        {
            {5, 4, 3},
            {2, 1},
            {8, 9, 10}
        },

        // vektor_liste
        {
            {1.5, 2.5},
            {3.5, 4.5, 5.5},
            {6.5}
        },

        // liste_vektor
        {
            {11, 12},
            {},
            {13, 14, 15}
        },

        // stl_array_2D
        {{
            {100, 200, 300},
            {400, 500, 600}
        }},

        // leer
        {}
    };
}

#endif //OOP_HAUSAUFGABE_MAIN_5_3_H
