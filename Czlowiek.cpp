#include "Czlowiek.h"
#include "Swiat.h"
#include <random>

Czlowiek::Czlowiek(int x, int y) : Zwierze('C', 5, 4, x, y)
{
    this->skill = 1;
}

void Czlowiek::rysuj() {
	std::cout <<getZnak();
}
int Czlowiek::getSkill() {
    return skill;
}
void Czlowiek::setSkill(bool* czyUzyto) {
    if (*czyUzyto)
    {
        skill = 0;
        *czyUzyto = false;
    }
    skill++;
}
//int getSkill();
bool Czlowiek::UzyjSkilla(){
    if (skill>=5)
    {
        return true;
    }
    return false;
}

void Czlowiek::akcja(){
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 7);
    char klaw;
    int x = getX();
    int y = getY();
    std::cout << getSkill() << std::endl;
    int a, liczba=0;
    bool ruchWykonany = true, specjal=false;
    while (ruchWykonany)
    {
        setSkill(&specjal);
        std::cin >> klaw;
        switch (klaw)
        {
        case 's':
            specjal=UzyjSkilla();
        case 'q':
            if (ruchy[0][0] + x >= 0 && ruchy[0][1] + y >= 0)
            {
                
                if (getSila()==-1)
                {
                    std::cout << "Nie mo¿esz wykonaæ Ruchu - zabito" << std::endl;
                    ruchWykonany = false;
                }
                else if (swiat->getOrganizm({ ruchy[0][0] + x , ruchy[0][1] + y }) == nullptr) {
                    a = ruchy[0][0];
                    setX(a);
                    a = ruchy[0][1];
                    setY(a);
                    ruchWykonany = false;
                }
                else if(swiat->getOrganizm({ ruchy[0][0] + x , ruchy[0][1] + y })->getZnak()=='A') {
                    liczba = dis(gen);
                    if (liczba%2==0)
                    {
                        kolizja(swiat->getOrganizm({ ruchy[0][0] + x , ruchy[0][1] + y }));
                    }
                    else
                    {
                        swiat->getOrganizm({ ruchy[0][0] + x , ruchy[0][1] + y })->akcja();

                    }
                    a = ruchy[0][0];
                    setX(a);
                    a = ruchy[0][1];
                    setY(a);
                    ruchWykonany = false;
                    
                }
                else{
                    kolizja(swiat->getOrganizm({ ruchy[0][0] + x , ruchy[0][1] + y }));
                    a = ruchy[0][0];
                    setX(a);
                    a = ruchy[0][1];
                    setY(a);
                    ruchWykonany = false;
                }
            }
            break;
        case 'w':
            if (ruchy[1][1] + getY() >= 0)
            {
                
                if (getSila() == -1)
                {
                    std::cout << "Nie mo¿esz wykonaæ Ruchu - zabito" << std::endl;
                    ruchWykonany = false;
                }
                else if (swiat->getOrganizm({ ruchy[1][0] + x , ruchy[1][1] + y }) == nullptr) {
                    a = ruchy[1][0];
                    setX(a);
                    a = ruchy[1][1];
                    setY(a);
                    ruchWykonany = false;
                }
                else if (swiat->getOrganizm({ ruchy[1][0] + x , ruchy[1][1] + y })->getZnak() == 'A') {
                    liczba = dis(gen);
                    if (liczba % 2 == 0)
                    {
                        kolizja(swiat->getOrganizm({ ruchy[1][0] + x , ruchy[1][1] + y }));
                    }
                    else
                    {
                        swiat->getOrganizm({ ruchy[1][0] + x , ruchy[1][1] + y })->akcja();
                    }
                    a = ruchy[1][0];
                    setX(a);
                    a = ruchy[1][1];
                    setY(a);
                    ruchWykonany = false;
                }
                else {
                    kolizja(swiat->getOrganizm({ ruchy[1][0] + x , ruchy[1][1] + y }));
                    a = ruchy[1][0];
                    setX(a);
                    a = ruchy[1][1];
                    setY(a);
                    ruchWykonany = false;
                }
            }
            break;
        case 'e':
            if (ruchy[2][0] + getX() < swiat->getSzerokosc() && ruchy[2][1] + getY() >= 0)
            {
                
                if (getSila() == -1)
                {
                    std::cout << "Nie mo¿esz wykonaæ Ruchu - zabito" << std::endl;
                    ruchWykonany = false;
                }
                else if (swiat->getOrganizm({ ruchy[2][0] + x , ruchy[2][1] + y }) == nullptr) {
                    a = ruchy[2][0];
                    setX(a);
                    a = ruchy[2][1];
                    setY(a);
                    ruchWykonany = false;
                }
                else if (swiat->getOrganizm({ ruchy[2][0] + x , ruchy[2][1] + y })->getZnak() == 'A') {
                    liczba = dis(gen);
                    if (liczba % 2 == 0)
                    {
                        kolizja(swiat->getOrganizm({ ruchy[2][0] + x , ruchy[2][1] + y }));
                    }
                    else
                    {
                        swiat->getOrganizm({ ruchy[2][0] + x , ruchy[2][1] + y })->akcja();
                    }
                    a = ruchy[2][0];
                    setX(a);
                    a = ruchy[2][1];
                    setY(a);
                    ruchWykonany = false;
                }
                else {
                    kolizja(swiat->getOrganizm({ ruchy[2][0] + x , ruchy[2][1] + y }));
                    a = ruchy[2][0];
                    setX(a);
                    a = ruchy[2][1];
                    setY(a);
                    ruchWykonany = false;
                }
            }
            break;
        case 'a':
            if (ruchy[3][0] + getX() >= 0)
            {
                
                if (getSila() == -1)
                {
                    std::cout << "Nie mo¿esz wykonaæ Ruchu - zabito" << std::endl;
                    ruchWykonany = false;
                }
                else if (swiat->getOrganizm({ ruchy[3][0] + x , ruchy[3][1] + y }) == nullptr) {
                    a = ruchy[3][0];
                    setX(a);
                    a = ruchy[3][1];
                    setY(a);
                    ruchWykonany = false;
                }
                else if (swiat->getOrganizm({ ruchy[3][0] + x , ruchy[3][1] + y })->getZnak() == 'A') {
                    liczba = dis(gen);
                    if (liczba % 2 == 0)
                    {
                        kolizja(swiat->getOrganizm({ ruchy[3][0] + x , ruchy[3][1] + y }));
                    }
                    else
                    {
                        swiat->getOrganizm({ ruchy[3][0] + x , ruchy[3][1] + y })->akcja();
                        
                    }
                    a = ruchy[3][0];
                    setX(a);
                    a = ruchy[3][1];
                    setY(a);
                    ruchWykonany = false;
                }
                else {
                    kolizja(swiat->getOrganizm({ ruchy[3][0] + x , ruchy[3][1] + y }));
                    a = ruchy[3][0];
                    setX(a);
                    a = ruchy[3][1];
                    setY(a);
                    ruchWykonany = false;
                }
            }
            break;
        case 'd':
            if (ruchy[4][0] + getX() < swiat->getSzerokosc())
            {
                kolizja(swiat->getOrganizm({ ruchy[4][0] + x , ruchy[4][1] + y }));
                if (getSila() == -1)
                {
                    std::cout << "Nie mo¿esz wykonaæ Ruchu - zabito" << std::endl;
                    ruchWykonany = false;
                }
                else if (swiat->getOrganizm({ ruchy[4][0] + x , ruchy[4][1] + y }) == nullptr) {
                    a = ruchy[4][0];
                    setX(a);
                    a = ruchy[4][1];
                    setY(a);
                    ruchWykonany = false;
                }
                else if (swiat->getOrganizm({ ruchy[4][0] + x , ruchy[4][1] + y })->getZnak() == 'A') {
                    liczba = dis(gen);
                    if (liczba % 2 == 0)
                    {
                        kolizja(swiat->getOrganizm({ ruchy[4][0] + x , ruchy[4][1] + y }));
                    }
                    else
                    {
                        swiat->getOrganizm({ ruchy[4][0] + x , ruchy[4][1] + y })->akcja();
                    }
                    a = ruchy[4][0];
                    setX(a);
                    a = ruchy[4][1];
                    setY(a);
                    ruchWykonany = false;
                }
                else {
                    kolizja(swiat->getOrganizm({ ruchy[4][0] + x , ruchy[4][1] + y }));
                    a = ruchy[4][0];
                    setX(a);
                    a = ruchy[4][1];
                    setY(a);
                    ruchWykonany = false;
                }
            }
            break;
        case 'z':
            if (ruchy[5][0] + getX() >= 0 && ruchy[5][1] + getY() < swiat->getWysokosc())
            {
                
                if (getSila() == -1)
                {
                    std::cout << "Nie mo¿esz wykonaæ Ruchu - zabito" << std::endl;
                    ruchWykonany = false;
                }
                else if (swiat->getOrganizm({ ruchy[5][0] + x , ruchy[5][1] + y }) == nullptr) {
                    a = ruchy[5][0];
                    setX(a);
                    a = ruchy[5][1];
                    setY(a);
                    ruchWykonany = false;
                }
                else if (swiat->getOrganizm({ ruchy[5][0] + x , ruchy[5][1] + y })->getZnak() == 'A') {
                    liczba = dis(gen);
                    if (liczba % 2 == 0)
                    {
                        kolizja(swiat->getOrganizm({ ruchy[5][0] + x , ruchy[5][1] + y }));
                    }
                    else
                    {
                        swiat->getOrganizm({ ruchy[5][0] + x , ruchy[5][1] + y })->akcja();
                    }
                    a = ruchy[5][0];
                    setX(a);
                    a = ruchy[5][1];
                    setY(a);
                    ruchWykonany = false;
                }
                else {
                    kolizja(swiat->getOrganizm({ ruchy[5][0] + x , ruchy[5][1] + y }));
                    a = ruchy[5][0];
                    setX(a);
                    a = ruchy[5][1];
                    setY(a);
                    ruchWykonany = false;
                }
            }
            break;
        case 'x':
            if (ruchy[6][1] + getY() < swiat->getWysokosc())
            {
                
                if (getSila() == -1)
                {
                    std::cout << "Nie mo¿esz wykonaæ Ruchu - zabito" << std::endl;
                    ruchWykonany = false;
                }
                else if (swiat->getOrganizm({ ruchy[6][0] + x , ruchy[6][1] + y }) == nullptr) {
                    a = ruchy[6][0];
                    setX(a);
                    a = ruchy[6][1];
                    setY(a);
                    ruchWykonany = false;
                }
                else if (swiat->getOrganizm({ ruchy[6][0] + x , ruchy[6][1] + y })->getZnak() == 'A') {
                    liczba = dis(gen);
                    if (liczba % 2 == 0)
                    {
                        kolizja(swiat->getOrganizm({ ruchy[6][0] + x , ruchy[6][1] + y }));
                        ruchWykonany = false;
                    }
                    else
                    {
                        swiat->getOrganizm({ ruchy[6][0] + x , ruchy[6][1] + y })->akcja();
                    }
                    a = ruchy[6][0];
                    setX(a);
                    a = ruchy[6][1];
                    setY(a);
                    ruchWykonany = false;
                }
                else {
                    kolizja(swiat->getOrganizm({ ruchy[6][0] + x , ruchy[6][1] + y }));
                    a = ruchy[6][0];
                    setX(a);
                    a = ruchy[6][1];
                    setY(a);
                    ruchWykonany = false;
                }
            }
            break;
        case 'c':
            if (ruchy[7][0] + getX() < swiat->getSzerokosc() && ruchy[7][1] + getY() < swiat->getWysokosc())
            {
                /*if (swiat->getOrganizm({ ruchy[7][0] + x , ruchy[7][1] + y })==nullptr)
                {
                    kolizja(swiat->getOrganizm({ ruchy[7][0] + x , ruchy[7][1] + y }));
                }*/
                if (getSila() == -1)
                {
                    std::cout << "Nie mo¿esz wykonaæ Ruchu - zabito" << std::endl;
                    ruchWykonany = false;
                }
                else if (swiat->getOrganizm({ ruchy[7][0] + x , ruchy[7][1] + y }) == nullptr) {
                    a = ruchy[7][0];
                    setX(a);
                    a = ruchy[7][1];
                    setY(a);
                    ruchWykonany = false;
                }
                else if (swiat->getOrganizm({ ruchy[7][0] + x , ruchy[7][1] + y })->getZnak() == 'A') {
                    liczba = dis(gen);
                    if (liczba % 2 == 0)
                    {
                        kolizja(swiat->getOrganizm({ ruchy[7][0] + x , ruchy[7][1] + y }));
                        ruchWykonany = false;
                    }
                    else
                    {
                        swiat->getOrganizm({ ruchy[7][0] + x , ruchy[7][1] + y })->akcja();
                    }
                    a = ruchy[7][0];
                    setX(a);
                    a = ruchy[7][1];
                    setY(a);
                    ruchWykonany = false;
                }
                else {
                    kolizja(swiat->getOrganizm({ ruchy[7][0] + x , ruchy[7][1] + y }));
                    a = ruchy[7][0];
                    setX(a);
                    a = ruchy[7][1];
                    setY(a);
                    ruchWykonany = false;
                }
            }
            break;
        default:
            break;
        }

    }
    setSkill(&specjal);
}
void Czlowiek::kolizja(Organizm* inny){
    if (this == inny)
        return;

    if (inny == nullptr)
    {
        return;
    }
    else if (this == inny) {
        return;
    }
    else if (getSila() > inny->getSila())
    {
        std::cout << "Wygral czlowiek" << std::endl;
        if (inny->getZnak()=='g')
        {
            setSila(3);
        }
        inny->zabij();
    }
    else if (getSila() < inny->getSila())
    {
        std::cout << "Przegral czlowiek" << std::endl;
        zabij();
    }
    else
    {
        std::cout << "Remis" << std::endl;
        zabij();
        inny->zabij();
    }
}
Organizm* Czlowiek::urodz(int x, int y){
	return nullptr;
}