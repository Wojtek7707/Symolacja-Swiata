#pragma once
#include "Roslina.h"
class Guarana :
	public Roslina
{
public:
	Guarana(int x, int y) : Roslina('g', 0, -1, x, y) {}
	virtual void akcja() override;
	virtual void kolizja(Organizm* inny) override;
	virtual void rysuj() override;
	virtual Organizm* urodz(int x, int y) override;
};