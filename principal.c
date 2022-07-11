#include "abb.h"
#include "sec_e_transp.h"


int main(){
    printf("\nSISTEMA DE ENCOMENDA DE LIVRO\n");
    int resp = -1;
    while(resp != 0){
        printf(" 1 - Encomendar um livro.\n");
        printf(" 2 - Remover uma encomenda de livro.\n");
        printf(" 3 - Remover um pedido de livro.\n");
        printf(" 0 - Sair do sistema!\n");
        printf("Digite a funcionalidade desejada: ");
        scanf("%d", &resp);
        if(resp == 1){
              system("clear");
              printf("------Encomendar livro------\n\n");
              insert_dados();
              printf("\n");
       }else if(resp == 2){
            system("clear");
            printf("------Remover encomenda------\n\n");
            printf("\nDigite seu cpf: \n");
            char cpf[100];
            scanf("%s", &cpf);
            printf("\nDigite sua senha: \n");
            char senha[100];
            scanf("%s", &senha);
            int retorno = verificador_secretario(cpf, senha);
            if(retorno == 1){ 
                in_ordem(raiz);
                int id = 0;
                printf("Digite o número do id a ser removido: \n");
                scanf("%d", &id);
                raiz = remover(raiz, id);
            }
        }else if(resp == 3){
            system("clear");
            printf("------Remover pedido------\n\n");
            printf("Digite seu cpf: \n");
            char cpf[100];
            scanf("%s", &cpf);
            printf("Digite sua senha: \n");
            char senha[100];
            scanf("%s", &senha);
            int retorno = verificador_transportador(cpf, senha);
            if(retorno == 1){
                remover_fila();
                printf("Pedido removido com sucesso!\n");
                }
            }
        
        }
        
    
    
    return 0;
}
