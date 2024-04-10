#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
protected:
    int szansaNaRozsianie;
public:
    Roslina(int x, int y, Swiat *swiat);
    void akcja() override;
    void kolizja(Organizm* org) override;
    void smierc() override;
    void probojSieRozmnazac();
    ~Roslina();
};