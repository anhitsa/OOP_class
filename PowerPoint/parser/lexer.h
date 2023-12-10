#ifndef LEXER_H
#define LEXER_H

#include <QString>
#include <string>
#include <tuple>
#include <utility> // std::pair
#include <vector>

class Lexer
{
public:
    Lexer() {}
    std::vector<std::string> tokenizeInput(const QString&);
    std::vector<std::string> tokenize(const std::string&, const char);
};

#endif // LEXER_H
