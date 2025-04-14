#ifndef STORE_VARIABLES_H
#define STORE_VARIABLES_H

#define MAX_VARIABLES 100
#define MAX_NAME_LEN 50

typedef struct {
     char name[MAX_NAME_LEN];
     int value;
} Variable;

void store_variable(const char* name, int value);
int get_variable(const char* name, int* found);

#endif