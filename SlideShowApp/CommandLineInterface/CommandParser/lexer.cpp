#include "lexer.h"

#include <sstream>

std::vector<std::string> Lexer::tokenizeInput(const QString& qstring)
{
    std::istringstream stream{qstring.toStdString()};
    std::vector<std::string> tokens;
    std::string token;
    while (stream >> token)
        tokens.push_back(token);
    return tokens;
}

std::vector<std::string> Lexer::tokenize(const std::string& str, const char delim=' ')
{
    std::vector<std::string> tokens;
    std::string::size_type beg = 0;
    for (auto end = 0; (end = str.find(delim, end)) != std::string::npos; ++end)
    {
        tokens.push_back(str.substr(beg, end - beg));
        beg = end + 1;
    }
    tokens.push_back(str.substr(beg));
    return tokens;
}
