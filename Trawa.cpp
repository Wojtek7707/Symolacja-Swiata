#include "Trawa.h"
#include "Swiat.h"
#include <random>
void Trawa::rysuj() {
	std::cout << getZnak();
}
void Trawa::akcja() {
	//std::cout << "akcja";
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 7);
    //std::cout << "akcja";
    int l = dis(gen);
    bool czyPuste = true;
    //czyPuste = true;
    int x = getX();
    int y = getY();
    swiat->czyPuste(l, x, y, &czyPuste);
    if (czyPuste) {
        swiat->Stworz(getZnak(),x+ruchy[l][0],y+ruchy[l][1]);
    }
}
void Trawa::kolizja(Organizm* inny) {
	std::cout << "Kolizja";
}
Organizm* Trawa::urodz(int x, int y) {
	return new Trawa(x,y);
}