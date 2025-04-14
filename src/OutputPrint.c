#include <stdio.h>
#include "StoreVariables.h"

void print_output(const char* arg){
     int found = 0;
     int value = get_variable(arg, &found);

     if(found){
          printf("%d\n", value);
     } else {
          printf("%s\n", arg);
     }
}