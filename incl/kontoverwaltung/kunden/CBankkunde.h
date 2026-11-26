#ifndef OOP_HAUSAUFGABE_CBANKKUNDE_H
#define OOP_HAUSAUFGABE_CBANKKUNDE_H

#include <vector>

#include "kontoverwaltung/kunden/CKunde.h"

using std::vector;

class CKonto;

class CBankkunde : public CKunde {
private:
    vector<CKonto*> konten;
    short anzahl_konten = 0;        // wird nach aufgabenstellung gefordert

    static constexpr short ANZAHL_KONTEN = 5;
public:

    // INITIALISIERUNG

    CBankkunde(const string &nachname, const DatumT &geburtsdatum={1, 1, 1900}, const string &vorname="");
    ~CBankkunde();

    // GETTER

    const short &get_anzahl_konten() const {
        return anzahl_konten;
    }

    double get_gesamtsaldo() const;

    void get_kontenliste() const;

    /**
     * @brief Liefert das zugeordnete Konto anhand seiner Objektadresse.
     * @param kontonummer Zeiger auf das gesuchte Konto.
     * @pre Der Zeiger muss in der Kontenliste des Kunden enthalten sein.
     * @return Iterator auf gefundenes Konto sonst auf .end()!
     */
    CKonto &get_konto(CKonto* kontonummer);

    // SETTER

    /**
     * @brief Trägt vorhandenes Konto ein und setzt Rückzeiger zum Kunden.
     * @throws std::length_error Wenn schon fünf Konten zugeordnet sind.
     * @throws std::invalid_argument Bei einem Nullzeiger oder doppelten Eintrag.
     * @throws std::logic_error Wenn Konto bereits einem anderen Kunden zugeordnet ist.
     */
    void add_konto(CKonto* konto);

    /**
     * @brief Entfernt Konto aus der Liste und löst Rückbeziehung.
     * @throws std::length_error Wenn die Kontenliste leer ist.
     * @throws std::invalid_argument Bei einem Nullzeiger oder nicht zugeordnetem Konto.
     */
    void delete_konto(CKonto* konto);

    /**
     * @brief Löst alle Kontozuordnungen und Rückbeziehungen.
     * Die Lebensdauer der Kontoobjekte wird separat verwaltet.
     */
    void delete_all_kontos();


};


#endif //OOP_HAUSAUFGABE_CBANKKUNDE_H
