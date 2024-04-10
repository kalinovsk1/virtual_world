#include "Czlowiek.h"

Czlowiek::Czlowiek(int x, int y, Swiat* swiat): Zwierze(x,y,swiat){
    this->sila=SILA_CZLOWIEK;
    this->inicjatywa = INICJATYWA_CZLOWIEK;
    this->type_id = czlowiek;
    this->nazwa = "Czlowiek";
    this->symbol = 'C';
    this->ladowanie = 0;
    this->niesmiertelny = false;
    this->pozostalyCzasUmiejetnosci = 0;
    this->kod = 0;
}


void Czlowiek::uzyjUmiejetnosci()
{
    if (ladowanie <= 0) {
        niesmiertelny = true;
        ladowanie = CZAS_LADOWANIA_UMIEJ;
        pozostalyCzasUmiejetnosci = CZAS_TRWANIA_UMIEJ;
    }

}


char Czlowiek::atak(Organizm* org)
{
    if(niesmiertelny){
        if (org->GetSila() > sila) {
            POLE* pole = znajdzPoleObok(true);
            if (pole != NULL) {
                return UCIECZKA;
            }
            else { 
                return ZOSTAN; 
            }
        }
    }
    else {
        return NULL;
    }
}


void Czlowiek::smierc(){
    if(!niesmiertelny){
        swiat->UsunOrganizm(this);
        string temp = ("[" + this->nazwa + " umiera" + "]");
        swiat->dodajDoDziennika(temp);
    }
    else{
        POLE* pole = znajdzPoleObok(true);
        if(pole != NULL){
            przemiesc(pole->x, pole->y);
            string temp = "[" + this->nazwa + " unika smierci]";
            swiat->dodajDoDziennika(temp);
        }
    }
}


int Czlowiek::GetLadowanie()
{
    return this->ladowanie;
}


int Czlowiek::GetPozostalyCzas()
{
    return this->pozostalyCzasUmiejetnosci;
}


void Czlowiek::SetLadowanie(int ladowanie){
    this->ladowanie = ladowanie;
}


void Czlowiek::SetPozostalyCzas(int pozostalyCzasUmiejetnosci){
    this->pozostalyCzasUmiejetnosci = pozostalyCzasUmiejetnosci;
}


void Czlowiek::akcja()
{
    wiek++;
    if(ladowanie>0){
        ladowanie--;
    }
    if(pozostalyCzasUmiejetnosci>0){
        pozostalyCzasUmiejetnosci--;
    }
    if(pozostalyCzasUmiejetnosci==0){
        niesmiertelny = false;
    }

    kod = swiat->GetKlawisz();
    if (kod == GORA || kod == DOL || kod == PRAWO || kod == LEWO) {
        ruchSterowany();
    }
    if(kod==SPACJA){
        uzyjUmiejetnosci();
    }
}


void Czlowiek::ustawKoordynaty(int* rx, int* ry){  
    switch (kod) {
    case GORA:
        *rx = x-1;
        *ry = y;
        break;
    case DOL:
        *rx = x+1;
        *ry = y;
        break;
    case LEWO:
        *rx = x;
        *ry = y - 1;
        break;
    case PRAWO:
        *rx = x;
        *ry = y+1;
        break;
    default:
        break;
    }
}


void Czlowiek::ruchSterowany(bool pustePole)
{
    int nx;
    int ny;
    ustawKoordynaty(&nx,&ny);
    if (swiat->sprawdzCzyPoleIstnieje(nx, ny)) {
        POLE* pole = swiat->getPole(nx, ny);
        if(pole!=NULL){
            if(pole->org==NULL){
                swiat->czyscPole(x,y);
                pole->org = this;
                x = pole->x;
                y = pole->y;
            }
            else{
                kolizja(pole->org);
            }
        }
    }
}


char Czlowiek::obrona(Organizm* org)
{
    if(niesmiertelny){
        if(org->GetSila()>=sila){
            POLE* pole = znajdzPoleObok(true);
            if(pole!=NULL){
                przemiesc(pole->x, pole->y);
            }
            else{
                return ZOSTAN;
            }
        }
        else{
            return NULL;
        }
    }
    else{
        return NULL;
    }
}


Czlowiek::~Czlowiek()
{
}
