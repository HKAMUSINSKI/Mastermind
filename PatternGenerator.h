#pragma once
#include <cstdlib>
#include <time.h>


class PatternGenerator {
    std::string pattern= "";


public:
    PatternGenerator (){ srand(time(0));}
    std::string getPattern() { return pattern; }

    void setPattern() 
    { 
        pattern = "";
        std::cout << "AI will try quess this pattern. Please rember that pater should contain only small letter " << std::endl;
        std::cout << "Please tell me pattern: " << std::endl;
        std::cin >> pattern;
        std::cout << "Your patern will be: " << pattern << std::endl;

    }

    void randomPattern(int lenght)
    {
        
        pattern = "";
        for (int it =0; it<lenght; it++)
        {
            
            pattern.push_back((char)(rand() % (lenght+2) + 97));
           
         }
    }



};