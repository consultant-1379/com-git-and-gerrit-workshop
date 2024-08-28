SRC = $(wildcard *.cc)
OBJ = $(patsubst %.cc,%.o,$(SRC))
BIN = crc32
CC = g++

all: $(BIN)

$(BIN): $(OBJ) crc32.h

.PHONY: clean
clean:
	rm -f $(BIN) $(OBJ)
