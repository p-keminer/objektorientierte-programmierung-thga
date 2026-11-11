<a name="top"></a>

<div align="center">

# OOP

---

Dieses Repository dient den Hausaufgaben und der Klausurvorbereitung für das Modul
Objektorientierte Programmierung. 



### **Studentisches Lernprojekt - Keine offizielle Hochschulvorlage, oder Musterlösung!**



[![Checkliste](https://img.shields.io/badge/Checkliste-24292f?style=for-the-badge)](#checkliste)
[![Struktur](https://img.shields.io/badge/Struktur-24292f?style=for-the-badge)](#struktur)
[![UML-Klassendiagramm](https://img.shields.io/badge/UML_Klassendiagramm-24292f?style=for-the-badge)](#uml)



---
**Stand: 11.11.2026** - In Bearbeitung

</div>

---

<a name="checkliste"></a>

## Checkliste

---



```text
- [x] Von C nach C++
    - [x] Referenzen
    - [x] Streams und Namespaces 
- [x] Objekte und Klassen
    - [x] HA 2.2
    - [x] HA 2.3
        - [x] Konstruktoren und Destruktoren
       (- [x] Cassert und Tests)
        - [x] Modularisierung auf Dateiebene
       (- [x] Einstieg CMakeLists)
        - [x] UML-Klassendiagramm
- [x] Klassen und Objektbeziehungen
    - [x] HA 3.1
        - [x] Public Vererbung
        - [x] Redefinierung und statische Methoden
       (- [x] Automatisierte Tests)
       (- [x] Exceptions)
    - [x] HA 3.2
       (- [x] Analyse und Überarbeitung vorgegebenen Codes)
        - [x] Assoziationen
           (- [x] STL (std::vector))
        - [x] UML-Darstellung (Objektbeziehungen)
- [x] Polymorphismus
    - [x] HA 4.1
- [ ] Sonstiges
    - [ ] HA 5.1
        - [ ] Operatorüberladung
    - [ ] HA 5.3/5.4
        - [ ] Templates
        - [ ] STL
        
- [ ] isolierte eigenständige Übungsaufgaben
    - [ ] Virtuelle Methoden und Destruktoren
        - [ ] Dynamisch Verwalteter Speicher
        - [ ] Basisklassenzeiger
        - [ ] Kopiekonstruktoren
    - [ ] STL und Iteratoren
 ```
---

<a name="struktur"></a>

## Struktur

---

```text
OOP/
├── src/
│   ├── konten/
│   │   ├── CGirokonto.cpp
│   │   ├── CGirokonto.h
│   │   ├── CKonto.cpp
│   │   ├── CKonto.h
│   │   ├── CSparbuch.cpp
│   │   └── CSparbuch.h
│   ├── kunden/
│   │   ├── originale/
│   │   │   └── CKunde.h
│   │   ├── CBankkunde.cpp
│   │   ├── CBankkunde.h
│   │   ├── CKunde.cpp
│   │   └── CKunde.h
│   └── main.cpp
├── tests/
│   ├── test_CGirokonto.cpp
│   ├── test_CKonto.cpp
│   ├── test_CKunde.cpp
│   ├── test_CSparbuch.cpp
│   └── test_CBankkunde.cpp
├── .gitignore
├── .gitlab-ci.yml
├── CMakeLists.txt
└── README.md
```
---

<a name="uml"></a>

## UML-Klassendiagramm

---

```text

    ┌───────────────────────────────────┐                    ┌────────────────────────────────────────┐
    │           CKunde                  │                    │           CBankkunde                   │
    ├───────────────────────────────────┤                    ├────────────────────────────────────────┤
    │ - nachname                        │                    │ - konten                               │
    │ - vorname                         │                    │ - anzahl_konten                        │
    │ - geburtsdatum                    │                    │ - ANZAHL_KONTEN=5 {static cexpr}       │
    │ - alter                           │                    ├────────────────────────────────────────┤
    ├───────────────────────────────────┤                    │ + CBankkunde(const str&, const dtmT&=, │
    │ - validiere_geburtsdatum          │                    │              const str&=)              │
    │ - berechne_alter                  │                    │ + ~CBankkunde                          │
    │                                   │                    │ + get_anzahl_konten                    │
    │ + CKunde(const str&,const dtmT&=, │◁───────────────────│ + get_gesamtsaldo                      │
    │           const str&=)            │                    │ + get_kontenliste                      │
    │ + anzeigen                        │                    │ + add_konto                            │
    │ + get_name                        │                    │ + delete_konto                         │
    │ + get_vorname                     │                    │ + delete_all_kontos                    │
    │ + get_alter                       │                    │ + get_konto                            │
    └───────────────────────────────────┘                    └────────────────────────────────────────┘         
                                                                       0..1
                                                                        │
                                                                        │
    ┌───────────────────────────────────┐                               │
    │           CKonto                  │                               │
    ├───────────────────────────────────┤0..5───────────────────────────┘
    │ - kontonummer                     │
    │ - kontostand                      │
    │ - laufende_nummer {static}        │
    │ - anzahl_konten {static}          │
    ├───────────────────────────────────┤
    │ - init_kontostand                 │
    │ - set_bankkunde                   │
    │                                   │
    │ # get_anzahl_konten {static}      │
    │ # set_kontostand                  │
    │                                   │
    │ + CKonto (const double&=)         │
    │ + ~CKonto                         │
    │                                   │
    │ + anzeigen {virtual}              │
    │ + zeige_anzahl_konten {static}    │
    │ + get_kontostand                  │
    │ + get_kontonummer                 │
    │ + einzahlen {virtual}             │
    │ + auszahlen {virtual}             │
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
    │ + CSparbuch(const dbl&,const dbl&=)  │          │                                      │
    │                                      │          │ + get_kredit                         │
    │ + get_zinssatz                       │          │ + set_kredit                         │
    │ + get_bearbeitungsgebuehr {static}   │          │ + auszahlen {override}               │
    │ + set_bearbeitungsgebuehr {static}   │          │ + einzahlen {override}               │
    │ + verzinsen                          │          │ + anzeigen {override}                │
    │ + einzahlen {override}               │          └──────────────────────────────────────┘
    │ + auszahlen {override}               │
    │ + anzeigen {override}                │
    └──────────────────────────────────────┘
    
```


<div align="center">

[![⬆_Nach_oben](https://img.shields.io/badge/⬆_Nach_Oben-24292f?style=for-the-badge)](#top)

</div>