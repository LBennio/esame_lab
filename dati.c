#include "dati.h"

struct PC {
    int ID;
    char marca[SIZE];
    int RAM;
    float prezzo;
    char OS[SIZE];
    float peso;
    int dimensioneSchermo;
};

int Flag;
unsigned int NumeroPc;

/**
 * restituisce il valore del flag dei Pc.
 * @pre non ci sono precondizioni.
 * @post restituisce il valore del flag.
 */
int GetFlagPc() {
    return Flag;
}

unsigned int GetNPc() {
    return NumeroPc;
}

// void SetIdbyI(int i) {

// }

// void SetMarcabyI(int i) {

// }

// void SetRambyI(int i) {

// }