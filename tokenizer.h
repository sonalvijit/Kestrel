#ifndef TOKENIZER_H
#define TOKENIZER_H

#define MAX_TOKENS 128
#define MAX_TOKEN_LEN 64

typedef struct {
    char tokens[MAX_TOKENS][MAX_TOKEN_LEN];
    int count;
} TokenList;

TokenList tokenize(const char *input);

#endif
