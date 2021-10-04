#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");
    RectangleShape bg;

    Texture bgTexture;
    if (!bgtexture.loadFromFile("images/bg.jpg")) {
        cout << "Error, images/bg.jpg not found" << endl;
    }
    bg.setTexture(&bgTexture);
    bg.setPosition(Vector2f(0, 0));
    bg.setSize(Vector2f(window.getSize().x, window.getSize().y));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(bg);
        window.display();
    }

    return 0;
}