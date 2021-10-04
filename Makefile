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
INCLUDE = -I $(SFML_INC) -I $(SRC_MENU) -I $(SRC_GAME)
SFML = -DSFML_STATIC $(INCLUDE) -L $(SFML_PATH) $(SFML_LIBS)

OBJECTS = $(OBJ_GAME)/main.o $(OBJ_GAME)/bg.o

bin/weigher.exe: $(OBJECTS)
	$(CXX) -o bin/weigher.exe $(OBJECTS) $(SFML)

$(OBJ_GAME)/main.o: $(SRC_GAME)/main.cpp
	$(CXX) $(CPPFLAGS) -c -o $(OBJ_GAME)/main.o $(SRC_GAME)/main.cpp $(SFML)

$(OBJ_GAME)/bg.o: $(SRC_GAME)/bg.cpp
	$(CXX) $(CPPFLAGS) -c -o $(OBJ_GAME)/bg.o $(SRC_GAME)/bg.cpp $(SFML)

$(OBJ_MENU)/game.a: $(OBJ_GAME)/main.o $(OBJ_GAME)/bg.o
	ar rcs $@ $^

-include main.d bg.d