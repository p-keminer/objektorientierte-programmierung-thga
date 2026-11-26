#ifndef OOP_HAUSAUFGABE_CKUNDE_H
#define OOP_HAUSAUFGABE_CKUNDE_H

#include <string>

using std::string;

struct DatumT
{
	int tag;
	int monat;
	int jahr;
};

class CKunde {
private:
	string nachname;
	string vorname;
	DatumT geburtsdatum;
	short alter;

	// INITIALISIERUNG & AKTUALISIERUNG

	/**
	 * @brief Prüft Kalendertag und Schaltjahr. Gültige Datumswerte sind von 1900 bis heute.
	 */
	bool validiere_geburtsdatum(DatumT datum);

	/**
	 * @brief Berechnet volle Lebensjahre und berücksichtigt, ob Geburtstag dieses Jahr schon war.
	 */
	void berechne_alter();

public:
	CKunde(const string &nachname,const DatumT &geburtsdatum = {1, 1, 1900}, const string &vorname="");

	// DEBUG

	string anzeigen() const;


	// GETTER

	const string& get_name() const {
		return nachname;
	}

	const string& get_vorname() const {
		return vorname;
	}

	/**
	 * @brief Berechnet Alter mit aktuellem Datum neu und liefert den gespeicherten Wert.
	 */
	const short& get_alter();


};

#endif //OOP_HAUSAUFGABE_CKUNDE_H
