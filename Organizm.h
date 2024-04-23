#pragma once
#include <string>
#include <iostream>
//#include "Swiat.h"

class Swiat;
class Organizm
{
private:
	std::pair<int, int> pozycja;
	int sila, inicjatywa, wiek; //wiek;//wiek jest po to, ¿eby móc wiedzieæ, kto ma pierwszeñstwo
	char znak;
	std::pair<int, int> poprzedniaPozycja;
	
protected:
	Swiat* swiat;
	//std::vector<Organizm*> organizmy;
	const int ruchy[8][2] = { {-1,-1},{0,-1},{1,-1},{-1,0}, {1,0} ,{-1,1},{0,1},{1,1} };
public:
	//dwa konstruktory, ¿eby moæ dodaæ obiekt na dwa ró¿ne sposoby
	Organizm(char znak, int sila, int inicjatywa, int x, int y);
	Organizm(const Organizm& a);
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* inny) = 0;
	virtual void rysuj()=0;
	virtual Organizm* urodz(int x, int y) = 0;
	void postarz();
	int getSila();
	int getInicjatywa();
	int getX();
	int getY();
	char getZnak();
	void setX(int x);
	void setY(int y);
	void setSila(int silaDodatkowa);
	void zabij();
	//bool PustePole(std::pair<int, int> pozycja, bool musiBycPuste);
	//Organizm* getOrganizm(std::pair<int, int> pozycja);
};