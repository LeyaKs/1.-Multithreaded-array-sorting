CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = main.c quicksort.c dialogue.c
EXE = quicksort

all: $(EXE)

$(EXE): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXE)

clean:
	rm -f $(EXE)