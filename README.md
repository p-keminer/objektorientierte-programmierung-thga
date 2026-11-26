<a name="top"></a>

<div align="center">

# Objektorientierte Programmierung

---

Dieses Repository dient den Hausaufgaben und der Klausurvorbereitung für das Modul
Objektorientierte Programmierung. 



### **Studentisches Lernprojekt - Keine offizielle Hochschulvorlage, oder Musterlösung!**


[![Einstieg](https://img.shields.io/badge/Einstieg-24292f?style=for-the-badge)](#einstieg)
[![Struktur](https://img.shields.io/badge/Struktur-24292f?style=for-the-badge)](#struktur)
[![UML-Klassendiagramm](https://img.shields.io/badge/UML_Klassendiagramm-24292f?style=for-the-badge)](#uml)



---
**Stand: 26.11.2026** - In Bearbeitung

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

## UML-Klassendiagramm Komplexe Zahlen

---

```mermaid
classDiagram
    direction LR

    class CComplexReader {
        -vector~CComplex~ komplexe_zahlen
        +get_komplexe_zahlen() vector~CComplex~&
        +constant_reader(istream& stream) void
        +finde_minmax() Iteratorpaar
        +finde_kleinstes_element() Iterator
        +finde_groesstes_element() Iterator
        +finde_komplexe_zahl(const CComplex& zahl) Iterator
        +finde_komplexe_zahl(double real, double imaginaer) Iterator
        +finde_komplexe_zahl(const string& zahl) Iterator
        +sortiere_vektor(bool aufsteigend) void
        +verschiebe_komplexe_zahlen() vector~CComplex~
    }

    class CComplex {
        -double real
        -double imaginaer
        -double betrag
        -double phase
        -standardisiere(double zahl, short nachkommastellen) double
        -get_imag_string() string
        -berechne_betrag() double
        -berechne_phase() double
        -aktualisiere_betrag_phase() void
        -aktualisiere_real_imaginaer() void
        +CComplex(const string& eingabe)
        +CComplex(double x, double y, bool kartesisch)
        +CComplex(double anderes)
        +get_real(short nachkommastellen) double
        +get_imaginaer(short nachkommastellen) double
        +get_betrag(short nachkommastellen) double
        +get_phase(short nachkommastellen) double
        +gradmaß(double bogenmaß) double
        +bogenmaß(double gradmaß) double
        +set_real(double wert) void
        +set_imaginaer(double wert) void
        +set_betrag(double wert) void
        +set_phase(double wert) void
        +toString(bool kartesisch) string
        +operator+=(const CComplex& rechts) CComplex&
        +operator-=(const CComplex& rechts) CComplex&
        +operator*=(const CComplex& rechts) CComplex&
        +operator/=(const CComplex& rechts) CComplex&
        +operator-() CComplex
    }

    CComplexReader "0..1" *-- "0..*" CComplex : speichert

    note for CComplex "Freie friend-Funktionen<br/>Binäre Rechenoperatoren, Vergleiche und Stream-Ausgabe"
```

---

## UML-Klassendiagramm Kontoverwaltung

---

```mermaid
classDiagram
    direction TB

    class CKunde {
        -string nachname
        -string vorname
        -DatumT geburtsdatum
        -short alter
        -validiere_geburtsdatum(DatumT datum) bool
        -berechne_alter() void
        +CKunde(string nachname, DatumT geburtsdatum, string vorname)
        +anzeigen() string
        +get_name() const string&
        +get_vorname() const string&
        +get_alter() const short&
    }

    class CBankkunde {
        -vector~CKonto*~ konten
        -short anzahl_konten
        -short ANZAHL_KONTEN = 5$
        +CBankkunde(string nachname, DatumT geburtsdatum, string vorname)
        +~CBankkunde()
        +get_anzahl_konten() const short&
        +get_gesamtsaldo() double
        +get_kontenliste() void
        +get_konto(CKonto* konto) CKonto&
        +add_konto(CKonto* konto) void
        +delete_konto(CKonto* konto) void
        +delete_all_kontos() void
    }

    class CKonto {
        -unsigned long long kontonummer
        -double kontostand
        -int laufende_nummer$
        -int anzahl_konten$
        -init_kontostand(double kontostand) void
        -set_bankkunde(CBankkunde* bankkunde) void
        #get_anzahl_konten() const int&$
        #set_kontostand(double kontostand, string berechtigung) void
        +CKonto(double kontostand)
        +~CKonto()
        +anzeigen() void
        +zeige_anzahl_konten() void$
        +get_kontostand() const double&
        +get_kontonummer() const unsigned long long&
        +einzahlen(double betrag) void
        +auszahlen(double betrag) double
    }

    class CSparbuch {
        -double zinssatz
        -double bearbeitungsgebuehr$
        +CSparbuch(double kontostand, double zinssatz)
        +get_zinssatz() const double&
        +get_bearbeitungsgebuehr() const double&$
        +set_bearbeitungsgebuehr(double gebuehr) void$
        +verzinsen() void
        +einzahlen(double betrag) void
        +anzeigen() void
    }

    class CGirokonto {
        -double kredit
        +CGirokonto(double kontostand, double kreditrahmen)
        +get_kredit() const double&
        +set_kredit(double kreditrahmen) void
        +auszahlen(double betrag) double
        +anzeigen() void
    }

    CKunde <|-- CBankkunde
    CKonto <|-- CSparbuch
    CKonto <|-- CGirokonto
    CBankkunde "0..1" -- "0..5" CKonto : verwaltet

    note for CKonto "Virtuell: anzeigen(), einzahlen(), auszahlen()<br/>Freie friend-Funktion: zeige_gesamtbetrag()"
```


<div align="center">

[![GitHub](https://img.shields.io/badge/GitHub-24292f?style=for-the-badge)](https://github.com/p-keminer/objektorientierte-programmierung-thga)
[![GitLab](https://img.shields.io/badge/GitLab-24292f?style=for-the-badge)](https://gitlab.thga.de/philip.keminer/OOP)
[![⬆_Nach_oben](https://img.shields.io/badge/⬆_Nach_Oben-24292f?style=for-the-badge)](#top)

</div>
