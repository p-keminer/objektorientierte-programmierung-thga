#include <stdexcept>
#include <algorithm>
#include <vector>
#include <iostream>

#include "kontoverwaltung/kunden/CBankkunde.h"
#include "kontoverwaltung/konten/CKonto.h"



using std::ranges::find;

/// INITIALISISERUNG

CBankkunde::CBankkunde(const string &nachname, const DatumT &geburtsdatum, const string &vorname)
    :CKunde(nachname, geburtsdatum, vorname)
{
}

CBankkunde::~CBankkunde() {
    delete_all_kontos();
}

/// GETTER


double CBankkunde::get_gesamtsaldo() const {
    double gesamtsaldo = 0;
    for (CKonto* konto : konten) {
        gesamtsaldo += konto->get_kontostand();
    }
    return gesamtsaldo;
}

void CBankkunde::get_kontenliste() const {
    for (CKonto* konto : konten) konto->anzeigen();
}

CKonto &CBankkunde::get_konto(CKonto* konto) {
    auto it = find(konten, konto);
    return (**it);
}

/// SETTER

void CBankkunde::add_konto(CKonto* konto) {

    if (anzahl_konten >= ANZAHL_KONTEN) throw std::length_error("Maximale Anzahl an Konten erreicht!");
    if (!konto) throw std::invalid_argument("Ungueltiger Zeiger!");

    auto it = find(konten, konto);

    if (it != konten.end()) throw std::invalid_argument("Konto schon vorhanden!");

    konto->set_bankkunde(this);
    konten.push_back(konto);
    anzahl_konten = konten.size();
}

void CBankkunde::delete_konto(CKonto *konto) {

    if (konten.empty()) throw std::length_error("Keine Konten vorhanden");
    if (!konto) throw std::invalid_argument("Ungueltiger Zeiger!");

    auto it = find(konten,konto);
    if (it != konten.end()) {
        konto->set_bankkunde(nullptr);
        konten.erase(it);
        anzahl_konten = konten.size();
    }
    else throw std::invalid_argument("Konto nicht gefunden!");
}

void CBankkunde::delete_all_kontos() {
    while (!konten.empty()) delete_konto(konten.back());
}
