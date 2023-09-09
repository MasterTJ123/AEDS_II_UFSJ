#include "agenda.h"

void erro_comando_invalido(){
    system("cls");
    printf("Erro! Comando invalido!\n\n");
    system("pause");
    system("cls");
}

int main()
{

    int escolha_menu = 0;

    int contador_compromisso = 0;
    int contador_agenda = 0;

    AGENDA agenda[12];

    int id_agenda_aux = 0;
    int id_compromisso_aux = 0;

    char nome_professor_aux[100];
    int ano_aux;

    TIPO_COMPROMISSO tipo_compromisso_aux = 0;
    DATA data_aux = {0};
    HORA hora_aux = {0};
    int duracao_aux = 0;
    char nome_compromisso_aux[100];
    COMPROMISSO compromisso_aux = {0};
    int prioridade_aux = 0;
    bool adiavel_aux = 0;
    STATUS_COMPROMISSO status_aux = 0;

    do{
        system("cls");
        printf("---------------------------------------------------------------\n  Bem-vindo ao Sistema Automatizado de Gerenciamento de Tempo  \n---------------------------------------------------------------\n\n");
        printf("1- Criar nova agenda\n");
        printf("2- Visualizar agenda existente\n");
        printf("3- Sair\n\n");
        printf("Selecione uma opcao: ");
        scanf("%d", &escolha_menu);
        fflush(stdin);
            if(escolha_menu == 1){
                if(contador_agenda < 12){
                    system("cls");
                    printf("Informe o seu nome: ");
                    scanf(" %[^\n]%*c", nome_professor_aux);
                    printf("Informe o ano: ");
                    scanf("%d", &ano_aux);
                    criaAgenda(agenda, contador_agenda, nome_professor_aux, ano_aux);
                    system("cls");
                    printf("A agenda foi criada com sucesso! %s, o id da sua agenda e %d!\n\n", agenda[contador_agenda].nome_professor, agenda[contador_agenda].id_agenda);
                    system("pause");
                    contador_agenda = contador_agenda + 1;
                } else {
                    system("cls");
                    printf("Erro! O numero maximo de professores e agendas foi atingido!\n\n");
                    system("pause");
                }
            } else if(escolha_menu == 2){
                if(contador_agenda != 0){
                    system("cls");
                    printf("Informe o id da agenda: ");
                    scanf("%d", &id_agenda_aux);
                    fflush(stdin);
                        if((id_agenda_aux < 1) || (id_agenda_aux > contador_agenda)){
                            system("cls");
                            printf("Erro! Esse id nao esta cadastrado!\n\n");
                            system("pause");
                        } else {
                            do{
                                system("cls");
                                printf("---------------------------------------------------------------\n  Bem-vindo ao Sistema Automatizado de Gerenciamento de Tempo  \n---------------------------------------------------------------\n\n");
                                printf("1- Opcoes dos compromissos\n");
                                printf("2- Opcoes da agenda\n");
                                printf("3- Sair\n\n");
                                printf("Selecione uma opcao: ");
                                scanf("%d", &escolha_menu);
                                fflush(stdin);
                                    if(escolha_menu == 1){
                                        do{
                                            system("cls");
                                            printf("---------------------------------------------------------------\n                         Compromisso  \n---------------------------------------------------------------\n\n");
                                            printf("1- Inicializar compromisso\n");
                                            printf("2- Alterar prioridade\n");
                                            printf("3- Adiar\n");
                                            printf("4- Alterar Status\n");
                                            printf("5- Verificar existencia de conflitos\n");
                                            printf("6- Imprimir compromisso\n");
                                            printf("7- Voltar\n\n");
                                            printf("Selecione uma opcao: ");
                                            scanf("%d", &escolha_menu);
                                            fflush(stdin);
                                            system("cls");
                                                if(escolha_menu == 1){
                                                    do{
                                                        printf("---------------------------------------------------------------\n                         Compromisso  \n---------------------------------------------------------------\n\n");
                                                        printf("1- Orientacao\n");
                                                        printf("2- Aula\n");
                                                        printf("3- Compromisso particular\n");
                                                        printf("4- Evento\n");
                                                        printf("5- Reuniao\n");
                                                        printf("6- Voltar\n\n");
                                                        printf("Selecione uma opcao: ");
                                                        scanf("%d", &escolha_menu);
                                                        fflush(stdin);
                                                            if((escolha_menu >= 1) && (escolha_menu <= 5)){
                                                                tipo_compromisso_aux = escolha_menu;
                                                                system("cls");
                                                                printf("---------------------------------------------------------------\n                         Compromisso  \n---------------------------------------------------------------\n\n");
                                                                printf("Informe o dia do compromisso: ");
                                                                scanf("%d", &data_aux.dia);
                                                                fflush(stdin);
                                                                printf("\nInforme o mes do compromisso: ");
                                                                scanf("%d", &data_aux.mes);
                                                                fflush(stdin);
                                                                printf("\nInforme o ano do compromisso: ");
                                                                scanf("%d", &data_aux.ano);
                                                                fflush(stdin);
                                                                printf("\nInforme a hora do compromisso: ");
                                                                scanf("%d", &hora_aux.hora);
                                                                fflush(stdin);
                                                                printf("\nInforme os minutos do compromisso: ");
                                                                scanf("%d", &hora_aux.minutos);
                                                                fflush(stdin);
                                                                printf("\nInforme a duracao do compromisso: ");
                                                                scanf("%d", &duracao_aux);
                                                                fflush(stdin);
                                                                printf("\nInforme o nome do compromisso: ");
                                                                scanf(" %[^\n]%*c", nome_compromisso_aux);
                                                                fflush(stdin);
                                                                compromisso_aux = inicializaCompromisso(compromisso_aux, contador_compromisso, tipo_compromisso_aux, data_aux, hora_aux, duracao_aux, nome_compromisso_aux);
                                                                insereCompromisso(agenda, compromisso_aux, id_agenda_aux, contador_compromisso);
                                                                contador_compromisso = contador_compromisso + 1;
                                                                break;
                                                            } else if (escolha_menu == 6){
                                                                system("cls");
                                                                break;
                                                            } else {
                                                                erro_comando_invalido();
                                                            }
                                                    } while(1);
                                                } else if(escolha_menu == 2){
                                                    printf("Informe o id do compromisso: ");
                                                    scanf("%d", &id_compromisso_aux);
                                                    fflush(stdin);
                                                    printf("\nA prioridade atual desse compromisso e %d", retornaPrioridade(&agenda[id_agenda_aux-1].lista_eventos[id_compromisso_aux-1]));
                                                    printf("\n\nAlterar prioridade para: ");
                                                    scanf("%d", &prioridade_aux);
                                                    alteraPrioridade(&agenda[id_agenda_aux-1].lista_eventos[id_compromisso_aux-1], prioridade_aux);
                                                    printf("\nSucesso! A nova prioridade e %d\n\n", retornaPrioridade(&agenda[id_agenda_aux-1].lista_eventos[id_compromisso_aux-1]));
                                                    system("pause");
                                                } else if(escolha_menu == 3){
                                                    printf("Informe o id do compromisso: ");
                                                    scanf("%d", &id_compromisso_aux);
                                                    fflush(stdin);
                                                        if(agenda[id_agenda_aux-1].lista_eventos[id_compromisso_aux-1].adiavel == 1){
                                                            printf("\nAtualmente o compromisso e adiavel!");
                                                        } else {
                                                            printf("\nAtualmente o compromisso nao e adiavel!");
                                                        }
                                                    printf("\n\nDeseja tornar o compromisso adiavel? ");
                                                    scanf("%d", (int*) &adiavel_aux);
                                                    fflush(stdin);
                                                    eAdiavel(&agenda[id_agenda_aux-1].lista_eventos[id_compromisso_aux-1], adiavel_aux);
                                                } else if(escolha_menu == 4){
                                                    printf("Informe o id do compromisso: ");
                                                    scanf("%d", &id_compromisso_aux);
                                                    fflush(stdin);
                                                    printf("\nO status atual desse compromisso e ");
                                                    retornaStatus(&agenda[id_agenda_aux-1].lista_eventos[id_compromisso_aux-1]);
                                                    printf("\n\nAlterar status para: ");
                                                    scanf("%d", (int*) &status_aux);
                                                    atribuiStatus(&agenda[id_agenda_aux-1].lista_eventos[id_compromisso_aux-1], status_aux);
                                                    system("pause");
                                                } else if(escolha_menu == 5){

                                                    int aux_id_1, aux_id_2;

                                                    system("cls");
                                                    printf("\nDigite o ID do compromisso 1: ");
                                                    scanf("%d", &aux_id_1);
                                                    printf("\nDigite o ID do compromisso 2: ");
                                                    scanf("%d", &aux_id_2);

                                                    int conflito = temConflito(&agenda[id_agenda_aux-1].lista_eventos[aux_id_1-1], &agenda[id_agenda_aux-1].lista_eventos[aux_id_2-1]);

                                                    if(conflito == 0) {
                                                        printf("\nNao ha nenhum conflito de horario entre os dois compromissos\n");
                                                    } else {
                                                        printf("\nHa um conflito de horario entre os dois compromissos.\n");
                                                    }

                                                    system("pause");

                                                } else if(escolha_menu == 6){
                                                    system("cls");
                                                    printf("Informe o id do compromisso: ");
                                                    scanf("%d", &id_compromisso_aux);
                                                    printf("\n");
                                                    imprimeCompromisso(&agenda[id_agenda_aux-1].lista_eventos[id_compromisso_aux-1]);
                                                    system("pause");
                                                } else if(escolha_menu == 7){
                                                    break;
                                                } else {
                                                    erro_comando_invalido();
                                                }
                                        } while(1);
                                    } else if(escolha_menu == 2){
                                        do {
                                            system("cls");

                                            printf("---------------------------------------------------------------\n                         Agenda  \n---------------------------------------------------------------\n\n");
                                            printf("1- Recupera agenda\n");
                                            printf("2- Remove compromisso\n");
                                            printf("3- Imprime agenda\n");
                                            printf("4- Resolve conflitos\n");
                                            printf("5- Numero de adiamentos\n");
                                            printf("6- Numero de cancelamentos\n");
                                            printf("7- Numero de compromissos\n");
                                            printf("8- Mostrar compromissos adiados\n");
                                            printf("9- Mostrar compromissos cancelados\n");
                                            printf("10- Mostrar compromissos a cumprir\n");
                                            printf("11- Voltar\n\n");
                                            printf("Selecione uma opcao: ");
                                            scanf("%d", &escolha_menu);
                                            fflush(stdin);

                                            if(escolha_menu == 1) {

                                                system("cls");
                                                printf("---------------------------------------------------------------\n                         Agenda  \n---------------------------------------------------------------\n\n");

                                                printf("Informe o dia do compromisso: ");
                                                scanf("%d", &data_aux.dia);
                                                fflush(stdin);
                                                printf("\nInforme o mes do compromisso: ");
                                                scanf("%d", &data_aux.mes);
                                                fflush(stdin);
                                                printf("\nInforme o ano do compromisso: ");
                                                scanf("%d", &data_aux.ano);

                                                recuperaAgenda(&agenda[id_agenda_aux-1], data_aux, contador_compromisso);
                                                system("cls");
                                            } else if (escolha_menu == 2) {

                                                system("cls");
                                                printf("Digite o id do compromisso a ser removido: ");
                                                scanf("%d", &id_compromisso_aux);

                                                removeCompromisso(&agenda[id_agenda_aux-1], &contador_compromisso, id_compromisso_aux);


                                            } else if (escolha_menu == 3) {
                                                imprimeAgenda(&agenda[id_agenda_aux-1], contador_compromisso);
                                                system("cls");
                                            } else if (escolha_menu == 4) {
                                                system("cls");
                                                resolveConflito(&agenda[id_agenda_aux-1], contador_agenda);
                                            } else if (escolha_menu == 5) {
                                                retornaNAdiamentos(&agenda[id_agenda_aux-1], contador_compromisso);
                                            } else if (escolha_menu == 6) {
                                                retornaNCancelamentos(&agenda[id_agenda_aux-1], contador_compromisso);
                                            } else if (escolha_menu == 7) {
                                                system("cls");
                                                printf("Voce tem %d compromissos\n", retornaNCompromissos(contador_compromisso));
                                                system("pause");
                                            } else if (escolha_menu == 8) {
                                                system("cls");
                                                imprimeCompromissosAdiados(&agenda[id_agenda_aux-1], contador_compromisso);
                                            } else if (escolha_menu == 9) {
                                                system("cls");
                                                imprimeCompromissosCancelados(&agenda[id_agenda_aux-1], contador_compromisso);
                                            } else if (escolha_menu == 10) {
                                                system("cls");
                                                imprimeCompromissosACumprir(&agenda[id_agenda_aux-1], contador_compromisso);
                                            } else if (escolha_menu == 11) {
                                                break;
                                            } else {
                                                erro_comando_invalido();
                                            }

                                        } while(1);

                                    } else if(escolha_menu == 3){
                                        break;
                                    } else {
                                        erro_comando_invalido();
                                    }
                            } while(1);
                        }
                } else {
                    system("cls");
                    printf("Erro! Nao existe nenhum professor e agenda cadastrada!\n\n");
                    system("pause");
                }
            } else if(escolha_menu == 3){
                system("cls");
                printf("Programa encerrado com sucesso!\n\n");
                system("pause");
                return 0;
            } else {
                erro_comando_invalido();
            }
    } while(1);

}
