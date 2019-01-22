# Copyright 2018 Grama Nicolae

CC = gcc
CFLAGS = -lm -Wall -Wextra -std=c99
EXE = bitsets
SOURCE = bitsets.c

# Archive settings
ANAME = bitsets.zip
ACONTENTS = README Makefile *.c *.h
AFLAGS = -FSr 

# Compile the program
build: $(SOURCE)
		$(CC) -o $(EXE) $^ $(CFLAGS)

# Build & run
run: build
		./$(EXE)

# Archive the files
pack:
	zip $(AFLAGS) $(ANAME) $(ACONTENTS) 
	
.PHONY:pack

# Delete the executable
clean:
	rm -f $(EXE)

.PHONY:clean

# Styles the code, with google's standard. The only difference is
# that it uses 4 spaces instead of two for "tabs"
beauty: 
	clang-format -i -style=file *.c

.PHONY:beauty

