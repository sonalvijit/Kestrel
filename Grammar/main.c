#include <stdio.h>
#include "parse.h"  // from peg_generator
#include "tokenizer.h"

int main() {
    const char *source = "let x = 10 + 5";

    Parser *p = _PyPegen_new_parser(source, NULL, NULL, NULL);
    mod_ty tree = start_rule(p);  // This will call your `start[]` rule

    if (tree) {
        printf("Parsed successfully!\n");
    } else {
        printf("Parsing failed.\n");
    }

    _PyPegen_destroy_parser(p);
    return 0;
}
