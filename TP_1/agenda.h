#ifndef AGENDA_H
#define AGENDA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compromisso.h"

typedef struct agenda{
    int id_agenda;
    char nome_professor[100];
    int ano;
    COMPROMISSO lista_eventos[100];
} AGENDA;

void criaAgenda(AGENDA *agenda, int contador_agenda, char *nome, int ano);
void insereCompromisso(AGENDA *agenda, COMPROMISSO compromisso_aux, int id_agenda_aux, int contador_compromisso);
void recuperaAgenda(AGENDA *agenda, DATA data, int contador_compromisso);
void removeCompromisso(AGENDA *agenda, int *contador_compromisso, int id);
void imprimeAgenda(AGENDA *agenda, int contador_compromisso);
int retornaNAdiamentos(AGENDA *agenda, int contador_compromisso);
int retornaNCancelamentos(AGENDA *agenda, int contador_compromisso);
int retornaNCompromissos(int contador_compromisso);
void imprimeCompromissosAdiados(AGENDA *agenda, int contador_compromisso);
void imprimeCompromissosCancelados(AGENDA *agenda, int contador_compromisso);
void resolveConflito(AGENDA *agenda, int contador_compromisso);
void imprimeCompromissosACumprir(AGENDA *agenda, int contador_compromisso);

#endif
