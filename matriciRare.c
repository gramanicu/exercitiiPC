#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

// Element al matricei
typedef struct {
    int lin;
    int col;
    long int val;
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
void adaugaElement(matrix *m, int lin, int col, int val) {
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

int main() {

    return 0;
}