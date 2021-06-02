#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamanho 5

//criando a fila de atividades


struct tipo_fila{
    int ini;
    int fim;
    char RA[tamanho][20];
    char nome_arq[tamanho][20];
    char ext_arq[tamanho][20];
    char matricula_prof[tamanho][20];
};


struct tipo_fila atv;

//prototipacao
void imprime_atvs();
void mostra_menu();
void inserir_atv();
void remover_atv();
void esvaziar_fila();

//main
int main(void) {
    char input[1];
    int op = 0;

    setlocale(LC_ALL, "Portuguese");
    atv.ini = 0;
	atv.fim = 0;

    while(op != 4){      
        
		imprime_atvs();
    	mostra_menu();
    	fflush(stdin);
    	scanf("%s", input);
        op = atoi(input);
    	
        switch(op){
            case 1:
                inserir_atv();
            break;

            case 2:
                remover_atv();
            break;
            
            case 3:
                esvaziar_fila();
            break;
            
            case 4:
                break;
            
            default:
                printf("\nOpção inválida. Por favor, insira uma das ações listadas.\n\n");
                system("pause");
            
        }
    }

    return (0);
}


//funcao para imprimir as atividades contidas na fila
void imprime_atvs() {
    int i;

    printf("\n--------------------------\n");

    if(atv.ini==atv.fim){
        printf("Ainda não há atividades cadastradas");
        printf("\n--------------------------\n\n");
    }else{
    	printf("Atividades na fila: \n\n");
        for(i=0; i<atv.fim; i++){
            printf("RA: %s\n", atv.RA[i]);
            printf("Nome do arquivo da atividade: %s\n", atv.nome_arq[i]);
            printf("Extensão do arquivo: %s\n", atv.ext_arq[i]);
            printf("Número da matrícula do professor: %s\n", atv.matricula_prof[i]);
            printf("\n");
        }
        printf("\n--------------------------\n\n");
    }
    
    
}

//funcao que mostra o menu
void mostra_menu() {
    
    printf("\nSelecione o número da ação a ser executada:\n");
    printf("1 - Inserir uma nova atividade na fila\n");
    printf("2 - Remover uma atividade da fila\n");
    printf("3 - Esvaziar fila\n");
    printf("4 - Encerrar o programa\n\n");

}

//funcao que insere uma atividade ao final da fila
void inserir_atv() {
    if(atv.fim==tamanho){
        printf("\nNão foi possível realizar esta ação, pois a lista está cheia.\n");
    }else{
        printf("\nDigite o RA do aluno:\n");
        fflush(stdin);
        scanf("%s", atv.RA[atv.fim]);
        printf("Digite o nome do arquivo:\n");
        fflush(stdin);
        scanf("%s", atv.nome_arq[atv.fim]);
        printf("Digite a extensão do arquivo:\n");
        fflush(stdin);
        scanf("%s", atv.ext_arq[atv.fim]);
        printf("Digite a matricula do professor:\n");
        fflush(stdin);
        scanf("%s", atv.matricula_prof[atv.fim]);
        fflush(stdin);
        atv.fim++;
    }
    
}

//funcao que remove uma atividade do comeco da fila
void remover_atv() {
    if(atv.ini==atv.fim){
        printf("\nNão foi possível realiazar esta ação, pois a lista está vazia.\n");
    }else{
        int i, j;
        printf("\nRemovendo a atividade com os seguintes dados:\n\n");
        printf("RA: %s\n", atv.RA[0]);
        printf("Nome do arquivo da atividade: %s\n", atv.nome_arq[0]);
        printf("Extensão do arquivo: %s\n", atv.ext_arq[0]);
        printf("Número da matrícula do professor: %s\n", atv.matricula_prof[0]);
        printf("\n");
        
        for(i=0; i<=atv.fim; i++){
            for(j=0; j<20; j++){
                atv.RA[i][j] = atv.RA[i+1][j+1];
                atv.nome_arq[i][j] = atv.nome_arq[i+1][j+1];
                atv.ext_arq[i][j+1] = atv.ext_arq[i+1][j+1];
                atv.matricula_prof[i][j] = atv.matricula_prof[i+1][j+1];
            }
            
        }
        atv.fim--;
    }
}

//funcao que esvazia a fila
void esvaziar_fila() {
    if(atv.ini==atv.fim){
        printf("\nNão foi possível realizar esta ação, pois a lista está vazia.\n");
    }else{
        int i;
        printf("\nEsvaziando a fila!\n");
        for(i=0; i<=atv.fim; i++){
            *atv.RA[i] = '\0';
            *atv.nome_arq[i] = '\0';
            *atv.ext_arq[i] = '\0';
            *atv.matricula_prof[i] = '\0';
        }
        atv.fim = 0;
    }
}