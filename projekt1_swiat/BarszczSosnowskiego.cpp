#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, Swiat* swiat) : Roslina(x, y, swiat) {
	this->sila = SILA_BARSZCZ;
	this->type_id = barsz_sos;
	this->nazwa = "Barszcz Sosnowskiego";
	this->symbol = 'B';
	this->szansaNaRozsianie = SZANSA_ROZ_BARSZCZ;
}


void BarszczSosnowskiego::UsunOtoczenie(){
	Organizm* org;
	if (swiat->sprawdzCzyPoleIstnieje(this->x + 1, this->y)) {
		org = swiat->getPole(this->x + 1, this->y)->org;
		if (org != NULL) {
			if(org->jestZwierzeciem()){
				org->smierc();
			}
		}
	}
	if (swiat->sprawdzCzyPoleIstnieje(this->x - 1, this->y)) {
		org = swiat->getPole(this->x - 1, this->y)->org;
		if (org != NULL) {
			if (org->jestZwierzeciem()) {
				org->smierc();
			}
		}
	}
	if (swiat->sprawdzCzyPoleIstnieje(this->x, this->y + 1)) {
		org = swiat->getPole(this->x, this->y + 1)->org;
		if (org != NULL) {
			if (org->jestZwierzeciem()) {
				org->smierc();
			}
		}
	}
	if (swiat->sprawdzCzyPoleIstnieje(this->x, this->y - 1)) {
		org = swiat->getPole(this->x, this->y - 1)->org;
		if (org != NULL) {
			if (org->jestZwierzeciem()) {
				org->smierc();
			}
		}
	}
}


void BarszczSosnowskiego::akcja(){
	wiek++;
	UsunOtoczenie();
	probojSieRozmnazac();
}


char BarszczSosnowskiego::obrona(Organizm* org){
	smierc();
	return SMIERC;
}


BarszczSosnowskiego::~BarszczSosnowskiego()
{
}