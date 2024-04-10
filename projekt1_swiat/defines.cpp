#pragma once

enum typ_stworzenia {
	wilk,
	owca,
	lis,
	zolw,
	antylopa,
	czlowiek,
	trawa,
	mlecz,
	guarana,
	wilcze_jagody,
	barsz_sos
};

enum collision_codes {
	UCIECZKA = 'E',
	SMIERC = 'D',
	ZOSTAN = 'S',
	PRZEMIESC = 'M',
};

#define BASIC_BOARD_SIZE 20
#define ILOSC_OPCJI_POL 4

#define SILA_ANTYLOPA 4
#define INICJATYWA_ANTYLOPA 4

#define SILA_LIS 3
#define INICJATYWA_LIS 7

#define SILA_OWCA 4
#define INICJATYWA_OWCA 4

#define SILA_WILK 9
#define INICJATYWA_WILK 5

#define SILA_ZOLW 2
#define INICJATYWA_ZOLW 1
#define OPOR_ZOLW 5

#define SILA_CZLOWIEK 5
#define INICJATYWA_CZLOWIEK 4
#define CZAS_TRWANIA_UMIEJ 5
#define CZAS_LADOWANIA_UMIEJ 10

#define INICJATYWA_ROSLIN 0

#define SILA_BARSZCZ 10
#define SZANSA_ROZ_BARSZCZ 10

#define SZANSA_ROZ_GUARANA 8
#define ZWIEKSZ_SILE 3

#define SZANSA_ROZ_MLECZ 6

#define SZANSA_ROZ_TRAWA 20

#define SILA_WILCZE_JAGODY 99
#define SZANSA_ROZ_WILCZE_JAGODY 9

#define ENTER 13
#define S 115
#define GORA 72
#define DOL 80
#define LEWO 75
#define PRAWO 77
#define SPACJA 32
#define Q 113