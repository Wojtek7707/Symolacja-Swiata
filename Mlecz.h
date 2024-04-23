#pragma once
#include "Roslina.h"
class Mlecz : public Roslina
{
public:
	Mlecz(int x, int y) : Roslina('m', 0, -1, x, y) {}
	virtual void akcja() override;
	virtual void kolizja(Organizm* inny) override;
	virtual void rysuj() override;
	virtual Organizm* urodz(int x, int y) override;
};

