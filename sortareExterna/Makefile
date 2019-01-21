# Copyright 2018 Grama Nicolae

CC = gcc
CFLAGS = -lm -Wall -Wextra -std=c99
EXE = sort
SOURCE = sort.c

# Archive settings
ANAME = sortareExterna.zip
ACONTENTS = README Makefile *.c *.h
AFLAGS = -FSr 

# Compile the program
build: $(SOURCE)
		$(CC) -o $(EXE) $^ $(CFLAGS)

# Build & run
run: build
		./$(EXE) fisier0.bin fisier1.bin fisier2.bin fisier3.bin fisier4.bin out.bin 

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

