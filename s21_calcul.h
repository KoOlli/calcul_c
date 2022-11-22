#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef union {
  double number;
  char symbol;
} Data;

typedef struct node {
  Data data;
  struct node *next;
} Node;

typedef struct {
  Node *top;
} Stack;


Stack *create_stack();
Data pop_elem(Stack *s);
void push_elem(Stack *s, Data elem);
void distroy(Stack *s);
int is_empty(Stack *s);
void check_unar_symbol(char *string, char *string_final);
void reduction_of_variables(char *string, char *string_final);
char check_is_digit(char *string, Stack *my_steck, Data elem);
int chityvatel_stroki(Stack *my_stack_for_number, Stack *my_stack_for_symbol, char *string, char* string_for_chityvatel);
void proverka_na_chislo(int i, int j, char *t, char *string);