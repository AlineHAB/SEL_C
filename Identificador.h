#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int id(){
    int numero;
    int min = 0;
    int max = 10000;

    srand(time(NULL));

    numero = (rand() % (min + max * 3))+ max;
      

      return numero;
};
