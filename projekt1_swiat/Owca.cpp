#include "Owca.h"

Owca::Owca(int x, int y, Swiat* swiat) :Zwierze(x, y, swiat) {
    sila = SILA_OWCA;
    inicjatywa = INICJATYWA_OWCA;
    type_id = owca;
    nazwa = "Owca";
    symbol = 'O';
}


Owca::~Owca() {
}