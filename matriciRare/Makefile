# Copyright 2018 Grama Nicolae

CC = gcc
CFLAGS = -lm -Wall -Wextra -std=c99
EXE = matrici
SOURCE = matrici.c

# arhiva
ANAME = exercitii.zip
ACONTENTS = Makefile *.c
AFLAGS = -FSr

# compilarea programului
build: $(SOURCE)
	$(CC) -o $(EXE) $^ $(CFLAGS)

# ruleaza programul
run: build
	./$(EXE)

# arhiveaza tema
pack:
	zip $(AFLAGS) $(ANAME) $(ACONTENTS) 
	
.PHONY:pack

# sterge executabilul
clean:
	rm -f $(EXE)

.PHONY:clean

# face coding-style automat, la standardul google, cu o mica modificare
# (4 spatii in loc de 2 la alineate)
beauty: 
	clang-format -i -style=file *.c

.PHONY:beauty
