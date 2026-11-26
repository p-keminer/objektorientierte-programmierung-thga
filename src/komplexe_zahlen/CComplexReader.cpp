#include "komplexe_zahlen/CComplexReader.h"

#include <algorithm>
#include <exception>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using std::cout, std::endl, std::istream;
using std::exception, std::invalid_argument;
using std::optional, std::nullopt;
using std::string;
using std::move, std::pair, std::string;
using std::ranges::find, std::ranges::is_sorted, std::ranges::minmax_element, std::ranges::sort;
using std::vector;


namespace {
    bool pruefe_abbruch(const string& eingabe) {
        return eingabe == "0+0i";
    }

    optional<CComplex> read(istream& stream) {
        string eingabe;
        cout << "Komplexe Zahl eingeben: " << endl;
        if (!(stream >> eingabe)) return nullopt;
        if (pruefe_abbruch(eingabe)) return nullopt;
        if (!eingabe.ends_with('i')) {
            throw invalid_argument("Keine Gueltige Eingabe - Gueltig: -5+5i, 5-5i oder -5-5i !");
        }
        return CComplex(eingabe);
    }
}

vector<CComplex>& CComplexReader::get_komplexe_zahlen() {
    return komplexe_zahlen;
}

void CComplexReader::constant_reader(istream& stream) {
    while (true) {
        try {
            auto zahl = read(stream);
            if (!zahl.has_value()) {
                cout << "Einlesene erfolgreich beendet!" << endl;
                return;
            }
            komplexe_zahlen.push_back(*zahl);
            cout << "Komplexe Zahl hinzugefuegt: " << komplexe_zahlen.back() << endl;
        }
        catch (const exception& e) {
            cout << e.what() << endl;
        }
    }
}

pair<vector<CComplex>::iterator, vector<CComplex>::iterator> CComplexReader::finde_minmax() {
    if (komplexe_zahlen.empty()) {
        throw invalid_argument("Keine Zahlen vorhanden zum durchsuchen");
    }
    auto [minimum, maximum] = minmax_element(komplexe_zahlen,
        [](const CComplex& a, const CComplex& b) { return a < b; });
    return {minimum, maximum};
}

vector<CComplex>::iterator CComplexReader::finde_kleinstes_element() {
    return finde_minmax().first;
}

vector<CComplex>::iterator CComplexReader::finde_groesstes_element() {
    return finde_minmax().second;
}

vector<CComplex>::iterator CComplexReader::finde_komplexe_zahl(const CComplex& zahl) {
    auto it = find(komplexe_zahlen, zahl);
    if (it == komplexe_zahlen.end()) throw invalid_argument("Zahl Nicht gefunden!");
    return it;
}

vector<CComplex>::iterator CComplexReader::finde_komplexe_zahl(double real, double imaginaer) {
    return finde_komplexe_zahl(CComplex(real, imaginaer));
}

vector<CComplex>::iterator CComplexReader::finde_komplexe_zahl(const string& zahl) {
    return finde_komplexe_zahl(CComplex(zahl));
}

void CComplexReader::sortiere_vektor(bool aufsteigend) {
    auto vergleiche = [aufsteigend](const CComplex& a, const CComplex& b) {
        return aufsteigend ? a < b : a > b;
    };
    if (is_sorted(komplexe_zahlen, vergleiche)) return;
    sort(komplexe_zahlen, vergleiche);
}

vector<CComplex> CComplexReader::verschiebe_komplexe_zahlen() {
    return move(komplexe_zahlen);
}
