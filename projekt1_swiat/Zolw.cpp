#include "Zolw.h"

Zolw::Zolw(int x, int y, Swiat* swiat) :Zwierze(x, y, swiat) {
    sila = SILA_ZOLW;
    inicjatywa = INICJATYWA_ZOLW;
    type_id = zolw;
    nazwa = "Zolw";
    symbol = 'Z';
}


void Zolw::akcja(){
    wiek++;
    random_device device;
    mt19937 gen(device());
    if (gen() % 4 == 0) {
        ruch();
    }
}


char Zolw::obrona(Organizm* org){
    if (org->GetSila() < OPOR_ZOLW) {
        return ZOSTAN;
    }
    else {
        return NULL;
    }
}


Zolw::~Zolw() {
}