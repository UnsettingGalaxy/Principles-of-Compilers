#include "words_parser.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>
#include <unordered_set>
bool isdigit(char c) {
    return c >= '0' && c <= '9';
}
bool isalpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
bool isbegin(char c){
    return isalpha(c)||c=='_';
}
bool ispart(char c){
    return isalpha(c)||isdigit(c)||c=='_';
}
bool isempty(char c){
    return c==' '||c=='\n'||c=='\t';
}
std::string enum_to_string[5] = {"ID", "NUM", "KEYWORD", "MARK", "eof"};
WordsParser::WordsParser(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    content = buffer.str();
    pos = 0;
}
token WordsParser::getNextToken() {
    while(pos<content.size()&&isempty(content[pos])){
        pos++;
    }
    if(pos>=content.size()){
        return {eof, ""};
    }
    if(content[pos]=='i'){
        int tmpos=pos;
        tmpos++;
        if(tmpos<content.size()&&content[tmpos]=='n'){
            tmpos++;
            if(tmpos<content.size()&&content[tmpos]=='t'){
                tmpos++;
                if(tmpos>=content.size()||isempty(content[tmpos])){
                    pos=tmpos;
                    return {KEYWORD,"int"};
                }
            }
        }
    }
    if(content[pos]=='r'){
        int tmpos=pos;
        tmpos++;
        if(tmpos<content.size()&&content[tmpos]=='e'){
            tmpos++;
            if(tmpos<content.size()&&content[tmpos]=='t'){
                tmpos++;
                if(tmpos<content.size()&&content[tmpos]=='u'){
                    tmpos++;
                    if(tmpos<content.size()&&content[tmpos]=='r'){
                        tmpos++;
                        if(tmpos<content.size()&&content[tmpos]=='n'){
                            tmpos++;
                            if(tmpos>=content.size()||isempty(content[tmpos])){
                                pos=tmpos;
                                return {KEYWORD,"return"};
                            }
                        }
                    }
                }
            }
        }
    }
    if(isbegin(content[pos])){
        std::string word = "";
        int tmpos=pos;
        while(tmpos<content.size()&&ispart(content[tmpos])){
            word+=content[tmpos];
            tmpos++;
        }
        pos=tmpos;
        return {ID, word};
    }
    if(isdigit(content[pos])){
        std::string num = "";
        int tmpos=pos;
        while(tmpos<content.size()&&isdigit(content[tmpos])){
            num+=content[tmpos];
            tmpos++;
        }
        pos=tmpos;
        return {NUM, num};
    }
    return {MARK, std::string(1, content[pos++])};
}