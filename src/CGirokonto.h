#ifndef OOP_HAUSAUFGABE_CGIROKONTO_H
#define OOP_HAUSAUFGABE_CGIROKONTO_H

#include "..\src\CKonto.h"


class CGirokonto : public CKonto {
private:
    double kredit;

public:
    CGirokonto(const double &kontostand=0, const double &kreditrahmen=0);

    /// GETTER

    double get_kredit() const {
        return kredit;
    }

    /// SETTER

    void set_kredit(const double &kreditrahmen);

    /// FUNKTIONALITÄT

    double auszahlen(const double &betrag);




};


#endif //OOP_HAUSAUFGABE_CGIROKONTO_H
