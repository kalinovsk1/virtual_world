#include "Roslina.h"

Roslina::Roslina(int x, int y, Swiat* swiat): Organizm(x,y,swiat){
    this->inicjatywa = INICJATYWA_ANTYLOPA;
    this->szansaNaRozsianie = 0;
    this->sila = 0;
}


void Roslina::probojSieRozmnazac(){
    random_device device;
	mt19937 gen(device());
    if(gen()%100<szansaNaRozsianie){
        rozmnazanie();
    }
} 


void Roslina::akcja(){
	wiek++;
    probojSieRozmnazac();
}


void Roslina::kolizja(Organizm* org){
    return;
}


void Roslina::smierc(){
    swiat->UsunOrganizm(this);
    string temp = ("[" + this->nazwa + " zostaje zjedzone]");
    swiat->dodajDoDziennika(temp);
}


Roslina::~Roslina()
{
}
