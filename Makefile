CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = src/main.c src/analyzer.c
INCLUDE = include
OUTPUT = analyzer

all: $(OUTPUT)

$(OUTPUT): $(SRC)
	$(CC) $(CFLAGS) -I$(INCLUDE) $(SRC) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)