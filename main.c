#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//structs
typedef struct {
    char nome[50];
    char matricula[10];
    float media[13];
    float media_final;
    int faltas[13];
    float falta;
    char login_aluno[50];
    char senha_aluno[50];
  } aluno;

typedef struct {
    char codigo[50];
    char login_func[50];
    char senha_func[50];
    } secretario;


// FUN플O PARA NOTAS
void inserir_notas(aluno dados_alunos[3],char nome_materia[13][25]){
    int j,i,pos;
    char matricula_aluno[50];
    printf("\nDIGITE A MATRICULA :   ");
    scanf("%s",&matricula_aluno);


    for(i = 0; i<3; i++){
        if(strcmp(matricula_aluno, dados_alunos[i].matricula) == 0){
            pos=i;
            printf("%i",pos);

        }
    }
    printf("COMPLETE COM AS NOTAS : ");
    for(j = 0; j<13; j++){
        printf("\n%s ", nome_materia[j]);
        scanf("%f",&dados_alunos[pos].media[j]);
    }
    exibe_dados_alunos_aluno(pos, dados_alunos, nome_materia);
}
// FUN플O PARA ALTERAR NOTAS
void alterar_notas(aluno dados_alunos[3],char nome_materia[13][25]){

    int j,i,pos,materia_alterar;
    char matricula_aluno[50];

    printf("\nDIGITE A MATRICULA :   ");
    scanf("%s",&matricula_aluno);

    for(i = 0; i<3; i++){
        if(strcmp(matricula_aluno, dados_alunos[i].matricula) == 0){
            pos=i;

        }
    }

    printf("\nQUAL A MATERIA QUE VOCE DESEJA ALTERAR ?  ");
    for(j = 0; j<13; j++){
        printf("\n%i - %s", j,nome_materia[j]);
    }
    scanf("%i",&materia_alterar);

    printf("\nQUAL A NOVA NOTA ?  ");
    scanf("%f",&dados_alunos[pos].media[materia_alterar]);
    exibe_dados_alunos_aluno(pos, dados_alunos, nome_materia);
}
// FUN플O PARA FALTAS
void alterar_faltas(aluno dados_alunos[3],char nome_materia[13][25]){

    int j,i,pos,faltas_alterar;
    char matricula_aluno[50];

    printf("\nDIGITE A MATRICULA :   ");
    scanf("%s",&faltas_alterar);


    for(i = 0; i<3; i++){
        if(strcmp(matricula_aluno, dados_alunos[i].matricula) == 0){
            pos=i;

        }
    }

    printf("\nQUAL A MATERIA QUE VOCE DESEJA ALTERAR ?  ");
    for(j = 0; j<13; j++){
        printf("\n%i - %s", j,nome_materia[j]);
    }
    scanf("%i",&faltas_alterar);

    printf("%i", faltas_alterar);

    printf("\nQUAL A NOVA QUANTIA DE FALTAS ?  ");
    scanf("%f",&dados_alunos[pos].faltas[faltas_alterar]);
    exibe_dados_alunos_aluno(pos, dados_alunos, nome_materia);
}

// FUN플O PARA ALTERAR FALTAS
void inserir_faltas(aluno dados_alunos[3], char nome_materia[13][25]){
    int j,i;
    float aux;
    char matricula_aluno[50],pos;
    printf("\nDIGITE A MATRICULA :   ");
    scanf("%s",&matricula_aluno);

    for(i = 0; i<3; i++){
        if(strcmp(matricula_aluno, dados_alunos[i].matricula) == 0){
            pos=i;
        }
    }
    printf("COMPLETE COM AS FALTAS : ");

    for(j = 0; j<13; j++){
        printf("\n%s ", nome_materia[j]);
        scanf("%i",&dados_alunos[pos].faltas[j]);
    }
    exibe_dados_alunos_aluno(pos, dados_alunos, nome_materia);
}
// FUN플O PARA VER SE O ALUNO SER� APROVADO POR FALTAS
void testando_aprovacao (aluno dados_alunos[3],char nome_materia[13][25], int pos){
     int aprovado[13],i,j, perdida,contador=0,k;
      i=pos;
        for (j=0; j<13; j++){
        aprovado[j]= (dados_alunos[i].faltas[j]*100)/60;
        }
        printf("\nAS MATERIAS DE REPROVA플OS POR FALTA S홒:\n");
        for (j=0; j<13; j++){
        if (aprovado[j]>25){
            printf("\n%s",nome_materia[j]);
            contador++;
        }
        }
        if (contador==0){
            printf("\nVOC� N홒 REPROVOU EM NENHUMA POR FALTA!");
        }
        }
//LOGAR E CONFERIR ALUNO
int logar_aluno(aluno dados_alunos[3]){

    int i,pos_aluno,pos;
    char login_aluno[50], senha_aluno[50];

    printf("\nDIGITE O LOGIN :   ");
    scanf("%s",&login_aluno);
    printf("\nDIGITE A SENHA :   ");
    scanf("%s",&senha_aluno);

    printf("antes do pos");
    pos = confere_aluno(dados_alunos,login_aluno, senha_aluno);

    printf("depois do pos");

    return pos;
}

int confere_aluno(aluno dados_alunos[3],char login_aluno[50], char senha_aluno[50]){

    int i, pos_aluno=0;
    printf("\nentrou no confere");
    for(i = 0; i<3; i++){

        if(strcmp(login_aluno, dados_alunos[i].login_aluno) == 0){

            pos_aluno=i;
            printf("%entrou no if");
        }
    }

    if(strcmp(senha_aluno, dados_alunos[pos_aluno].senha_aluno) == 0){
        return pos_aluno;
    }else{
        logar_aluno(dados_alunos);
    }
}

//LOGAR E CONFERIR SECRET핾IO
void logar_secretario(aluno dados_secretario[3]){

    int i,pos_aluno;
    char login_secretario[50], senha_secretario[50];

    printf("\nDIGITE O LOGIN :   ");
    scanf("%s",&login_secretario);
    printf("\nDIGITE A SENHA :   ");
    scanf("%s",&senha_secretario);

    confere_secretario(dados_secretario,login_secretario, senha_secretario);
}

void confere_secretario(secretario dados_secretario[3], char login_secretario[50], char senha_secretario[50]){

    int i, pos_sec;

    for(i = 0; i<2; i++){
        if(strcmp(login_secretario, dados_secretario[i].login_func) == 0){
            pos_sec=i;
        }
    }
    if(strcmp(senha_secretario, dados_secretario[pos_sec].senha_func) == 0){
        printf("LOGIN FEITO COM SUCESSO !");
    }else{
        logar_secretario(dados_secretario);
    }
}
void exibe_notas_especificas(aluno dados_alunos[], char nome_materia[13][25], int pos, int especifica){
    int i,j;
    i = pos;
        printf("\n\n%s %.2f", nome_materia[especifica-1],dados_alunos[i].media[especifica-1]);

}
// FUN플O PARA EXIBIR AS NOTAS
void exibe_notas(aluno dados_alunos[], char nome_materia[13][25], int pos){
    int i,j;
    i = pos;
    for(j = 0; j<13; j++){
        printf("\n\n%s %.2f", nome_materia[j],dados_alunos[i].media[j]);
        }
}
// FUN플O PARA EXIBIR OS DADOS DOS ALUNOS
void exibe_dados_alunos(aluno dados_alunos[], char nome_materia[13][25]){

    int i,j,k;

    for( i = 0; i< 10; i++ ){
        printf("\nNOME                : %s",  dados_alunos[i].nome);
        printf("\nMATRICULA           : %i",  dados_alunos[i].matricula);
        printf("\nLOGIN               : %s",  dados_alunos[i].login_aluno);
        printf("\nSENHA               : %s",  dados_alunos[i].senha_aluno);
        printf("\n\nMEDIAS              : %s");

        for(j = 0; j<13; j++){
            printf("\n\n%s %.2f", nome_materia[j],dados_alunos[i].media[j]);
        }

        printf("\n\nFALTAS              : %s",  dados_alunos[i].senha_aluno);

        for(j = 0; j<13; j++){
            printf("\n\n%s %i", nome_materia[j],dados_alunos[i].faltas[j]);
        }
    }
}
// FUN플O PARA EXIBIR AS FALTAS DOS ALUNOS
void exibe_faltas(int pos,aluno dados_alunos[], char nome_materia[13][25]){
    int i=pos,j,k;

    printf("\n\nFALTAS              : %s",  dados_alunos[i].senha_aluno);

    for(j = 0; j<13; j++){
        printf("\n%s %i", nome_materia[j],dados_alunos[i].faltas[j]);
    }
}
void exibe_faltas_especifica(int pos,aluno dados_alunos[], char nome_materia[13][25],int especifica){
    int i=pos,j,k;

        printf("\n%s %i", nome_materia[especifica-1],dados_alunos[i].faltas[especifica-1]);
    }
// FUN플O PARA EXIBIR OS DADOS DOS ALUNOS
void exibe_dados_alunos_aluno(int pos,aluno dados_alunos[], char nome_materia[13][25]){
    int i=pos,j,k;
    printf("\nNOME                : %s",  dados_alunos[i].nome);
    printf("\nMATRICULA           : %i",  dados_alunos[i].matricula);
    printf("\nLOGIN               : %s",  dados_alunos[i].login_aluno);
    printf("\nSENHA               : %s",  dados_alunos[i].senha_aluno);
    printf("\nMEDIAS              : ");
    printf("\n__________________________________________________________\n");
    printf("\nDISCIPLINAS MATRICULADAS:\n");
    for(j = 0; j<13; j++){
        printf("\n%s %.2f", nome_materia[j],dados_alunos[i].media[j]);
    }
    printf("\n__________________________________________________________\n");
    printf("\nDISCIPLINAS EM RECUPERA플O POR NOTA BAIXA:\n");
    for(j = 0; j<13; j++){
        if(dados_alunos[i].media[j]<7){
            printf("\n%s",nome_materia[j]);
        }
    }
    printf("\n____________________________________________________________\n");
    printf("\nFALTAS              : %s",  dados_alunos[i].senha_aluno);

    for(j = 0; j<13; j++){
        printf("\n%s %i", nome_materia[j],dados_alunos[i].faltas[j]);
    }
    printf("\n____________________________________________________________\n");
    testando_aprovacao ( dados_alunos, nome_materia,  pos);
}
// FUN플O MENU
void menu(aluno dados_alunos[3], secretario dados_funcionarios[2], char nome_materia[13][25]){

    int entrada_menu, pos,entrada_aluno,entrada_sec,escolha,especifica;

    printf("SEJA BEM VINDO AO PORTAL\n");
    printf("\nESCOLHA UMA OP플O :");
    printf("\n1 - LOGAR COMO ALUNO");
    printf("\n2 - LOGAR COMO SECRET핾IO");
    printf("\n3 - FINALIZAR PROGRAMA");
    printf("\nRESPOSTA :   ");
    scanf("%i", &entrada_menu);

    while(entrada_menu != 3 ){
        switch (entrada_menu){
            case 1:
                system("cls");

                pos = logar_aluno(dados_alunos);
                printf("\n 1 - VISUALIZAR SEUS DADOS COMPLETOS: ");
                printf("\n 2 - VISUALIZAR APENAS AS FALTAS NAS DISCIPLINAS:");
                printf("\n 3 - VISUALIZAR APENAS AS NOTAS DAS DISCIPLINAS:");
                printf("\nRESPOSTA: ");
                scanf("%i",&entrada_aluno);
                system("cls");
                if(entrada_aluno==1){
                    exibe_dados_alunos_aluno(pos, dados_alunos, nome_materia);
                }
                if(entrada_aluno==2){
                    printf("1 - EM TODAS\n");
                    printf("2 - ALGUMA ESPEC�FICA");
                    printf("\nRESPOSTA: ");
                    scanf("%i", &escolha);
                    if (escolha == 1)
                        exibe_faltas(pos, dados_alunos,  nome_materia);
                    if (escolha == 2){
                        printf("\nSELECIONE O NUMERO REFERENTE A DISCIPLINA:");
                        printf("\n1 - LINGUA PORTUGUESA\n2 - MATEM햀ICA \n3 - BIOLOGIA \n4 - F�SICA\n5 - QU�MICA\n6 - FILOSOFIA\n7 - INGL�S\n8 - GEOGRAFIA\n9 - HIST�RIA\n10 - SOCIOLOGIA\n11 - EDUCA플O F�SICA\n12 - EDUCA플O ARTISTICA\n13 - LITERATURA\n " );
                        printf("\nRESPOSTA: ");
                        scanf("%i", &especifica);
                        exibe_faltas_especifica(pos, dados_alunos,  nome_materia,especifica);
                        }
                }
                if(entrada_aluno==3){
                    printf("1 - EM TODAS\n");
                    printf("2 - ALGUMA ESPEC�FICA\n");
                    printf("RESPOSTA: ");
                    scanf("%i", &escolha);
                if (escolha == 1){
                      exibe_notas(dados_alunos, nome_materia,pos);
                }
                }
                if (escolha == 2){
                    printf("SELECIONE O NUMERO REFERENTE A DISCIPLINA:");
                    printf("\n1 - LINGUA PORTUGUESA\n2 - MATEM햀ICA, \n3 - BIOLOGIA \n4 - F�SICA\n5 - QU�MICA\n6 - FILOSOFIA\n7 - INGL�S\n8 - GEOGRAFIA\n9 - HIST�RIA\n10 - SOCIOLOGIA\n11 - EDUCA플O F�SICA\n12 - EDUCA플O ARTISTICA\n13 - LITERATURA\n" );
                    printf("\nRESPOSTA: ");
                    scanf("%i", &especifica);
                      exibe_notas_especificas(dados_alunos, nome_materia,pos,especifica);
                }


                break;
            case 2:
                system("cls");
                logar_secretario(dados_funcionarios);
                printf("\n\nESCOLHA UMA OP플O :");
                printf("\n1 - INSERIR NOTAS");
                printf("\n2 - INSERIR FALTAS");
                printf("\n3 - MODIFICAR NOTAS");
                printf("\n4 - MODIFICAR FALTAS");
                printf("\nRESPOSTA :   ");
                scanf("%i",&entrada_sec);
                if( entrada_sec==1){
                    inserir_notas(dados_alunos,nome_materia);
                }
                if( entrada_sec==2){
                    inserir_faltas(dados_alunos,nome_materia);
                }
                if( entrada_sec==3){
                    alterar_notas(dados_alunos,nome_materia);
                }
                if( entrada_sec==4){
                    alterar_faltas(dados_alunos,nome_materia);
                }
                break;

        }
        printf("\n\nESCOLHA UMA OP플O :");
        printf("\n1 - LOGAR COMO ALUNO");
        printf("\n2 - LOGAR COMO SECRET핾IO");
        printf("\n2 - FINALIZAR PROGRAMA");
        printf("\nRESPOSTA :   ");
        scanf("%i", &entrada_menu);

}
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    //VARI햂EIS
    int i;
    FILE *arq, *arq1;
    char Linha[100];
    char *result;
    arq = fopen("est.txt", "r");             // LEITURA

    aluno dados_alunos[3];
    secretario dados_funcionarios[2];


    char nome_materia[13][25]={"LINGUA PORTUGUESA   : ",  //vetor de strings para armazenar os nomes das mat�rias
                               "MATEMATICA          : ",
                               "BIOLOGIA            : ",
                               "FISICA              : ",
                               "QUIMICA             : ",
                               "FILOSOFIA           : ",
                               "INGLES              : ",
                               "GEOGRAFIA           : ",
                               "HISTORIA            : ",
                               "SOCIOLOGIA          : ",
                               "EDUCACAO FISICA     :",
                               "EDUCAO ARTISTICA    :",
                               "LITERATURA          :"
                          };

    while (!feof(arq)){//ALUNO
            // L� UMA LINHA (INCLUSIVE COM O '\N')O 'FGETS'
            if (result){  // SE FOI POSS�VEL LER VAI EXECUTAR
                for(i = 0; i<3; i++){
                    result = fgets(Linha, 100, arq);//NOME
                    result[strlen(result)-1] = '\0';
                    sprintf(dados_alunos[i].nome, "%s", result);


                    result = fgets(Linha, 100, arq);//MATRICULA
                    result[strlen(result)-1] = '\0';
                    sprintf(dados_alunos[i].matricula, "%s", result);


                    result = fgets(Linha, 100, arq);//LOGIN
                    result[strlen(result)-1] = '\0';
                    sprintf(dados_alunos[i].login_aluno, "%s", result);



                    result = fgets(Linha, 100, arq);//SENHA
                    if(i==2){
                        result[strlen(result)] = '\0';
                    }else{
                        result[strlen(result)-1] = '\0';
                    }
                    sprintf(dados_alunos[i].senha_aluno, "%s", result);

                }
            }
    }
    fclose(arq);

    arq1 = fopen("sec.txt", "r");             // LEITURA DO TXT DE SECRET핾IOS
    while (!feof(arq1)){//SECRETARIO
        // L� UMA LINHA (INCLUSIVE COM O '\N')O 'FGETS'
        if (result){  // SE FOI POSS�VEL LER VAI EXECUTAR
            for(i = 0; i<2; i++){

                result = fgets(Linha, 100, arq);//CODIGO
                result[strlen(result)-1] = '\0';
                sprintf(dados_funcionarios[i].codigo, "%s", result);


                result = fgets(Linha, 100, arq);//LOGIN
                result[strlen(result)-1] = '\0';
                sprintf(dados_funcionarios[i].login_func, "%s", result);


                result = fgets(Linha, 100, arq);//SENHA
                if(i==1){
                    result[strlen(result)] = '\0';
                }else{
                    result[strlen(result)-1] = '\0';
                }

                sprintf(dados_funcionarios[i].senha_func, "%s", result);

            }
        }
    }

    menu(dados_alunos,dados_funcionarios, nome_materia);

    return 0;
}
