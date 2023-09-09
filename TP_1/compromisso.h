#ifndef COMPROMISSO_H
#define COMPROMISSO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct data {
    int dia;
    int mes;
    int ano;
} DATA;

typedef struct hora {
    int hora;
    int minutos;
} HORA;

typedef enum tipo_compromisso {
    _ORIENTACAO = 1,
    _AULA,
    _COMPROMISSO_PARTICULAR,
    _EVENTO,
    _REUNIAO
} TIPO_COMPROMISSO;

typedef enum status_compromisso {
    A_SER_CUMPRIDO = 1,
    ADIADO,
    CANCELADO
} STATUS_COMPROMISSO;

typedef struct compromisso {
    int id_compromisso;
    TIPO_COMPROMISSO tipo_compromisso;
    int prioridade;
    bool adiavel;
    STATUS_COMPROMISSO status_compromisso;
    DATA data;
    HORA hora;
    int duracao;
    char nome[100];
} COMPROMISSO;


COMPROMISSO inicializaCompromisso(COMPROMISSO compromisso, int contador_compromisso, TIPO_COMPROMISSO tipo_compromisso, DATA data, HORA hora, int duracao, char *nome);

void alteraPrioridade(COMPROMISSO *compromisso, int novaPri);

int retornaPrioridade(COMPROMISSO *compromisso);

void eAdiavel(COMPROMISSO *compromisso, bool flag);

void atribuiStatus(COMPROMISSO *compromisso, STATUS_COMPROMISSO flag);

void retornaStatus(COMPROMISSO *compromisso);

void imprimeCompromisso(COMPROMISSO *compromisso);

int temConflito(COMPROMISSO *compromisso1, COMPROMISSO *compromisso2);

#endif
