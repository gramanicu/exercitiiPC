#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef struct {
    int putere;
    int cuplu;
    float consum;
} motor;

typedef struct {
    char nume[30];
    char producator[30];
    motor propulsie;
    char altele[300];
} vehicul;

motor* adauga_motor(int putere, int cuplu, float consum) {
    motor *propulsie = malloc(sizeof(motor));

    (*propulsie).putere = putere;
    (*propulsie).cuplu = cuplu;
    (*propulsie).consum = consum;

    return propulsie;
}

vehicul* adauga_vehicul(char *nume, char *producator, motor *propulsie, char *altele) {
    vehicul *masina = malloc(sizeof(vehicul));

    strcat((*masina).nume, nume);
    strcat((*masina).producator, producator);
    strcat((*masina).altele, altele);

    (*masina).propulsie = *propulsie;

    return masina;
}

void print_vehicul(vehicul *masina) {
    printf("Producator %s\n", (*masina).producator);
    printf("Model %s\n", (*masina).nume);
    printf("Motor\n");
    printf("  Putere %d CP\n", (*masina).propulsie.putere);
    printf("  Cuplu %d Nm\n", (*masina).propulsie.cuplu);
    printf("  Consum %.1f l/100km\n", (*masina).propulsie.consum);
    printf("Altele %s\n", (*masina).altele);
}

vehicul* citeste_vehicul(FILE *in) {
    vehicul *masina = malloc(sizeof(vehicul));
    fread(masina, sizeof(vehicul), 1, in);
    return masina;
}

void scrie_vehicul(vehicul *masina, FILE *out) {
    fwrite(masina, sizeof(vehicul), 1, out);
}

int main() {
    FILE *in = fopen("audi_A4.bin", "rb");
    // FILE *out = fopen("audi_A4.bin", "wb");
    // scrie_vehicul(adauga_vehicul("A4", "audi", adauga_motor(300, 500, 10), ""), out);
    print_vehicul(citeste_vehicul(in));

    return 0;
}

