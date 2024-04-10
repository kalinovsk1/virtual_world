#pragma once
#include "Swiat.h"
#include "defines.cpp"
#include <string>
#include <random>

using namespace std;

class Swiat;
struct POLE;

class Organizm {
protected:
	string nazwa;
	int sila, inicjatywa, type_id, wiek, x, y;
	Swiat* swiat;
	char symbol;
public:
	Organizm(int x, int y, Swiat *swiat);
	virtual void akcja() = 0;
	POLE* znajdzPoleObok(bool pole_puste=false);
	void rozmnazanie();
	virtual void kolizja(Organizm* org) = 0;
	void rysowanie();
	virtual char atak(Organizm *org);
	virtual char obrona(Organizm* org);
	virtual void smierc();
	int GetId();
	int GetSila();
	void SetSila(int sila);
	int GetX();
	int GetY();
	int GetWiek();
	void SetWiek(int wiek);
	int GetInicjatywa();
	string GetNazwa();
	void SetX(int x);
	void SetY(int y);
	virtual bool jestZwierzeciem();
	virtual ~Organizm();
};