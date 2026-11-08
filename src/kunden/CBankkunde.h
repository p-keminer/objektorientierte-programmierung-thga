#ifndef OOP_HAUSAUFGABE_CBANKKUNDE_H
#define OOP_HAUSAUFGABE_CBANKKUNDE_H

#include <vector>

#include "CKunde.h"

using std::vector;

class CKonto;

class CBankkunde : public CKunde {
private:
    vector<CKonto*> konten;
    short anzahl_konten = 0;        // wird nach aufgabenstellung gefordert

    static constexpr short ANZAHL_KONTEN = 5;
public:

    /// INITIALISIERUNG

    CBankkunde(const string &nachname, const DatumT &geburtsdatum={1, 1, 1900}, const string &vorname="");
    ~CBankkunde();

    /// GETTER

    const short &get_anzahl_konten() const {
        return anzahl_konten;
    }

    double get_gesamtsaldo() const;

    void get_kontenliste() const;

    /// SETTER

    void add_konto(CKonto* konto);

    void delete_konto(CKonto* konto);

    void delete_all_kontos();


};


#endif //OOP_HAUSAUFGABE_CBANKKUNDE_H
