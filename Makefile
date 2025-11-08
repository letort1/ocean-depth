CC = gcc
CFLAGS = -std=c99 -Wall -Wextra
SRC = src/main.c src/creatures.c src/joueur.c src/combat.c
OBJ = $(SRC:.c=.o)
BIN = oceandepths

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

clean:
	del src\*.o 2>nul || true

run: $(BIN)
	./$(BIN)
