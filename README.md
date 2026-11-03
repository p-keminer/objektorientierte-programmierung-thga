# UML-KLassendiagramm

---
    +-----------------------------------+
    |           CKonto                  |
    +-----------------------------------+
    | - kontonummer                     |
    | - kontostand                      |
    | - laufende_nummer {static}        |
    +-----------------------------------+
    | - init_kontonummer                |
    | - init_kontostand                 |
    |                                   |
    | # get_laufende_nummer             |
    |                                   |
    | + CKonto (double&)                |
    | + ~CKonto                         |
    |                                   |
    | + anzeigen                        |
    | + zeige_anzahl_konten {static}    |
    | + get_kontostand                  |
    | + get_kontonummer                 |
    | + einzahlen                       |
    | + auszahlen                       |
    +-----------------------------------+