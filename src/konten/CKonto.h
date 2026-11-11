#ifndef OOP_HAUSAUFGABE_CKONTO_H
#define OOP_HAUSAUFGABE_CKONTO_H

#include <string>

using std::string;

class CBankkunde;

class CKonto {
    friend class CBankkunde;
private:
    unsigned long long kontonummer = 1000000000;
    double kontostand;

    inline static int laufende_nummer = 0;
    inline static int anzahl_konten = 0;

    CBankkunde* bankkunde = nullptr;

    /// nur für CBankkunde gedacht

    void set_bankkunde(CBankkunde* bankkunde);

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
    //CKonto (const CKonto &anderes) = delete;
    ~CKonto();


    /// DEBUG

    virtual void anzeigen() const;

    static void zeige_anzahl_konten();


    /// GETTER

    const double &get_kontostand() const {
        return kontostand;
    }

    const unsigned long long &get_kontonummer() const {
        return kontonummer;
    }

    /// FUNKTIONALITÄT

    virtual void einzahlen(const double &betrag);

    virtual double auszahlen(const double &betrag);


    CKonto operator=(const CKonto &anderes) = delete;

    friend void zeige_gesamtbetrag(const CKonto kontos[], const int &n);
};


#endif //OOP_HAUSAUFGABE_CKONTO_H
