CC=gcc
CFLAGS=-Wall
LDFLAGS=-lGLEW -lglfw3 -lGL -ldl -pthread -lGL -lX11 -lm

.PHONY: all
all: main

.PHONY: clean
clean:
	${RM} *.o main

OBJECTS=main.o
main: ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} -o main ${LDFLAGS}