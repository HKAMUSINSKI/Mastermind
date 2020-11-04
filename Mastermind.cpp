#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Matcher.h"
#include "PatternGenerator.h"
#include "Display.h"
#include "Game.h"
#include "Player.h"
#include "Menu.h"
#include<windows.h>

void choice_msg(unsigned int* choice)
{
    std::cout << "You have chosen: " << *choice << std::endl;
    Sleep(400);
    system("cls");
}


int main() {
    unsigned int choice =0;
    Player* player= nullptr; /// wskaznik 
    PatternGenerator pattern; 
    Matcher matcher;
    
    Game game(pattern, player, matcher, new Display);
      
    while (choice != 9)
    {
        game.menu_show();
        std::cin >> choice;
        choice_msg(&choice);

        switch (choice)
        {
        case 1:
            
            player = new Player_Human(); // przypisanie obiektu do wskaznika 
            game.set_player(player);
            game.run();

            delete player; // kasowanie obiektu
            
            break;

        case 2:
            player = new Player_AI(); // przypisanie obiektu do wskaznika 
            game.set_player(player);
            game.run();

            delete player; // kasowanie obiektu
            
            
            break;

            
        case 3:
            std::cout << "This option is not ready" << std::endl;
            
            break;

        case 4:
            std::cout << "This option is not ready" << std::endl;

            break;

        case 5:
            pattern.setPattern();

            break;

        case 6:
            std::cout << "Please set pattern lenght: ";
            int lenght;
            std::cin >> lenght;
            pattern.randomPattern(lenght);
            std::cout << "Created pattern is:  "<< pattern.getPattern() << std::endl;
            Sleep(1000);
            system("cls");
            break;

        case 9:
            std::cout << "We leave the game" << std::endl;
            Sleep(1000);
            break;

        default:
            std::cout << "There is no option, try again" << std::endl;


            break;
        }
        

    }

    
    system("cls");


              

    
    

    
   
}


// console.addHandler(std::unique_ptr<CommandHandler>(new Quitter));
//console.addHandler(std::unique_ptr<CommandHandler>(new Printer));