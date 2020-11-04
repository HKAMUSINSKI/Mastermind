#pragma once

struct MatchResult {
private:
    int star, dot;
    std::string result = "";

public:
    MatchResult(int star, int dot) {
        this->star = star;
        this->dot = dot;
    }

    std::string get_result() {
        result = "";
        for (int j = 0; j < star; j++)
            result += '*';

        for (int j = 0; j < dot; j++)
            result += 'o';

        return this->result;
    }

    int get_star()
    {
        return star;
    }

};


class Matcher {
    int star;
    int dot;
public:
   
    MatchResult match(std::string pattern, std::string guess) {
        star = 0;
        dot = 0;
        

        for (unsigned int i = 0; i < pattern.size(); i++)
        {
            if (guess[i] == pattern[i])
            {
                guess[i] = '*';
                pattern[i] = '?';
                star++;
            }
        }
        for (unsigned int i = 0; i < pattern.size(); i++)
        {

            for (unsigned int j = 0; j < pattern.size(); j++)
            {
                if (guess[i] == pattern[j])
                {
                    pattern[j] = '0';
                    dot++;
                }
            }
        }

        return { MatchResult(star, dot) };
    }
};