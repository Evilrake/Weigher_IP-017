#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

RectangleShape initBg(RenderWindow& window)
{
    RectangleShape bg;

    bg.setPosition(Vector2f(0, 0));
    bg.setSize(Vector2f(window.getSize().x, window.getSize().y));

    return bg;
}

Texture& initBgTexture()
{
    Texture texture;
    if (!texture.loadFromFile("images/bg.jpg")) {
        cout << "Error, images/bg.jpg not found" << endl;
    }

    Texture& res = texture;
    return res;
}
