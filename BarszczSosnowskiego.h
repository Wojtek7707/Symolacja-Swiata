//#pragma once
//class BarszczSosnowskiego
//{
//};
#pragma once
#include "Roslina.h"
class BarszczSosnowskiego : public Roslina
{
public:
	BarszczSosnowskiego(int x, int y) : Roslina('b', 10, -1, x, y) {}
	virtual void akcja() override;
	virtual void kolizja(Organizm* inny) override;
	virtual void rysuj() override;
	virtual Organizm* urodz(int x, int y) override;
};
