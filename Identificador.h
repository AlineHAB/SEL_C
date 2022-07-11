#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int identificador(){
    int id; 
    int sort_id =0 ;
    srand(time(NULL));

    sort_id = rand()%9;
    if (sort_id % 2 == 0){
          id = 1000 + rand()%5000;
          printf("%d\n", id);
    }else {
          id = 5000 + rand()%5000;
          printf("%d\n", id);
    }
   return id;
}
