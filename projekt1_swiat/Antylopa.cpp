#include "Antylopa.h"

Antylopa::Antylopa(int x, int y, Swiat* swiat) :Zwierze(x, y, swiat) {
    sila = SILA_ANTYLOPA;
    inicjatywa = INICJATYWA_ANTYLOPA;
    type_id = antylopa;
    nazwa = "Antylopa";
    symbol = 'A';
}


void Antylopa::akcja(){
    wiek++;
    ruch(true);
    ruch();
}


char Antylopa::atak(Organizm* org){
    random_device device;
    mt19937 gen(device());
    if (gen() % 2 == 0) {
        POLE* p = znajdzPoleObok(true);
        if(p != NULL){
            string temp = ("[" + this->nazwa + " ucieka" + "]");
            swiat->dodajDoDziennika(temp);
            przemiesc(p->x, p->y);
            return PRZEMIESC;
        }
        else{
            return NULL;
        }
    }
    else {
        return NULL;
    }

}


char Antylopa::obrona(Organizm* org)
{
    random_device device;
    mt19937 gen(device());
    if(gen() % 2== 0){
        POLE* p = znajdzPoleObok(true);
        if(p != NULL){
            string temp = ("[" + this->nazwa + " ucieka" + "]");
            swiat->dodajDoDziennika(temp);
            przemiesc(p->x, p->y);
            return PRZEMIESC;
        }
        else{
            return NULL;
        }
    }
    else{
        return NULL;
    }
   
}


Antylopa::~Antylopa() {
}