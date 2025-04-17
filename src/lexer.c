/*
 * lexer.c
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

typedef enum{
     TOKEN_UNKNOWN,
     TOKEN_INT,
     TOKEN_RETURN,
     TOKEN_INT,
     TOKEN_IF,
     TOKEN_ELSE,
     TOKEN_WHILE,
     TOKEN_FOR,
     TOKEN_IDENTIFIER,
     TOKEN_NUMBER,
     TOKEN_EOF
} TokenType;

typedef struct{
     const char* keyword;
     TokenType token;
} keyword;

keyword keywords[] = {
     {"int", TOKEN_INT},
     {"return", TOKEN_RETURN},
     {"if", TOKEN_IF},
     {"else", TOKEN_ELSE},
     {"while",TOKEN_WHILE},
     {"for", TOKEN_FOR},
     {NULL, TOKEN_UNKNOWN}
};

TokenType identify_keyword(const char* str){
     for(int i = 0; keywords[i].keyword != NULL; ++i){
          if(strcmp(str, keywords[i].keyword) == 0) return keywords[i].token;
     }
     return TOKEN_IDENTIFIER;
}

int main(){
     char word[64];
     while(scanf("%63s", word) == 1){
          TokenType t = identify_keyword(word);
          printf("Token: %d (%s)\n", t, word);
     }
     return 0;
}