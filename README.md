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
    │ + CKonto (const double&)          │
    │ + ~CKonto                         │
    │                                   │
    │ + anzeigen                        │
    │ + zeige_anzahl_konten {static}    │
    │ + get_kontostand                  │
    │ + get_kontonummer                 │
    │ + einzahlen                       │
    │ + auszahlen                       │
    ├───────────────────────────────────┤
    │ + zeige_gesamtbetrag {friend}     │
    └───────────────────────────────────┘
        △
        │
        │
        │
    ┌────────────────────────────────────┐
    │           CSparbuch                │
    ├────────────────────────────────────┤
    │ - zinssatz                         │
    │ - bearbeitungsgebuehr {static}     │
    ├────────────────────────────────────┤
    │ + CSparbuch(const dbl&,const dbl&) │
    │                                    │
    │ + get_zinssatz                     │
    │ + get_bearbeitungsgebuehr          │
    │ + set_bearbeitungsgebuehr {static} │
    │ + verzinsen                        │
    │ + einzahlen                        │
    └────────────────────────────────────┘