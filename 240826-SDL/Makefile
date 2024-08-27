#OBJS specifies which files to compile as part of the project.
SRC = 7-sdl_tutorial.c

#CC specifies which compiler we're using.
CC = gcc

#CFLAGS specifies the additional compilation options we're using.
CFLAGS = -Wall -Werror -Wextra -pedantic

#LINKER_FLAGS specifies the libraries we're linking against.
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

NAME = sdl_tutorial

.PHONY: all debug

all: $(SRC)
	$(CC) $(SRC) $(LINKER_FLAGS) -o $(NAME)


debug: $(SRC)
	$(CC) $(SRC) -g $(LINKER_FLAGS) -o $(NAME)
