#pragma once
#include "swiat.h"
#include <iostream>
#include <fstream>
using namespace std;
class Swiat;

class KreatorSwiata {
public:
    KreatorSwiata();
    void stworzPlik(Swiat* swiat, string nazwa = "zapis.txt");
    Swiat* stworzSwiat(int szer, int wys);
    Swiat* stworzSwiat(string nazwaPliku = "zapis.txt");
    void usunSwiat(Swiat* swiat);
    ~KreatorSwiata();
};