#OBJS specifies which files to compile as part of the project.
SRC = 01_hello_SDL.cpp

#CC specifies which compiler we're using.
CC = gcc

#CFLAGS specifies the additional compilation options we're using.
CFLAGS = -Wall -Werror -Wextra -pedantic

#LINKER_FLAGS specifies the libraries we're linking against.
LINKER_FLAGS = -lSDL2

NAME = 01_hello_SDL

.PHONY: all

all: $(SRC)
	$(CC) $(SRC) $(LINKER_FLAGS) -o $(NAME)
