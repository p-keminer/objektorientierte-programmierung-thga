#include <iostream>
#include "CKonto.h"

#define ANZAHL_KONTEN 3


int main() {

    CKonto konto1(0.00);
    konto1.einzahlen(100.00);
    konto1.anzeigen();
    konto1.auszahlen(100.00);
    konto1.anzeigen();
    CKonto konto2;
    konto2.anzeigen();
    CKonto::zeige_anzahl_konten();


    CKonto kontos[ANZAHL_KONTEN] = {100, 300, 400};
    zeige_gesamtbetrag(kontos, ANZAHL_KONTEN);

    kontos[0].anzeigen();
    kontos[1].anzeigen();
    kontos[2].anzeigen();
    CKonto::zeige_anzahl_konten();


    return 0;
}