#include "Guarana.h"
#include "Swiat.h"
#include <random>
void Guarana::rysuj() {
    std::cout << getZnak();
}
void Guarana::akcja() {
    std::cout << "akcja" << std::endl;
}
void Guarana::kolizja(Organizm* inny) {
    std::cout << "Kolizja";
}
Organizm* Guarana::urodz(int x, int y) {
    return new Guarana(x, y);
}