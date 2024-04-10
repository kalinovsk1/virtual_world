#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
    int ladowanie;
    bool niesmiertelny;
    int pozostalyCzasUmiejetnosci;
    int kod;
public:
    Czlowiek(int x, int y, Swiat* swiat);
    void uzyjUmiejetnosci();
    void akcja() override;
    void ustawKoordynaty(int* rx, int* ry);
    char obrona(Organizm *org) override;
    char atak(Organizm* org) override;
    void ruchSterowany(bool pustePole = false);
    void smierc() override;
    int GetLadowanie();
    void SetLadowanie(int ladowanie);
    void SetPozostalyCzas(int pozostalyCzasUmiejetnosci);
    int GetPozostalyCzas();
	~Czlowiek();
};