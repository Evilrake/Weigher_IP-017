#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

struct keyboardSymbol {
    sf::RectangleShape shape;
    std::string str;
    std::string folder;
    bool active = true;
};

struct secretSymbol {
    std::string str;
    bool open;
};

std::vector<secretSymbol> initSecretWord(std::string word);
int checkWin(std::vector<secretSymbol> secretSymbols);
int startGame(sf::RenderWindow& window, std::string (&words)[3][4]);
