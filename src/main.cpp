#include <iostream>

#include "konten/CGirokonto.h"
#include "konten/CSparbuch.h"
#include "kunden/CBankkunde.h"

using std::cout, std::endl;

int main() {

    CBankkunde kunde1("Conrad",{1,1,1990},"Paul");

    CGirokonto girokonto1(500,500);
    CSparbuch sparbuch1(5000);

    kunde1.add_konto(&girokonto1);
    kunde1.add_konto(&sparbuch1);

    cout << kunde1.get_gesamtsaldo() << endl;
    cout << kunde1.get_anzahl_konten() << endl;

    kunde1.get_kontenliste();




    return 0;
}