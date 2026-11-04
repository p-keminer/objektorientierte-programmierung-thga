#include <cassert>

#include "../src/CKonto.h"
#include "../src/CGirokonto.h"


struct girokontostruct{
    CGirokonto konto1, konto2, konto3, konto4, konto5;
};

girokontostruct test_konstruktor() {

    // initialisierung und erstellen

    girokontostruct konten{
        {200, 200},
        {400, -500},
        {},
        {-200, -500},
        {0, 500},

    };

    // negative Werte werden zu 0 validiert

    assert(konten.konto2.get_kredit() == 0);
    assert(konten.konto4.get_kontostand() == 0);
    assert(konten.konto4.get_kredit() == 0);


    return konten;
}

void test_auszahlen() {

    girokontostruct konten = test_konstruktor();

    // vollständige auszahlung funktioniert

    assert(konten.konto1.auszahlen(400) == 400);
    assert(konten.konto1.get_kontostand() == -200);

    // konto ohne kreditrahmen kann nicht überzogen werden

    assert(konten.konto2.auszahlen(500) == 0);
    assert(konten.konto2.get_kontostand() == 400);

    // aber bis zur belastungsgrenze ausgezahlt werden

    assert(konten.konto2.auszahlen(400) == 400);
    assert(konten.konto2.get_kontostand() == 0);

    // konto ohne kredit und 0 euro kontostand kann nichts auszahlen

    assert(konten.konto3.auszahlen(200) == 0);
    assert(konten.konto3.get_kontostand() == 0);

 // negative auszahungen funktionieren nicht
    assert(konten.konto3.auszahlen(-200) == 0);
    assert(konten.konto3.get_kontostand() == 0);

    // kontostand wächst vom negativen ins positive

    assert(konten.konto1.get_kontostand() == -200);
    konten.konto1.einzahlen(200);
    assert(konten.konto1.get_kontostand() == 0);
    konten.konto1.einzahlen(200);
    assert(konten.konto1.get_kontostand() == 200);

    // kontostand ohne guthaben aber kredit ist normal funktionsfähig

    assert(konten.konto5.auszahlen(500) == 500);
    assert(konten.konto5.get_kontostand() == -500);

    // weitere abhebungen funktionierne auch hier nicht

    assert(konten.konto5.auszahlen(1) == 0);
    assert(konten.konto5.get_kontostand() == -500);


}



int main() {

    test_konstruktor();
    test_auszahlen();


    return 0;
}