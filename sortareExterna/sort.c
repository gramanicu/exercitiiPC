#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define numarFisereGenerate 5
typedef long int LINT;

// Functie pentru development ( testare )
void genereazaFisiere() {
    long int i;
    int j;
    FILE *out;
    for(j=0; j<numarFisereGenerate; j++) {
        char filename[20] = "fisier";
        char numar[10];
        snprintf(numar, 10, "%d", j);
        strcat(filename, numar);
        strcat(filename, ".bin");
        out = fopen(filename, "wb");
        for(i=0; i<32000; i++) {
            fwrite(&i, sizeof(LINT), 1, out);
        }
    }
}

int fileSize(char *filename) {
    FILE *in = fopen(filename, "rb");
    if (in == NULL) {
        return -1;
    }
    fseek(in, 0, SEEK_END);
    int count = ftell(in);
    fclose(in);
    return count;
}

int oneOpen(char *c, int size) {
    int i;
    for(i=0; i<size; i++) {
        if(c[i]==1) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    // genereazaFisiere();

    FILE **input = malloc(argc-2);
    char *open = calloc(argc-2, sizeof(char));

    int i;
    for(i=0; i<argc-2; i++) {
        input[i] = fopen(argv[i+1], "rb");
        if(input[i]==NULL) {
            open[i] = 0;
        } else {
            open[i] = 1;
        }
    }


    // TO DO - use a struct or multiple arrays to keep count the size & how much was read

    return 0;
}
