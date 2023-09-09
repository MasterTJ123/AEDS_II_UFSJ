#include "arvore_binaria_nao_balanceada.h"

Dicionario* inicializar_arvore_binaria_nao_balanceada(Dicionario* dicionario_arvore){
    dicionario_arvore = (Dicionario*) malloc(sizeof(Dicionario));
    if(dicionario_arvore != NULL){
        *dicionario_arvore = NULL;
        printf("O dicionario foi inicializado com sucesso!\n\n");
    } else {
        printf("Erro ao alocar a memoria do dicionario!\n\n");
    }
    system("pause");
    return dicionario_arvore;
}

int inserir_arvore_binaria_nao_balanceada(Dicionario* dicionario_arvore, Chave chave){
    if(dicionario_arvore == NULL){
        system("cls");
        printf("Erro! A arvore precisa ser inicializada primeiro!\n\n");
        system("pause");
        return 0;
    } else {
        Apontador novo_no;
        novo_no = (Apontador) malloc(sizeof(Apontador));
            if(novo_no == NULL){
                system("cls");
                printf("Erro ao alocar a memoria do novo no!\n\n");
                system("pause");
                return 0;
            } else {
                novo_no->registro.chave = chave;
                novo_no->direita = NULL;
                novo_no->esquerda = NULL;
                    if(*dicionario_arvore == NULL){
                        *dicionario_arvore = novo_no;
                        system("cls");
                        printf("Chave inserida com sucesso!\n\n");
                        system("pause");
                        return 1;
                    } else {
                        Apontador no_atual = *dicionario_arvore;
                        Apontador no_anterior = NULL;
                            while(no_atual != NULL){
                                no_anterior = no_atual;
                                    if(chave == no_atual->registro.chave){
                                        free(novo_no);
                                        system("cls");
                                        printf("Erro! A chave ja existe!\n\n");
                                        system("pause");
                                        return 0;
                                    } else if(chave > no_atual->registro.chave){
                                        no_atual = no_atual->direita;
                                    } else {
                                        no_atual = no_atual->esquerda;
                                    }
                            }
                            if(chave > no_anterior->registro.chave){
                                no_anterior->direita = novo_no;

                            } else {
                                no_anterior->esquerda = novo_no;
                            }
                            system("cls");
                            printf("Chave inserida com sucesso!\n\n");
                            system("pause");
                            return 1;
                    }
            }
    }
}

Apontador remove_no_atual_arvore_binaria_nao_balanceada(Apontador no_atual){
    Apontador no1, no2; //no1 e o pai de no2
    if(no_atual->esquerda == NULL){
        no2 = no_atual->direita;
        free(no_atual);
        return no2;
    }
    no1 = no_atual;
    no2 = no_atual->esquerda;
    while(no2->direita != NULL){
        no1 = no2;
        no2 = no2->direita;
    }
    if(no1 != no_atual){
        no1->direita = no2->esquerda;
        no2->esquerda = no_atual->esquerda;
    }
    no2->direita = no_atual->direita;
    free(no_atual);
    return no2;
}

int remove_arvore_binaria_nao_balanceada(Dicionario* dicionario_arvore, Chave chave){
    if(dicionario_arvore == NULL){
        system("cls");
        printf("Erro! A arvore precisa ser inicializada primeiro!\n\n");
        system("pause");
        return 0;
    } else {
        Apontador no_atual = *dicionario_arvore;
        Apontador no_anterior = NULL;
            while(no_atual != NULL){
                if(chave == no_atual->registro.chave){
                    if(no_atual == *dicionario_arvore){
                        *dicionario_arvore = remove_no_atual_arvore_binaria_nao_balanceada(no_atual); //E a raiz
                    } else {
                        if(no_anterior->direita == no_atual){
                            no_anterior->direita = remove_no_atual_arvore_binaria_nao_balanceada(no_atual); //E o no a direita do anterior
                        } else {
                            no_anterior->esquerda = remove_no_atual_arvore_binaria_nao_balanceada(no_atual); //E o no a esquerda do anterior
                        }
                    }
                    system("cls");
                    printf("Chave removida com sucesso!\n\n");
                    system("pause");
                    return 1;
                }
                no_anterior = no_atual;
                    if(chave > no_atual->registro.chave){
                        no_atual = no_atual->direita;
                    } else {
                        no_atual = no_atual->esquerda;
                    }
            }
            system("cls");
            printf("Erro! A chave nao foi encontrada!\n\n");
            system("pause");
            return 0;
    }
}

int pesquisa_arvore_binaria_nao_balanceada(Dicionario* dicionario_arvore, Chave chave){
    if(dicionario_arvore == NULL){
        system("cls");
        printf("Erro! A arvore precisa ser inicializada primeiro!\n\n");
        system("pause");
        return 0;
    }
    Apontador no_atual = *dicionario_arvore;
        while(no_atual != NULL){
            if(chave == no_atual->registro.chave){
                system("cls");
                printf("Chave encontrada com sucesso!\n\n");
                printf("Conteudo do campo \"Chave\" do registro: %ld\n\n", no_atual->registro.chave);
                system("pause");
                return 1;
            }
            if(chave > no_atual->registro.chave){
                no_atual = no_atual->direita;
            } else {
                no_atual = no_atual->esquerda;
            }
        }
    system("cls");
    printf("Erro! A chave nao foi encontrada!\n\n");
    system("pause");
    return 0;
}
