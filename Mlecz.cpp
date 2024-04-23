#include "Mlecz.h"
#include "Swiat.h"
#include <random>
//std::random_device rdMlecz;
//std::mt19937 gen(rdMlecz());
//std::uniform_int_distribution<> dis(0, 7);
void Mlecz::rysuj() {
	std::cout << getZnak();
}
void Mlecz::akcja() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 7);
	//std::cout << "akcja";
    for (int i = 0; i < 3; i++)
    {
        //ruchy[dis(gen)][dis2(gen)]
        int l = dis(gen);
        bool czyPuste=true;
        //czyPuste = true;
        int x = getX();
        int y = getY();
        swiat->czyPuste(l, x, y, &czyPuste);
        if (czyPuste){
            swiat->dodajOrganizm(urodz(ruchy[l][0] + x, ruchy[l][1] + y));
        }
        //for (Organizm* o2 : swiat->getListaOrganizm()) {
        //
        //}
    }
}
void Mlecz::kolizja(Organizm* inny) {
	std::cout << "Kolizja";
}
Organizm* Mlecz::urodz(int x, int y){
	return new Mlecz(x,y);
}