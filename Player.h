#pragma once
#include <cmath>



class Player {
    
protected:

std::string guess;
public:
    
    Player() {}

    virtual void new_guess(unsigned int length) =0;
    virtual std::string last_guess() = 0;
    virtual void won() = 0;
  
    
/*
Player operator = (Player &p)
{
    this -> guess = p.guess;
}
*/
};


class Player_Human  : public Player 
{
    
public:
    Player_Human() {}

    void new_guess(unsigned int length) override
    {
        std::cout << "Please tell me next guess" << std::endl;
        std::cin >> guess;
        if (guess.length() != length)
        {
            std::cout << "Solution should have "<< length <<" chars" << std::endl;
            new_guess(length);
        }
           }

    std::string last_guess() override
    {
        return guess;
    }
    
    void won()
    {
        std::cout << "You Won!" << std::endl;
    }

};


class Player_AI : public Player
{
private:   
    unsigned int counter;
    
public:
    Player_AI() { counter = 0;}

    
    void new_guess(unsigned int length) override
    {
        guess = "";
        unsigned int  temp = counter;
        unsigned int  znak;
        unsigned int  potega;
        unsigned int  move;
            for (auto it = length; it > 0; it--)
            {                
                potega = pow((length + 2 ), it-1);
                
                if (temp >= potega)
                {
                   move = temp / potega;
                   temp = temp - (potega * move);
                    
                }
                else
                {
                 move = 0;
                }
                znak = (97 + move);
                
                guess.push_back((char)znak);
            }
            counter++;
        std::cout << "AI give answer: " << guess << std::endl;
        

       
        
    }
 
    std::string last_guess() override
    {
        return guess;
    }

    void won()
    {
        std::cout << "Computer won" << std::endl;
        counter = 0;
        
    }

};