#include "arvore_binaria_nao_balanceada.h"

void erro_comando_invalido(){
    system("cls");
    printf("Erro! Comando invalido!\n\n");
    system("pause");
    system("cls");
}

int main(){

    int escolha_menu = 0;
    Chave nova_chave = 0;

    Dicionario* dicionario_arvore = NULL;

    do{
        system("cls");
        printf("---------------------------------------------------------------\n                       Menu Principal \n---------------------------------------------------------------\n\n");
        printf("1- Arvore binaria nao balanceada\n");
        printf("2- Hash com solucao de colisao por listas lineares\n");
        printf("3- Hash com solucao de colisao por enderecamento aberto\n");
        printf("4- Sair\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha_menu);
        fflush(stdin);
            if(escolha_menu == 1){
                do{
                    system("cls");
                    printf("---------------------------------------------------------------\n                Arvore binaria nao balanceada \n---------------------------------------------------------------\n\n");
                    printf("1- Inicializar\n");
                    printf("2- Inserir\n");
                    printf("3- Remover\n");
                    printf("4- Pesquisar\n");
                    printf("5- Voltar\n\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &escolha_menu);
                    fflush(stdin);
                        if(escolha_menu == 1){
                            do{
                                system("cls");
                                printf("Voce deseja inicializar um novo dicionario?\n\n");
                                printf("1- Sim\n");
                                printf("2- Nao\n\n");
                                printf("Escolha uma opcao: ");
                                scanf("%d", &escolha_menu);
                                fflush(stdin);
                                    if(escolha_menu == 1){
                                            system("cls");
                                        if(dicionario_arvore == NULL){
                                            dicionario_arvore = inicializar_arvore_binaria_nao_balanceada(dicionario_arvore);
                                        } else {
                                            printf("Erro! A sua arvore ja foi inicializada anteriormente!\n\n");
                                            system("pause");
                                        }
                                        break;
                                    } else if(escolha_menu == 2){
                                        break;
                                    } else {
                                        erro_comando_invalido();
                                    }
                            } while(1);
                        } else if(escolha_menu == 2){
                            system("cls");
                            printf("Insira a chave: ");
                            scanf("%ld", &nova_chave);
                            fflush(stdin);
                            inserir_arvore_binaria_nao_balanceada(dicionario_arvore, nova_chave);
                        } else if(escolha_menu == 3){
                            system("cls");
                            printf("Insira a chave: ");
                            scanf("%ld", &nova_chave);
                            fflush(stdin);
                            remove_arvore_binaria_nao_balanceada(dicionario_arvore, nova_chave);
                        } else if(escolha_menu == 4){
                            system("cls");
                            printf("Insira a chave: ");
                            scanf("%ld", &nova_chave);
                            fflush(stdin);
                            pesquisa_arvore_binaria_nao_balanceada(dicionario_arvore, nova_chave);
                        } else if(escolha_menu == 5){
                            break;
                        } else {
                            erro_comando_invalido();
                        }
                } while(1);
            } else if(escolha_menu == 2){
                system("cls");
                printf("Implementado por outro aluno!\n\n");
                system("pause");
                return 0;
            } else if(escolha_menu == 3){
                system("cls");
                printf("Implementado por outro aluno!\n\n");
                system("pause");
                return 0;
            } else if(escolha_menu == 4){
                system("cls");
                printf("Programa encerrado com sucesso!\n\n");
                system("pause");
                return 0;
            } else {
                erro_comando_invalido();
            }
    } while(1);
}
