#include "abb.h"
#include "filaL.h"
#include "sec_e_transp.h"


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
        if(resp == 1){
            
              system("cls");
              insert_dados();
              printf("\n\n");
//-----------------------------------------------------------------------------------

       }else if(resp == 2){
            //remover uma encomenda de livro da ABB (id)
            //para remover eu preciso:
            //1 - visualizar as encomendas (in_ordem)
            
            system("cls");
            in_ordem(raiz);
            
           
            
            
            //2 - verificar o usuario
            printf(" Digite seu cpf:\n");
            char cpf[100];
            scanf("%s", &cpf);
            printf(" Digite sua senha:\n");
            char senha[100];
            scanf("%s", &senha);
            int retorno = verificador_secretario(cpf, senha);
            if(retorno == 1){
                //3 - chama a funcao remover_abb por id (CADE ESSA FUNCAO?)
                int id = 0;
                printf("Digite o número do id a ser removido\n");
                scanf("%d", &id);
                remover(raiz, id);
                //4 - setar novos dados (faltando)
                //5 - add_fila(....);
        }else if(resp == 3){
               
                //2 - verificar o usuario
            printf(" Digite seu cpf:\n");
            char cpf[100];
            scanf("%s", &cpf);
            printf(" Digite sua senha:\n");
            char senha[100];
            scanf("%s", &senha);
            int retorno = verificador_transportador(cpf, senha);
            if(retorno == 1){
                //remover da fila de prioridade
                remover_fila();
                printf("Pedido removido com sucesso!\n");
                }
            }
        
        }
        
    }
    
    return 0;
}
