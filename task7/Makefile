CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = main.c file_operations.c
EXE = copy_file

all: $(EXE)

$(EXE): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXE)

clean:
	rm -f $(EXE)