#include "kontoverwaltung/kunden/CBankkunde.h"
#include "kontoverwaltung/konten/CGirokonto.h"
#include "kontoverwaltung/konten/CSparbuch.h"

#include <cassert>
#include <stdexcept>
#include <iostream>

using std::cout, std::endl;

struct bankkundenstruct {
    CBankkunde kunde1, kunde2;
};

struct kontenstruct {
    CGirokonto konto1, konto2, konto3;
    CSparbuch konto4, konto5, konto6;
};

DatumT geburtstage[6] = {
    {20, 1, 1967},
    {29, 2, 2000},
    {26, 7, 1980},
};


bankkundenstruct erzeuge_kunden() {

    return bankkundenstruct {
        {"OK", geburtstage[0]},
        {"OK mit Vorname", geburtstage[0],"Vorname"},
    };


}

kontenstruct erzeuge_konten() {

    return kontenstruct {
        {200},
        {400},
        {},
        {0,500},
        {700,900},
        {0,0}
    };

}

void teste_add_konto() {

    bankkundenstruct kunden = erzeuge_kunden();
    kontenstruct konten = erzeuge_konten();

    // ungueltiger zeiger

    bool exc = false;
    try {
        kunden.kunde1.add_konto(nullptr);
    }
    catch (const std::invalid_argument &e) {
        exc = true;
        cout << e.what() << endl;;
    }
    assert(exc);

    kunden.kunde1.add_konto(&konten.konto1);
    kunden.kunde1.add_konto(&konten.konto2);
    kunden.kunde1.add_konto(&konten.konto3);
    kunden.kunde1.add_konto(&konten.konto4);
    kunden.kunde1.add_konto(&konten.konto5);

    // maximal 5 konten

    exc = false;
    try {
        kunden.kunde1.add_konto(&konten.konto6);
    }
    catch (const std::length_error &e) {
        exc = true;
        cout << e.what() << endl;;
    }
    assert(exc);

    // zwei mal das gleiche konto

    kunden.kunde1.delete_konto(&konten.konto5);

    exc = false;
    try {
        kunden.kunde1.add_konto(&konten.konto4);
    }
    catch (const std::logic_error &e) {
        exc = true;
        cout << e.what() << endl;;
    }
    assert(exc);

}

void teste_delete_konto() {

    bankkundenstruct kunden = erzeuge_kunden();
    kontenstruct konten = erzeuge_konten();

    // ungueltiger zeiger

    kunden.kunde1.add_konto(&konten.konto1);

    bool exc = false;
    try {
        kunden.kunde1.add_konto(nullptr);
    }
    catch (const std::invalid_argument &e) {
        exc = true;
        cout << e.what() << endl;;
    }
    assert(exc);


    // keine konten vorhanden

    kunden.kunde1.delete_konto(&konten.konto1);

    exc = false;
    try {
        kunden.kunde1.delete_konto(&konten.konto1);
    }
    catch (const std::length_error &e) {
        exc = true;
        cout << e.what() << endl;;
    }
    assert(exc);

    // konto nicht vorhanden

    kunden.kunde1.add_konto(&konten.konto1);

    exc = false;
    try {
        kunden.kunde1.delete_konto(&konten.konto5);
    }
    catch (const std::invalid_argument &e) {
        exc = true;
        cout << e.what() << endl;;
    }
    assert(exc);

}

void teste_get_gesamtsaldo() {

    bankkundenstruct kunden = erzeuge_kunden();
    kontenstruct konten = erzeuge_konten();

    kunden.kunde1.add_konto(&konten.konto1);
    kunden.kunde1.add_konto(&konten.konto2);
    kunden.kunde1.add_konto(&konten.konto3);
    kunden.kunde1.add_konto(&konten.konto4);
    kunden.kunde1.add_konto(&konten.konto5);

    assert(kunden.kunde1.get_gesamtsaldo() == 1300);

}

void teste_assoziation_bankkunden() {

    bankkundenstruct kunden = erzeuge_kunden();
    kontenstruct konten = erzeuge_konten();

    kunden.kunde1.add_konto(&konten.konto1);

    bool exc = false;
    try {
        kunden.kunde2.add_konto(&konten.konto1);
    }
    catch (const std::logic_error &e) {
        exc = true;
        cout << e.what() << endl;;
    }
    assert(exc);

}

int main() {

    teste_add_konto();
    teste_delete_konto();
    teste_get_gesamtsaldo();
    teste_assoziation_bankkunden();

    return 0;
}