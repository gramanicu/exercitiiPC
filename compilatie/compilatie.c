#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

// Dimensiunea maxima a numelui fisierului
#define NAMESIZE 50

// Afla dimensiunea unui fisier (in bytes/caractere)
int dimensiuneFisier(char *nume) {
    FILE *in = fopen(nume, "rt");

    fseek(in, 0, SEEK_END);
    int pos = ftell(in);
    fclose(in);
    return pos;
}

// Citeste fragmentul din fiserul sursa si il adauga in compilatie
void citireFragment(char *sursa, int start, int lines, FILE *dest) {
    FILE *in = fopen(sursa, "rt");
    int lc = 1, i;
    char c;

    for (i = 0; i < dimensiuneFisier(sursa); i++) {
        fscanf(in, "%c", &c);
        // Verifica daca linia curenta exista se afla in fragmentul cerut
        if (lc >= start && lc < start + lines) {
            fprintf(dest, "%c", c);
        }
        if (c == '\n') {
            lc++;
        }
    }
}

// Verifica daca un sir de caractere exista deja in vectorul de stringuri
int dejaExistent(char **vector, char *c, int size) {
    int i;
    for(i = 0; i < size; i++) {
        if(!strcmp(vector[i], c)) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    //Adauga extensia .cpl numelui de fiser dat ca argument
    char *outName = calloc(strlen(argv[1]) + strlen(".cpl"), sizeof(char));
    strcat(outName, argv[1]);
    strcat(outName, ".cpl");

    FILE *in = fopen(argv[1], "rt");
    FILE *out = fopen(outName, "wt");

    // Vector de caractere in care se salveaza temporar numele de fiser citit din catalog
    char *filename = calloc(NAMESIZE, sizeof(char));

    // Vector de pointeri in care se salveaza numele fisierelor deja citite
    char **fisiere = calloc(argc, sizeof(char*));
    int start, lines, nr_fisiere = 0;

    // Citirea datelor din catalog
    fscanf(in, "%s %d %d", filename, &start, &lines);
    while (!feof(in)) {
        // Verifica daca fisierul din catalog a mai fost "cerut" o data
        if(!dejaExistent(fisiere, filename, nr_fisiere)) {
            fisiere[nr_fisiere] = calloc(strlen(filename), sizeof(char));
            strcat(fisiere[nr_fisiere], filename);
            nr_fisiere++;
        }
        
        // Citeste fragmentul din folderul "cerut"
        citireFragment(filename, start, lines, out);

        // Citeste urmatoarele date (si afla daca mai exista)
        fscanf(in, "%s %d %d", filename, &start, &lines);
    }

    // Afiseaza numarul total de fisiere
    printf("%d\n", nr_fisiere);

    return 0;
}
