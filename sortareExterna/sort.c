#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define numarFisereGenerate 5
#define outputText "out.text"
typedef long int LINT;


// Functie pentru development ( testare ) - genereaza fisiere
void genereazaFisiere() {
    LINT i;
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

// Functie testare - transcrie un fiser binar intr-un fiser text
void toText(char *filename) {
    FILE *in = fopen(filename, "rb");
    FILE *out = fopen(outputText, "wt");
    int count = 1;
    LINT number;

    while(count) {
        if(!fread(&number, sizeof(LINT), 1, in)) {
            count = 0;
        } else {
            fprintf(out, "%ld ", number);
        }
    }

}

// Determina dimensiuea unui fiser binar
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

// Numara cate fisiere sunt deschise
int countOpened(char *c, int size) {
    int i;
    int open=0;
    for(i=0; i<size; i++) {
        if(c[i]==1) {
            open++;
        }
    }
    return open;
}


int main(int argc, char **argv) {
    // Genereaza fisiere binare cu numere ordonate crescator
    // genereazaFisiere();

    FILE **input = malloc(sizeof(FILE*) * (argc-2));
    char *open = calloc(argc-2, sizeof(char));
    FILE *output = fopen(argv[argc-1], "wb");

    // Deschide fisierele
    int i;
    for(i=0; i<argc-2; i++) {
        input[i] = fopen(argv[i+1], "rb");
        if(input[i]==NULL) {
            open[i] = 0;
        } else {
            open[i] = 1;
        }
    }

    int filesOpened = countOpened(open, argc-2);

    LINT *numbers = calloc(argc-2, sizeof(LINT));
    
    // Retine pozitia initiala a pointerului din fisiere, ca programul
    // sa se poata intoarce unde a fost inainte de citirea tuturor numerelor
    fpos_t *original = calloc(argc - 2, sizeof(fpos_t));
    
    // Verifica toate fisierele valabile
    while(filesOpened) {
        for(i=0; i<argc-2; i++) {
            if(open[i]) {
                // Salveaza positia intiala
                fgetpos(input[i], original+i);

                // Citeste numerele si verifica daca a ajuns la finalul fisierelor
                if(fread(numbers + i, sizeof(LINT), 1, *(input + i))) {
                    open[i] = 1;
                } else {
                    open[i] = 0;
                }
            }
        }

        // Gaseste primul fisier din care a putut citi o variabila
        int pos=0;
        for(i=0; i<argc-2; i++) {
            if(open[i]) {
                pos=i;
                break;
            }
        }

        // Gaseste cel mai mic numar citit
        for(i=1; i<argc-2; i++) {
            if(open[i]) {
                if(numbers[i] < numbers[pos]) {
                    pos = i;
                }
            }
        }

        // Intoarce restul fisierelor (cele care nu au cel mai mic numar)
        // la pozitia intiala. Astfel, va putea reciti numerele la pasul urmator
        for(i=0; i<argc-2; i++) {
            if(i!=pos) {
                if(open[i]) {
                    fsetpos(input[i], original + i);
                }
            }
        }

        // Scrie cel mai mic numar gasit in fisierul de output
        fwrite(numbers + pos, sizeof(LINT), 1, output);

        // Verifica daca mai sunt numere de citit
        filesOpened = countOpened(open, argc-2);
    }

    // Functie de testare - afiseaza toate numerele in format HR (human readable)
    // toText(argv[argc-1]);

    // Frees the memory and closes all files
    fclose(output);
    for(i=0; i<argc-2; i++) {
        fclose(input[i]);
    }

    free(numbers);
    free(input);
    free(open);

    return 0;
}
