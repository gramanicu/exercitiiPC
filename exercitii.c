#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

char * strdel(char *s, int pos, int n);
char * strins(char *s1, int pos, char *s2);
int eq_mask(char *sir, char *masca);
int eqcuv(char *cuv, char **tablou);

// int main(void) {
// 	char *tablou[100] = {"curs1", "curs2", "curs3"};
// 	char *cuv1 = "curs2", *cuv2 = "curs5";
// 	printf("curs2 %s in tablou\n",(eqcuv(cuv1, tablou)) ? "este" : "nu este");
// 	printf("curs5 %s in tablou\n",(eqcuv(cuv2, tablou)) ? "este" : "nu este");	
// }

int main(int argc, char *argv[]) {
    if(argc==1) {
        exit(1);
    } else {
        
    }

    return 0;
}

int eq_mask(char *sir, char *masca) {
    int lSir, lMasca;
    lSir = strlen(sir);
    lMasca = strlen(masca);
    if(lSir != lMasca) {
        return 0;
    } else {
        int i;
        for(i=0; i<lSir; i++) {
            if(sir[i]!=masca[i] && masca[i]!='?') {
                return 0;
            } 
        }
    }
    return 1;
}