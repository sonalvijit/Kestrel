/*
 * main.c
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
#include "Parser.h"

int main(int argc, char* argv[]){
     if(argc!=2){
          printf("Usage: Kestrel <filename.kes>\n");
          return 1;
     }

     FILE* file = fopen(argv[1], "r");
     if(!file){
          printf("Could not open file: %s\n", argv[1]);
          return 1;
     }

     char line[256];
     while(fgets(line, sizeof(line), file)){
          run_line(line);
     }

     fclose(file);
     return 0;
}