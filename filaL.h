#include <stdio.h>
#include <stdlib.h>
#define MAX_PRIORIDADE 100


typedef struct pedido{
    int identificador;
    char * nome_aluno;
    int *matricula;
    char * descricao;
    int prioridade;
    
}PEDIDO;

typedef struct no{
   
    PEDIDO *p;
    char *nomecampuslivro, *nomecampusaluno;
    struct no * prox;
}No;

No* inicio = NULL;
No * fim = NULL;
int tam = 0;

void inserir_na_fila(VERTICE *encomenda){
    
        PEDIDO * p = malloc(sizeof(PEDIDO));
        
        p->identificador = encomenda->id;
        p->nome_aluno = encomenda->nome_aluno;
        p->matricula = encomenda->matricula;
        p->descricao = encomenda->descricao;
     
        No * novo = malloc(sizeof(No));
        printf("insira o campus do livro: \n");
        scanf("%s", novo->nomecampuslivro);
        printf("insira o campus do aluno: \n");
        scanf("%s", novo->nomecampusaluno);
        printf("insira a prioridade do pedido: \n");
        scanf("%d", novo->p->prioridade);
        novo->p = p;
        novo->prox = NULL;
    
    
        if(inicio == NULL){ 
            inicio = novo;
            fim = novo;
            tam++;
        }else{
            if (novo -> p -> prioridade == 0) {
                fim -> prox = novo;
                fim = novo;
                tam++;
            }
            
            else if (novo->p->prioridade == MAX_PRIORIDADE) {
                novo -> prox = inicio;
                inicio = novo;
                tam++;
            }

            else {
                No * aux = inicio;
                for (int i = 0; i < tam - 1; i++) {
                    if (novo->p->prioridade > aux -> prox -> p -> prioridade) {
                        novo -> prox = aux -> prox;
                        //novo -> prox = aux -> prox;
                        aux -> prox = novo;
                        tam++;
                        break;
                    } 
                    else {
                        aux = aux -> prox;
                    }

            }
        }
    }
}


void imprimir(){
    No * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("identificador: %s\n", aux->p->identificador);
        printf("nome do aluno: %s\n", aux->p->nome_aluno);
        printf("livro: %s\n", aux->p->descricao);
            aux = aux->prox;
    }
}

PEDIDO remover_fila(){
    PEDIDO pedido;
        //remover!
        if(inicio != NULL){
            
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

