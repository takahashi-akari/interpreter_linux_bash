CC            = gcc
CFLAGS        = 
DEST 		= ./
SRC 		= ./interpreter_linux_bash.c
OBJ 		= ./interpreter_linux_bash.o
PROGRAM 	= ./interpreter_linux_bash

all: $(PROGRAM)

$(PROGRAM): $(OBJ)
	$(CC) $(OBJ) -o $(PROGRAM)

clean:
	rm -f $(PROGRAM) $(OBJ)
