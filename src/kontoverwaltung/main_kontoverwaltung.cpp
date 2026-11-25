#include <iostream>
#include <vector>

#include "kontoverwaltung/konten/CGirokonto.h"
#include "kontoverwaltung/konten/CSparbuch.h"
#include "kontoverwaltung/kunden/CBankkunde.h"


using std::cout, std::endl;
using std::vector;

int main() {
    CBankkunde kunde1("Conrad",{1,1,1990},"Paul");

    CGirokonto girokonto1(500,500);
    CSparbuch sparbuch1(5000);

    kunde1.add_konto(&girokonto1);
    kunde1.add_konto(&sparbuch1);

    cout << kunde1.get_gesamtsaldo() << endl;
    cout << kunde1.get_anzahl_konten() << endl;

    kunde1.get_kontenliste();
    kunde1.get_konto(&sparbuch1).einzahlen(kunde1.get_konto(&girokonto1).auszahlen(1000));
    kunde1.get_kontenliste();

    return 0;
}