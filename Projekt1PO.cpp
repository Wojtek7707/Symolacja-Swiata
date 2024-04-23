// Projekt1PO.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include "Swiat.h"
#include <iostream>
#include <fstream>
#include <string>
#include <random>
int main()
{
   
    Swiat swiat = Swiat(5,5);
    swiat.getInstance();
    swiat.poczatkowaPopulacja();
    while (true)
    {
        swiat.rysujSwiat();
        swiat.wykonajTure();

    }
    
    swiat.rysujSwiat();



    //Swiat* swiat = Swiat::getInstance(5, 5);
    //std::ifstream plik("plik.txt");
    //if (plik.is_open())
    //    swiat = Swiat::getInstance(plik);
    //swiat->rysujSwiat();
    //plik.close();
    //swiat->zapiszDoPliku("zapisz.txt");
    
    ////system("cls");
    
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
