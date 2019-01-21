# Comment Remover

This is a C program that will remove comments from its source code. 

# Usage

## Makefile

The makefile includes two important functions, needed because of the nature of the application.
1. backup - makes a copy of the source code
2. redo - switches the copy of the source code with the original. Can be called for an ulimited number of times.

## Code

The application supports 1 argument, called "source". This will specify the path to the C code that needs to be "uncommented". If it's run without any argument, it will uncomment its own source code.

# cRem.c


`#define AUX_FILE "aux"` - this is a macro with the auxiliary filename 

__int char_count(char *filename)__ - returns the number of chars in a file, or -1, if the file doesn't exist

```c
int char_count(char *filename) {
    FILE *in = fopen(filename, "rt");
    if (in == NULL) {
        return -1;
    }
    fseek(in, 0, SEEK_END);
    int count = ftell(in);
    fclose(in);
    return count;
}
```

> The function opens the file (and checks if it succeded), jumps to the end of the file and stores in the variable `count` the position (wich represents also the number of characters). Then, it closes the file and returns `count`

__void overwrite_source(char *filename)__ - moves the content of the auxiliar file (uncommented code) over the original code

> It opens the files then finds the length of the auxiliary file
```c
    for (i = 0; i < size; i++) {
        fscanf(in, "%c", &c);
        fprintf(out, "%c", c);
    }
```
> Then it reads all chars in a file and puts them in the other one. At the end, it closes
the files & deletes the auxiliary file.
```c
    remove(AUX_FILE);
```
___
__void delete_Comments(char *filename)__ - This function will search for comments in a given file removes them (inline and block comments) & write the intermediary result to another file

### Search algorithm
- If it ecounters a '/', it will read the next character :
    1. If it is a '/', it is a inline comment
    2. If it is a '*', it is a block comment
    3. Else, it's not a comment, so it will write it

- If it encounter a '*' (after a block has started), it will read the next character :
    1. If it is a '/', the block comment has ended
    2. Else, it is still in a block comment, so the chars are ignored

- If it encounters a newline & a inline comment is started, the inline comment has ended

© 2019 Grama Nicolae