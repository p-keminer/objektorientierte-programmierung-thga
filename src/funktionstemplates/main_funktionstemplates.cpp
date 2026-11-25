#include <iostream>

#include "funktionstemplates/main_funktionstemplates.h"



int main() {

    auto container = erzeuge_1D_container();
    auto container2 = erzeuge_2D_container();

    /// Suche 1D

    std::cout << "\n--- Suche 1D ---\n\n";

    ausgabe(container.array, 4);
    ausgabe(container.vektor, 2);
    ausgabe(container.stl_array, 5);
    ausgabe(container.liste, 1);
    ausgabe(container.dezimalzahlen, 3.5);
    ausgabe(container.texte, "DNS");
    ausgabe(container.negative_zahlen, -5);
    ausgabe(container.negative_zahlen, 0);
    ausgabe(container.duplikate, 3);
    ausgabe(container.einzelwert, 42);
    ausgabe(container.liste, 35);
    ausgabe(container.leer, 5);
    ausgabe(container.einzelwert, 99);

    /// Suche 2D

    std::cout << "\n--- Suche 2D ---\n\n";

    ausgabe_2D(container2.array_2D, 6);
    ausgabe_2D(container2.array_2D, 1);
    ausgabe_2D(container2.vektor_2D, 90);
    ausgabe_2D(container2.liste_2D, 1);
    ausgabe_2D(container2.vektor_liste, 5.5);
    ausgabe_2D(container2.liste_vektor, 14);
    ausgabe_2D(container2.stl_array_2D, 600);
    ausgabe_2D(container2.vektor_2D, 999);
    ausgabe_2D(container2.leer, 5);

    /// Ersetzen

    std::cout << "\n--- Ersetzen ---\n\n";

    std::cout << "Array: " << ersetze(container.array, 2, 99) << '\n'
              << "Vektor: " << ersetze(container.vektor, 2, 99) << '\n'
              << "STL-Array: " << ersetze(container.stl_array, 2, 99) << '\n'
              << "Liste: " << ersetze(container.liste, 2, 99) << '\n'
              << "Dezimalzahlen: " << ersetze(container.dezimalzahlen, 2.5, 9.5) << '\n'
              << "Texte: " << ersetze(container.texte,"SSH","HTTPS") << '\n'
              << "Negative Zahlen: " << ersetze(container.negative_zahlen, -5, 99) << '\n'
              << "Duplikate: " << ersetze(container.duplikate, 3, 99) << '\n'
              << "Leerer Container: " << ersetze(container.leer, 5, 99) << '\n'
              << "Einzelwert: " << ersetze(container.einzelwert, 42, 99) << '\n'
              << "Nicht vorhandener Wert: " << ersetze(container.vektor, 500, 99)
              << std::endl;

    return 0;
}


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
