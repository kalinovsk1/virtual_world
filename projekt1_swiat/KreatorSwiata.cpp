#include "KreatorSwiata.h"
#include "Czlowiek.h"

KreatorSwiata::KreatorSwiata()
{
}


void KreatorSwiata::stworzPlik(Swiat* swiat, string nazwa)
{ 
    ofstream plik;
    plik.open(nazwa);
    
    plik << 1 << endl;
    plik << swiat->GetSzer() << " " << swiat->GetWys() << endl;

    vector<Organizm*>* organizmy = swiat->getOrganizmy();
    for (int i = 0; i < organizmy->size();i++) {
        Organizm* org = (*organizmy)[i];
        plik << org->GetId() << " " << org->GetX() << " " << org->GetY() << " " << org->GetWiek() << " " << org->GetSila();
        if(org->GetId() == czlowiek){
            Czlowiek* cz = (Czlowiek*)org;
            plik << " " << cz->GetLadowanie() << " " << cz->GetPozostalyCzas();
        }
        plik << endl;
    }
    plik.close();
}


Swiat* KreatorSwiata::stworzSwiat(int szer, int wys)
{
    Swiat* swiat = new Swiat(szer,wys);
    return swiat;
}


Swiat* KreatorSwiata::stworzSwiat(string nazwaPliku)
{
    ifstream plik;
    plik.open(nazwaPliku);
    int szer, wys; 
    Swiat* swiat = NULL;
    /*tryb = 1 - wczytywanie pliku z dodatkowymi wartosciami zmienionymi
      tryb = 0 - wczytywanie pliku z podstawowymi wartosciami*/
    bool tryb;
    int id, x, y, s, w, l, c;
    if (plik.is_open()) {
        plik >> tryb;
        plik >> szer >> wys;
        swiat = new Swiat(szer, wys);
		while (plik.good()) {
            plik >> id >> x >> y;
            Organizm* org = swiat->stworzNowyOrganizm(id,x,y);
            if(tryb){
                plik >> s >> w;
                org->SetSila(s);
                org->SetWiek(w);
                if(id==czlowiek){
                    plik >> l >> c;
                    Czlowiek* cz = (Czlowiek*)org;
                    cz->SetLadowanie(l);
                    cz->SetLadowanie(c);
                }
            }
            swiat->DodajOrganizm(org, x,y);
        }
    }
    plik.close();
    return swiat;
}


void KreatorSwiata::usunSwiat(Swiat* swiat)
{
}


KreatorSwiata::~KreatorSwiata()
{
}