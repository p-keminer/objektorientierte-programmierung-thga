#include "CGirokonto.h"

CGirokonto::CGirokonto(const double &kontostand, const double &kreditrahmen)
    : CKonto(kontostand)
{
    set_kredit(kreditrahmen);
}

void CGirokonto::set_kredit(const double &kreditrahmen ) {
    kredit = kreditrahmen > 0 ? kreditrahmen : 0;
}

double CGirokonto::auszahlen(const double &betrag) {
    double auszahlungsbetrag = (betrag > 0 ? betrag : 0);
    auszahlungsbetrag = (auszahlungsbetrag <= get_kontostand() + kredit ?
                         auszahlungsbetrag : 0);
    set_kontostand(get_kontostand() - auszahlungsbetrag, "OK");
    return auszahlungsbetrag;
}



