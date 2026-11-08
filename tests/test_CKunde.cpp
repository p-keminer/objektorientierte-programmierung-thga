#include "../src/kunden/CKunde.h"

#include <cassert>
#include <stdexcept>
#include <iostream>

using std::cout, std::endl;

struct kundenstruct {
    CKunde kunde1, kunde2, kunde3, kunde4;
};


    DatumT geburtstage[6] = {
        {20, 1, 1967},      // OK
        {29, 2, 2000},      // Schaltjahr
        {29, 2, 2001},      // kein Schaltjahr
        {20, 1, 1899},      // vor 1900
        {20, 13, 1901},     // 13er monat
        {31, 4, 2000}       // april hat nur 30 Tage
    };


kundenstruct erzeuge_kunden() {

    return kundenstruct{
        {"OK", geburtstage[0]},
        {"OK mit Vorname", geburtstage[0],"Vorname"},
        {"Schaltjahr", geburtstage[1]},
        {"Standard"}
    };


}

void teste_konstruktor_exceptions() {


    bool exc = false;
    try {
        CKunde kunde1("x", geburtstage[2]);
    }
    catch (const std::invalid_argument &e) {
        exc = true;
        cout << e.what() << endl;;
    }
    assert(exc);

    exc = false;
    try {
        CKunde kunde1("x", geburtstage[3]);
    }
    catch (const std::invalid_argument &e) {
        exc = true;
        cout << e.what() << endl;;
    }
    assert(exc);

    exc = false;
    try {
        CKunde kunde1("x",geburtstage[4]);
    }
    catch (const std::invalid_argument &e) {
        exc = true;
        cout << e.what() << endl;;
    }
    assert(exc);

    exc = false;
    try {
        CKunde kunde1("x",geburtstage[5]);
    }
    catch (const std::invalid_argument &e) {
        exc = true;
        cout << e.what() << endl;;
    }
    assert(exc);


}

void teste_get_alter() {

    kundenstruct kunden = erzeuge_kunden();

    assert(kunden.kunde1.get_alter() == 59);
    assert(kunden.kunde3.get_alter() == 26);
    assert(kunden.kunde4.get_alter() == 126);

}

void teste_get_name_vorname() {

    kundenstruct kunden = erzeuge_kunden();
    assert(kunden.kunde1.get_name() == "OK");
    assert(kunden.kunde2.get_vorname() == "Vorname");
    assert(kunden.kunde4.get_vorname() == "");
}

void teste_anzeigen() {

    CKunde kunde1("OK", geburtstage[0],"VOROK");
    assert(kunde1.anzeigen()=="Name        : OK\nVorname     : VOROK\nGeburtsdatum: 20.1.1967\n");

}



int main() {

    teste_konstruktor_exceptions();
    teste_get_alter();
    teste_get_name_vorname();
    teste_anzeigen();

    return 0;
}