#include "Mlecz.h"

Mlecz::Mlecz(int x, int y, Swiat* swiat) : Roslina(x, y, swiat) {
	this->type_id = mlecz;
	this->nazwa = "Mlecz";
	this->symbol = 'M';
	this->szansaNaRozsianie = SZANSA_ROZ_MLECZ;
}


void Mlecz::akcja()
{
	wiek++;
	probojSieRozmnazac();
	probojSieRozmnazac();
	probojSieRozmnazac();
}


Mlecz::~Mlecz()
{
}