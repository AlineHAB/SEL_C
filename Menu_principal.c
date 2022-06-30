#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include "fila.h"
#include "Identificador.h"


void encomendar_livro(){
      
    system("clear");
    int id_pessoa = id();
    printf("%d\n", id_pessoa);

    printf(" Digite o nome do aluno:\n");
    char * nome = malloc(sizeof(char));
    scanf(" %[^\n]s", &nome);
    printf(" Digite a matricula:\n");
    int matricula = malloc(sizeof(int));
    scanf(" %[^\n]d", &matricula);

    printf(" Digite a descricao:\n");
    char * descricao = malloc(sizeof(char));
    scanf(" %[^\n]s", &descricao);
            
};

int main(){
    printf("\nSISTEMA DE ENCOMENDA DE LIVRO\n");
    int resp = -1;
    while(resp != 0){
        printf(" 1 - Encomendar um livro.\n");
        printf(" 2 - Remover uma encomenda de livro.\n");
        printf(" 3 - Remover um pedido de livro.\n");
        printf(" 0 - Sair do sistema!\n");
        printf("Digite a funcionalidade desejada:");
        scanf("%d", &resp);

        switch (resp)
        {
        case 1:
          encomendar_livro();
        default:
            break;
        }
      

    }
    return 0;
}
