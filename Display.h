#pragma once
#include "Matcher.h"
#include<vector>
#include <iostream>
#include <utility> 




class Display {
    
    std::vector< std::pair<std::string, std::string>> answers;
    
public:
    
     
    Display() = default;
    ~Display() = default;


    void get_history()
    {
        for (unsigned int it = 0; it < answers.size(); it++)
        {
            std::cout << "Yours answer "; 
            std::cout << it+1; 
            std::cout << " - ";
            std::cout << answers[it].first;
            std::cout << " get score: ";
            std::cout << answers[it].second;
            std::cout << std::endl;
               
        }
    }

    void save_answer(std::string _answer, std::string _mr)
    {
        
        answers.push_back(std::make_pair(_answer, _mr));
    }

    void clean_history()
    {
        answers.clear();
        std::cout << "****All answers are lost****" << std::endl;
    }


};