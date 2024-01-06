#include "lexer.h"

std::vector<std::string> Lexer::tokenizeInput(std::istream& input)
{
    std::vector<std::string> tokens;
    std::string token;

    while (input >> std::ws)
    {
        char ch = input.peek();

        if (ch == '\"')
        {
            input.ignore();
            std::getline(input, token, '\"');
            tokens.push_back(token);
            input.ignore();
        }
        else
        {
            if (input >> token)
                tokens.push_back(token);
            else break;
        }
    }

    return tokens;
}

