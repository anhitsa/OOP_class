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
    //TK: Tokenizer should be based on istream (or QTextStream at least) not on QString
    //TK: Also you do not need tokenize whole input at once, it is mor optimal to tokenize one-by-one in the course of parsing upon necessity
    std::vector<std::string> tokenizeInput(const QString&);
    //TK:  You should not need to variants of tokenize, keep only one of them, delimiter can have default value = '\n',
    //TK: also do not skip local variable names in defintions, they are improving readability
    std::vector<std::string> tokenize(const std::string&, const char);
};

#endif // LEXER_H
