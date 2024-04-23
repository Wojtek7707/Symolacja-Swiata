#pragma once
#include "Zwierze.h"
class Wilk : public Zwierze
{
private:
public:
	Wilk(int x, int y);
	virtual void akcja() override;
	virtual void kolizja(Organizm* inny) override;
	virtual void rysuj() override;
	virtual Organizm* urodz(int x, int y) override;
};

