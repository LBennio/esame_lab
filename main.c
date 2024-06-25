#include "funzioni.h"

/**
 * 
 * punto di ingresso del programma, mostra il menu.
 * @return 0 se il programma termina correttamente.
 */
int main() {
    menu();

    return 0;
}

/**
 * consente all'utente di acquisire dati da un file da lui chiamato da tastiera.
 * @pre l'utente deve aver selezionato 1 da menù.
 * @post la funzione continuerà finché non sono stati acquisiti dei dati e finché il file selezionato non è valido
 */
void acquisizione() {
    if(GetFlagPc() == 0) {
        acquisisci();
    } else {
        printf("\ngià in fase di acquisizione");
    }
}

void ricerca() {

}

void ordinamento() {

}