#include "Organizm.h"

Organizm::Organizm(int x, int y, Swiat* swiat) {
	this->x = x;
	this->y = y;
	this->swiat = swiat;
	this->wiek = 0;
}


POLE* Organizm::znajdzPoleObok(bool pole_puste)
{
	random_device device;
	mt19937 gen(device());
	POLE* tab[ILOSC_OPCJI_POL];
	int index = 0;
	POLE* temp;
	if (swiat->sprawdzCzyPoleIstnieje(x + 1, y)) {
		temp = swiat->getPole(x + 1, y);
		if (!(temp->org != NULL && pole_puste)) {
			tab[index] = temp;
			index++;
		}
	}
	if (swiat->sprawdzCzyPoleIstnieje(x, y + 1)) {
		temp = swiat->getPole(x, y + 1);
		if (!(temp->org != NULL && pole_puste)) {
			tab[index] = temp;
			index++;
		}
	}
	if (swiat->sprawdzCzyPoleIstnieje(x - 1, y)) {
		temp = swiat->getPole(x - 1, y);
		if (!(temp->org != NULL && pole_puste)) {
			tab[index] = temp;
			index++;
		}
	}
	if (swiat->sprawdzCzyPoleIstnieje(x, y - 1)) {
		temp = swiat->getPole(x, y - 1);
		if (!(temp->org != NULL && pole_puste)) {
			tab[index] = temp;
			index++;
		}
	}
	if (index == 0) {
		return NULL;
	}
	return tab[gen() % index];
}


void Organizm::rozmnazanie(){
	POLE* pole = znajdzPoleObok(true);
	if(pole!=NULL){
		swiat->DodajOrganizm(pole,type_id);
		string temp = ("[" + this->nazwa + " rozmnozyl sie]");
		swiat->dodajDoDziennika(temp);
	}
}


void Organizm::rysowanie()
{
	putchar(symbol);
}


char Organizm::atak(Organizm *org)
{
	return NULL;
}


char Organizm::obrona(Organizm *org)
{
	return NULL;
}


void Organizm::smierc()
{
	swiat->UsunOrganizm(this);
	string temp = ("[" + this->nazwa + " umiera]");
	swiat->dodajDoDziennika(temp);
}


int Organizm::GetId(){
	return this->type_id;
}


int Organizm::GetSila()
{
	return this->sila;
}


void Organizm::SetSila(int sila){
	this->sila = sila;
}


int Organizm::GetX()
{
	return this->x;
}


int Organizm::GetY()
{
	return this->y;
}


int Organizm::GetWiek()
{
	return this->wiek;
}


void Organizm::SetWiek(int wiek){
	this->wiek = wiek;
}


int Organizm::GetInicjatywa()
{
	return this->inicjatywa;
}


string Organizm::GetNazwa()
{
	return this->nazwa;
}


void Organizm::SetX(int x)
{
	this->x = x;
}


void Organizm::SetY(int y)
{
	this->y = y;
}


bool Organizm::jestZwierzeciem() {
	return false;
}


Organizm::~Organizm(){
}

