SRC=src
BUILD=build
INC=include
LIB=lib
NAME=SimpleGame

FLAGS= -g
FLAGS+= `sdl2-config --cflags`
FLAGS+= -I${INC}
FLAGS+= -Wall -Werror

LINK= -lm `sdl2-config --libs`

CC=clang++

all: game

game:
	${CC} ${FLAGS} ${LINK} -o ${BUILD}/${NAME} ${SRC}/*.cpp 

clean:
	@rm ${BUILD}/${NAME}
