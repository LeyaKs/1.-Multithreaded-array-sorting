CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = main.c output_info.c
EXE = file_info

all: $(EXE)

$(EXE): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXE)

clean:
	rm -f $(EXE)