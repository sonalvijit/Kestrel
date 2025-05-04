#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "tokenizer.h"

TokenList tokenize(const char *input) {
    TokenList list;
    list.count = 0;

    int i = 0;
    while (input[i] != '\0') {
        if (isspace(input[i])) {
            i++;
            continue;
        }

        if (input[i] == '(' || input[i] == ')') {
            // Single char token
            list.tokens[list.count][0] = input[i];
            list.tokens[list.count][1] = '\0';
            list.count++;
            i++;
        } else {
            // Parse symbol or number
            int j = 0;
            while (input[i] != '\0' && !isspace(input[i]) && input[i] != '(' && input[i] != ')') {
                list.tokens[list.count][j++] = input[i++];
            }
            list.tokens[list.count][j] = '\0';
            list.count++;
        }
    }

    return list;
}
