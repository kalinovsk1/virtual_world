#include "Guarana.h"

Guarana::Guarana(int x, int y, Swiat* swiat) : Roslina(x, y, swiat) {
	this->type_id = guarana;
	this->nazwa = "Guarana";
	this->symbol = 'G';
	this->szansaNaRozsianie = SZANSA_ROZ_GUARANA;
}


char Guarana::obrona(Organizm* org)
{
	int s = org->GetSila();
	s += ZWIEKSZ_SILE;
	org->SetSila(s);
	string temp = ("[sila " + org->GetNazwa() + " zostaje zwiekszona]");
	swiat->dodajDoDziennika(temp);
	return NULL;
}


Guarana::~Guarana()
{
}