#pragma once
#include "Roslina.h"

class WilczeJagody : public Roslina {
public:
	WilczeJagody(int x, int y, Swiat* swiat);
	char obrona(Organizm* org) override;
	~WilczeJagody();
};
