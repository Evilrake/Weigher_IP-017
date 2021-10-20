#include <SFML/Graphics.hpp>
#include <fstream>
#include <game.h>
#include <iostream>
#include <menu.h>
#include <string>
#include <vector>

using namespace std;
using namespace sf;
vector<string> split(string line)
{
    vector<string> res;
    int last = 0;
    for (unsigned int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            res.push_back(line.substr(last, i - last));
            last = i + 1;
        }
    }
    return res;
}

int main()
{
    string easyWords[3][4];
    string middleWords[3][4];
    string hardWords[3][4];

    ifstream in("word.txt");
    string line;
    if (in.is_open()) {
        for (int i = 0; i < 3; i++) {
            getline(in, line);
            vector<string> arr;

            arr = split(line);
            for (unsigned int j = 0; j < arr.size(); j++) {
                easyWords[i][j] = arr[j];
            }
        }
        getline(in, line);
        for (int i = 0; i < 3; i++) {
            getline(in, line);
            vector<string> arr;

            arr = split(line);
            for (unsigned int j = 0; j < arr.size(); j++) {
                middleWords[i][j] = arr[j];
            }
        }
        getline(in, line);
        for (int i = 0; i < 3; i++) {
            getline(in, line);
            vector<string> arr;

            arr = split(line);
            for (unsigned int j = 0; j < arr.size(); j++) {
                hardWords[i][j] = arr[j];
            }
        }
    }

    in.close();
    srand(time(NULL));
    RenderWindow window(sf::VideoMode(1000, 600), "Weigher game");

    vector<vector<string>> words;

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
