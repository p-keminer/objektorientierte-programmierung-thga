#include <cassert>
#include <cmath>
#include <numbers>
#include <stdexcept>

#include "komplexe_zahlen/CComplex.h"

void test_konstruktor() {
    const CComplex kartesisch(3, 4);
    assert(kartesisch.get_real() == 3);
    assert(kartesisch.get_imaginaer() == 4);
    assert(kartesisch.get_betrag() == 5);

    // Betrag 2 und Winkel pi/2 = 0 + 2i

    const CComplex polar(2, pi / 2, false);
    assert(std::abs(polar.get_real(12)) < 1e-9);
    assert(std::abs(polar.get_imaginaer(12) - 2) < 1e-9);
}

void test_string_konstruktor() {
    const CComplex plus_plus("5+2i");
    const CComplex plus_minus("5-2i");
    const CComplex minus_plus("-5+2i");
    const CComplex minus_minus("-5-2i");

    assert(plus_plus.get_real() == 5 && plus_plus.get_imaginaer() == 2);
    assert(plus_minus.get_real() == 5 && plus_minus.get_imaginaer() == -2);
    assert(minus_plus.get_real() == -5 && minus_plus.get_imaginaer() == 2);
    assert(minus_minus.get_real() == -5 && minus_minus.get_imaginaer() == -2);

    const CComplex negativer_nullanteil("5-0i");
    assert(negativer_nullanteil.toString() == "5 + 0 i");
}

void test_ungueltiges_trennzeichen() {
    bool exc = false;
    try {
        const CComplex zahl("5+-2i");
    }
    catch (const std::invalid_argument&) {
        exc = true;
    }
    assert(exc);
}

void test_grundrechenarten() {
    const CComplex zahl1(1, 1), zahl2(1, -1);

    const CComplex summe = zahl1 + zahl2;
    assert(summe.get_real() == 2 && summe.get_imaginaer() == 0);

    const CComplex differenz = zahl1 - zahl2;
    assert(differenz.get_real() == 0 && differenz.get_imaginaer() == 2);

    // Bei Umrechnung aus Polarform können Rundungsfehler entstehen

    const CComplex produkt = zahl1 * zahl1;
    assert(std::abs(produkt.get_real(12)) < 1e-9);
    assert(std::abs(produkt.get_imaginaer(12) - 2) < 1e-9);

    // (21 + 28i) / 7i = 4 - 3i

    const CComplex quotient = CComplex(21, 28) / CComplex(0, 7);
    assert(std::abs(quotient.get_real(12) - 4) < 1e-9);
    assert(std::abs(quotient.get_imaginaer(12) + 3) < 1e-9);
}

void test_division_durch_null() {
    const CComplex zahl(3, 4), null(0, 0);

    bool exc = false;
    try {
        static_cast<void>(zahl / null);
    }
    catch (const std::invalid_argument&) {
        exc = true;
    }
    assert(exc);
}

int main() {
    test_konstruktor();
    test_string_konstruktor();
    test_ungueltiges_trennzeichen();
    test_grundrechenarten();
    test_division_durch_null();

    return 0;
}
