#include <cassert>

#include "kontoverwaltung/konten/CKonto.h"
#include "kontoverwaltung/konten/CSparbuch.h"

struct sparbuchstruct{
    CSparbuch konto1, konto2, konto3, konto4;
};


sparbuchstruct test_konstruktor() {

    //initialiserung

    sparbuchstruct konten{
        {200},
        {400},
        {0},
        {-200}
        };

    //konstruktor setzt zinssatz auf 3,3

    assert(konten.konto1.get_zinssatz() == 3.3 &&
           konten.konto2.get_zinssatz() == 3.3 &&
           konten.konto3.get_zinssatz() == 3.3 &&
           konten.konto4.get_zinssatz() == 3.3
        );

    return konten;
}

void test_get_set_bearbeitungsgebuehr() {

    sparbuchstruct konten = test_konstruktor();

    // bearbeitungsbeuehr ist anfänglich 1

    assert(konten.konto1.get_bearbeitungsgebuehr() == 1 &&
           konten.konto2.get_bearbeitungsgebuehr() == 1 &&
           konten.konto3.get_bearbeitungsgebuehr() == 1 &&
           konten.konto4.get_bearbeitungsgebuehr() == 1
        );

    CSparbuch::set_bearbeitungsgebuehr(4);

    // static funktion setzt die bearbeitungsbeuehr globald auf 4

    assert(konten.konto1.get_bearbeitungsgebuehr() == 4 &&
           konten.konto2.get_bearbeitungsgebuehr() == 4 &&
           konten.konto3.get_bearbeitungsgebuehr() == 4 &&
           konten.konto4.get_bearbeitungsgebuehr() == 4
        );

}

void test_verzinsen() {

    sparbuchstruct konten = test_konstruktor();

    konten.konto1.verzinsen();
    konten.konto2.verzinsen();
    konten.konto3.verzinsen();

    // verzinsen rechnet korrekt

    assert(konten.konto1.get_kontostand() == 206.6);
    assert(konten.konto2.get_kontostand() == 413.2);
    assert(konten.konto3.get_kontostand() == 0);

}

void test_CSparbuch_einzahlen() {

    sparbuchstruct konten = test_konstruktor();

    // bearbeitungsbeguehr wird abgezogen

    konten.konto1.einzahlen(200);

    assert(konten.konto1.get_kontostand() == 396);

    // negative werte werden nicht akzeptiert und es wird
    // keine bearbeitungsbeühr abgezogen

    konten.konto2.einzahlen(-200);
    assert(konten.konto2.get_kontostand() == 400);


}



int main() {

    test_konstruktor();
    test_get_set_bearbeitungsgebuehr();
    test_verzinsen();
    test_CSparbuch_einzahlen();

    return 0;

}
