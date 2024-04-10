#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(int x, int y, Swiat* swiat) : Roslina(x, y, swiat) {
	this->sila = SILA_WILCZE_JAGODY;
	this->type_id = wilcze_jagody;
	this->nazwa = "Wilcze Jagody";
	this->symbol = 'w';
	this->szansaNaRozsianie = SZANSA_ROZ_WILCZE_JAGODY;
}


char WilczeJagody::obrona(Organizm* org)
{
	return SMIERC;
}


WilczeJagody::~WilczeJagody()
{
}