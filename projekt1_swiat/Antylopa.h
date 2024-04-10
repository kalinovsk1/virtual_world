#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
	Antylopa(int x, int y, Swiat* swiat);
	void akcja() override;
	char atak(Organizm* org) override;
	char obrona(Organizm* org) override;
	~Antylopa();
};