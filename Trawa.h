#pragma once
#include "Roslina.h"
class Trawa : public Roslina
{
	public:
		Trawa(int x, int y) : Roslina('t', 0, -1, x, y) {}
		virtual void akcja() override;
		virtual void kolizja(Organizm* inny) override;
		virtual void rysuj() override;
		virtual Organizm* urodz(int x, int y) override;
};

