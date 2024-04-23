#pragma once
//#include "Czlowiek.h"
#include "Organizm.h"
#include <vector>

class Swiat
{
public:
	Swiat(int szerokosc, int wysokosc);
	~Swiat();
	static Swiat* getInstance();
	static Swiat* getInstance(int szerokosc, int wysokosc);
	static Swiat* getInstance(std::ifstream& plik);
	void zapiszDoPliku(const std::string& nazwaPliku);
	int getSzerokosc();
	int getWysokosc();
	int getXCzlowiek();
	int getYCzlowiek();
	void czyPuste(int l, int x, int y, bool* czyPuste);
	Organizm* getOrganizm(std::pair<int, int> pozycja);
	//std::vector<Organizm*> getListaOrganizm();
	void wykonajTure();
	void rysujSwiat();
	void poczatkowaPopulacja();
	void Stworz(char a, int x, int y);
	void dodajOrganizm(Organizm* organizm);
protected:
	/*const int ruchy[8][2] = { {0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1} };*/
	const int ruchy[8][2] = { {-1,-1},{0,-1},{1,-1},{-1,0}, {1,0} ,{-1,1},{0,1},{1,1} };
	
private:
	int szerokosc;
	int wysokosc;
	std::vector<Organizm*> organizmy;
	Organizm* czlowiek;
	static Swiat* instance;

	//Organizm* czlowiek;
	//static Swiat* instance;
	//std::list<Organizm*> organizmy;
};
