#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include "controlli.h"

/**
 * apre un file con il nome e la modalità specificata, resituendo il puntatore al file.
 * 
 * @param[in] nome_file il nome del file da aprire.
 * @param[in] modo la modalità di apertura del file.
 * @return il puntatore al file aperto, NULL in caso di errore.
 */
int apri_file(char *nome_file, char *modo);

/**
 * choide il file attualmente aperto
 */
void chiudi_file();

#endif // FILE_H_INCLUDED