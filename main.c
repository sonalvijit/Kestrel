#include <stdio.h>
#include "tokenizer.h"

int main() {
    char input[256];
    printf("MiniLisp > ");
    fgets(input, sizeof(input), stdin);

    TokenList tokens = tokenize(input);

    printf("Tokens:\n");
    for (int i = 0; i < tokens.count; i++) {
        printf("  [%d]: %s\n", i, tokens.tokens[i]);
    }

    return 0;
}
