#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum { T_LET, T_NAME, T_EQ, T_PLUS, T_NUMBER, T_NEWLINE, T_END } TokenType;

typedef struct {
    TokenType type;
    char value[64];
} Token;

Token tokenize(const char* input) {
    // Basic tokenizer example
    // You should implement a real tokenizer here
}
