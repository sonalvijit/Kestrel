/*
 * Parser.c
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
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "store_variables.h"
#include "output_print.h"

void trim_spaces(char* str){
     char* src = str;
     char* dst = str;
     while(*src){
          if(!isspace((unsigned char)*src)){
               *dst++ = *src;
          }
          ++src;
     }
     *dst = '\0';
}

void run_line(const char* line){
     if(strncmp(line, "print(",6) == 0){
          char expr[100];
          strncpy(expr, line + 6, sizeof(expr));
          char* closing = strchr(expr, ')');
          if(closing) *closing = '\0';

          trim_spaces(expr);
          print_output(expr);
     } else {
          char var[50], expr[50];
          if(sscanf(line, "%49[^=]=%49s", var, expr) == 2){
               trim_spaces(var);
               trim_spaces(expr);
               int val = atoi(expr);
               store_variable(var, val);
          }
     }
}