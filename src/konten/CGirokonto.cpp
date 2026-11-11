#include "CGirokonto.h"

#include <iostream>

using std::cout, std::endl;

CGirokonto::CGirokonto(const double &kontostand, const double &kreditrahmen)
    : CKonto(kontostand)
{
    set_kredit(kreditrahmen);
}

void CGirokonto::set_kredit(const double &kreditrahmen ) {
    kredit = (kreditrahmen > 0 ? kreditrahmen : 0);
}

double CGirokonto::auszahlen(const double &betrag) {
    double auszahlungsbetrag = (betrag > 0 ? (betrag <= get_kontostand() + kredit ?
                                betrag : 0) : 0);
    set_kontostand(get_kontostand() - auszahlungsbetrag, "OK");
    return auszahlungsbetrag;
}

void CGirokonto::anzeigen() const {
    CKonto::anzeigen();
    cout << "Kreditrahmen: " << kredit << endl;
}

