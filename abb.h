#include "Identificador.h"
#include "filaL.h"


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
    printf("%d\n", aux->id);
    printf("%s\n", aux->nome_aluno);
    printf("%d\n", aux->matricula);
    printf("%s\n", aux->descricao);
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

VERTICE* remover(VERTICE *novo, int id) {
    if(novo == NULL){
        printf("ID nao encontrado!\n");
        return NULL;
    }else{
        if(id < novo->id){
                novo->esq = remover(novo->esq, id);
        }else if(id > novo ->id){
                novo->dir = remover(novo->dir, id);
        }else{
    
            
            inserir_na_fila(novo);
            
            
            if(novo->esq == NULL && novo->dir == NULL) {
                free(novo);
                printf("ID removido: %d! \n", id);
                
            }else{
                if(novo->esq != NULL && novo->dir != NULL){
                    VERTICE *aux = novo->esq;
                    while(aux->dir != NULL)
                        aux = aux->dir;
                    novo->id = aux->id;
                    aux->id = id;
                    printf("ID trocado: %d! \n", id);
                    novo->esq = remover(novo->esq, id);
                    
                }
                else{
                    if(novo->esq != NULL)
                        novo = novo->esq;
                    else
                        novo = novo->dir;
                    free(novo);
                    printf("ID removido: %d! \n", id);
                
                }
            }
        }
        return novo;
    }
}








