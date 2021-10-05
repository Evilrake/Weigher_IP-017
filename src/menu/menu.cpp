#include <SFML/Graphics.hpp>
#include <bg.h>
#include <iostream>

using namespace std;
using namespace sf;

int callChooseDifficultMenu(RenderWindow& window)
{
    int difficult = 0;

    // bg
    Texture texture;
    if (!texture.loadFromFile("images/bg.jpg")) {
        cout << "Error, images/bg.jpg not found" << endl;
    }
    RectangleShape bg = initBg(window);
    bg.setTexture(&texture);

    // Buttons
    RectangleShape easyButton;
    easyButton.setPosition(Vector2f(40, 40));
    easyButton.setSize(Vector2f(300, 70));
    easyButton.setFillColor(Color(0, 0, 0, 0));
    easyButton.setOutlineColor(Color(80, 130, 255));
    easyButton.setOutlineThickness(5);

    RectangleShape middleButton;
    middleButton.setPosition(Vector2f(40, 140));
    middleButton.setSize(Vector2f(300, 70));
    middleButton.setFillColor(Color(0, 0, 0, 0));
    middleButton.setOutlineColor(Color(80, 130, 255));
    middleButton.setOutlineThickness(5);

    RectangleShape hardButton;
    hardButton.setPosition(Vector2f(40, 240));
    hardButton.setSize(Vector2f(300, 70));
    hardButton.setFillColor(Color(0, 0, 0, 0));
    hardButton.setOutlineColor(Color(80, 130, 255));
    hardButton.setOutlineThickness(5);

    // buttonText
    Font font;
    if (!font.loadFromFile("fonts/font.ttf")) {
        cout << "Error, fonts/font.ttf not found" << endl;
    }
    Text easyButtonText;
    easyButtonText.setFont(font);
    easyButtonText.setCharacterSize(40);
    easyButtonText.setFillColor(Color::Black);
    easyButtonText.setPosition(Vector2f(50, 50));
    easyButtonText.setString(L"Легкий");

    Text middleButtonText;
    middleButtonText.setFont(font);
    middleButtonText.setCharacterSize(40);
    middleButtonText.setFillColor(Color::Black);
    middleButtonText.setPosition(Vector2f(50, 150));
    middleButtonText.setString(L"Средний");

    Text hardButtonText;
    hardButtonText.setFont(font);
    hardButtonText.setCharacterSize(40);
    hardButtonText.setFillColor(Color::Black);
    hardButtonText.setPosition(Vector2f(50, 250));
    hardButtonText.setString(L"Тяжелый");

    while (!difficult) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    if (easyButton.getGlobalBounds().contains(
                                event.mouseButton.x, event.mouseButton.y)) {
                        difficult = 1;
                    }
                    if (middleButton.getGlobalBounds().contains(
                                event.mouseButton.x, event.mouseButton.y)) {
                        difficult = 2;
                    }
                    if (hardButton.getGlobalBounds().contains(
                                event.mouseButton.x, event.mouseButton.y)) {
                        difficult = 3;
                    }
                }
            }
        }

        window.clear();
        window.draw(bg);
        window.draw(easyButton);
        window.draw(middleButton);
        window.draw(hardButton);
        window.draw(easyButtonText);
        window.draw(middleButtonText);
        window.draw(hardButtonText);
        window.display();
        sleep(milliseconds(1000 / 60));
    }
    return difficult;
}

int callMenu(RenderWindow& window, int win)
{
    Font font;
    if (!font.loadFromFile("fonts/font.ttf")) {
        cout << "Error, fonts/font.ttf not found" << endl;
    }
    Text winText;
    winText.setFont(font);
    winText.setCharacterSize(40);
    winText.setPosition(400, 100);

    if (win == 1) {
        winText.setFillColor(Color::Green);
        winText.setString(L"Вы выиграли!");
    } else if (win == 0) {
        winText.setFillColor(Color::Red);
        winText.setString(L"Вы проиграли!");
    }
    int difficult = 0;
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
    Text startButtonText;
    startButtonText.setFont(font);
    startButtonText.setCharacterSize(40);
    startButtonText.setFillColor(Color::Black);
    startButtonText.setPosition(50, 50);
    startButtonText.setString(L"Начать игру");

    while (window.isOpen()) {
        if (difficult) {
            break;
        }
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    if (startButton.getGlobalBounds().contains(
                                event.mouseButton.x, event.mouseButton.y)) {
                        difficult = callChooseDifficultMenu(window);
                    }
                }
            }
        }

        window.clear();
        window.draw(bg);
        window.draw(startButton);
        window.draw(startButtonText);
        window.draw(wintext);
        window.display();
        sleep(milliseconds(1000 / 60));
    }
    return difficult;
}
