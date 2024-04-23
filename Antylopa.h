#pragma once
#include "Zwierze.h"
class Antylopa : public Zwierze {
private:
protected:
	const int ruchy[8][2] = { {-2,-2},{0,-2},{2,-2},{-2,0}, {2,0} ,{-2,2},{0,2},{2,2} };
public:
	Antylopa(int x, int y);
	virtual void akcja() override;
	virtual void kolizja(Organizm* inny) override;
	virtual void rysuj() override;
	virtual Organizm* urodz(int x, int y) override;
};

