CC=g++
LIBS=-lGL -lglut -lGLU
OBJ=circle.cpp

circle: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)
