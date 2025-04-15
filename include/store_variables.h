/*
 * StoreVariables.h
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