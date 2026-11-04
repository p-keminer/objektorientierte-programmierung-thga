#ifndef OOP_HAUSAUFGABE_CSPARBUCH_H
#define OOP_HAUSAUFGABE_CSPARBUCH_H

#include "CKonto.h"

class CSparbuch : public CKonto {
private:
    double zinssatz;
    inline static double bearbeitungsgebuehr = 1;

public:
    CSparbuch(const double &kontostand, const double &zinssatz = 3.3);


    /// GETTER

    double get_zinssatz() const {
        return zinssatz;
    }

    double get_bearbeitungsgebuehr() const {
        return bearbeitungsgebuehr;
    }

    /// SETTER

    static void set_bearbeitungsgebuehr(const double &gebuehr);


    /// FUNKTIONALITÄT

    void verzinsen();

    void einzahlen(const double &betrag);



};


#endif //OOP_HAUSAUFGABE_CSPARBUCH_H
