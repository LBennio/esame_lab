#include "funzioni.h"
#include "controlli.h"

/**
 * pulisce la console.
 * @pre la console deve essere in uno stato di visualizzazione.
 * @post la console è stata pulita
 */
void CleanConsole() {
    system("pause");
    system("cls");
}

/**
 * visualizza il menù principale.
 * @pre la console deve essere in uno stato di visualizzazione
 * @post la console è stata pulita
 */
void menu() {
    printf("\n<1> acquisizione\n<2> ricerca\n<3> ordinamento");

    unsigned int scelta = 0;

    controllo_scelta(&scelta);
    while(scelta > 4 && scelta < 0) {
        switch(scelta) {
            case 1:
                acquisizione();
                CleanConsole();
                break;
            case 2:
                ricerca();
                CleanConsole();
                break;
            case 3:
                CleanConsole();
                ordinamento();
                break;
            default:
                printf("\ninvalid input");
        }

    }
}

// void inizializza(int i) {
//     SetIdbyI(i);
//     SetMarcabyI(i);
//     SetRambyI(i);
//     SetPrezzobyI(i);
//     SetOSbyI(i);
//     SetPesobyI(i);
//     SetDimenbyI(i);
// }

// void inizializzaAll() {
//     if(GetNPc() < 3) {
//         puts("numero di pc disponibili non sufficiente");
//         return;
//     }

//     for(int i = 0; i < GetNPc(); i++) {
//         inizializza(i);
//     }
// }

void acquisisci() {
    puts("\ninserire il nome del file da cui acquisire i dati: ");
    char nome_file[SIZE];
    scanf("%s", nome_file);

    if(apri_file(nome_file, "r") == 0) {
        puts("impossibile acquisire da questo file");
        return;
    } else {
        puts("acquisizione in corso...");
        // inizializzaAll();
        leggi_file();

        if(GetNPc() != 0) {
            
        } else {
            puts("file vuoto");
            acquisizione();
        }
    }
    chiudi_file();
    puts("acquisizione terminata");
}

void cerca() {

}

void ordina() {

}