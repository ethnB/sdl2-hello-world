CC = g++

LINKS := -lSDL2

SRC := main.cpp

build: $(SRC)
	$(CC) $(SRC) $(INCLUDE) $(LINKS) -o main

clean:
	rm main

.PHONY: clean