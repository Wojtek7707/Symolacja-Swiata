#pragma once
#include "Zwierze.h"
class Owca : public Zwierze
{
private:
public:
	Owca(int x, int y);
	virtual void akcja() override;
	virtual void kolizja(Organizm* inny) override;
	virtual void rysuj() override;
	virtual Organizm* urodz(int x, int y) override;
};

