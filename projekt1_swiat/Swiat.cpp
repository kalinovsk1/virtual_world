#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Roslina.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "Czlowiek.h"

Swiat::Swiat(int szer, int wys){
	this->dziennik = "";
	this->autor = "Robert Kalinowski";
	this->koniec = false;
	this->klawisz = NULL;
	this->szer = szer;
	this->wys = wys;
	this->kreator = NULL;
	this->plansza = new POLE*[szer];
	for (int i = 0; i < szer; i++) {
		plansza[i] = new POLE[wys];
		for(int j = 0; j < wys; j++){
			plansza[i][j].org = NULL;
			plansza[i][j].x = i;
			plansza[i][j].y = j;
		}
	}
}


POLE** Swiat::getPlansza()
{
	return plansza;
}


POLE* Swiat::getPole(int x, int y)
{
	return &plansza[x][y];
}


Organizm* Swiat::stworzNowyOrganizm(int type_id, int x, int y)
{
	Organizm* temp = NULL;
	switch (type_id) {
	case wilk:
		temp = new Wilk(x,y,this);
		break;
	case owca:
		temp = new Owca(x, y, this);
		break;
	case lis:
		temp = new Lis(x, y, this);
		break;
	case zolw:
		temp = new Zolw(x, y, this);
		break;
	case antylopa:
		temp = new Antylopa(x, y, this);
		break;
	case czlowiek:
		temp = new Czlowiek(x, y, this);
		break;
	case trawa:
		temp = new Trawa(x, y, this);
		break;
	case mlecz:
		temp = new Mlecz(x, y, this);
		break;
	case guarana:
		temp = new Guarana(x, y, this);
		break;
	case wilcze_jagody:
		temp = new WilczeJagody(x, y, this);
		break;
	case barsz_sos:
		temp = new BarszczSosnowskiego(x, y, this);
		break;
	}
	return temp;
}


void Swiat::DodajOrganizm(int x, int y, int type_id){
	Organizm* o = stworzNowyOrganizm(type_id,x,y);
	plansza[x][y].org = o;
	noweOrganizmy.push_back(o);
}


void Swiat::DodajOrganizm(POLE* pole, int type_id){
	int x = pole->x;
	int y = pole->y;
	Organizm* o = stworzNowyOrganizm(type_id,x,y);
	pole->org = o;
	noweOrganizmy.push_back(o);
}


void Swiat::DodajOrganizm(Organizm* o, int x, int y){
	noweOrganizmy.push_back(o);
	plansza[x][y].org = o;
}


void Swiat::UsunOrganizm(Organizm* org){
	for (int i = 0; i < this->organizmy.size(); i++) {
		if (organizmy[i] == org) {
			organizmy.erase(organizmy.begin() + i);
		}
	}
	getPole(org->GetX(), org->GetY())->org= NULL;
}


void Swiat::PrzemiescOrganizm(Organizm* org, int x, int y){
	getPole(org->GetX(), org->GetY())->org = NULL;
	plansza[x][y].org = org;
	org->SetX(x);
	org->SetY(y);
}


void Swiat::czyscPole(int x, int y)
{
	plansza[x][y].org = NULL;
}


bool Swiat::sprawdzCzyPoleIstnieje(int x, int y)
{
	if (x >= 0 && x < szer && y >= 0 && y < wys) {
		return true;
	}
	else
		return false;
}


void Swiat::wykonajTure(){
	czyscDziennik();
	
	sort(organizmy.begin(), organizmy.end(), []( Organizm* a, Organizm* b){
		if(a->GetInicjatywa() == b->GetInicjatywa()){
			return(a->GetWiek()<b->GetWiek());
		}else{
			return(a->GetInicjatywa() < b->GetInicjatywa());
		}
	});
	
	for (int i = 0; i < organizmy.size(); i++) {
		organizmy[i]->akcja();
	}

	for(int i = 0; i < noweOrganizmy.size(); i++){
		organizmy.push_back(noweOrganizmy[i]);
	}
	noweOrganizmy.clear();
}

void Swiat::rysujSwiat(){
	system("cls");
	for (int i = 0; i < autor.size(); i++) {
		cout << "*";
	}
	cout << endl;
	cout << autor << endl;
	for (int i = 0; i < autor.size(); i++) {
		cout << "*";
	}
	cout << endl;
	for (int i = 0; i < szer; i++) {
		cout << '+';
	}
	cout << endl;
	for (int i = 0; i < szer; i++) {
		for (int j = 0; j < wys; j++) {
			if (plansza[i][j].org != NULL) {
				plansza[i][j].org->rysowanie();
			}
			else {
				cout<<".";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < szer; i++) {
		cout << '+';
	}
	cout << endl;
	cout << endl;
	cout << "Dziennik wydarzen:" << endl;
	cout << dziennik << endl;
}


bool Swiat::porownywaczOrganizmow(Organizm& a, Organizm& b)
{
	if(a.GetSila() != b.GetSila()){
		return a.GetSila() < b.GetSila();
	}
	else{
		return a.GetWiek() <= b.GetWiek();
	}
}


void Swiat::czyscDziennik()
{
	dziennik.clear();
}


void Swiat::dodajDoDziennika(string wpis)
{
	dziennik += (wpis+"\n");
}


void Swiat::zbierzDane(){
	int code = 0;
	klawisz = NULL;
	while (code != ENTER && code != S && code!=DOL && code!=LEWO&&code!=PRAWO&&code!=GORA&&code!=SPACJA && code != Q){
		if (_kbhit()) {
			code = _getch();

			switch (code) {
			case ENTER:
				wykonajTure();
				rysujSwiat();
				break;
			case S:
				zapisz();
				break;
			case Q:
				koniec = true;
			default:
				if (code == DOL || code == LEWO || code == PRAWO || code == GORA || code == SPACJA) {
					klawisz = code;
					wykonajTure();
					rysujSwiat();
					break;
				}
			}
		}
	}
}


bool Swiat::CzySkonczony()
{
	return this->koniec;
}


int Swiat::GetKlawisz()
{
	return this->klawisz;
}


int Swiat::GetSzer()
{
	return this->szer;
}


int Swiat::GetWys()
{
	return this->wys;
}


void Swiat::setKreator(KreatorSwiata* k){
	kreator = k;
}


void Swiat::zapisz()
{
	if(kreator!=NULL){
		kreator->stworzPlik(this, "zapis.txt");
	}
}


vector<Organizm*>* Swiat::getOrganizmy(){
	return &organizmy;
}


Swiat::~Swiat()
{
}