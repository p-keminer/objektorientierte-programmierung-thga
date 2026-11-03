#include <iostream>
#include "CKonto.h"

using std::cout, std::cin, std::endl;


int main() {

    CKonto konto1(0.00);
    konto1.einzahlen(100.00);
    konto1.anzeigen();
    konto1.auszahlen(100.00);
    konto1.anzeigen();
    CKonto konto2;
    konto2.anzeigen();
    konto2.zeige_anzahl_konten();

    return 0;
}