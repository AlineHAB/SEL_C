#include <stdio.h>
#include <stdlib.h>

typedef struct SEC_TR{
    char * nome;
    char cpf[100];
    char senha[100];

    //necessario um campo que garanta que e um secretario ou transportador, por equanto vou deixar 1 para secretario e 2 para transportador
    int verificador;
    struct SEC_TR* prox;
}SEC_TR;


SEC_TR sec1 = {.nome = "Secretario 1", .cpf = "433.939.340-15", .senha = "secretario2222", .verificador = 1};
SEC_TR sec2 = {.nome = "Secretario 2", .cpf = "348.589.917-30", .senha = "secretario1265", .verificador = 1};
SEC_TR sec3 = {.nome = "Secretario 3", .cpf = "423.599.760-28", .senha = "secretario9732", .verificador = 1};

SEC_TR transp1 = {.nome = "Transportador 1", .cpf = "446.186.810-98", .senha = "transportador3221", .verificador = 2};
SEC_TR transp2 = {.nome = "Transportador 2", .cpf = "439.127.180-08", .senha = "transportador7864", .verificador = 2};
SEC_TR transp3 = {.nome = "Transportador 3", .cpf = "944.979.350-60", .senha = "transportador9023", .verificador = 2};
SEC_TR transp4 = {.nome = "Transportador 3", .cpf = "515.070.820-88", .senha = "transportador8074", .verificador = 2};
SEC_TR transp5 = {.nome = "Transportador 4", .cpf = "244.939.960-72", .senha = "transportador6485", .verificador = 2};