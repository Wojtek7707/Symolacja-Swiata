#include "BarszczSosnowskiego.h"
#include "Swiat.h"
#include <random>
void BarszczSosnowskiego::rysuj() {
    std::cout << getZnak();
}
void BarszczSosnowskiego::akcja() {
    /*std::cout << "akcja" << std::endl;*/
    int a;
    bool ruchWykonany = true;
    for (int i = 0; i < 8; i++)
    {
        if (swiat->getOrganizm({ ruchy[i][0] + getX() , ruchy[i][1] + getY() })!=nullptr)
        {
            swiat->getOrganizm({ ruchy[i][0] + getX() , ruchy[i][1] + getY() })->zabij();
        }
        //zabij();
    }

}
void BarszczSosnowskiego::kolizja(Organizm* inny) {
    std::cout << "Kolizja";
    std::cout << "Zjedzono Barszcz Sosnowskiego" << std::endl;
    zabij();
    inny->zabij();
}
Organizm* BarszczSosnowskiego::urodz(int x, int y) {
    return new BarszczSosnowskiego(x, y);
}