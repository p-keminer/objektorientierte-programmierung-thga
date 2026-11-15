#include "CComplex.h"
#include <string>
#include <cmath>
#include <complex>
#include <iomanip>
#include <sstream>
#include <stdexcept>

using std::string;
using std::abs;
using std::numbers::pi, std::atan2, std::sin, std::cos;


void CComplex::aktualisiere_betrag_phase() {
    betrag = berechne_betrag();
    phase = berechne_phase();
}

void CComplex::aktualisiere_real_imaginaer() {
    real = betrag * cos(phase);
    imaginaer = betrag * sin(phase);
}

/* könnte beide aufgaben übernehmen

CComplex::CComplex(double x=0, double y=0, bool kartesissch=true)
:real(x), imaginaer(y)
{
aktualisiere_betrag_phase();
}

*/

/// Normaler Konstruktor

CComplex::CComplex(double x, double y, bool kartesisch)
    :real(0), imaginaer(0), betrag(0), phase(0)
{
    if (kartesisch) {
        set_real(x);
        set_imaginaer(y);
        aktualisiere_betrag_phase();
    }
    else {
        set_betrag(x);
        set_phase(y);
        aktualisiere_real_imaginaer();
    }

}

/// Typumwandlungskonstruktor


CComplex::CComplex(double anderes)
        :real(anderes), imaginaer(0)
{
    aktualisiere_betrag_phase();
}


/// Setter

void CComplex::set_real(double wert) {
    real = wert;
    aktualisiere_betrag_phase();
}

void CComplex::set_imaginaer(double wert) {
    imaginaer = wert;
    aktualisiere_betrag_phase();
}

void CComplex::set_betrag(double wert) {
    betrag = abs(wert);
    aktualisiere_real_imaginaer();
}

void CComplex::set_phase(double wert) {
    phase = wert;
    aktualisiere_real_imaginaer();
}

string CComplex::get_imag_string() const {
    std::ostringstream stream;
    if (imaginaer >= 0) {
        stream << " + " << imaginaer << " i" ;
    }
    else {
        stream << " - " << abs(imaginaer) << " i" ;
    }
    return stream.str();
}

string CComplex::toString(const bool kartesisch) const {

    std::ostringstream stream;
    if (kartesisch) {
        stream << real << get_imag_string();
    }
    else {
        stream << betrag << " e^(i " << phase / pi << " pi)";
    }

    return stream.str();
}

/// Operatorüberladung

CComplex operator+(const CComplex& links, const CComplex& rechts) {
    return {
        links.real + rechts.real,
        links.imaginaer + rechts.imaginaer
    };
}

CComplex &CComplex::operator+=(const CComplex &rechts) {
    *this = *this + rechts;
    return *this;
}

CComplex operator-(const CComplex &links, const CComplex &rechts) {
    return {
        links.real - rechts.real,
        links.imaginaer - rechts.imaginaer
    };
}

CComplex& CComplex::operator-=(const CComplex &rechts) {
    *this = *this - rechts;
    return *this;
}

CComplex operator*(const CComplex &links, const CComplex &rechts) {
    return {
        links.betrag * rechts.betrag,
        links.phase + rechts.phase,
        false
    };
}

CComplex& CComplex::operator*=(const CComplex &rechts) {
    *this = *this * rechts;
    return *this;
}

CComplex operator/(const CComplex &links, const CComplex &rechts) {
    if (!rechts.real && !rechts.imaginaer) throw std::invalid_argument("Division durch 0 nicht definiert!");
    return {
        links.betrag / rechts.betrag,
        links.phase - rechts.phase,
        false
    };
}

CComplex& CComplex::operator/=(const CComplex &rechts) {
    *this = *this / rechts;
    return *this;
}

bool operator==(const CComplex &links, const CComplex &rechts){
    return links.real == rechts.real && links.imaginaer == rechts.imaginaer;
}

bool operator<(const CComplex &links, const CComplex &rechts) {
    return links.betrag < rechts.betrag;
}

bool operator>(const CComplex &links, const CComplex &rechts) {
    return links.betrag > rechts.betrag;
}

CComplex CComplex::operator-() const {
    return {
        -real,
        -imaginaer
    };
}





























