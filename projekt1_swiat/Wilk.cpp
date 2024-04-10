#include "Wilk.h"

Wilk::Wilk(int x, int y, Swiat* swiat) :Zwierze(x,y,swiat){
    sila = SILA_WILK;
    inicjatywa = INICJATYWA_WILK;
    type_id = wilk;
    nazwa = "Wilk";
    symbol = 'W';
}


Wilk::~Wilk(){
}
