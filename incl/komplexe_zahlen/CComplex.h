#ifndef OOP_HAUSAUFGABE_CCOMPLEX_H
#define OOP_HAUSAUFGABE_CCOMPLEX_H

#include <string>
#include <cmath>
#include <iostream>
#include <vector>


using std::string;
using std::hypot, std::pow, std::numbers::pi;
using std::ostream;
using std::vector;



class CComplex {
private:
    double real;
    double imaginaer;

    double betrag;
    double phase;

    double standardisiere(const double zahl,const short nachkommastellen) const {
        return round(zahl * pow(10, nachkommastellen)) / pow(10, nachkommastellen);
    }

    string get_imag_string() const;


    double berechne_betrag() const {
        return hypot(real, imaginaer);
    }

    double berechne_phase() const {
        return atan2(imaginaer, real);
    }

    void aktualisiere_betrag_phase();

    void aktualisiere_real_imaginaer();



public:
    explicit CComplex(const string& eingabe);

    CComplex(double x, double y, bool kartesisch=true);

    CComplex(double anderes);


    double get_real(const short nachkommastellen=6) const {
        return standardisiere(real, nachkommastellen);
    }

    double get_imaginaer(const short nachkommastellen=6) const {
        return standardisiere(imaginaer, nachkommastellen);
    }

    double get_betrag(const short nachkommastellen=6) const {
        return standardisiere(betrag, nachkommastellen);
    }

    double get_phase(const short nachkommastellen=6) const {
        return standardisiere(phase, nachkommastellen);
    }

    double gradmaß(double bogenmaß) const {
        return bogenmaß * 180 / pi;
    }

    double bogenmaß(double gradmaß) const {
        return gradmaß * pi / 180;
    }

    void set_real(double wert);

    void set_imaginaer(double wert);

    void set_betrag(double wert);

    void set_phase(double wert);

    string toString(bool kartesisch=true) const;


    /// Operatorüberladungen

    friend CComplex operator+(const CComplex& links,const CComplex& rechts);

    CComplex& operator+=(const CComplex& rechts);

    friend CComplex operator-(const CComplex &links, const CComplex &rechts);

    CComplex& operator-=(const CComplex &rechts);

    friend CComplex operator*(const CComplex &links, const CComplex &rechts);

    CComplex& operator*=(const CComplex &rechts);

    friend CComplex operator/(const CComplex &links, const CComplex &rechts);

    CComplex& operator/=(const CComplex &rechts);

    friend ostream& operator<<(ostream& ostream, const CComplex &zahl) {
        return ostream << zahl.real << zahl.get_imag_string();
    }

    friend bool operator==(const CComplex &links, const CComplex &rechts);

    friend bool operator<(const CComplex &links, const CComplex &rechts);
    friend bool operator>(const CComplex &links, const CComplex &rechts);

    CComplex operator-() const;

};


namespace CComplex_reader {
    vector<CComplex> constant_reader();
}






#endif //OOP_HAUSAUFGABE_CCOMPLEX_H
