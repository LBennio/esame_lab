#include "controlli.h"

/**
 * verifica se l'input utente per la scelta in menù è un intero senza segno tra 1 e 3;
 * se l'input non è accettato, viene chiesto di riinserire il valore.
 * 
 * @pre "input" punta a scelta in menu, deve essere quindi valido.
 * @post la variabile "input" puntata contiene il valore tra 1 e 3.
 */
void controllo_scelta(unsigned int *input) {
    
    char tmp[1024] = "";
    scanf("%s", tmp);

    while(strlen(tmp) > 1 || isalpha(tmp[0] || atoi(tmp) > 3 || atoi(tmp) < 1)) {
        printf("\ninput non valido, insrire un numero tra 1 e 3: ");
        scanf("%s", tmp);
    }

    sscanf(tmp, "%u", input);
}