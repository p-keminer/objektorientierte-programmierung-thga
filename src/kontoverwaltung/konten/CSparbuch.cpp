#include "kontoverwaltung/konten/CKonto.h"
#include "kontoverwaltung/konten/CSparbuch.h"

#include <iostream>

using std::cout, std::endl;

// PUBLIC

CSparbuch::CSparbuch(const double &kontostand, const double &zinssatz)
    : CKonto(kontostand), zinssatz(zinssatz) {

}

// SETTER

void CSparbuch::set_bearbeitungsgebuehr(const double &gebuehr) {
    bearbeitungsgebuehr = (gebuehr > 0 ? gebuehr : 0 );
}

// FUNKTIONALITÄT

void CSparbuch::verzinsen() {
    CKonto::einzahlen(get_kontostand() * zinssatz/100 );
}

void CSparbuch::einzahlen(const double &betrag) {
    CKonto::einzahlen(betrag-bearbeitungsgebuehr);
}

void CSparbuch::anzeigen() const {
    CKonto::anzeigen();
    cout << "Zinssatz: " << zinssatz << ", "
         << "Bearbeitungsgebuehr: " << bearbeitungsgebuehr << endl;
}