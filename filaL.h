#include <stdio.h>
#include <stdlib.h>
#define MAX_PRIORIDADE 100

typedef struct Vertice{
    int id;
    char * nome_aluno;
    int *matricula;
    char * descricao;
    
    struct Vertice * esq;
    struct Vertice * dir;
}VERTICE;


typedef struct pedido{
    int identificador;
    char * nome_aluno;
    int *matricula;
    char * descricao;

    char *campus_doaluno;
    char *campus_livro;
    char *respon_encomenda;

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
    
        p->nome_aluno = encomenda->nome_aluno;
        //mesma coisa para matricula e para descricao...
    
        printf("(aluno) Informe o seu campus: \n");
        p->campus_doaluno = malloc(sizeof(char));
        scanf(" %[^\n]s", p->campus_doaluno);
        
        printf("(Pedido) Informe o campus que o livro está: \n");
        p->campus_livro = malloc(sizeof(char));
        scanf(" %[^\n]s", p->campus_livro);

        printf("Responsavel pela encomenda: \n");
        p->respon_encomenda = malloc(sizeof(char));
        scanf(" %[^\n]s", p->respon_encomenda);
    
        printf("Insira a prioridade do pedido: \n");
        scanf("%d", &p->prioridade);
    
        No * novo = malloc(sizeof(No));
        novo->p = malloc(sizeof(PEDIDO));
        novo->p = p;
        novo->prox = NULL;

        if(inicio == NULL){
            inicio = novo;
            fim = novo;
            tam++;
        }else if (novo->p->prioridade < fim-p->prioridade) {
                fim -> prox = novo;
                fim = novo;
                tam++;
            }else if (novo->p->prioridade > inicio->p->prioridade) {
                novo -> prox = inicio;
                inicio = novo;
                tam++;
            }
            else{
                No * aux = inicio;
                while(aux->prox != NULL && novo->p->prioridade < aux->prox->p-> prioridade) {
                    aux = aux->prox;
                }
                   //novo->prox = aux -> prox;
                   //aux -> prox = novo;
                   //tam++;
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
                inicio = NULL;
                fim = NULL;
            }
        }
    return pedido;
}

