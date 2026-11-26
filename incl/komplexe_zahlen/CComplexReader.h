#ifndef OOP_HAUSAUFGABE_CCOMPLEXREADER_H
#define OOP_HAUSAUFGABE_CCOMPLEXREADER_H

#include "komplexe_zahlen/CComplex.h"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using std::cin, std::istream;
using std::string;
using std::pair;
using std::vector;

class CComplexReader {
    std::vector<CComplex> komplexe_zahlen;

public:
    std::vector<CComplex>& get_komplexe_zahlen();

    /**
     * @brief Liest komplexe Zahlen und hängt sie an die gespeicherten Werte im Vektor an.
     * @param stream Quelle der Eingaben. Übergabe zu Testzwecken.
     * @details `0+0i` oder Ende des Streams beendet das Einlesen.
     * Fehler beim Einlesen werden ausgegeben und anschließend weitergelesen.
     */
    void constant_reader(istream& stream=cin);

    /**
     * @brief Ermittelt Elemente mit kleinstem und größtem Betrag.
     * @return Iteratoren auf das kleinste und größte Element.
     * @throws std::invalid_argument Wenn der Vektor leer ist.
     */
    pair<vector<CComplex>::iterator, vector<CComplex>::iterator> finde_minmax();
    vector<CComplex>::iterator finde_kleinstes_element();
    vector<CComplex>::iterator finde_groesstes_element();

    /**
     * @brief Sucht erstes Vorkommen für exakt gleichen Real und Imaginärteil.
     * @return Iterator auf gefundenen Eintrag im Vektor.
     * @throws std::invalid_argument Wenn Zahl nicht gespeichert ist.
     */
    vector<CComplex>::iterator finde_komplexe_zahl(const CComplex& zahl);
    vector<CComplex>::iterator finde_komplexe_zahl(double real, double imaginaer);
    vector<CComplex>::iterator finde_komplexe_zahl(const string& zahl);

    /**
     * @brief Sortiert nach Betrag. Gleich große Beträge können Reihenfolge ändern.
     */
    void sortiere_vektor(bool aufsteigend=true);

    /**
     * @brief Übergibt gespeicherte Zahlen. Reader ist anschließend leer.
     * @return Vektor mit eingelesenen Zahlen.
     * Reader kann nach Leerung erneut gefüllt werden.
     */
    vector<CComplex> verschiebe_komplexe_zahlen();
};

#endif // OOP_HAUSAUFGABE_CCOMPLEXREADER_H
