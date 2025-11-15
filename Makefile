CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -I include
SRC = src/main.c src/creatures.c src/joueur.c src/combat.c src/inventaire.c src/recompenses.c
OBJ = $(SRC:.c=.o)
BIN = oceandepths

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

clean:
	del src\*.o 2>nul || true

run: $(BIN)
	./$(BIN)
