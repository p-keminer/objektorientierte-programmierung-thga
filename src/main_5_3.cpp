#include <iostream>

#include "main_5_3.h"



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

