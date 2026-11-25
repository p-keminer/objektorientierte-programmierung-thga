//CKunde.h
#ifndef _KUNDE_
#define _KUNDE_
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
using namespace std;
struct DatumT
{
    unsigned short tag;
    unsigned short monat;
    unsigned short jahr;
};

static DatumT aktuellesDatum()
{
    DatumT d{};
    time_t t;
    tm* currentTime;
    time(&t);
    currentTime = localtime(&t);
    d.tag = currentTime->tm_mday;
    d.monat = currentTime->tm_mon+1;
    d.jahr = currentTime->tm_year+1900;
    return d;
}

static string datumTToString(DatumT datum)
{
    stringstream out;
    out << datum.tag<<"."<<datum.monat<<"."<<datum.jahr;
    return out.str();
}
static DatumT stringToDatumT(string date) {
    DatumT datum{};

    int currentYear=aktuellesDatum().jahr;
    int r;
    char sd[3],sm[3],sy[5],sdate[20];
    int y,m,d;
    r=sscanf(date.c_str(),"%2[^.].%2[^.].%4[^.]",sd,sm,sy);
    if(r==3)
    {
        d=atoi(sd);
        m=atoi(sm);
        y=atoi(sy);
        if(1<=d && d<=31 && 1<=m && m<=12 && 1900<=y && y<=currentYear)
        {
            datum.tag=d;
            datum.monat=m;
            datum.jahr=y;
        }
    }

    return datum;
}

class CKunde {
private:
	string name;
	string vorname;
	DatumT geburtsDatum;
public:
    /**
    Initialisierung eines CKunde-Objektes
    Parameter:
        n=Nachname
        gd=Geburtsdatum (Format: TT.MM.JJJJ)
        vn=Vorname
    */
	CKunde(string nn, string gt="1.1.1900", string vn = "" ){
	    name=nn;
	    vorname=vn;
	    geburtsDatum=stringToDatumT(gt);
    };
	string getName(){return name;}
	string getVorname(){return vorname;}
	int getAlter(){
	    short alter_j,alter_m,alter_t;
	    DatumT heute=aktuellesDatum();
	    alter_j = heute.jahr-geburtsDatum.jahr;

	    alter_m = heute.monat-geburtsDatum.monat;
	    alter_t = heute.tag-geburtsDatum.tag;
 	    if(alter_m<0)
            alter_j--;
        else if(alter_m==0 && alter_t<0)
            alter_j--;

        if(alter_j>=125)
            return -1;
        else
            return alter_j;
	}
	string toString(){
	    stringstream out;
		out << "Name        : " << name << endl;
		out << "Vorname     : " << vorname << endl;
		out << "Geburtsdatum: " << datumTToString(geburtsDatum) << endl;
		return out.str();
	};
};
#endif