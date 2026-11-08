#ifndef OOP_HAUSAUFGABE_CKONTO_H
#define OOP_HAUSAUFGABE_CKONTO_H

#include <string>

using std::string;

class CBankkunde;

class CKonto {
private:
    unsigned long long kontonummer = 1000000000;
    double kontostand;

    inline static int laufende_nummer = 0;
    inline static int anzahl_konten = 0;

    CBankkunde* bankkunde = nullptr;

    /// INITIALISIERUNG

    void init_kontostand(const double &kontostand);

protected:

    const static int &get_anzahl_konten() {
        return anzahl_konten;
    }

    /// nur für girokonto gedacht

    void set_kontostand(const double &kontostand, const string &berechtigung="nein");

public:
    CKonto (const double &kontostand=0);
    ~CKonto();


    /// DEBUG

    void anzeigen() const;

    static void zeige_anzahl_konten();


    /// GETTER

    const double &get_kontostand() const {
        return kontostand;
    }

    const unsigned long long &get_kontonummer() const {
        return kontonummer;
    }

    /// SETTER

    void set_bankkunde(CBankkunde* bankkunde);

    /// FUNKTIONALITÄT

    void einzahlen(const double &betrag);

    double auszahlen(const double &betrag);


    friend void zeige_gesamtbetrag(const CKonto kontos[], const int &n);
};


#endif //OOP_HAUSAUFGABE_CKONTO_H
