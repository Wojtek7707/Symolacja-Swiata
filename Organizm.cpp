#include "Organizm.h"
#include "Swiat.h"
Organizm::Organizm(char znak, int sila, int inicjatywa, int x, int y)
{
	this->swiat = Swiat::getInstance();
	//this->organizmy = Swiat::getListaOrganizm();
	this->znak = znak;
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->pozycja = { x, y };
	this->wiek = 0;
	swiat->dodajOrganizm(this);
	//swiat->dodajOrganizm(this);
}
Organizm::Organizm(const Organizm& a)
{
	this->swiat = a.swiat;
	this->znak = a.znak;
	this->sila = a.sila;
	this->inicjatywa = a.inicjatywa;
	this->pozycja = a.pozycja;
	this->wiek = 0;
	swiat->dodajOrganizm(this);
}
void Organizm::postarz()
{
	wiek += 1;
}

void Organizm::rysuj()
{
	std::cout << getZnak();
}

int Organizm::getX()
{
	return pozycja.first;
}

int Organizm::getY()
{
	return pozycja.second;
}

int Organizm::getSila()
{
	return sila;
}

int Organizm::getInicjatywa()
{
	return inicjatywa;
}

char Organizm::getZnak()
{
	return znak;
}
void Organizm::setX(int x)
{
	pozycja.first=x+getX();
}

void Organizm::setY(int y)
{
	pozycja.second=y+getY();
}

void Organizm::zabij() {
	/*pozycja = { -1, -1 };*/
	sila = -1;
	inicjatywa = -1;
	pozycja.first = -1;
	pozycja.second = -1;
}

void Organizm::setSila(int silaDodatkowa) {
	sila += silaDodatkowa;
}

//bool Organizm::PustePole(std::pair<int, int> pozycja, bool musiBycPuste)
//{
//	if (pozycja.first < 0 || pozycja.first >= swiat->getSzerokosc() || pozycja.second < 0 || pozycja.second >= swiat->getWysokosc())
//		return false;
//	if (musiBycPuste && swiat->getOrganizm(pozycja) != nullptr)
//		return false;
//	poprzedniaPozycja = this->pozycja;
//	Organizm* inny = swiat->getOrganizm(pozycja);
//	this->pozycja = pozycja;
//	//swiat->dodajLog(this, "Ruch (" + to_string(poprzedniaPozycja.first) + "," + to_string(poprzedniaPozycja.second) + ") -> (" + to_string(pozycja.first) + "," + to_string(pozycja.second) + ")");
//	if (inny != nullptr)
//	{
//		inny->kolizja(this);
//	}
//	return true;
//}
