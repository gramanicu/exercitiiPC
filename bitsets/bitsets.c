#include <stdio.h>

char get_bit(char n, int i) {
    // Creem o masca si se face SI logic intre char si masca. Daca bitul exista, 
    //rezultatul o sa fie masca, care este evident diferita de 0. Asa ca, 
    // comparam rezultatul cu 0, pentru a intoarce doar 0 sau 1. In loc de "!=0" 
    // se putea scrie "==(1<<i)", dar ar fi presupus o operatie in plus
    return ((1 << i) & n) != 0;
}

char is_even(char n) {
    // Deoarece get bit intoarce valoarea bitului, iar un numar este par
    // doar daca ultimul bit (0) este 0, negam raspunsul intors de functie
    return !get_bit(n, 0);
}

char set_bit(char n, int i) {
    // Se creeza o masca si se efectueaza SAU logic intre ea si char
    // Rezultatul este noul char (cu al i-lea bit setat, egal cu 1)
    return n | (1 << i);
}

char unset_bit(char n, int i) {
    // Se creeza o masca si se efectueaza SI logic intre ea si char
    // Rezultatul este noul char (cu al i-lea bit resetat, egal cu 0)
    return n & (~(1 << i));
}

// Inverseaza bitii din bitset
char flip_bits(char n) { return ~n; }

// Afiseaza toti bitii din bitset
void print_bits(char n) {
    int i;
    for (i = 0; i < 8; i++) {
        printf("%d", get_bit(n, i));
    }
    printf("\n");
}

// Verifica daca numarul corespondent bitsetului o putere a lui 2
char is_power(char n) {
    int i;
    // Compara bitsetul cu toate mastile de 8 biti (puteri ale lui 2)
    for (i = 0; i < 8; i++) {
        if(n == (1 << i)) {
            return 1;
        }
    }
    return 0;
}

// Efectueaza teste pentru a testa functionalitatea
int main() {
    char a = 31;
    printf("Este par: %d\n", is_even(a));
    print_bits(a);
    a = flip_bits(a);
    print_bits(a);
    a = set_bit(a, 0);
    print_bits(a);
    a = unset_bit(a, 0);
    print_bits(a);
    printf("Este putere a lui 2: %d\n", is_power(a));
    a = flip_bits(a);
    a = unset_bit(a, 0);
    a = unset_bit(a, 2);
    a = unset_bit(a, 3);
    a = unset_bit(a, 4);
    print_bits(a);
    printf("Este putere a lui 2: %d\n", is_power(a));
    printf("Este par: %d\n", is_even(a));
    printf("Numarul : %d\n", a);

    return 0;
}
