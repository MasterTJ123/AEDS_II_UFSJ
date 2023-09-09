#include "agenda.h"

void criaAgenda(AGENDA *agenda, int contador_agenda, char *nome, int ano){
    agenda[contador_agenda].id_agenda = contador_agenda + 1;
    strcpy(agenda[contador_agenda].nome_professor, nome);
    agenda[contador_agenda].ano = ano;
}

void insereCompromisso(AGENDA *agenda, COMPROMISSO compromisso_aux, int id_agenda_aux, int contador_compromisso){
    system("cls");
    if(contador_compromisso == 100){
        printf("Falha! A agenda atingiu o limite de compromissos!");
        system("pause");
    } else {
        agenda[id_agenda_aux-1].lista_eventos[contador_compromisso] = compromisso_aux;
        printf("Compromisso inicializado e inserido com sucesso na agenda! O id do compromisso e %d!\n\n", agenda[id_agenda_aux-1].lista_eventos[contador_compromisso].id_compromisso);
        system("pause");
    }
}

void recuperaAgenda(AGENDA *agenda, DATA data, int contador_compromisso) {

    if(contador_compromisso == 0) {
        printf("\nErro! A agenda nao possui nenhum compromisso cadastrado!\n\n");
    } else {
        int count = 0;

        printf("\nProfessor: %s", agenda->nome_professor);
        printf("\nAno: %d", agenda->ano);
            for(int i = 0; i < contador_compromisso; i++) {
                if(agenda->lista_eventos[i].data.ano > data.ano) {
                    count++;
                    continue;
                } else if (agenda->lista_eventos[i].data.ano < data.ano) {
                    continue;
                }
                if (agenda->lista_eventos[i].data.mes > data.mes) {
                    count++;
                    continue;
                } else if (agenda->lista_eventos[i].data.mes < data.mes){
                    continue;
                }
                if(agenda->lista_eventos[i].data.dia > data.dia) {
                    count++;
                    continue;
                } else if(agenda->lista_eventos[i].data.dia < data.dia) {
                    continue;
                }
            }
        printf("\nNumero de compromissos: %d\n\n", count);
    }
    system("pause");
}

void removeCompromisso(AGENDA *agenda, int *contador_compromisso, int id) {
    int existe_id = 0;

    system("cls");

    if(*contador_compromisso == 0){
        printf("Erro! A agenda nao possui nenhum compromisso cadastrado!\n\n");
    } else {
        for(int i = 0; i < *contador_compromisso; i++) {
            if(agenda->lista_eventos[i].id_compromisso == id) {
                for(int j = i; j < *contador_compromisso; j++){
                    strcpy(agenda->lista_eventos[j].nome, agenda->lista_eventos[j+1].nome);
                    agenda->lista_eventos[j].adiavel = agenda->lista_eventos[j+1].adiavel;
                    agenda->lista_eventos[j].data.dia = agenda->lista_eventos[j+1].data.dia;
                    agenda->lista_eventos[j].data.mes = agenda->lista_eventos[j+1].data.mes;
                    agenda->lista_eventos[j].data.ano = agenda->lista_eventos[j+1].data.ano;
                    agenda->lista_eventos[j].duracao = agenda->lista_eventos[j+1].duracao;
                    agenda->lista_eventos[j].hora.hora = agenda->lista_eventos[j+1].hora.hora;
                    agenda->lista_eventos[j].hora.minutos = agenda->lista_eventos[j+1].hora.minutos;
                    agenda->lista_eventos[j].id_compromisso = agenda->lista_eventos[j+1].id_compromisso;
                    agenda->lista_eventos[j].prioridade = agenda->lista_eventos[j+1].prioridade;
                    agenda->lista_eventos[j].status_compromisso = agenda->lista_eventos[j+1].status_compromisso;
                    agenda->lista_eventos[j].tipo_compromisso = agenda->lista_eventos[j+1].tipo_compromisso;
                }
                existe_id = 1;
                break;
            }
        }
        if(existe_id == 1){
            printf("Compromisso removido com sucesso!\n\n");
            *contador_compromisso = *contador_compromisso - 1;
        } else {
            printf("Erro! Nao foi achado nenhum compromisso com esse id!\n\n");
        }
    }
    system("pause");
}

void imprimeAgenda(AGENDA *agenda, int contador_compromisso) {

    int i, j;

    COMPROMISSO compromisso_copia[100];
    COMPROMISSO compromisso_aux_aux = {0};

    memcpy(&compromisso_copia, agenda->lista_eventos, sizeof(agenda->lista_eventos));

    system("cls");
    printf("Compromissos agendados para o professor %s:\n\n", agenda->nome_professor);

    for(i = 1; i < contador_compromisso; i++){
        compromisso_aux_aux = compromisso_copia[i];
            for(j = i; (j > 0); j--){
                if(compromisso_aux_aux.data.ano < compromisso_copia[j-1].data.ano){
                    compromisso_copia[j] = compromisso_copia[j-1];
                } else if((compromisso_aux_aux.data.mes < compromisso_copia[j-1].data.mes) &&
                          (compromisso_aux_aux.data.ano == compromisso_copia[j-1].data.ano)){
                    compromisso_copia[j] = compromisso_copia[j-1];
                } else if((compromisso_aux_aux.data.dia < compromisso_copia[j-1].data.dia) &&
                          (compromisso_aux_aux.data.mes == compromisso_copia[j-1].data.mes) &&
                          (compromisso_aux_aux.data.ano == compromisso_copia[j-1].data.ano)){
                    compromisso_copia[j] = compromisso_copia[j-1];
                } else if((compromisso_aux_aux.hora.hora < compromisso_copia[j-1].hora.hora) &&
                          (compromisso_aux_aux.data.dia == compromisso_copia[j-1].data.dia) &&
                          (compromisso_aux_aux.data.mes == compromisso_copia[j-1].data.mes) &&
                          (compromisso_aux_aux.data.ano == compromisso_copia[j-1].data.ano)){
                    compromisso_copia[j] = compromisso_copia[j-1];
                } else if((compromisso_aux_aux.hora.minutos < compromisso_copia[j-1].hora.minutos) &&
                          (compromisso_aux_aux.hora.hora == compromisso_copia[j-1].hora.hora) &&
                          (compromisso_aux_aux.data.dia == compromisso_copia[j-1].data.dia) &&
                          (compromisso_aux_aux.data.mes == compromisso_copia[j-1].data.mes) &&
                          (compromisso_aux_aux.data.ano == compromisso_copia[j-1].data.ano)){
                    compromisso_copia[j] = compromisso_copia[j-1];
                } else if((compromisso_aux_aux.data.dia = compromisso_copia[j-1].data.dia) &&
                          (compromisso_aux_aux.data.mes = compromisso_copia[j-1].data.mes) &&
                          (compromisso_aux_aux.data.ano = compromisso_copia[j-1].data.ano) &&
                          (compromisso_aux_aux.hora.hora = compromisso_copia[j-1].hora.hora) &&
                          (compromisso_aux_aux.hora.minutos = compromisso_copia[j-1].hora.minutos)){
                    if(compromisso_aux_aux.prioridade < compromisso_copia[j-1].prioridade){
                        compromisso_copia[j] = compromisso_copia[j-1];
                    } else if(compromisso_aux_aux.prioridade == compromisso_copia[j-1].prioridade){
                            typedef enum tipo_compromisso {
                                _EVENTO_AUX = 1,
                                _REUNIAO_AUX,
                                _AULA_AUX,
                                _ORIENTACAO_AUX,
                                _COMPROMISSO_PARTICULAR_AUX
                            } TIPO_COMPROMISSO_AUX;
                            TIPO_COMPROMISSO_AUX tipo_compromisso_copia_aux;
                            TIPO_COMPROMISSO_AUX tipo_compromisso_aux;
                            switch(compromisso_aux_aux.tipo_compromisso){
                                case _ORIENTACAO:
                                    tipo_compromisso_aux = _ORIENTACAO_AUX;
                                    break;
                                case _AULA:
                                    tipo_compromisso_aux = _AULA_AUX;
                                    break;
                                case _COMPROMISSO_PARTICULAR:
                                    tipo_compromisso_aux = _COMPROMISSO_PARTICULAR_AUX;
                                    break;
                                case _EVENTO:
                                    tipo_compromisso_aux = _EVENTO_AUX;
                                    break;
                                case _REUNIAO:
                                    tipo_compromisso_aux = _REUNIAO_AUX;
                                    break;
                            }
                            switch(compromisso_copia[j-1].tipo_compromisso){
                                case _ORIENTACAO:
                                    tipo_compromisso_copia_aux = _ORIENTACAO_AUX;
                                    break;
                                case _AULA:
                                    tipo_compromisso_copia_aux = _AULA_AUX;
                                    break;
                                case _COMPROMISSO_PARTICULAR:
                                    tipo_compromisso_copia_aux = _COMPROMISSO_PARTICULAR_AUX;
                                    break;
                                case _EVENTO:
                                    tipo_compromisso_copia_aux = _EVENTO_AUX;
                                    break;
                                case _REUNIAO:
                                    tipo_compromisso_copia_aux = _REUNIAO_AUX;
                                    break;
                            }
                                if(tipo_compromisso_aux < tipo_compromisso_copia_aux){
                                    compromisso_copia[j] = compromisso_copia[j-1];
                                }
                    }
                }
            }
        compromisso_copia[j] = compromisso_aux_aux;
    }
    for(int i = 0; i < contador_compromisso; i++){
        imprimeCompromisso(&compromisso_copia[i]);
    }
    system("pause");
}

void resolveConflito(AGENDA *agenda, int contador_compromisso) {

    int cont = 0;

for(int j = 0; j < contador_compromisso; j++){
    for(int i = j; i < contador_compromisso; i++) {

        int aux_conflito = temConflito((&agenda->lista_eventos[i]), (&agenda->lista_eventos[i+1]));

        if(aux_conflito == 1) {

            cont++;

            if(agenda->lista_eventos[i].prioridade > agenda->lista_eventos[i+1].prioridade) {

                if(agenda->lista_eventos[i+1].adiavel == 1) {
                agenda->lista_eventos[i+1].status_compromisso = ADIADO;
                } else if (agenda->lista_eventos[i+1].adiavel == 0) {
                    agenda->lista_eventos[i+1].status_compromisso = CANCELADO;
                }

            } else if(agenda->lista_eventos[i].prioridade < agenda->lista_eventos[i+1].prioridade) {

                if(agenda->lista_eventos[i].adiavel == 1) {
                agenda->lista_eventos[i].status_compromisso = ADIADO;

                } else if (agenda->lista_eventos[i].adiavel == 0) {
                    agenda->lista_eventos[i].status_compromisso = CANCELADO;
                }

            } else if (agenda->lista_eventos[i].prioridade == agenda->lista_eventos[i+1].prioridade) {

                typedef enum tipo_compromisso {
                    _EVENTO_AUX = 1,
                    _REUNIAO_AUX,
                    _AULA_AUX,
                    _ORIENTACAO_AUX,
                    _COMPROMISSO_PARTICULAR_AUX
                } TIPO_COMPROMISSO_AUX;
                TIPO_COMPROMISSO_AUX tipo_compromisso_aux1;
                TIPO_COMPROMISSO_AUX tipo_compromisso_aux2;
                switch(agenda->lista_eventos[i].tipo_compromisso){
                    case _ORIENTACAO:
                        tipo_compromisso_aux1 = _ORIENTACAO_AUX;
                        break;
                    case _AULA:
                        tipo_compromisso_aux1 = _AULA_AUX;
                        break;
                    case _COMPROMISSO_PARTICULAR:
                        tipo_compromisso_aux1 = _COMPROMISSO_PARTICULAR_AUX;
                        break;
                    case _EVENTO:
                        tipo_compromisso_aux1 = _EVENTO_AUX;
                        break;
                    case _REUNIAO:
                        tipo_compromisso_aux1 = _REUNIAO_AUX;
                        break;
                }
                switch(agenda->lista_eventos[i+1].tipo_compromisso){
                    case _ORIENTACAO:
                        tipo_compromisso_aux2 = _ORIENTACAO_AUX;
                        break;
                    case _AULA:
                        tipo_compromisso_aux2 = _AULA_AUX;
                        break;
                    case _COMPROMISSO_PARTICULAR:
                        tipo_compromisso_aux2 = _COMPROMISSO_PARTICULAR_AUX;
                        break;
                    case _EVENTO:
                        tipo_compromisso_aux2 = _EVENTO_AUX;
                        break;
                    case _REUNIAO:
                        tipo_compromisso_aux2 = _REUNIAO_AUX;
                        break;
                }
                if(tipo_compromisso_aux1 < tipo_compromisso_aux2){
                    if(agenda->lista_eventos[i+1].adiavel == 1) {
                        agenda->lista_eventos[i+1].status_compromisso = ADIADO;
                    } else if (agenda->lista_eventos[i+1].adiavel == 0) {
                        agenda->lista_eventos[i+1].status_compromisso = CANCELADO;
                    }
                } else if(tipo_compromisso_aux1 > tipo_compromisso_aux2){
                    if(agenda->lista_eventos[i].adiavel == 1) {
                        agenda->lista_eventos[i].status_compromisso = ADIADO;
                    } else if (agenda->lista_eventos[i].adiavel == 0) {
                        agenda->lista_eventos[i].status_compromisso = CANCELADO;
                    }
                }

            }
        }
    }
}
    if(cont == 0) {
        printf("Nenhum conflito foi encontrado.\n");
    } else if (cont != 0) {
        printf("O conflito foi resolvido!\n");
    }
    system("pause");
}

int retornaNAdiamentos(AGENDA *agenda, int contador_compromisso) {
    int cont = 0;

    for(int i = 0; i < contador_compromisso; i++) {
        if(agenda->lista_eventos[i].status_compromisso == ADIADO) {
            cont++;
        }
    }
    return cont;
}

int retornaNCancelamentos(AGENDA *agenda, int contador_compromisso) {
    int cont = 0;

    for(int i = 0; i < contador_compromisso; i++) {
        if(agenda->lista_eventos[i].status_compromisso == CANCELADO) {
            cont++;
        }
    }
    return cont;
}

int retornaNCompromissos(int contador_compromisso) {
    return contador_compromisso;
}

void imprimeCompromissosAdiados(AGENDA *agenda, int contador_compromisso) {
    system("cls");

    printf("Compromissos adiados do professor %s:\n", agenda->nome_professor);

    for(int i = 0; i < contador_compromisso; i++) {
        if(agenda->lista_eventos[i].status_compromisso == ADIADO) {
            printf("\n%s", agenda->lista_eventos[i].nome);
        }
    }
    printf("\n");
    system("pause");
}

void imprimeCompromissosCancelados(AGENDA *agenda, int contador_compromisso) {

    system("cls");
    printf("Compromissos a cumprir do professor %s:\n", agenda->nome_professor);

    for(int i = 0; i < contador_compromisso; i++) {
        if(agenda->lista_eventos[i].status_compromisso == CANCELADO) {
            printf("\n%s", agenda->lista_eventos[i].nome);
        }
    }
    printf("\n");
    system("pause");
}

void imprimeCompromissosACumprir(AGENDA *agenda, int contador_compromisso) {

    system("cls");
    printf("Compromissos a cumprir do professor %s:\n", agenda->nome_professor);

    for(int i = 0; i < contador_compromisso; i++) {
        if(agenda->lista_eventos[i].status_compromisso == A_SER_CUMPRIDO) {
            printf("\n%s", agenda->lista_eventos[i].nome);
        }
    }
    printf("\n");
    system("pause");
}
