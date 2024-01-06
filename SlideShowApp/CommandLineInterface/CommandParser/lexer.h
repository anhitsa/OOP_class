#ifndef LEXER_H
#define LEXER_H

#include <istream>
#include <string>
#include <vector>

class Lexer
{
public:
    Lexer()=default;
    std::vector<std::string> tokenizeInput(std::istream&);

};

#endif // LEXER_H
