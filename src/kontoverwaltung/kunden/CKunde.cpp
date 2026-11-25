#include "kontoverwaltung/kunden/CKunde.h"

#include <ctime>
#include <stdexcept>
#include <tuple>
#include <iostream>

using std::string, std::to_string;
using std::cout, std::endl;


/// HELFER

namespace
{
    DatumT aktuelles_datum() {
        const std::time_t jetzt = std::time(nullptr);
        const std::tm* zeit = std::localtime(&jetzt);

        if (zeit == nullptr) throw std::runtime_error("Aktuelles Datum nicht verfügbar.");

        return {zeit->tm_mday,zeit->tm_mon + 1,zeit->tm_year + 1900};
    }

    string datum_als_string(DatumT datum) {
        return to_string(datum.tag) + "."
             + to_string(datum.monat) + "."
             + to_string(datum.jahr);
    }

}

/// INITIALISIERUNG

bool CKunde::validiere_geburtsdatum(DatumT datum) {
    if (datum.jahr < 1900 || datum.monat < 1 || datum.monat > 12) return false;

    const int monatstage[] = { 31, 28, 31, 30, 31, 30,
                               31, 31, 30, 31, 30, 31
                              };

    int maximale_tage = monatstage[datum.monat - 1];

    const bool schaltjahr = datum.jahr % 4 == 0 &&
                            (datum.jahr % 100 != 0 || datum.jahr % 400 == 0);

    if (datum.monat == 2 && schaltjahr) maximale_tage = 29;

    if (datum.tag < 1 || datum.tag > maximale_tage) return false;

    const DatumT heute = aktuelles_datum();

    // zuerst Jahr, dann Monat, dann Tag
    return std::tie(datum.jahr, datum.monat, datum.tag)
        <= std::tie(heute.jahr, heute.monat, heute.tag);
}


void CKunde::berechne_alter() {
    const DatumT heute = aktuelles_datum();
    short alter = heute.jahr - geburtsdatum.jahr;

    alter = (heute.monat < geburtsdatum.monat ||
            (heute.monat == geburtsdatum.monat && heute.tag < geburtsdatum.tag) ?
            --alter : alter);

    this->alter = alter;
}

CKunde::CKunde(const string &nachname,const DatumT &geburtsdatum, const string &vorname)
    : nachname(nachname), vorname(vorname)
{
    if (!validiere_geburtsdatum(geburtsdatum)) throw std::invalid_argument("Ungueltiges Geburtsdatum.");
    this->geburtsdatum = geburtsdatum;
    berechne_alter();
}

/// DEBUG

string CKunde::anzeigen() const {
    string vorstellen =   "Name        : " + nachname
                        + "\nVorname     : " + vorname
                        + "\nGeburtsdatum: " + datum_als_string(geburtsdatum)
                        + "\n";
    cout << vorstellen << endl;
    return vorstellen;
}


/// GETTER

const short &CKunde::get_alter() {
    berechne_alter();
    return alter;
}



