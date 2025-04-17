/*
 * OutputPrint.c
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

#include <stdio.h>
#include "store_variables.h"

void print_output(const char* arg){
     int found = 0;
     int value = get_variable(arg, &found);

     if(found){
          printf("%d\n", value);
     } else {
          printf("%s\n", arg);
     }
}