#ifndef OOP_HAUSAUFGABE_CSPARBUCH_H
#define OOP_HAUSAUFGABE_CSPARBUCH_H

#pragma once

#include "CKonto.h"

class CSparbuch : public CKonto {
private:
    double zinssatz;
    inline static double bearbeitungsgebuehr = 1;

public:
    CSparbuch(const double &kontostand, const double &zinssatz = 3.3);


    /// GETTER

    const double &get_zinssatz() const {
        return zinssatz;
    }

    const static double &get_bearbeitungsgebuehr() {
        return bearbeitungsgebuehr;
    }

    /// SETTER

    static void set_bearbeitungsgebuehr(const double &gebuehr);


    /// FUNKTIONALITÄT

    void verzinsen();

    void einzahlen(const double &betrag);



};


#endif //OOP_HAUSAUFGABE_CSPARBUCH_H
