CC = gcc
CFLAGS = `sdl2-config --cflags` -D_REENTRANT -g
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lSDL2_gfx -lSDL2

SRC = src/main.c src/map.c src/event_handling.c src/element_logic.c
OBJ = $(SRC:.c=.o)
EXEC = game

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
re:
	make clean
	make all

.PHONY: all clean re
