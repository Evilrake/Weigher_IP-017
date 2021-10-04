#include <SFML/Graphics.hpp>
#include <bg.h>
#include <iostream>

using namespace std;
using namespace sf;

int callMenu(RenderWindow& window)
{
	// bg
    Texture texture;
    if (!texture.loadFromFile("images/bg.jpg")) {
        cout << "Error, images/bg.jpg not found" << endl;
    }
    RectangleShape bg = initBg(window);
    bg.setTexture(&texture);

    // Button
    RectangleShape startButton;
    startButton.setSize(Vector2f(300, 70));
    startButton.setPosition(Vector2f(40, 40));
    startButton.setFillColor(Color(0, 0, 0, 0));
    startButton.setOutlineColor(Color(80, 130, 255));
    startButton.setOutlineThickness(5);

    // buttonText
    Font font;
    if (!font.loadFromFile("fonts/font.ttf")) {
        cout << "Error, fonts/font.ttf not found" << endl;
    }
    Text startButtonText;
    startButtonText.setFont(font);
    startButtonText.setCharacterSize(40);
    startButtonText.setFillColor(Color::Black);
    startButtonText.setPosition(50, 50);
    startButtonText.setString(L"Начать игру");

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    if (startButton.getGlobalBounds().contains(
                                event.mouseButton.x, event.mouseButton.y)) {
                        cout << 1;
                    }
                }
            }
        }

        window.clear();
        window.draw(bg);
        window.draw(startButton);
        window.draw(startButtonText);
        window.display();
        sleep(milliseconds(1000 / 60));
    }
    return 0;
    }