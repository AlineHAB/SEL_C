#include <stdio.h>
#include <stdlib.h>


typedef struct pedido{
    int identificador;
    char * nome_aluno;
    int matricula;
    char * descricao;
    int prioridade;
    
}PEDIDO;

typedef struct no{
   
    PEDIDO *p;
    
    //mecanismo p/ unir nos!
    struct no * prox;
}No;

No* inicio = NULL;
No * fim = NULL;
int tam = 0;

void inserir_na_fila(int identificador, char *nome_aluno,int matricula, char * descricao, int prioridade){
    
        PEDIDO * p = malloc(sizeof(PEDIDO));

        p->identificador = identificador;
        p->nome_aluno = nome_aluno;
        p->matricula = matricula;
        p->descricao = descricao;
        p->prioridade = prioridade;
        
        No * novo = malloc(sizeof(No));
        novo->p = p;
        novo->prox = NULL;
    
    
        if(inicio == NULL){ //fila vazia
            inicio = novo;
            fim = novo;
            tam++;
        }else{ //adiciona de acordo com a prioridade! :D
            //modificar!
            //prioridade numeros de 0 a 100
            //se o numero for menor que 100 ele entra no inicio; 
          
            fim->prox = novo;
            fim = novo;
            tam++;
        }
}


void imprimir(){
    No * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("Identificador: %d\n", aux->p->identificador);
            aux = aux->prox;
    }
}

PEDIDO remover_fila(){
    PEDIDO pedido;
        //remover!
        if(inicio != NULL){ //remover do antigo inicio da lista!
            
            No *lixo = inicio;
            inicio = inicio->prox;
            pedido.identificador = lixo->p->identificador;
            pedido.nome_aluno = lixo->p->nome_aluno;
            pedido.matricula = lixo->p->matricula;
            pedido.descricao = lixo->p->descricao;
            free(lixo);
            tam--;
            if(tam == 1){
                inicio == NULL;
                fim = NULL;
            
            
            }
        }
    return pedido;
}


