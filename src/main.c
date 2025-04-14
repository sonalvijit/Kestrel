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