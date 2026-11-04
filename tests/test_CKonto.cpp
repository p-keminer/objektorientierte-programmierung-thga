#include <cassert>
#include <iostream>

# include "../src/CKonto.h"

using std::cout, std::endl;

struct kontostruct{
        CKonto konto1, konto2, konto3, konto4;
    };

kontostruct test_konstruktor() {

    // initialisierung und erstellen

    kontostruct konten{
        {200},
        {400},
        {0},
        {-200}
    };

    // negative Werte werden zu 0 validiert

    assert(konten.konto4.get_kontostand() == 0);

    return konten;

}


void test_ein_aus_zahlen() {

    kontostruct konten = test_konstruktor();

    // normale erwartete funktionalität

    konten.konto1.einzahlen(200);
    assert(konten.konto1.get_kontostand() == 400);
    konten.konto1.auszahlen(200);
    assert(konten.konto1.get_kontostand() == 200);

    // negativen wert einzahlen

    konten.konto2.einzahlen(-200);
    assert(konten.konto2.get_kontostand() == 400);

    // negativen wert auszahlen

    assert(konten.konto2.auszahlen(-200) == 0);
    assert(konten.konto2.get_kontostand() == 400);

    // kontostand zu gering für auszahlung

    konten.konto3.auszahlen(1);
    assert(konten.konto3.get_kontostand() == 0);

    // rückgabewert auszahlung

    assert(konten.konto2.auszahlen(200) == 200);
    assert(konten.konto1.auszahlen(171) == 171);


}


void test_init_kontonummer() {

    // kontonummern sind bei 2 konten eindeutig


    CKonto konto1, konto2, konto3;
    assert(konto1.get_kontonummer() != konto2.get_kontonummer());
    assert(konto1.get_kontonummer() != konto2.get_kontonummer());

    kontostruct konten = test_konstruktor();
    assert(konten.konto1.get_kontonummer() != konten.konto2.get_kontonummer());
    assert(konten.konto2.get_kontonummer() != konten.konto3.get_kontonummer());


}

void test_get_laufende_nummer() {

    // anzahl konten stimmt global überein

    kontostruct konten = test_konstruktor();
    cout << "\nHIER MUSS > 4 < STEHEN" << endl;
    CKonto::zeige_anzahl_konten();


}


int main() {

    test_konstruktor();
    test_init_kontonummer();
    test_ein_aus_zahlen();
    test_get_laufende_nummer();

    return 0;
}