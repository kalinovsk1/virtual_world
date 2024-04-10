#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
public:
    Zwierze(int x, int y, Swiat *swiat);
    void akcja() override;
    virtual void ruch(bool pustePole=false);
    void kolizja(Organizm *org) override;
    void przemiesc(int x, int y);
    void rozpatrzEfekt(char kod, int x, int y);
    bool jestZwierzeciem() override;
    void ZwiekszSile();
    ~Zwierze();
};