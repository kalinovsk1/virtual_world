#include "Zwierze.h"

Zwierze::Zwierze(int x, int y, Swiat *swiat): Organizm(x,y,swiat){
}


void Zwierze::akcja(){
   wiek++;
   ruch();
}


void Zwierze::ruch(bool pustePole)
{
    POLE* pole = znajdzPoleObok(pustePole);
    if(pole!=NULL){
        if(pole->org==NULL){
            swiat->czyscPole(x,y);
            pole->org = this;
            x = pole->x;
            y = pole->y;
        }else{
            kolizja(pole->org);
        }
    }
}


void Zwierze::kolizja(Organizm* cel){
    if (cel->GetId() == this->type_id) {
        rozmnazanie();
    }
    else {
        int x = cel->GetX();
        int y = cel->GetY();
        char umiej_efekt = atak(cel);
        if (umiej_efekt == NULL) {
            umiej_efekt = cel->obrona(this);
        }
        if(umiej_efekt == NULL){
            if (this->sila > cel->GetSila()) {
                string temp = ("[" + this->nazwa + " zabija " + cel->GetNazwa() + "]");
                swiat->dodajDoDziennika(temp);
                cel->smierc();
                przemiesc(x, y);
            }
            else {
                string temp = ("[" + cel->GetNazwa() + " zabija " + this->nazwa + "]");
                swiat->dodajDoDziennika(temp);
                this->smierc();
            }
        }
        else{
             rozpatrzEfekt(umiej_efekt, x, y);
        }
    }
}


void Zwierze::rozpatrzEfekt(char kod, int x, int y) {
    POLE * p = znajdzPoleObok(true);
    switch (kod) {
    case NULL:
        break;
    case UCIECZKA:
        przemiesc(p->x, p->y);
        break;
    case SMIERC:
        smierc();
        break;
    case ZOSTAN:
        break;
    case PRZEMIESC:
        przemiesc(x, y);
        break;
    }
}


bool Zwierze::jestZwierzeciem(){
    return true;
}


void Zwierze::przemiesc(int x, int y){
    swiat->PrzemiescOrganizm(this, x, y);
}


Zwierze::~Zwierze()
{
}