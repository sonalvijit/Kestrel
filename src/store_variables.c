/*
 * StoreVariables.c
 *
 * Kestrel Programming Language Interpreter
 * Copyright (C) 2025 Sonal Vijit
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

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