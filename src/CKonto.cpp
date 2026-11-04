#include <iostream>
#include <random>
#include <chrono>

#include "CKonto.h"

using std::cout, std::endl;

/// PRIVATE

void CKonto::init_kontostand(const double &kontostand) {
    this->kontostand = (kontostand >= 0 ? kontostand : 0);
}

/// PROTECTED

void CKonto::set_kontostand(const double &kontostand, const string &berechtigung) {
    this->kontostand = (berechtigung == "OK" ? kontostand : this->kontostand);
}


/// PUBLIC

CKonto::CKonto (const double &kontostand)
{
    init_kontostand(kontostand);
    kontonummer += laufende_nummer;
    laufende_nummer++;
    anzahl_konten++;
    // cout << "\nobjekt " << kontonummer << " erstellt\n" << endl;
}

CKonto::~CKonto() {
    auszahlen(kontostand);
    anzahl_konten--;
    // cout << "\nobjekt " << kontonummer << " zerstoert\n" << endl;
};

/// DEBUG

void CKonto::anzeigen() const {
    cout << "Kontonummer: " << kontonummer << ", Kontostand: "
         << kontostand << " EUR"<< endl;;
}

void CKonto::zeige_anzahl_konten() {
    cout << "Anzahl Konten: " << anzahl_konten << endl;
}

/// FUNKTIONALITÄT

void CKonto::einzahlen(const double &betrag) {
    kontostand += (betrag > 0 ? betrag : 0) ;
}

double CKonto::auszahlen(const double &betrag) {
    double auszahlungsbetrag = (betrag > 0 ? (betrag <= kontostand ? betrag : 0) : 0);
    kontostand -= auszahlungsbetrag;
    return auszahlungsbetrag;
}



void zeige_gesamtbetrag(const CKonto kontos[], const int &n) {
    double summe = 0;
    for (int i = 0; i < n; i++ ) {
        summe += kontos[i].kontostand;
    }
    cout << "Gesamtbetrag aller Konten: " << summe << endl;
}



