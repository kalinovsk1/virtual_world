#include "Trawa.h"

Trawa::Trawa(int x, int y, Swiat* swiat): Roslina(x,y,swiat){
	this->type_id = trawa;
	this->nazwa = "Trawa";
	this->symbol = 'T';
	this->szansaNaRozsianie = SZANSA_ROZ_TRAWA;
}


Trawa::~Trawa()
{
}
