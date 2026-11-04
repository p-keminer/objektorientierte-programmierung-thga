# UML-KLassendiagramm

---
    ┌───────────────────────────────────┐
    │           CKonto                  │
    ├───────────────────────────────────┤
    │ - kontonummer                     │
    │ - kontostand                      │
    │ - laufende_nummer {static}        │
    │ - anzahl_konten {static}          │
    ├───────────────────────────────────┤
    │ - init_kontostand                 │
    │                                   │
    │ # get_anzahl_konten               │
    │                                   │
    │ + CKonto (const double&=)         │
    │ + ~CKonto                         │
    │                                   │
    │ + anzeigen                        │
    │ + zeige_anzahl_konten {static}    │
    │ + get_kontostand                  │
    │ + get_kontonummer                 │
    │ + einzahlen                       │
    │ + auszahlen                       │
    ├───────────────────────────────────┤ ◁─────────────────┐
    │ + zeige_gesamtbetrag {friend}     │                   │
    └───────────────────────────────────┘                   │
        △                                                   │
        │                                                   │
        │                                                   │
        │                                                   │
    ┌──────────────────────────────────────┐          ┌──────────────────────────────────────┐  
    │           CSparbuch                  │          │           CGirokonto                 │
    ├──────────────────────────────────────┤          ├──────────────────────────────────────┤
    │ - zinssatz                           │          │ - kredit                             │
    │ - bearbeitungsgebuehr {static}       │          ├──────────────────────────────────────┤
    ├──────────────────────────────────────┤          │ + CGirokonto(const dbl&=,const dbl&=)│
    │ + CSparbuch(const dbl&=,const dbl&=) │          │                                      │
    │                                      │          │ + get_kredit                         │
    │ + get_zinssatz                       │          │ + set_kredit                         │
    │ + get_bearbeitungsgebuehr            │          │ + auszahlen                          │
    │ + set_bearbeitungsgebuehr {static}   │          └──────────────────────────────────────┘
    │ + verzinsen                          │
    │ + einzahlen                          │
    └──────────────────────────────────────┘