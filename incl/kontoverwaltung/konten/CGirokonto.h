#ifndef OOP_HAUSAUFGABE_CGIROKONTO_H
#define OOP_HAUSAUFGABE_CGIROKONTO_H


#include "kontoverwaltung/konten/CKonto.h"


class CGirokonto : public CKonto {
private:
    double kredit;

public:
    CGirokonto(const double &kontostand=0, const double &kreditrahmen=0);

    // GETTER

    const double &get_kredit() const {
        return kredit;
    }

    // SETTER

    void set_kredit(const double &kreditrahmen);

    // FUNKTIONALITÄT

    /**
     * @brief Zahlt positiven Betrag bis zur Grenze aus Guthaben und Kreditrahmen aus.
     * @return Ausgezahlter Betrag.
     * Auszahlungen werden zu Null validiert, wenn diese abgelehnt werden.
     */
    double auszahlen(const double &betrag) override;

    void anzeigen() const override;


};


#endif //OOP_HAUSAUFGABE_CGIROKONTO_H
