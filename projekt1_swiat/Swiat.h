#pragma once
#include "Organizm.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <conio.h>
#include "defines.cpp"
#include "KreatorSwiata.h"

using namespace std;

class KreatorSwiata;
class Organizm;


struct POLE {
	int x, y;
	Organizm* org;
};


class Swiat {
private:
	vector<Organizm*> organizmy;
	vector<Organizm*> noweOrganizmy;
	KreatorSwiata* kreator;
	string dziennik;
	string autor;
	POLE** plansza;
	int szer, wys;
	bool koniec;
	int klawisz;
public:
	Swiat(int szer, int wys);
	POLE** getPlansza();
	POLE* getPole(int x, int y);
	Organizm* stworzNowyOrganizm(int type_id, int x, int y);
	vector<Organizm*>* getOrganizmy();
	void DodajOrganizm(int x, int y, int type_id);
	void DodajOrganizm(POLE* pole, int type_id);
	void DodajOrganizm(Organizm* org, int x, int y);
	void UsunOrganizm(Organizm* org);
	void PrzemiescOrganizm(Organizm* org, int x, int y);
	void czyscPole(int x, int y);
	bool sprawdzCzyPoleIstnieje(int x, int y);
	void wykonajTure();
	void rysujSwiat();
	bool porownywaczOrganizmow(Organizm& a, Organizm& b);
	void czyscDziennik();
	void dodajDoDziennika(string wpis);
	void zbierzDane();
	bool CzySkonczony();
	int GetKlawisz();
	int GetSzer();
	int GetWys();
	void setKreator(KreatorSwiata* k);
	void zapisz();
	~Swiat();
}; 

