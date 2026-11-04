
#ifndef OOP_HAUSAUFGABE_CKONTO_H
#define OOP_HAUSAUFGABE_CKONTO_H


class CKonto {
private:
    unsigned long long kontonummer = 1000000000;
    double kontostand;

    inline static int laufende_nummer = 0;
    inline static int anzahl_konten = 0;

    /// INITIALISIERUNG

    void init_kontostand(const double &kontostand);

protected:

    int get_anzahl_konten() const {
        return anzahl_konten;
    }

public:
    CKonto (const double &kontostand=0);
    ~CKonto();

    /// DEBUG

    void anzeigen() const;

    static void zeige_anzahl_konten();

    /// GETTER


    double get_kontostand() const {
        return kontostand;
    }

    unsigned long long get_kontonummer() const {
        return kontonummer;
    }

    /// SETTER



    /// FUNKTIONALITÄT

    void einzahlen(const double &betrag);

    void auszahlen(const double &betrag);



    friend void zeige_gesamtbetrag(const CKonto kontos[], const int &n);
};


#endif //OOP_HAUSAUFGABE_CKONTO_H
