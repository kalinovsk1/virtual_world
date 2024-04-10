#include <iostream>
#include "Swiat.h"
#include "KreatorSwiata.h"

using namespace std;

int main() {
	int choice;
	cout << "Wybierz plansze: " << endl;
	cout << "1) tradycyjnie" << endl;
	cout << "2) z pliku" << endl;
	cin >> choice;
	KreatorSwiata* kreator = new KreatorSwiata();
	if (choice == 1) {
		Swiat* swiat = kreator->stworzSwiat(BASIC_BOARD_SIZE, BASIC_BOARD_SIZE);
		swiat->setKreator(kreator);
		swiat->DodajOrganizm(1, 3, wilk);
		swiat->DodajOrganizm(15, 2, wilk);
		swiat->DodajOrganizm(2, 5, owca);
		swiat->DodajOrganizm(10, 2, owca);
		swiat->DodajOrganizm(4, 8, lis);
		swiat->DodajOrganizm(1, 9, zolw);
		swiat->DodajOrganizm(3, 15, antylopa);
		swiat->DodajOrganizm(15, 15, czlowiek);
		swiat->DodajOrganizm(2, 11, trawa);
		swiat->DodajOrganizm(15, 19, mlecz);
		swiat->DodajOrganizm(0, 2, guarana);
		swiat->DodajOrganizm(17, 3, wilcze_jagody);
		swiat->DodajOrganizm(10, 10, barsz_sos);
		while (!swiat->CzySkonczony()) {
			swiat->zbierzDane();
		}
	}
	else if (choice == 2) {
		Swiat* swiat = kreator->stworzSwiat("zapis.txt");
		swiat->setKreator(kreator);
		while (!swiat->CzySkonczony()) {
			swiat->zbierzDane();
		}
	}
	return 0;
}