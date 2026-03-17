#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>
#include <unordered_set>
#include "words_parser.hpp"
int main() {
    WordsParser parser("src/test.c");
    std::vector<token> tokens;
    token tok;
    while((tok = parser.getNextToken()).type != eof) {
        tokens.push_back(tok);
    }
    tokens.push_back(tok); // push the eof token
    for(const auto& t : tokens) {
        std::cout << "<"<< enum_to_string[t.type] <<" , "<< t.value << ">"  << std::endl;
    }
    
    return 0;
}
