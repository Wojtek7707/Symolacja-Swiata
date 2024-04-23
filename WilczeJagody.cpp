#include "WilczeJagody.h"
#include "Guarana.h"
#include "Swiat.h"
#include <random>
void WilczeJagody::rysuj() {
    std::cout << getZnak();
}
void WilczeJagody::akcja() {
    std::cout << "akcja" << std::endl;
    /*std::cout << "akcja" << std::endl;*/
    
}
void WilczeJagody::kolizja(Organizm* inny) {
    std::cout << "Kolizja";
}
Organizm* WilczeJagody::urodz(int x, int y) {
    return new WilczeJagody(x, y);
}
