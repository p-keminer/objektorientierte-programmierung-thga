#include "komplexe_zahlen/CComplex.h"

#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>


using std::string, std::stod;
using std::abs;
using std::numbers::pi, std::atan2, std::sin, std::cos;
using std::invalid_argument;
using std::vector;
using std::pair;



// Helfer

namespace {

    /**
     * @brief Ermittelt Vorzeichen für kartesische Eingabe.
     * @return führendes Minus vom Realteil und Trennzeichen oder Trennzeichen allein.
     * @throws std::invalid_argument Bei fehlenden, zusätzlichen oder falsch platzierten Vorzeichen.
     * Eingaben wie 5asd-4axzi sind erlaubt und werden später von std::stod verwaltet.
     */
    vector<char> finde_vorzeichen(const string &eingabe) {
        size_t index1 = eingabe.find_first_of("+-");
        size_t index2 = eingabe.find_last_of("+-");
        char vorzeichen1 = '\0';
        char vorzeichen2 = '\0';

        if (index1 != string::npos) vorzeichen1 = eingabe[index1];
        else throw invalid_argument("Keine Gueltige Eingabe - Gueltig: -5+5i, 5-5i oder -5-5i !");

        vector<char> vorzeichen;
        if (index2 != index1) {
            if (index1) throw invalid_argument("Operatoren an ungueltiger Position!");
            vorzeichen2 = eingabe[index2];
            if (vorzeichen1 == '+') throw invalid_argument("Kein + vor oder nach dem Realteil benoetigt!");
            if (eingabe.find_first_of("+-", index1+1) != index2) throw invalid_argument("Zu viele Operatoren eingegeben!");
            vorzeichen.push_back(vorzeichen1);
            vorzeichen.push_back(vorzeichen2);
            return vorzeichen;
        }
        vorzeichen.push_back(vorzeichen1);
        return vorzeichen;
    }
    /**
     * @brief Ermittelt aus zuvor ermittelten Vorzeichen das Trennzeichen.
     * @return zuvor validiertes Trenzzeichen.
     */
    const char validiere_trennzeichen(vector<char> vorzeichen) {
        return vorzeichen.size() > 1 ? *(vorzeichen.begin()+1) : *vorzeichen.begin();
    }

    /**
     * @brief trennt Eingaben (-5+7i oder 4-3i) an '+', '-' auf, separiert die Bestandteile Links und Rechts.
     * @return Bestandteile Links und Rechts vom Trennzeichen.
     */
    vector<string> split_string(string aufzuteilen, char trennzeichen) {
        vector<string> aufgeteilt;
        size_t index = aufzuteilen.rfind(trennzeichen);

        aufgeteilt.push_back(aufzuteilen.substr(0, index));
        aufgeteilt.push_back(aufzuteilen.substr(index + 1));
        return aufgeteilt;
    }

    /**
     * @brief wandelt zuvor aufgeteilte Strings in double um.
     * @return Realteil als Element 'first' und Imaginärteil als 'second'.
     * Beachtet bei Umwandlung nur das Vorzeichen vom Realteil.
     */
    pair<double, double> umwandeln(vector<string> aufgeteilt) {
        return {stod(*aufgeteilt.begin()),stod(aufgeteilt.back())};
    }

    /**
     * @brief Verwaltet vorherigen Funktionen, ermittelt das Vorzeichen vom Imaginärteil und gleicht diesen an.
     * @return Endgültige Werte für den String Konstruktor.
     * @throws std::invalid_argument Bei fehlenden, zusätzlichen oder falsch platzierten Vorzeichen.
     * Eingaben wie 5asd-4axzi sind erlaubt.
     */
    pair<double,double> string_zu_double(const string &eingabe) {
        auto vorzeichen = finde_vorzeichen(eingabe);
        char trennzeichen = validiere_trennzeichen(vorzeichen);
        auto umgewandelt = umwandeln(split_string(eingabe, trennzeichen));
        if (trennzeichen == '-') umgewandelt.second *= -1;
        return umgewandelt;
    }

}


// CComplex

void CComplex::aktualisiere_betrag_phase() {
    betrag = berechne_betrag();
    phase = berechne_phase();
}

void CComplex::aktualisiere_real_imaginaer() {
    real = betrag * cos(phase);
    imaginaer = betrag * sin(phase);
}



// String Konstruktor

CComplex::CComplex(const string& eingabe)
    :real(0), imaginaer(0), betrag(0), phase(0)
{
    auto werte = string_zu_double(eingabe);
    real = werte.first;
    imaginaer = werte.second;
    aktualisiere_betrag_phase();
}


// Normaler Konstruktor

CComplex::CComplex(double x, double y, bool kartesisch)
    :real(0), imaginaer(0), betrag(0), phase(0)
{
    if (kartesisch) {
        set_real(x);
        set_imaginaer(y);
    }
    else {
        set_betrag(x);
        set_phase(y);
    }

}

// Typumwandlungskonstruktor


CComplex::CComplex(double anderes)
        :real(anderes), imaginaer(0)
{
    aktualisiere_betrag_phase();
}


// Setter

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
    phase = std::remainder(wert, 2 * pi);
    aktualisiere_real_imaginaer();
}

string CComplex::get_imag_string() const {
    std::ostringstream stream;
    if (imaginaer >= 0) {
        stream << " + " << abs(imaginaer) << " i" ;
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

// Operatorüberladung

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




























