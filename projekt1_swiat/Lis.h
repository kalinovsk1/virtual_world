#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
public:
	char atak(Organizm* org) override;
	Lis(int x, int y, Swiat* swiat);
	~Lis();
};