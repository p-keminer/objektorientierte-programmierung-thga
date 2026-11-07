#ifndef OOP_HAUSAUFGABE_CKUNDE_H
#define OOP_HAUSAUFGABE_CKUNDE_H

#pragma once

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

	/// INITIALISIERUNG & AKTUALISIERUNG

	bool validiere_geburtsdatum(DatumT datum);

	void berechne_alter();

public:
	CKunde(const string &nachname,const DatumT &geburtsdatum = {1, 1, 1900}, const string &vorname="");

	/// DEBUG

	string anzeigen() const;


	/// GETTER

	const string& get_name() const {
		return nachname;
	}

	const string& get_vorname() const {
		return vorname;
	}

	const short &get_alter();


};

#endif //OOP_HAUSAUFGABE_CKUNDE_H
