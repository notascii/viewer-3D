CC=gcc
CFLAGS=-ansi -Wpedantic -Wall -Wextra
LDFLAGS=-lGL -lGLU -lglut -lm
EXEC=main
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $^ $(CFLAGS)

clean:
	rm -f *.o $(EXEC)

re: clean all