#pragma once
#include "Roslina.h"

class Guarana : public Roslina {
public:
	Guarana(int x, int y, Swiat* swiat);
	char obrona(Organizm* org) override;
	~Guarana();
};