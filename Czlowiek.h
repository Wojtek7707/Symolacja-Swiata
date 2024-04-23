#pragma once
#include "Zwierze.h"
class Czlowiek : public Zwierze {
private:
	int skill;
	int silaPomocnicza;
public:
    /*Czlowiek(int x, int y): Zwierze('c', 4, 5, x, y) {}*/
	Czlowiek(int x, int y);
	virtual void akcja() override;
	virtual void kolizja(Organizm* inny) override;
	virtual void rysuj() override;
	virtual Organizm* urodz(int x, int y) override;
	void setSkill(bool* czyUzyto);
	int getSkill();
	bool UzyjSkilla();
};


