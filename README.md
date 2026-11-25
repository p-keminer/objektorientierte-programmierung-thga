<a name="top"></a>

<div align="center">

# OOP

---

Dieses Repository dient den Hausaufgaben und der Klausurvorbereitung für das Modul
Objektorientierte Programmierung. 



### **Studentisches Lernprojekt - Keine offizielle Hochschulvorlage, oder Musterlösung!**


[![Einstieg](https://img.shields.io/badge/Einstieg-24292f?style=for-the-badge)](#einstieg)
[![Struktur](https://img.shields.io/badge/Struktur-24292f?style=for-the-badge)](#struktur)
[![UML-Klassendiagramm](https://img.shields.io/badge/UML_Klassendiagramm-24292f?style=for-the-badge)](#uml)



---
**Stand: 25.11.2026** - In Bearbeitung

</div>

---

<a name="einstieg"></a>

## Einstieg

---

### Voraussetzungen

---
| Werkzeug | Anforderung | Lokales Setup unter Windows                  |
| --- | --- |----------------------------------------------|
| C++-Compiler | Unterstützung für `C++20` | MinGW-w64 mit GCC 13.1.0 aus Qt-Installation |
| CMake | Version `4.2` oder neuer | CMake 4.3.1 aus `CLion`                      |
| Ninja | Build mit `-G Ninja` | Ninja 1.13.2 aus `CLion`                     |
| CTest | Ausführen der automatisierten Tests | In `CMake` enthalten                         |


>Qt liefert in diesem Setup den MinGW-Compiler.
>Das Projekt verwendet bisher keine Qt-Bibliotheken und baut auch mit
>einem anderen C++20-fähigen Compiler.

---

### Bauen und Testen

```shell
 # CMake, CTest und MinGW in PowerShell verfügbar machen
 $env:Path = "$env:LOCALAPPDATA\Programs\CLion\bin\cmake\win\x64\bin;C:\Qt\Tools\mingw1310_64\bin;$env:Path"

 # Hauptprogramme und Testprogramme kompilieren
 cmake --build cmake-build-debug

 # Alle registrierten Tests ausführen
 ctest --test-dir cmake-build-debug --output-on-failure --no-tests=error

 # Hauptprogramme starten
 $env:Path = "$env:LOCALAPPDATA\Programs\CLion\bin\cmake\win\x64\bin;C:\Qt\Tools\mingw1310_64\bin;$env:Path"
 cmake --build cmake-build-debug --target run_all

 # Isolierte Tests durchführen (CBankkunde)
 ctest --test-dir cmake-build-debug -R '^CBankkunde$' --output-on-failure

```

---

<a name="struktur"></a>

## Struktur

---

```text
OOP/
├── src/
│   ├── kontoverwaltung/
│   │   ├── konten/
│   │   │   ├── CGirokonto.cpp
│   │   │   ├── CKonto.cpp
│   │   │   └── CSparbuch.cpp
│   │   ├── kunden/
│   │   │   ├── CBankkunde.cpp
│   │   │   └── CKunde.cpp
│   │   └── main_kontoverwaltung.cpp
│   ├── komplexe_zahlen/
│   │   ├── CComplex.cpp
│   │   ├── CComplexReader.cpp
│   │   └── main_CComplex.cpp
│   └── funktionstemplates/
│       └── main_funktionstemplates.cpp
├── incl/
│   ├── kontoverwaltung/
│   │   ├── konten/
│   │   │   ├── CGirokonto.h
│   │   │   ├── CKonto.h
│   │   │   └── CSparbuch.h
│   │   └── kunden/
│   │       ├── originale/
│   │       │   └── CKunde.h
│   │       ├── CBankkunde.h
│   │       └── CKunde.h
│   ├── komplexe_zahlen/
│   │   ├── CComplex.h
│   │   └── CComplexReader.h
│   └── funktionstemplates/
│       └── main_funktionstemplates.h
├── tests/
│   ├── komplexe_zahlen/
│   │   ├── test_CComplex.cpp
│   │   └── test_CComplexReader.cpp
│   └── kontoverwaltung/
│       ├── test_CBankkunde.cpp
│       ├── test_CGirokonto.cpp
│       ├── test_CKonto.cpp
│       ├── test_CKunde.cpp
│       └── test_CSparbuch.cpp
├── .gitignore
├── .gitlab-ci.yml
├── CMakeLists.txt
└── README.md
```

---

<a name="uml"></a>

## UML-Klassendiagramm Kontoverwaltung

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
