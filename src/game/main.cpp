#include <SFML/Graphics.hpp>
#include <game.h>
#include <iostream>
#include <menu.h>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

int main()
{
    srand(time(NULL));
    RenderWindow window(sf::VideoMode(1000, 600), "Weigher game");

    vector<vector<string>> words;

    string easyWords[3][4]
            = {{"фрукты", "яблоко", "банан", "груша"},
               {"посуда", "тарелка", "кружка", "чашка"},
               {"животные", "тигр", "олень", "лев"}};
    string middleWords[3][4]
            = {{"фрукты", "ананас", "мандарин", "слива"},
               {"посуда", "поднос", "скалка", "кувшин"},
               {"животные", "жираф", "панда", "кенгуру"}};
    string hardWords[3][4]
            = {{"фрукты", "авокадо", "манго", "папайя"},
               {"посуда", "графин", "солонка", "противень"},
               {"животные", "киви", "лемур", "геккон"}};

    int win;
    while (1) {
        int difficult = callMenu(window, win);
        if (difficult == 1) {
            win = startGame(window, easyWords);
        } else if (difficult == 2) {
            win = startGame(window, middleWords);
        } else {
            win = startGame(window, hardWords);
        }
    }

    return 0;
}
