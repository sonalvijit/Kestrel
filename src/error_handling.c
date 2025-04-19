#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_VARS 100
#define MAX_NAME_LEN 32
#define MAX_LINE_LEN 128

typedef struct {
    char name[MAX_NAME_LEN];
    double value;
    int defined;
} Variable;

Variable vars[MAX_VARS];

Variable* get_var(const char* name) {
    for (int i = 0; i < MAX_VARS; i++) {
        if (vars[i].defined && strcmp(vars[i].name, name) == 0)
            return &vars[i];
    }
    return NULL;
}

Variable* set_var(const char* name, double value) {
    for (int i = 0; i < MAX_VARS; i++) {
        if (!vars[i].defined || strcmp(vars[i].name, name) == 0) {
            strcpy(vars[i].name, name);
            vars[i].value = value;
            vars[i].defined = 1;
            return &vars[i];
        }
    }
    return NULL;
}

// Very basic evaluator: supports only single-variable math like `x + 2`
double eval_expr(const char* expr, int* error) {
    char var[MAX_NAME_LEN] = "";
    char op = 0;
    double val = 0;

    int scanned = sscanf(expr, "%31s %c %lf", var, &op, &val);

    if (scanned == 1 && isalpha(var[0])) {
        Variable* v = get_var(var);
        if (!v) {
            *error = 1;
            printf("[Error] Undefined variable '%s'\n", var);
            return 0;
        }
        return v->value;
    } else if (scanned == 3 && isalpha(var[0])) {
        Variable* v = get_var(var);
        if (!v) {
            *error = 1;
            printf("[Error] Undefined variable '%s'\n", var);
            return 0;
        }

        if (op == '/' && val == 0) {
            *error = 1;
            printf("[Error] Division by zero\n");
            return 0;
        }

        switch (op) {
            case '+': return v->value + val;
            case '-': return v->value - val;
            case '*': return v->value * val;
            case '/': return v->value / val;
            default:
                *error = 1;
                printf("[Error] Unknown operator '%c'\n", op);
                return 0;
        }
    }

    *error = 1;
    printf("[Error] Invalid expression\n");
    return 0;
}

void handle_line(const char* line) {
    char cmd[MAX_LINE_LEN];
    if (sscanf(line, "print(%127[^)])", cmd) == 1) {
        int error = 0;
        double result = eval_expr(cmd, &error);
        if (!error) {
            printf("%g\n", result);
        }
    } else {
        // Try parsing as assignment
        char name[MAX_NAME_LEN];
        char expr[MAX_LINE_LEN];
        if (sscanf(line, "%31s = %127[^\n]", name, expr) == 2) {
            if (!isalpha(name[0])) {
                printf("[Error] Invalid variable name\n");
                return;
            }
            int error = 0;
            double value = eval_expr(expr, &error);
            if (!error) {
                set_var(name, value);
            }
        } else {
            printf("[Error] Invalid syntax\n");
        }
    }
}

int main() {
    printf("JoeLang C Interpreter (type 'exit' to quit)\n");
    char line[MAX_LINE_LEN];

    while (1) {
        printf(">> ");
        if (!fgets(line, sizeof(line), stdin))
            break;
        if (strncmp(line, "exit", 4) == 0)
            break;

        handle_line(line);
    }

    return 0;
}
