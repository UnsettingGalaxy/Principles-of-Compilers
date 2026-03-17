#include <string>
enum Type{
    ID,
    NUM,
    KEYWORD,
    MARK,
    eof
};
struct token {
    Type type;
    std::string value;
};
class WordsParser {
    public:
        WordsParser(const std::string& filename);
        token getNextToken();
    private:    
        std::string content;
        size_t pos;
};
extern std::string enum_to_string[5];
bool isempty(char c);
bool isbegin(char c);
bool ispart(char c);
bool isalpha(char c);
bool isdigit(char c);