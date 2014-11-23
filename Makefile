CC=g++
CFLAGS=-lglut -lGLU -lGL -std=c++11

OBJ_DIR=build

OBJ_LIST=main.o solid.o scene.o camera.o editor.o
OBJ=$(patsubst %,$(OBJ_DIR)/%,$(OBJ_LIST))

$(OBJ_DIR)/%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

build/main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 
