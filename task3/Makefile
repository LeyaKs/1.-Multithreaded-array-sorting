CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = main.c file_operations.c string_operations.c
EXE = sorting_strings

all: $(EXE)

$(EXE): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXE)

clean:
	rm -f $(EXE)