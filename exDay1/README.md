# Exercitii pentru examenul de PC

- Să se scrie o funcţie pentru ştergerea (eliminarea) a n caractere dintr-o poziţie dată a unui şir ce returnează adresa șirului de caractere modificat
  - `char * strdel(char *s, int pos, int n)` - Sterge 'n' caractere din sirul 's', la pozitia 'pos' 

- Să se scrie o funcţie pentru inserarea unui şir s2 într-o poziţie dată pos dintr-un şir s1. Se va presupune că există suficient loc în vectorul lui s1 pentru a face loc şirului s2. Funcţia returnează adresa şirului s1.
  - `char * strins(char *s1, int pos, char *s2)` - Insereaza sirul 's2' in sirul 's1' la pozitia 'pos'

- Scrieţi o funcţie care stabileşte dacă un şir dat (format din caractere alfanumerice) este egal cu o mască, ce poate conţine caractere alfanumerice şi caracterul special '?'. Se consideră că acest caracter înlocuieşte orice alt caracter alfanumeric. De exemplu, “abcde” este echivalent cu ”?bc?e”.
  - `int eq_mask(char *sir, char *masca)` - Verifica daca sirul 'sir' verifica masca 'masca'. '?' poate fi inlocuit cu orice caracter (un singur caracter). Intoarce 1 in caz pozitiv, 0 in caz negativ


- Scrieţi o funcţie care stabileşte dacă un cuvânt dat se găseşte sau nu într-un tablou de cuvinte.
  - `int eqcuv(char *cuv, char **tablou)` - Verifica daca sirul 'cuv' se regaseste in tabloul de siruri 'tablou'. Intoarce 1 in caz pozitiv, 0 in caz negativ

