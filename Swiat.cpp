#include "Swiat.h"
#include "Organizm.h"
#include "Czlowiek.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "Lis.h"
#include "Owca.h"
#include "Wilk.h"
#include "Zolw.h"
#include "Antylopa.h"
#include <random>
#include <sstream>
#include <fstream>
//#include <ifstream>
#include <istream>
#include <string>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 7); // Rozk³ad jednostajny na przedziale [1, 100]
std::uniform_int_distribution<> dis2(0, 1);
Swiat* Swiat::instance = nullptr; // Definicja statycznego sk³adowego instance

Swiat::Swiat(int szerokosc, int wysokosc) // Definicja konstruktora
    : szerokosc(szerokosc), wysokosc(wysokosc)
{
}

Swiat::~Swiat()
{
}


Swiat* Swiat::getInstance(int szerokosc, int wysokosc) {
    if (instance != nullptr)
        delete instance;
    instance = new Swiat(szerokosc, wysokosc);
    return instance;
}

Swiat* Swiat::getInstance(){
    return instance;
}
void Swiat::poczatkowaPopulacja() {
    std::uniform_int_distribution<int> distribX(0, szerokosc - 1);
    std::uniform_int_distribution<int> distribY(0, wysokosc - 1);
    getInstance(szerokosc, wysokosc);

    dodajOrganizm(new Czlowiek(distribX(gen), distribY(gen)));
    dodajOrganizm(new Trawa(distribX(gen), distribY(gen)));
    //dodajOrganizm(new BarszczSosnowskiego(distribX(gen), distribY(gen)));
    /*dodajOrganizm(new Lis(distribX(gen), distribY(gen)));
    dodajOrganizm(new Lis(distribX(gen), distribY(gen)));
    dodajOrganizm(new Lis(distribX(gen), distribY(gen)));
    dodajOrganizm(new Lis(distribX(gen), distribY(gen)));
    dodajOrganizm(new Lis(distribX(gen), distribY(gen)));
    dodajOrganizm(new Lis(distribX(gen), distribY(gen)));
    dodajOrganizm(new Lis(distribX(gen), distribY(gen)));
    dodajOrganizm(new Lis(distribX(gen), distribY(gen)));
    dodajOrganizm(new Lis(distribX(gen), distribY(gen)));*/
    //dodajOrganizm(new Owca(distribX(gen), distribY(gen)));
    //dodajOrganizm(new Owca(distribX(gen), distribY(gen)));
    //dodajOrganizm(new Owca(distribX(gen), distribY(gen)));
    //dodajOrganizm(new Owca(distribX(gen), distribY(gen)));
    //dodajOrganizm(new Owca(distribX(gen), distribY(gen)));
    //dodajOrganizm(new Owca(distribX(gen), distribY(gen)));
    //dodajOrganizm(new Owca(distribX(gen), distribY(gen)));
    /*dodajOrganizm(new Owca(distribX(gen), distribY(gen)));
    dodajOrganizm(new Owca(distribX(gen), distribY(gen)));
    dodajOrganizm(new Zolw(distribX(gen), distribY(gen)));
    dodajOrganizm(new Zolw(distribX(gen), distribY(gen)));
    dodajOrganizm(new Zolw(distribX(gen), distribY(gen)));
    dodajOrganizm(new Zolw(distribX(gen), distribY(gen)));
    dodajOrganizm(new Zolw(distribX(gen), distribY(gen)));
    dodajOrganizm(new Zolw(distribX(gen), distribY(gen)));
    dodajOrganizm(new Wilk(distribX(gen), distribY(gen)));
    dodajOrganizm(new Wilk(distribX(gen), distribY(gen)));*/
    /*dodajOrganizm(new Antylopa(distribX(gen), distribY(gen)));
    dodajOrganizm(new Antylopa(distribX(gen), distribY(gen)));
    dodajOrganizm(new Antylopa(distribX(gen), distribY(gen)));
    dodajOrganizm(new Antylopa(distribX(gen), distribY(gen)));
    dodajOrganizm(new Antylopa(distribX(gen), distribY(gen)));*/

}
void Swiat::wykonajTure(){
    
    for (Organizm* o : organizmy)
    {
        if (o->getSila()>-1)
        {
            o->akcja();
        }
        /*o->kolizja(getOrganizm({o->getX(),o->getY()}));*/
    }
    new Trawa(0, 0);
}
//}


void Swiat::rysujSwiat()
{
    //std::cout << "XD";
    //poczatkowaPopulacja();
    //organizmy.back(Czlowiek(2, 2));
    //organizmy.push_back(new Czlowiek(2, 2));

    for (int i = 0; i < szerokosc + 2; i++)
    {
        std::cout << "#";
    }
    std::cout << std::endl;
    for (int y = 0; y < wysokosc; y++) {
        std::cout << "#";
        for (int x = 0; x < szerokosc; x++)
        {
            /*for (int i = 0; i < organizmy.size(); i++)
            {
                if (organizmy[i]->getX()==x && organizmy[i]->getY() == y)
                {
                    organizmy[i]->rysuj();
                    x++;
                }
            }*/
            int i = 0;
            bool czyNarysowane = true;
            //if (czlowiek->getX() == x && czlowiek->getY() == y)
            //{
            //    czlowiek->rysuj();
            //    czyNarysowane = false;
            //    //x++;
            //}
            while (i<organizmy.size()&& czyNarysowane)
            {
                if (organizmy[i]->getX() == x && organizmy[i]->getY() == y)
                {
                    organizmy[i]->rysuj();
                    czyNarysowane = false;
                    break;
                }
                i++;
            }
            if (czyNarysowane)
            {
                std::cout << " ";
            }
            //for (Organizm* o : organizmy)
            //{
                //if (o->getX()==i&&o->getY()==j)
                //{
                //    o->rysuj();
                //}
                //if (czlowiek->getX() == i && czlowiek->getY() == j)
                //{
                //    czlowiek->rysuj();
                //}
                //else if (i == o->getX() && j == o->getY())
                //{
                //    o->rysuj();
                //}
                //else
                //{
                //    std::cout << " ";
                //}
            //}
        }
        std::cout << "#\n";
    }
    for (int i = 0; i < szerokosc + 2; i++)
    {
        std::cout << "#";
    }
    std::cout << std::endl;
    //czlowiek->rysuj();
    //std::cout << czlowiek->getX();
    //std::cout << czlowiek->getY() << std::endl;
    for (Organizm* o : organizmy)
    {
        o->rysuj();
        std::cout<<o->getX();
        std::cout <<o->getY()<<std::endl;
        std::cout << o->getSila() << std::endl;
    }
    //for (Organizm* o : organizmy)
    //{
    //    o->rysuj();
    //    /*if (o->getSila() > -1)
    //        o->rysuj();*/
    //}
}
int Swiat::getSzerokosc()
{
    return szerokosc;
}

int Swiat::getWysokosc()
{
    return wysokosc;
}

int Swiat::getXCzlowiek()
{
    return czlowiek->getX();
}

int Swiat::getYCzlowiek()
{
    return czlowiek->getY();
}
void Swiat::Stworz(char a, int x, int y) {
    if (a=='t')
    {
        new Trawa(x, y);
    }
};


void Swiat::dodajOrganizm(Organizm* organizm) {
    // SprawdŸ, czy organizm ju¿ istnieje w wektorze
    //for (Organizm* org : organizmy) {
    //    if (org == organizm) {
    //        //std::cout << "Ten organizm ju¿ istnieje w œwiecie." << std::endl;
    //        return; // Organizm ju¿ istnieje, wiêc nie dodawaj go ponownie
    //    }
    //}
    if (organizm==nullptr) {
 /*       std::cout << "Ten organizm ju¿ istnieje w œwiecie." << std::endl;*/
        return; // Organizm ju¿ istnieje, wiêc nie dodawaj go ponownie
    }
    // Jeœli organizm nie istnieje, dodaj go do wektora
    organizmy.push_back(organizm);
}
//std::vector<Organizm*> Swiat::getListaOrganizm() {
//    std::vector<Organizm*> lista = organizmy;
//    return lista; // Zwrócenie kopii wektora organizmy
//}
void Swiat::czyPuste(int l, int x , int y, bool* czyPuste){
    //bool czyPuste = true;
    *czyPuste = true;
    for (Organizm* o2 : organizmy) {
        if (ruchy[l][0] + x == o2->getX() && ruchy[l][1] + y == o2->getY())
        {
            *czyPuste = false;
        }
    }
    if (*czyPuste &&
        //ruchy[l][0] + x != getXCzlowiek() &&
        //ruchy[l][1] + y != getYCzlowiek() &&
        ruchy[l][0] + x < szerokosc &&
        ruchy[l][1] + y < wysokosc &&
        ruchy[l][0] + x > -1 &&
        ruchy[l][1] + y > -1)
    {
        //organizmy.push_back(o->urodz(ruchy[l][0] + o->getX(), ruchy[l][1] + o->getY()));
        //return true;
        *czyPuste = true;
        //dodajOrganizm(new Mlecz(ruchy[l][0] + x, ruchy[l][1] + y));
    }
    else {
        *czyPuste = false;
    }
}
Organizm* Swiat::getOrganizm(std::pair<int, int> pozycja)
{
    if (pozycja.first < 0 || pozycja.first >= szerokosc || pozycja.second < 0 || pozycja.second >= wysokosc)
        return nullptr;
    for (Organizm* o : organizmy)
    {
        if (o->getX() == pozycja.first && o->getY() == pozycja.second)
        {
            return o;
        }
    }
    return nullptr;
}

Swiat* Swiat::getInstance(std::ifstream& plik) {
   /* if (!plik.is_open()) {
        std::cout << "Nie mo¿na otworzyæ pliku." << std::endl;
        return nullptr;
    }*/
    delete instance;
    // Wczytaj pierwsz¹ liniê zawieraj¹c¹ wysokoœæ i szerokoœæ œwiata
    std::string linia;
    getline(plik, linia);
    std::istringstream iss(linia);
    int szerokosc, wysokosc;
    iss >> szerokosc >> wysokosc;

    // Stwórz instancjê œwiata
    Swiat* instance = new Swiat(szerokosc, wysokosc);

    // Wczytaj pozosta³e obiekty z pliku
    while (getline(plik, linia, ';')) {
        std::string nazwa = linia;
        getline(plik, linia, ';');
        int x = stoi(linia);
        getline(plik, linia, ';');
        int y = stoi(linia);

        // Utwórz odpowiedni obiekt w zale¿noœci od nazwy
        Organizm* obj = nullptr;
        if (nazwa == "Czlowiek") {
            obj = new Czlowiek(x, y);
            //instance->czlowiek = obj;
            //getline(plik, linia, ';');
            //int umiejetnosc = stoi(linia);
            //((Czlowiek*)obj)->setUmiejetnosc(umiejetnosc);
        }
        else if (nazwa == "Wilk")
            obj = new Wilk(x, y);
        else if (nazwa == "Owca")
            obj = new Owca(x, y);
        else if (nazwa == "Lis")
            obj = new Lis(x, y);
        else if (nazwa == "Zolw")
            obj = new Zolw(x, y);
        else if (nazwa == "Antylopa")
            obj = new Antylopa(x, y);
        else if (nazwa == "Trawa")
            obj = new Trawa(x, y);
        else if (nazwa == "Mlecz")
            obj = new Mlecz(x, y);
        else if (nazwa == "Guarana")
            obj = new Guarana(x, y);
        else if (nazwa == "WilczeJagody")
            obj = new WilczeJagody(x, y);
        else if (nazwa == "BarszczSosnowskiego")
            obj = new BarszczSosnowskiego(x, y);
        // Tutaj dodaj pozosta³e warunki dla pozosta³ych organizmów

        // Dodaj obiekt do wektora organizmów
        instance->dodajOrganizm(obj);
    }

    return instance;
}
void Swiat::zapiszDoPliku(const std::string& nazwaPliku) {
    std::ofstream plik(nazwaPliku);
    if (!plik.is_open()) {
        std::cerr << "Nie mo¿na otworzyæ pliku do zapisu." << std::endl;
        return;
    }

    // Zapisz szerokoœæ i wysokoœæ œwiata
    plik << szerokosc << " " << wysokosc << ";" << std::endl;

    // Zapisz pozycje organizmów
    for (size_t i = 0; i < organizmy.size(); ++i) {
        Organizm* org = organizmy[i];
        /*std::pair<int, int> pozycja = pozycjeOrganizmow[org];*/
        std::string nazwa = "";
        if (org->getZnak()=='C')
        {
            nazwa = "Czlowiek";
        }else if (org->getZnak() == 'A')
        {
            nazwa = "Antylopa";
        }
        else if (org->getZnak() == 'O')
        {
            nazwa = "Owca";
        }
        else if (org->getZnak() == 'Z')
        {
            nazwa = "¯ó³w";
        }
        else if (org->getZnak() == 'L')
        {
            nazwa = "Lis";
        }
        else if (org->getZnak() == 'X')
        {
            nazwa = "Wilk";
        }
        else if (org->getZnak() == 'b')
        {
            nazwa = "BarszczSosnowskiego";
        }
        else if (org->getZnak() == 'w')
        {
            nazwa = "WilczeJagody";
        }
        else if (org->getZnak() == 'g')
        {
            nazwa = "Guarana";
        }
        else if (org->getZnak() == 't')
        {
            nazwa = "Trawa";
        }
        else if (org->getZnak() == 'm')
        {
            nazwa = "Mlecz";
        }
        plik << nazwa << ";" << org->getX() << ";" << org->getY();
        if (i != organizmy.size() - 1) // Nie dodawaj œrednika na koñcu pliku
            plik << ";";
        /*plik << std::endl;*/
    }

    plik.close();
    std::cout << "Dane zosta³y zapisane do pliku " << nazwaPliku << "." << std::endl;
}