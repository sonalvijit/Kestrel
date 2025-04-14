#include "StoreVariables.h"
#include <string.h>

static Variable variables[MAX_VARIABLES];
static int variable_count = 0;

void store_variable(const char* name, int value){
     for(int i = 0; i < variable_count; ++i){
          if(strcmp(variables[i].name, name) == 0){
               variables[i].value = value;
               return;
          }
     }

     if(variable_count < MAX_VARIABLES){
          strncpy(variables[variable_count].name, name, MAX_NAME_LEN);
          variables[variable_count].value = value;
          variable_count++;
     }
}

int get_variable(const char* name, int* found){
     for(int i = 0; i < variable_count; ++i){
          if(strcmp(variables[i].name, name) == 0){
               *found = 1;
               return variables[i].value;
          }
     }
     *found = 0;
     return 0;
}