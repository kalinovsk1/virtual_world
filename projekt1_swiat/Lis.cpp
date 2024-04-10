#include "Lis.h"

Lis::Lis(int x, int y, Swiat* swiat) :Zwierze(x, y, swiat) {
    sila = SILA_LIS;
    inicjatywa = INICJATYWA_LIS;
    type_id = lis;
    nazwa = "Lis";
    symbol = 'L';
}


char Lis::atak(Organizm* org){
    if (this->sila < org->GetSila()) {
        return ZOSTAN;
    }
    else {
        return NULL;
    }
}


Lis::~Lis() {
}