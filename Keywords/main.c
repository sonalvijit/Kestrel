#include <stdio.h>
#include <string.h>
#include "keywords.h"

int is_keyword(const char *token){
     for(int i = 0; keywords[i] != NULL; ++i){ if(strcmp(token, keywords[i]) == 0) return 1; }
     return 0;
}

int main(){
     const char *test_tokens[] = {"if", "variable", "while", "function", NULL};

     for (int i = 0; test_tokens[i] != NULL; ++i) {
         if (is_keyword(test_tokens[i])) {
             printf("\"%s\" is a keyword.\n", test_tokens[i]);
         } else {
             printf("\"%s\" is not a keyword.\n", test_tokens[i]);
         }
     } 
     return 0;
}