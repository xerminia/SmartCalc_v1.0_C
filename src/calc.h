#ifndef SRC_CALC_H_
#define SRC_CALC_H_

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack_chislo Stack_chislo;

struct Stack_chislo {
  double Data;
  Stack_chislo* Next;
};

typedef struct Stack_sim Stack_sim;

struct Stack_sim {
  char Data;
  Stack_sim* Next;
};

char* calcash(char* arr, char* x);

//======= Функция реализации приоритета операций =========

int priority(char a);

// ============== Добавление элемента в стек =============

void push_chislo(Stack_chislo** t, double x);
void push_sim(Stack_sim** t, char x);

// ============== Извлечение элемента из стека ===============

double pop_chislo(Stack_chislo** t);
char pop_sim(Stack_sim** t);

// Все остальное

bool to_sym_no_minus(char x);
bool to_sym(char x);
void operating(Stack_sim** headsym, Stack_chislo** head);
int two_sim(char s);
void destroy(Stack_sim** headsym, Stack_chislo** head);
char* s21_strcat(char* dest, const char* src);
int two_sim_no_skobka(char s);
bool check_x_bool(char x);
int check_x(char* x);

#endif  // SRC_CALC_H_
