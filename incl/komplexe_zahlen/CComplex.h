#ifndef OOP_HAUSAUFGABE_CCOMPLEX_H
#define OOP_HAUSAUFGABE_CCOMPLEX_H

#include <cmath>
#include <numbers>
#include <ostream>
#include <string>


using std::string;
using std::hypot, std::pow, std::numbers::pi;
using std::ostream;


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
    /**
     * @brief Erzeugt komplexe Zahl aus kartesischer Schreibweise.
     * @param eingabe Real und Imaginärteil zum Beispiel `-5+2i`.
     * @throws std::invalid_argument Bei ungültigen Vorzeichen oder nicht lesbaren Zahlenteilen.
     * @throws std::out_of_range Wenn Zahlen außerhalb des Wertebereichs von double liegen.
     */
    explicit CComplex(const string& eingabe);

    /**
     * @brief Erstellt eine komplexe Zahl aus kartesischen oder polaren Koordinaten.
     * @param x Realteil bei kartesischer Eingabe, sonst Betrag.
     * @param y Imaginärteil bei kartesischer Eingabe, sonst Winkel im Bogenmaß.
     * @param kartesisch Wählt bei true kartesische Koordinaten, bei false Polarkoordinaten.
     */
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

    /**
     * @brief Übernimmt den Absolutwert. Berechnet bei gleicher Phase die Komponenten neu.
     */
    void set_betrag(double wert);

    /**
     * @brief Reduziert endlichen Winkel im Bogenmaß auf [-pi, pi]. Aktualisiert die Komponenten.
     */
    void set_phase(double wert);

    string toString(bool kartesisch=true) const;


    // Operatorüberladungen

    friend CComplex operator+(const CComplex& links,const CComplex& rechts);

    CComplex& operator+=(const CComplex& rechts);

    friend CComplex operator-(const CComplex &links, const CComplex &rechts);

    CComplex& operator-=(const CComplex &rechts);

    /**
     * @brief Multipliziert Beträge und addiert Phasen.
     */
    friend CComplex operator*(const CComplex &links, const CComplex &rechts);

    CComplex& operator*=(const CComplex &rechts);

    /**
     * @brief Dividiert Beträge und subtrahiert Phasen.
     * @throws std::invalid_argument Wenn Real und Imaginärteil des Nenners null sind (0+0i).
     */
    friend CComplex operator/(const CComplex &links, const CComplex &rechts);

    CComplex& operator/=(const CComplex &rechts);

    friend ostream& operator<<(ostream& ostream, const CComplex &zahl) {
        return ostream << zahl.real << zahl.get_imag_string();
    }

    /**
     * @brief Vergleicht Real und Imaginärteil exakt, ohne Toleranz für Rundungsfehler.
     */
    friend bool operator==(const CComplex &links, const CComplex &rechts);

    /**
     * @brief Vergleicht komplexe Zahlen anhand des Betrags.
     */
    friend bool operator<(const CComplex &links, const CComplex &rechts);

    /**
     * @brief Vergleicht komplexe Zahlen anhand des Betrags.
     */
    friend bool operator>(const CComplex &links, const CComplex &rechts);

    CComplex operator-() const;

};










#endif //OOP_HAUSAUFGABE_CCOMPLEX_H
