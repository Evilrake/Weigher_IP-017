CXX = g++
CPPFLAGS = -Wall -Werror -MP -MMD

SRC_GAME = src/game
SRC_MENU = src/menu

OBJ_GAME = obj/src/game
OBJ_MENU = obj/src/menu

SFML_LIBS = -lsfml-window -lsfml-system -lsfml-graphics -lfreetype  
SFML_PATH = thirdparty/SFML/lib
SFML_INC = thirdparty/SFML/include
SFML_TYPE = SFML_STATIC

INCLUDE = -I $(SFML_INC) -I $(SRC_MENU) -I $(SRC_KEYBOARD)
SFML = -DSFML_STATIC $(INCLUDE) -L $(SFML_PATH) $(SFML_LIBS)

OBJECTS = $(OBJ_GAME)/main.o

bin/weigher.exe: $(OBJECTS)
	$(CXX) -o bin/weigher.exe $(OBJECTS)

$(OBJ_GAME)/main.o: $(SRC_GAME)/main.cpp
	$(CXX) $(CPPFLAGS) -c -o $(OBJ_GAME)/main.o $(SRC_GAME)/main.cpp

$(OBJ_MENU)/game.a: $(OBJ_GAME)/main.o
		ar rcs $@ $^

-include main.d