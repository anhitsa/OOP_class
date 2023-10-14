#ifndef LEXER_H
#define LEXER_H

#include "../items/item.h"
#include "../input_handler/userinputhandler.h"

#include <string>
#include <tuple>
#include <utility> // std::pair
#include <vector>

class Lexer
{
public:
    Lexer() {}
    std::vector<std::string> tokenizeInput(UserInputHandler::InputStream&);
    std::vector<std::string> tokenize(const std::string&, const char);
};

#endif // LEXER_H
