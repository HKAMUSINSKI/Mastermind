#pragma once
#include <iostream>

class Menu {

public:
    
    Menu() = default;
      
    void show()
        {
            std::cout << "Witam w grze stworzeonej przez Huberta" << std::endl;
            std::cout << "Oto dostepne opcje do wyboru" << std::endl;
            std::cout << "1 - zgaduj" << std::endl;
            std::cout << "2 - niech komputer zgaduje metoda silowa" << std::endl;
            std::cout << "3 - niech komputer zgaduje metoda inteligetna" << std::endl;
            std::cout << "4 - opcja 2 i 3 naraz" << std::endl;
            std::cout << "5 - ustawienia" << std::endl;
            std::cout << "9 - wyjscie" << std::endl;
        }

      

    
   
};