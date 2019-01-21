// Grama Nicolae, 2019
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#define AUX_FILE "aux"

// Finds the number of characters
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

void overwrite_source(char *filename) {
    // Replaces the original file with the auxiliar one and deletes the comments
    int size = char_count(AUX_FILE);
    FILE *in = fopen(AUX_FILE, "rt");
    FILE *out = fopen(filename, "wt");
    char c;
    int i;

    for (i = 0; i < size; i++) {
        fscanf(in, "%c", &c);
        fprintf(out, "%c", c);
    }

    fclose(in);
    fclose(out);
    remove(AUX_FILE);
}

/*
    This function will search for comments in a given file,
    remove them (inline and block comments), write the intermediary
    result to another file, and then overwrite the original with
    the comments of the auxiliar one (the one with no comments).
    At the end, it deletes the auxiliar file
*/
void delete_Comments(char *filename) {
    int size = char_count(filename);
    if (size == -1) {
        return;
    }
    int lineDel = 0;
    int blockDel = 0;
    int printed = 0;

    FILE *in = fopen(filename, "rt");
    FILE *out = fopen(AUX_FILE, "wt");
    int i = 0;
    for (i = 0; i < size; i++) {
        printed = 0;
        char c1, c2;
        fscanf(in, "%c", &c1);
        if (c1 == '/') {
            fscanf(in, "%c", &c2);
            i++;
            if (!lineDel && !blockDel) {
                if (c1 == c2) {
                    lineDel = 1;
                } else if (c2 == '*') {
                    blockDel = 1;
                } else {
                    fprintf(out, "%c", c1);
                    fprintf(out, "%c", c2);
                    printed = 1;
                }
            }
        } else if (c1 == '\n') {
            lineDel = 0;
        } else if (c1 == '*') {
            if (blockDel) {
                fscanf(in, "%c", &c2);
                i++;
                if (c2 == '/') {
                    blockDel = 0;
                } else {
                    fprintf(out, "%c", c1);
                    fprintf(out, "%c", c2);
                    printed = 1;
                }
            }
        }

        if (!lineDel && !blockDel && !printed) {
            fprintf(out, "%c", c1);
        }
    }

    fclose(in);
    fclose(out);

    overwrite_source(filename);
}

// The main function
int main(int argc, char **argv) {
    if (argc == 1) {
        char *name = malloc(strlen(argv[0]) + strlen(".c"));
        memcpy(name, argv[0], strlen(argv[0]));
        memcpy(name + strlen(argv[0]), ".c", strlen(".c"));

        delete_Comments(name);
    } else {
        delete_Comments(argv[1]);
    }

    return 0;
}
