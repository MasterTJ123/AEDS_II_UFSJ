#ifndef ARVORE_BINARIA_NAO_BALANCEADA_H
#define ARVORE_BINARIA_NAO_BALANCEADA_H

#include <stdio.h>
#include <stdlib.h>

typedef long Chave;

typedef struct Registro{
    Chave chave;
} REGISTRO;

typedef struct No* Apontador;

typedef struct No {
REGISTRO registro;
Apontador esquerda, direita;
} NO;

typedef Apontador Dicionario;

Dicionario* inicializar_arvore_binaria_nao_balanceada(Dicionario* dicionario_arvore);
int inserir_arvore_binaria_nao_balanceada(Dicionario* dicionario_arvore, Chave chave);
int remove_arvore_binaria_nao_balanceada(Dicionario* dicionario_arvore, Chave chave);
Apontador remove_no_atual_arvore_binaria_nao_balanceada(Apontador no_atual);
int pesquisa_arvore_binaria_nao_balanceada(Dicionario* dicionario_arvore, Chave chave);

#endif
