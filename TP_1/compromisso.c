#include "compromisso.h"

COMPROMISSO inicializaCompromisso(COMPROMISSO compromisso, int contador_compromisso, TIPO_COMPROMISSO tipo_compromisso, DATA data, HORA hora, int duracao, char *nome){
    compromisso.data = data;
    compromisso.hora = hora;
    compromisso.duracao = duracao;
    strcpy(compromisso.nome, nome);
    compromisso.status_compromisso = A_SER_CUMPRIDO;
    compromisso.adiavel = false;
    compromisso.tipo_compromisso = tipo_compromisso;
    compromisso.prioridade = tipo_compromisso;
    compromisso.id_compromisso = contador_compromisso + 1;
    return compromisso;
}

void alteraPrioridade(COMPROMISSO *compromisso, int novaPri){
    compromisso->prioridade = novaPri;
}

int retornaPrioridade(COMPROMISSO *compromisso){
    return compromisso->prioridade;
}

void eAdiavel(COMPROMISSO *compromisso, bool flag){
    if((compromisso->tipo_compromisso == _AULA) || (compromisso->tipo_compromisso == _EVENTO)){
        printf("\nErro! Nao e possivel tornar uma aula ou um evento adiavel!\n\n");
    } else {
        compromisso->adiavel = flag;
            if(flag == 1){
                printf("\nSucesso! O compromisso agora e adiavel!\n\n");
            } else {
                printf("\nSucesso! O compromisso agora nao e adiavel!\n\n");
            }
    }
    system("pause");
}

int temConflito(COMPROMISSO *compromisso1, COMPROMISSO *compromisso2) {

    int aux_duracao_1 = compromisso1->hora.hora + compromisso1->duracao;
    int aux_duracao_2 = compromisso2->hora.hora + compromisso2->duracao;

    if((compromisso1->data.ano == compromisso2->data.ano) && (compromisso1->data.mes == compromisso2->data.mes) && (compromisso1->data.dia == compromisso2->data.dia)) {

        if(compromisso2->hora.hora > compromisso1->hora.hora && compromisso2->hora.hora < aux_duracao_1) {
            return 1;
        } else if (compromisso1->hora.hora > compromisso2->hora.hora && compromisso1->hora.hora < aux_duracao_2) {
            return 1;
        } else {
            return 0;
        }

    } else if((compromisso1->data.dia == compromisso2->data.dia) &&
            (compromisso1->data.mes == compromisso2->data.mes) &&
            (compromisso1->data.ano == compromisso2->data.ano) &&
            (compromisso1->hora.hora == compromisso2->hora.hora) &&
            (compromisso1->hora.minutos == compromisso2->hora.minutos)) {
        return 1;
    } else {
        return 0;
    }
}

void atribuiStatus(COMPROMISSO *compromisso, STATUS_COMPROMISSO flag){
    if(((compromisso->tipo_compromisso == _AULA) && (flag == ADIADO)) || ((compromisso->tipo_compromisso == _EVENTO) && (flag == ADIADO))){
        printf("\nErro! Uma aula ou um evento nao podem ser adiados!\n\n");
    } else if ((compromisso->adiavel == 0) && (flag == ADIADO)){
        printf("\nErro! Esse compromisso nao e adiavel! Voce precisa mudar o valor do campo adiavel primeiro!");
    } else {
        compromisso->status_compromisso = flag;
        printf("\nSucesso! O status atual desse compromisso e ");
        retornaStatus(compromisso);
        printf("\n\n");
    }
}

void retornaStatus(COMPROMISSO *compromisso) {
    switch(compromisso->status_compromisso) {
        case A_SER_CUMPRIDO:
            printf("A SER CUMPRIDO");
            break;
        case ADIADO:
            printf("ADIADO");
            break;
        case CANCELADO:
            printf("CANCELADO");
            break;
    }
}

void imprimeCompromisso(COMPROMISSO *compromisso){
    printf("Id: %d\nNome: %s\nData: %02d/%02d/%d\nHora: %02d:%02d\n", compromisso->id_compromisso,
                                                                                compromisso->nome,
                                                                                compromisso->data.dia,
                                                                                compromisso->data.mes,
                                                                                compromisso->data.ano,
                                                                                compromisso->hora.hora,
                                                                                compromisso->hora.minutos);
        if(compromisso->tipo_compromisso == _EVENTO){
            printf("Duracao: %d dias\n", compromisso->duracao);
        } else {
            printf("Duracao: %d horas\n", compromisso->duracao);
        }
        printf("Prioridade: %d\n", compromisso->prioridade);
        switch((int)compromisso->adiavel){
            case 0:
                printf("Adiavel: Nao e adiavel\n");
                break;
            case 1:
                printf("Adiavel E adiavel\n");
                break;
        }
        switch(compromisso->tipo_compromisso){
            case _ORIENTACAO:
                printf("Tipo de compromisso: Orientacao\n");
                break;
            case _AULA:
                printf("Tipo de compromisso: Aula\n");
                break;
            case _COMPROMISSO_PARTICULAR:
                printf("Tipo de compromisso: Compromisso particular\n");
                break;
            case _EVENTO:
                printf("Tipo de compromisso: Evento\n");
                break;
            case _REUNIAO:
                printf("Tipo de compromisso: Reuniao\n");
                break;
        }
        switch(compromisso->status_compromisso){
            case A_SER_CUMPRIDO:
                printf("Status do compromisso: A ser cumprido\n\n");
                break;
            case ADIADO:
                printf("Status do compromisso: Adiado\n\n");
                break;
            case CANCELADO:
                printf("Status do compromisso: Cancelado\n\n");
                break;
        }
    }
