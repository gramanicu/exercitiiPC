#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef long int LINT;

// Element al matricei
typedef struct {
    int lin;
    int col;
    LINT val;
} element;

// Matricea rara
typedef struct {
    int count;
    element *elements;
} matrix;

// Initializare matrice si adaugarea primului element
matrix* initializareMatrice(int lin, int col, int val) {
    matrix *m = malloc(sizeof(matrix));
    m->count = 0;
    m->elements = malloc(sizeof(element));
    m->elements[m->count].col = col;
    m->elements[m->count].lin = lin;
    m->elements[m->count].val = val;
    m->count += 1;
    return m;
}

// Adauga element in matrice
void adaugaElement(matrix *m, int lin, int col,LINT val) {
    if(m->count==0) exit(1);
    m->elements = realloc(m->elements, sizeof(element)*m->count);
    m->elements[m->count].col = col;
    m->elements[m->count].lin = lin;
    m->elements[m->count].val = val;
    m->count += 1;
}

// Sterge o matrice din memorie
void stergeMatrice(matrix *m) {
    free(m->elements);
    free(m);
}

// Verifica daca elementele sunt mai mici decat numarul dat ('numar')
// Intoarce 1 daca verifica conditia, 0 daca nu
// Functie ptr punctul C
int selectieMatrice(matrix *m,LINT numar) {
    int i;
    for(i=0; i<m->count; i++) {
        if(m->elements[i].val >= numar) {
            return 0;
        }
    }

    return 1;
}


// Citeste matricele din fisierul binar
// Structura de date din fiser va fi 
// - numar de matrici 
// -- dimensiunea matricei
// -- elementele matricei
void citesteMatriceB(char *fisier) {
    FILE *file;
    file = fopen(fisier,"rb");

    // Numar de matrici
    int count;
    fread(&count, sizeof(int), 1, file);

    int i;
    // Citirea fiecarei matrici rare, pe rand
    for(i=0; i<count; i++) {
        // Numarul de elemente
        int dim;
        fread(&dim, sizeof(int), 1, file);

        matrix *m;
        int lin, col;
        LINT val;
        
        fread(&lin, sizeof(int), 1, file);
        fread(&col, sizeof(int), 1, file);
        fread(&val, sizeof(LINT), 1, file);

        m = initializareMatrice(lin, col, val);

        int j;
        for(j=1; j<dim; j++) {
            fread(&lin, sizeof(int), 1, file);
            fread(&col, sizeof(int), 1, file);
            fread(&val, sizeof(LINT), 1, file);

            adaugaElement(m, lin, col, val);
        }

        // Numarul folosit ca argument
        LINT numar;
        // Functia de selectie este folosita dupa citire (care este folosita si la 
        // punctul b, si c si d)
        selectieMatrice(m, numar);
        
        // Se scrie matricea in fiserul binar, si se retine un pointer catre finalul
        // fisierului (pentu a putea sa facem seek oricand la inceputul matricei),
        // ca sa crestem numarul de matrici (daca e nevoie)



        

    }
}


// Citeste matricile si le proceseaza, dintr-un fisier text
void citesteMatrice(char *fisier) {
    FILE *in;
    in = fopen(fisier,"rb");

    // Numar de matrici
    int count;
    fscanf(in, "%d", &count);

    int i;
    // Citirea fiecarei matrici rare, pe rand
    for(i=0; i<count; i++) {
        // Dimensiunea matricei
        int dim;
        fscanf(in, "%d", &dim);

        matrix *m;

        //......................


    }

}

int main() {
    return 0;
}