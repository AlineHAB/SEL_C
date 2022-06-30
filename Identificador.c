#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int id(){
    int number;
    int lower = 0;
    int upper = 10000;

    srand(time(NULL));

    number = (rand() % (lower + upper * 3))+ upper;
      

      return number;
};
