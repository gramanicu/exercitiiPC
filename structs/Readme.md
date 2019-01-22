# Observati

Aparent nu e chiar asa usor sa scrii un struct complex (cu date alocate dinamic) direct intr-un fiser binar. Cel mai probabil, ori nu sunt scrise date, ori sunt scrise adresele datelor (sirurilor de caractere, de exemplu).

Din acest motiv, toate sirurile de caractere sunt alocate static, pentru a simplifica scrierea si forta fwrite sa scrie valorile, nu pointeri. Asta ajuta si la citire, deoarece programul v-a stii cu exacitate dimensiunea structurilor.