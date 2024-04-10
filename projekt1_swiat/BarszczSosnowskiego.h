#pragma once
#include "Roslina.h"

class BarszczSosnowskiego : public Roslina {
public:
	BarszczSosnowskiego(int x, int y, Swiat* swiat);
	void UsunOtoczenie();
	void akcja() override;
	char obrona(Organizm *org) override;
	~BarszczSosnowskiego();
};

