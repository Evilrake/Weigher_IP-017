#include <SFML/Graphics.hpp>
#include <bg.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

struct keyboardSymbol {
    RectangleShape shape;
    string str;
    string folder;
};

struct secretSymbol {
    string str;
    bool open;
};

vector<secretSymbol> initSecretWord(string word)
{
    vector<secretSymbol> secretSymbols;
    for (unsigned int i = 0; i < word.size(); i++) {
        secretSymbol currentSecretSymbol;
        currentSecretSymbol.str = word[i];
        currentSecretSymbol.open = true;
        secretSymbols.push_back(currentSecretSymbol);
    }
    return secretSymbols;
}

void drawSecretSymbols(RenderWindow& window, vector<secretSymbol> secretSymbols)
{
    RectangleShape underline;
    underline.setFillColor(Color(80, 130, 255));
    underline.setSize(Vector2f(30, 3));

    Font font;
    if (!font.loadFromFile("fonts/font.ttf")) {
        cout << "Error, fonts/font.ttf not found" << endl;
    }
    Text symbol;
    symbol.setFont(font);
    symbol.setCharacterSize(25);
    symbol.setFillColor(Color::Black);

    for (unsigned int i = 0; i < secretSymbols.size(); i++) {
        underline.setPosition(Vector2f(600 + i * 50, 200));
        if (secretSymbols[i].open) {
            symbol.setPosition(Vector2f(605 + i * 50, 170));
            symbol.setString(secretSymbols[i].str);
            window.draw(symbol);
        }
        window.draw(underline);
    }
}

void drawWeigher(RenderWindow& window, int step)
{
    int x = 100;
    int y = 100;
    RectangleShape currentShape;
    currentShape.setFillColor(Color(80, 130, 255));
    CircleShape currentCircleShape;
    currentCircleShape.setOutlineColor(Color(80, 130, 255));
    currentCircleShape.setFillColor(Color(0, 0, 0, 0));
    currentCircleShape.setOutlineThickness(10);
    if (step >= 1) {
        currentShape.setPosition(Vector2f(x, y));
        currentShape.setSize(Vector2f(10, 300));
        currentShape.setRotation(0);
        window.draw(currentShape);
    }
    if (step >= 2) {
        currentShape.setPosition(Vector2f(x, y));
        currentShape.setSize(Vector2f(200, 10));
        currentShape.setRotation(0);
        window.draw(currentShape);
    }
    if (step >= 3) {
        currentShape.setPosition(Vector2f(x + 45, y + 10));
        currentShape.setSize(Vector2f(10, 50));
        currentShape.setRotation(45);
        window.draw(currentShape);
    }
    if (step >= 4) {
        currentShape.setPosition(Vector2f(x - 40, y + 300));
        currentShape.setSize(Vector2f(100, 10));
        currentShape.setRotation(0);
        window.draw(currentShape);
    }
    if (step >= 5) {
        currentShape.setPosition(Vector2f(x + 195, y));
        currentShape.setSize(Vector2f(10, 50));
        currentShape.setRotation(0);
        window.draw(currentShape);
    }
    if (step >= 6) {
        currentCircleShape.setPosition(Vector2f(x + 175, y + 50));
        currentCircleShape.setRadius(25);
        window.draw(currentCircleShape);
    }
    if (step >= 7) {
        currentCircleShape.setPosition(Vector2f(x + 150, y + 115));
        currentCircleShape.setRadius(50);
        window.draw(currentCircleShape);
    }
    if (step >= 8) {
        currentShape.setPosition(Vector2f(x + 280, y + 100));
        currentShape.setSize(Vector2f(50, 10));
        currentShape.setRotation(150);
        window.draw(currentShape);
    }
    if (step >= 9) {
        currentShape.setPosition(Vector2f(x + 120, y + 90));
        currentShape.setSize(Vector2f(50, 10));
        currentShape.setRotation(40);
        window.draw(currentShape);
    }
    if (step >= 10) {
        currentShape.setPosition(Vector2f(x + 240, y + 200));
        currentShape.setSize(Vector2f(70, 10));
        currentShape.setRotation(40);
        window.draw(currentShape);
    }
    if (step >= 11) {
        currentShape.setPosition(Vector2f(x + 170, y + 210));
        currentShape.setSize(Vector2f(70, 10));
        currentShape.setRotation(150);
        window.draw(currentShape);
    }
}

void checkClick(vector<keyboardSymbol> keyboardSymbols, int x, int y)
{
    for (unsigned int i = 0; i < keyboardSymbols.size(); i++) {
        if (keyboardSymbols[i].shape.getGlobalBounds().contains(x, y)) {
            cout << keyboardSymbols[i].str;
        }
    }
}

void drawKeyboard(RenderWindow& window, vector<keyboardSymbol>& keyboardSymbols)
{
    for (unsigned int i = 0; i < keyboardSymbols.size(); i++) {
        Texture texture;
        if (!texture.loadFromFile(keyboardSymbols[i].folder)) {
            cout << "Error, " + keyboardSymbols[i].folder + " not found";
        }
        keyboardSymbols[i].shape.setTexture(&texture);
        window.draw(keyboardSymbols[i].shape);
    }
}

void initKeyboard(vector<keyboardSymbol>& keyboardSymbols)
{
    string symbols[33]
            = {"à", "á", "â", "ã", "ä", "å", "¸", "æ", "ç", "è", "é",
               "ê", "ë", "ì", "í", "î", "ï", "ð", "ñ", "ò", "ó", "ô",
               "õ", "ö", "÷", "ø", "ù", "ú", "û", "ü", "ý", "þ", "ÿ"};
    for (int i = 0; i < 33; i++) {
        keyboardSymbol currentSymbol;
        currentSymbol.str = symbols[i];

        currentSymbol.folder = "images/" + to_string(i + 1) + ".png";
        RectangleShape currentShape;

        currentShape.setSize(Vector2f(50, 50));
        currentShape.setPosition(
                Vector2f((i % 10) * 60 + 100, 100 + (i / 10 * 100)));
        currentSymbol.shape = currentShape;
        keyboardSymbols.push_back(currentSymbol);
    }
}

string getRandomWord(string (&words)[3][4], string& theme)
{
    int a = rand() % 3;
    theme = words[a][0];
    return words[a][rand() % 3 + 1];
}

void startGame(RenderWindow& window, string (&words)[3][4])
{
    setlocale(LC_ALL, "Russian");
    vector<keyboardSymbol> keyboardSymbols;
    initKeyboard(keyboardSymbols);

    string theme;
    string word = getRandomWord(words, theme);
    vector<secretSymbol> secretSymbols = initSecretWord(word);
    int step = 12;

    // bg
    Texture texture;
    if (!texture.loadFromFile("images/bg.jpg")) {
        cout << "Error, images/bg.jpg not found" << endl;
    }
    RectangleShape bg = initBg(window);
    bg.setTexture(&texture);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    checkClick(
                            keyboardSymbols,
                            event.mouseButton.x,
                            event.mouseButton.y);
                }
            }
        }

        window.clear();
        window.draw(bg);
        // drawKeyboard(window, keyboardSymbols);
        drawSecretSymbols(window, secretSymbols);
        drawWeigher(window, step);
        window.display();
        sleep(milliseconds(1000 / 60));
    }
}
