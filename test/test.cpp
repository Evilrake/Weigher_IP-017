#define CATCH_CONFIG_MAIN
#include <SFML/Graphics.hpp>
#include <bg.h>
#include <catch.hpp>
#include <game.h>
#include <iostream>
#include <locale>
#include <menu.h>
#include <string>
#include <vector>

TEST_CASE("Check function", "")
{
    SECTION("Check win")
    {
        std::vector<secretSymbol> secretSymbols1;
        secretSymbol tmp;
        tmp.open = true;
        secretSymbols1.push_back(tmp);
        secretSymbols1.push_back(tmp);
        secretSymbols1.push_back(tmp);
        secretSymbols1.push_back(tmp);
        CHECK(checkWin(secretSymbols1) == 1);

        std::vector<secretSymbol> secretSymbols2;
        tmp.open = true;
        secretSymbols2.push_back(tmp);
        secretSymbols2.push_back(tmp);
        secretSymbols2.push_back(tmp);
        tmp.open = false;
        secretSymbols2.push_back(tmp);
        CHECK(checkWin(secretSymbols2) == 0);

        std::vector<secretSymbol> secretSymbols3;
        tmp.open = false;
        secretSymbols3.push_back(tmp);
        secretSymbols3.push_back(tmp);
        secretSymbols3.push_back(tmp);
        secretSymbols3.push_back(tmp);
        CHECK(checkWin(secretSymbols3) == 0);

        std::vector<secretSymbol> secretSymbols4;
        tmp.open = true;
        secretSymbols4.push_back(tmp);
        secretSymbols4.push_back(tmp);
        tmp.open = false;
        secretSymbols4.push_back(tmp);
        secretSymbols4.push_back(tmp);
        CHECK(checkWin(secretSymbols4) == 0);
        system("pause");
    }
}

TEST_CASE("Check init", "")
{
    SECTION("Check init")
    {
        std::vector<secretSymbol> a = initSecretWord("string");
        CHECK(a[0].str == "s");
        CHECK(a[1].str == "t");
        CHECK(a[2].str == "r");
        CHECK(a[3].str == "i");
        CHECK(a[4].str == "n");
        CHECK(a[5].str == "g");
        system("pause");
    }
}
