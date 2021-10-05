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
    RenderWindow window(sf::VideoMode(1000, 600), "Weigher game");

    int difficult = callMenu(window);
    startGame(window, difficult);

    return 0;
}
