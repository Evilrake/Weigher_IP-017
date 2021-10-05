#include <SFML/Graphics.hpp>
#include <iostream>
#include <menu.h>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1000, 600), "Weigher Game");

    callMenu(window);

    return 0;
}
