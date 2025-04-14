#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "StoreVariables.h"
#include "OutputPrint.h"

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