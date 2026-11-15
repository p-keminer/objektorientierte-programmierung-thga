#include "CComplex/CComplex.h"

#include <iostream>

using std::cout, std::endl;

int main() {

    CComplex zahl1(5,5), zahl2(zahl1);
    cout << zahl1.get_betrag() << "\n"
         << zahl1.get_phase() << "\n"
         << zahl1.get_real() << "\n"
         << zahl1.get_imaginaer() << "\n"
         << zahl1.toString() << "\n"
         << zahl1.toString(0) << "\n"
         << zahl1
         << endl;


    zahl1 *= 2 + zahl2 -= 4;

    cout << "Zahl1 - Kartesich: "
         << zahl1 << endl;;
    cout << "Zahl1 - Exponentialform: "
         << zahl1.toString(0) << endl;

    cout << "Zahl2 unveraendert: " << zahl2 << endl;

    cout << "Unaerer operator-: " << -zahl2 << endl;






    return 0;
}