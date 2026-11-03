
#ifndef OOP_HAUSAUFGABE_CKONTO_H
#define OOP_HAUSAUFGABE_CKONTO_H


class CKonto {
private:
    unsigned long long kontonummer;
    double kontostand;

    inline static int laufende_nummer = 0;

    /// INITIALISIERUNG

    void init_kontostand(const double &kontostand);

    void init_kontonummer();

protected:

    int get_laufende_nummer() const {
        return laufende_nummer;
    }

public:
    CKonto (const double &kontostand=0);
    ~CKonto();

    /// DEBUG

    void anzeigen() const;

    void zeige_anzahl_konten();

    /// GETTER


    double get_kontostand() const {
        return kontostand;
    }

    long long get_kontonummer() const {
        return kontonummer;
    }


    void einzahlen(const double &betrag);

    void auszahlen(const double &betrag);

    friend void berechne_gesamtbetrag(const std::vector<CKonto> kontos, const int &n);
};


#endif //OOP_HAUSAUFGABE_CKONTO_H
