#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "abb.h"
#include "fila.h"


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
        /*if(resp == 1){*/

        typedef struct pedido{

        int id; //identificador
        char * nome_aluno;
        int matricula;
        char * descricao;
        struct PEDIDO *P;//USADO NO REMOVER

        //mecanismo p/ unir nos!

        struct PEDIDO * esq;
        struct PEDIDO * dir;

        }PEDIDO;

        typedef struct no{

            struct no *prox;

        }NO;

        NO *inicio = NULL;
        NO *fim = NULL;
        int tam = 0;

        PEDIDO *raiz = NULL;



//-----------------------------------------------------------------------------------
        //criar um funcao para gerar id unico (:D)

        int id_unic(){

        int num;
        srand(time(NULL));

        num = rand() % 10;
        printf("\n %d", num);

        return 0;

        }


//-----------------------------------------------------------
        //add_abb(id, nome, matricula, descricao);

        void add_abb(int id, char *nome_aluno, int matricula, char *descricao){

        PEDIDO* aux = buscar(id, raiz);

        if(aux != NULL && aux->id == id){
            printf("Insercao invalida!\n");
        }else{

            PEDIDO* novo = malloc(sizeof(PEDIDO));
            novo->id = id;
            novo->nome_aluno = nome_aluno;
            novo->matricula = matricula;
            novo->descricao = descricao;
            novo->esq = NULL;
            novo->dir = NULL;

            if(aux == NULL){//arvore esta vazia
                raiz = novo;
            }else{
                if(id < aux->id){
                    aux->esq = novo;
                }else{
                    aux->dir = novo;
                }
            }
        }
    }


    void in_ordem(PEDIDO *aux){

        if(aux->esq != NULL){
            in_ordem(aux->esq);
        }
        printf("%d\n", aux->id);
        printf("%s\n", aux->nome_aluno);
        printf("%d\n", aux->matricula);
        printf("%s\n", aux->descricao);
        if(aux->dir != NULL){
            in_ordem(aux->dir);
            }
    }



//-------------------------------------------------------------------------------------------------------
//ENTENDENDO UM REMOVER COMUM

    /*NO *remover(NO *raiz, int chave){
    if(raiz == NULL){
        printf("valor não encontrado!\n");
        return NULL;
    }else{ //prcurar o no que quer remover
        if(raiz->conteudo == chave){
            //remover nos folhas(nos sem filhos)
            if(raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                printf("Elemento folha removido: !\n", chave);
                return NULL;
            }else{
                //remover nós com 2 filhos
                if(raiz->esquerda != NULL && raiz->direita != NULL){
                    NO *aux = raiz->esquerda;
                    while(aux->direita != NULL)
                        aux = aux->direita;
                    raiz->conteudo = auz->conteudo;
                    aux->conteudo = chave;
                    raiz->esquerda = remover(raiz->esquerda,chave);
                    return raiz;

                }else{//remover nós que tem apenas 1 filho
                    No *aux;
                    if(raiz->esquerda !=NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    return aux;
                }
            }
        }else{
            if(chave< raiz->conteudo)
                raiz->esquerda = remover(raiz->esquerda, chave);
            else
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
    }
*/







//-----------------------------------------------------------------------------------------------------
        /*}else if(resp == 2){
            //remover uma encomenda de livro da ABB (id)
            //para remover eu preciso:
            //1 - visualizar as encomendas (in_ordem)
            in_ordem();
            //2 - verificar o usuario
            printf(" Digite seu cpf:\n");
            char cpf[100];
            scanf("%s", &cpf);
            printf(" Digite sua senha:\n");
            char senha[100];
            scanf("%s", &senha);
            //int retorno = verificar(cpf, senha);
            if(retorno == 1){
                //3 - chama a funcao remover_abb por id (CADE ESSA FUNCAO?)
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
                    //int retorno = verificar(cpf, senha);
                    if(retorno == 1){
                        //remover da fila de prioridade
                    }
            }

        }*/

    }

int main(){
    /*//encomendar um livro
         printf(" Digite o nome do aluno:\n");
         char * nome = malloc(sizeof(char));
         scanf(" %[^\n]s", nome);
         //... matricula e descricao..*/
         /*scanf("%d", matricula);
         printf("Descrição: \n");
         char * descricao = malloc(sizeof(char));
         scanf(" %[^\n]s", descrição);*/
         id_unic();




return 0;
}
