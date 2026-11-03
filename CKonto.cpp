#include <iostream>
#include <random>
#include <chrono>

#include "CKonto.h"

using std::cout, std::endl;

/// PRIVATE

void CKonto::init_kontostand(const double &kontostand) {
    this->kontostand = (kontostand >= 0 ? kontostand : 0);
}

void CKonto::init_kontonummer() {
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<unsigned long long> dist(100000000000ULL, 999999999999ULL);
    kontonummer = dist(rng);
}

/// PUBLIC

CKonto::CKonto (const double &kontostand)
{
    init_kontostand(kontostand);
    init_kontonummer();
    laufende_nummer++;
    // cout << "\nobjekt " << kontonummer << " erstellt\n" << endl;
}

CKonto::~CKonto() {
    auszahlen(kontostand);
    laufende_nummer--;
    // cout << "\nobjekt " << kontonummer << " zerstoert\n" << endl;
};

/// DEBUG

void CKonto::anzeigen() const {
    cout << "Kontonummer: " << kontonummer << ", Kontostand: "
         << kontostand << " EUR"<< endl;;
}

void CKonto::zeige_anzahl_konten() {
    cout << "Anzahl Konten: " << laufende_nummer << endl;
}

/// FUNKTIONALITÄT

void CKonto::einzahlen(const double &betrag) {
    kontostand += (betrag > 0 ? betrag : 0) ;
}

void CKonto::auszahlen(const double &betrag) {
    kontostand -= (betrag <= kontostand ? betrag : 0) ;
}



void zeige_gesamtbetrag(const CKonto kontos[], const int &n) {
    double summe = 0;
    for (int i = 0; i < n; i++ ) {
        summe += kontos[i].kontostand;
    }
    cout << "Gesamtbetrag aller Konten: " << summe << endl;
}



