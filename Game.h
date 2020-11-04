#pragma once
#include "Player.h"
#include "Display.h"


class Game {
private:
    PatternGenerator& pattern;
    Player* player;
    Matcher& matcher;
    Display* display;

public:
    Game(PatternGenerator& pattern,
        Player* player,
        Matcher& matcher,
        Display* display) : pattern(pattern), player(player), matcher(matcher), display(display) 
    
    {   
    }

    ~Game() 
    {
        delete display;
        
    }

    void run() {
        MatchResult mr(0, 0);
        display->clean_history();

        while (pattern.getPattern().length() != mr.get_star())
        {
            display->get_history();
            player->new_guess(pattern.getPattern().length());

            mr = matcher.match(pattern.getPattern(), player->last_guess());
            std::cout << mr.get_result() << std::endl;
            display->save_answer(player->last_guess(), mr.get_result());
            
            
                       
        }
        player->won();
        display->clean_history();
    }

        void set_player(Player * p)
        {
            player = p;
        }


        void menu_show()
        {
            std::cout << "Welcome:) This game was created by Hubert" << std::endl;
            std::cout << "Here is Yours options:" << std::endl;
            std::cout << "1 - You guess" << std::endl;
            std::cout << "2 - Computer guess - option 1 " << std::endl;
            std::cout << "3 - Computer guess - option 2" << std::endl;
            std::cout << "4 - Option 2 then 3" << std::endl;
            std::cout << "5 - Set your pattern for AI" << std::endl;
            std::cout << "6 - Set random pattern" << std::endl;
            std::cout << "9 - Exit" << std::endl;
        }
        
    

};