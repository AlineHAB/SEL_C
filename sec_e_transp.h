#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sec_transp{
    char * nome;
    char cpf[100];
    char senha[100];

    //necessario um campo que garanta que e um secretario ou transportador, por equanto vou deixar 1 para secretario e 2 para transportador
    int identificador;
    struct sec_transp *prox;
}SEC_TR;

SEC_TR sec1, sec2, sec3, transp1, transp2, transp3, transp4, transp5;
SEC_TR sec1 = {.nome = "Secretario 1", .cpf = "433.939.340-15", .senha = "secretario2222", .identificador = 1, .prox = &sec2};
SEC_TR sec2 = {.nome = "Secretario 2", .cpf = "348.589.917-30", .senha = "secretario1265", .identificador = 1, .prox = &sec3};
SEC_TR sec3 = {.nome = "Secretario 3", .cpf = "423.599.760-28", .senha = "secretario9732", .identificador = 1, .prox = &transp1};
SEC_TR transp1 = {.nome = "Transportador 1", .cpf = "446.186.810-98", .senha = "transportador3221", .identificador = 2, .prox = &transp2};
SEC_TR transp2 = {.nome = "Transportador 2", .cpf = "439.127.180-08", .senha = "transportador7864", .identificador = 2, .prox = &transp3};
SEC_TR transp3 = {.nome = "Transportador 3", .cpf = "944.979.350-60", .senha = "transportador9023", .identificador = 2, .prox = &transp4};
SEC_TR transp4 = {.nome = "Transportador 3", .cpf = "515.070.820-88", .senha = "transportador8074", .identificador = 2, .prox = &transp5};
SEC_TR transp5 = {.nome = "Transportador 4", .cpf = "244.939.960-72", .senha = "transportador6485", .identificador = 2, .prox = NULL};

SEC_TR * sectr_ini = &sec1;
SEC_TR * sectr_fim = &transp5;
int sectr_tam = 8;

int verificador(char cpf[100], char senha[100]) {
    if (strcmp(sectr_ini ->cpf, cpf) == 0 && strcmp(sectr_ini ->senha, senha) == 0) {
        return 1;
    }

    else if (strcmp(sectr_fim ->cpf, cpf) == 0 && strcmp(sectr_fim ->senha, senha) == 0) {
        return 1;
    }

    else {
        SEC_TR *aux = sectr_ini;
        for (int i = 0; i < sectr_tam; i++) {
            if (strcmp(aux -> cpf, cpf) == 0 && strcmp(aux -> senha, senha) == 0) {
                return 1;
            }

            else {
                aux = aux -> prox;
            }
        }
    }
}
