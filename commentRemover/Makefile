# Copyright 2018 Grama Nicolae

CC = gcc
CFLAGS = -lm -Wall -Wextra -std=c99
EXE = cRem
SOURCE = cRem.c

# Archive settings
ANAME = commentRemover.zip
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

# Backup the source code
backup:
	cp $(SOURCE) $(SOURCE).bkp

.PHONY:backup

# Bring back original and backup the current
redo:
	cp $(SOURCE).bkp backup
	cp $(SOURCE) $(SOURCE).bkp
	cp backup $(SOURCE)
	rm -f backup
.PHONY:redo

# Delete the executable
clean:
	rm -f $(EXE) $(SOURCE).bkp

.PHONY:clean

# Styles the code, with google's standard. The only difference is
# that it uses 4 spaces instead of two for "tabs"
beauty: 
	clang-format -i -style=file *.c

.PHONY:beauty

