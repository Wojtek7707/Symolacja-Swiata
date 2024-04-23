#pragma once
#include "Organizm.h"
class Roslina : public Organizm {
public:
    Roslina(char znak, int sila, int inicjatywa, int x, int y) : Organizm(znak, sila, inicjatywa, x, y) {}

    virtual void akcja() override = 0;
    virtual void kolizja(Organizm* inny) override = 0;
    virtual void rysuj() override = 0;
    virtual Organizm* urodz(int x, int y) override = 0;
};

