#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// Dimensiunea tabloului de sirurilor
#define tablou_d 100

// Dimensiunea sirurilor
// (sunt alocate ca vectori "[]" pentru a ne asigura ca inserarea e posibila)
#define cuvant_d 100

// Sterge 'n' caractere din sirul 's', la pozitia 'pos'
char * strdel(char *s, int pos, int n);

// Insereaza sirul 's2' in sirul 's1' la pozitia 'pos'
char * strins(char *s1, int pos, char *s2);

// Verifica daca sirul 'sir' verifica masca 'masca'.
// '?' poate fi inlocuit cu orice caracter (un singur caracter)
int eq_mask(char *sir, char *masca);

// Verifica daca sirul 'cuv' se regaseste in tabloul de siruri 'tablou'
// Intoarce 1 in caz pozitiv, 0 in caz negativ
int eqcuv(char *cuv, char **tablou);


int main() {
	char *tablou[tablou_d] = {"curs1", "curs2", "curs3"};
	char *cuv1 = "curs2", *cuv2 = "curs5", *cuv3 = "cars1", *cuv4 = "aur";
    char *mask = "c??s?";

	printf("'%s' %s in tablou\n",cuv1, (eqcuv(cuv1, tablou)) ? "este" : "nu este");
	printf("'%s' %s in tablou\n",cuv2, (eqcuv(cuv2, tablou)) ? "este" : "nu este");	
    printf("'%s' %s masca '%s'\n", cuv2, eq_mask(cuv2, mask) ? "verifica" : "nu verifica", mask);
    printf("'%s' %s masca '%s'\n", cuv3, eq_mask(cuv3, mask) ? "verifica" : "nu verifica", mask);
    printf("'%s' %s masca '%s'\n", cuv4, eq_mask(cuv4, mask) ? "verifica" : "nu verifica", mask);

    char ins1[cuvant_d] = "cuv1";
    char oins1[cuvant_d] = "cuv1";
    char ins2[cuvant_d] = "cuv2";
    int poz = 2;
    
    strins(ins1, poz, ins2);
    printf("'%s' inserat in '%s' pe pozitia %d este '%s'\n", ins2, oins1, poz, ins1);

    char del[cuvant_d] = "cuvinte la intamplare";
    char odel[cuvant_d] = "cuvinte la intamplare";
    poz = 7;
    int size = 4;
    strdel(del, poz, size);
    printf("%d litere sterse din '%s' la pozita %d rezulta '%s'\n", size, odel, poz, del);
}

int eq_mask(char *sir, char *masca) {
    int lSir, lMasca;
    lSir = strlen(sir);
    lMasca = strlen(masca);

    // Verifica daca cele doua siruri au aceeasi dimensiune
    if(lSir != lMasca) {
        return 0;
    } else {
        int i;

        // Verifica caracterele unul cate unul
        for(i=0; i<lSir; i++) {
            if(sir[i]!=masca[i] && masca[i]!='?') {
                return 0;
            } 
        }
    }
    return 1;
}

int eqcuv(char *cuv, char **tablou) {
    int i;
    for(i=0; i<tablou_d; i++) {
        if(cuv == tablou[i]) {
            return 1;
        }
    }
    return 0;
}

char * strins(char *s1, int pos, char *s2) {
    // Muta caractere din s1 pentru a putea insera sirul s2
    memmove(s1+pos+strlen(s2), s1+pos, strlen(s2));

    // Insereaza sirul s2 in sirul s1
    memcpy(s1+pos, s2, strlen(s2));
    return s1;
}

char * strdel(char *s, int pos, int n) {
    int size = strlen(s);

    // Muta toate caracterele de dupa "pos" spre stanga
    // pentru a ocupa zona stearsa
    memmove(s + pos , s + pos + n, size-n);

    // Se sterg caracterele nefolosite de la sfarsitul sirului
    memset(s + size - n + 1, '\0' , n - 1);
    return s;
}