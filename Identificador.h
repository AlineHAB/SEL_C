#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int id(){
    int id[1000];
    int soma =0;
    srand(time(NULL));

    for (int i =0; i<=5; i++){
        id[i]= rand()%10;
        soma = id[i]+ soma*10;
        
           
    }
    printf("%d\n", soma);
    return soma;

}
