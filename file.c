#include "file.h"

FILE *fp;

/**
 * apre un file con il nome e la modalità specificata e resituisce 1 se il file è stato aperto e 0 in caso contrario.
 * @pre 'nome_file' deve essere una stringa valida, così come 'modo'.
 * @post se il file non è stato aperto correttamente, viene restituito un messaggio di errore.
 */
int apri_file(char *nome_file, char *modo) {
    fp = fopen(nome_file, modo);
    
    if(fp == NULL) {
        perror("impossibile aprire il file\n");
        return 0;
    } else {
        return 1;
    }
}

/**
 * chiude il file attualmente aperto.
 * @pre il file deve essere aperto.
 * @post il file è chiuso.
 */
void chiudi_file() {
    fclose(fp);
}

void leggi_file() {
    char verificatore[BIG];
    unsigned int contatore;
    int j = 0;
    if(GetNPc() != 0) {
        contatore = GetNPc();
    } else {
        contatore = 0;
    }

    while(!eof(fp)) {
        if(contatore < 0 || contatore > SIZE) {
            pust("impossibile proseguire");
            return;
        }

        verificatore[j] = fgetc(fp);

        if((verificatore[j] == '\n' || verificatore[j] == EOF) && strlen(verificatore > 2)) {
            verificatore[j] = '\0';

            if(EnpersendSuFile(verificatore)) {
                tokenator(verificatore, &contatore);
                strcpy(verificatore, "");
                contatore++;
                j = -1;
            } else {
                j = -1;
            }
        } else if(verificatore[0] == '\n') {
            strcpy(verificatore, "");
            j = -1;
        } 
        j++;
    }

    puts("****************************************************************************************");
    printf("caricamento completato...\n");   
}

void tokenator(char *frase, unsigned int *i) {
    i_tokenator(*i);
    char *token = NULL;
    int controllore = 0;
    int ID;
    char marca[SIZE];
    int RAM;
    float prezzo;
    char OS[SIZE];
    float peso;
    int dimensioneSchermo;

    token = strtok(frase, "&");
    ID = atoi(token);

    if(controllo_vuota(ID, "ID")) {
        puts("--------------------------------");
        printf("ID non presente all'indice %d\n", *i+1);
        --*i;

        system("pause");
        return;
    }

    token = strtok(NULL, "&");
    strcpy(marca, token);

    if(controllo_vuota(marca, "marca")) {
        puts("--------------------------------");
        printf("marca non presente all'indice %d", *i+1);
        --*i;
        system("pause");
        return;
    }

    token = strtok(NULL, "&");
    RAM = atoi(token);
    
    if(controllo_vuota(RAM, "RAM")) {
        puts("-------------------------------");
        printf("RAM non presente all'indice %d", *i+1);
        --*i;
        system("pause");
        return;
    }

    token = strtok(NULL, "&");
    prezzo = atof(token);
    
    if(controllo_vuota(prezzo, "prezzo")) {
        puts("-------------------------------");
        printf("prezzo non presente all'indice %d", *i+1);
        --*i;
        system("pause");
        return;
    }

    
    token = strtok(NULL, "&");
    strcpy(OS, token);
    
    if(controllo_vuota(OS, "OS")) {
        puts("-------------------------------");
        printf("OS non presente all'indice %d", *i+1);
        --*i;
        system("pause");
        return;
    }
    
    token = strtok(NULL, "&");
    peso = atof(token);
    
    if(controllo_vuota(peso, "peso")) {
        puts("-------------------------------");
        printf("peso non presente all'indice %d", *i+1);
        --*i;
        system("pause");
        return;
    }
    
    token = strtok(NULL, "&");
    dimensioneSchermo = atoi(token);
    
    if(controllo_vuota(dimensioneSchermo, "dimensioneSchermo")) {
        puts("-------------------------------");
        printf("dimensione schermo non presente all'indice %d", *i+1);
        --*i;
        system("pause");
        return;
    }

    if(!controllo_atoi(ID) || !controllo_marca(marca) || !controllo_atof(prezzo) || controllo_atoi(RAM) || controllo_OS(OS) || !controllo_atof(peso) || controllo_atoi(dimensioneSchermo)) {
        controllore = 1;
    }
}