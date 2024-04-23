#pragma once
#include "Roslina.h"
class WilczeJagody : public Roslina
{
public:
	WilczeJagody(int x, int y) : Roslina('w', 99, -1, x, y) {}
	virtual void akcja() override;
	virtual void kolizja(Organizm* inny) override;
	virtual void rysuj() override;
	virtual Organizm* urodz(int x, int y) override;
};
