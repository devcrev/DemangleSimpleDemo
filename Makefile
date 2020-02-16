SOURCES = main.cpp

COMPILER = g++

COMPILER_FLAGS = -Wall -std=c++17

# LINKER_FLAGS specifies the libraries we're linking against. E.g. "-lSDL2".
LINKER_FLAGS =

EXE_NAME = bin/main

.PHONY: clean run

all: $(SOURCES)
	mkdir -v --parents bin
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCES) -o $(EXE_NAME) $(LINKER_FLAGS)

clean:
	rm -f -v $(EXE_NAME)

run:
	./$(EXE_NAME)

