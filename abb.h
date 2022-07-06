#include "Identificador.h"

typedef struct Vertice{
    int id; 
    char * nome_aluno;
    int *matricula;
    char * descricao;
    
    struct Vertice * esq;
    struct Vertice * dir;
}VERTICE;

VERTICE * raiz = NULL;

VERTICE* buscar(int id, VERTICE *aux){
    
    if(aux != NULL){
        if(aux->id == id){
            return aux;
        }else if(id < aux->id){
            if(aux->esq != NULL){
                return buscar(id, aux->esq);
            }else{
                return aux;
            }
        }else if(id > aux->id){
            if(aux->dir != NULL){
                return buscar(id, aux->dir);
            }else{
                return aux;
            }
        }
    }else{
        return NULL;
    }
}

void add_abb(int id, char *nome_aluno, int *matricula, char *descricao){

    VERTICE* aux = buscar(id, raiz);
    
    if(aux != NULL && aux->id == id){
        printf("Insercao invalida!\n");
    }else{
        
        VERTICE* novo = malloc(sizeof(VERTICE));
        novo->id = id;
        novo->nome_aluno = nome_aluno;
        novo->matricula = matricula;
        novo->descricao = descricao;
        novo->esq = NULL;
        novo->dir = NULL;
        
        if(aux == NULL){
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

void in_ordem(VERTICE *aux){
    
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    printf("%d \n", aux->id);
    printf("%s \n", aux->nome_aluno);
    printf("%d \n", aux->matricula);
    printf("%s \n", aux->descricao);
    if(aux->dir != NULL){
        in_ordem(aux->dir);
        }
}
void insert_dados(){
    
    printf("Gerando ID:\n");
    int id_gerado = identificador();
    printf("Digite o nome do aluno: \n");
    char * nome =(char * )malloc(100 * sizeof(char));
    scanf(" %[^\n]s", nome);
    printf("Matricula: \n");
    int *matricula = malloc(sizeof(int));
    scanf("%d", &matricula);
    printf("Descricao: \n");
    char * descricao = (char * )malloc(100 * sizeof(char));
    scanf(" %[^\n]s", descricao);
    
    add_abb(id_gerado,nome,matricula,descricao);
}

VERTICE* remover(VERTICE *raiz, int id) {
    if(raiz == NULL){
        printf("ID nao encontrado!\n");
        return NULL;
    } else { 
        if(raiz->id == id) {
            
            if(raiz->esq == NULL && raiz->dir == NULL) {
                free(raiz);
                printf("ID removido: %d! \n", id);
                return NULL;
            }
            else{
                if(raiz->esq != NULL && raiz->dir != NULL){
                    VERTICE *aux = raiz->esq;
                    while(aux->dir != NULL)
                        aux = aux->dir;
                    raiz->id = aux->id;
                    aux->id = id;
                    printf("ID trocado: %d! \n", id);
                    raiz->esq = remover(raiz->esq, id);
                    return raiz;
                }
                else{
                    VERTICE *aux;
                    if(raiz->esq != NULL)
                        aux = raiz->esq;
                    else
                        aux = raiz->dir;
                    free(raiz);
                    printf("ID removido: %d! \n", id);
                    return aux;
                }
            }
        } else {
            if(id < raiz->id)
                raiz->esq = remover(raiz->esq, id);
            else
                raiz->dir = remover(raiz->dir, id);
            return raiz;
        }
    }
}








