#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

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

void reduction_of_variables(char *string);
void check_unar_symbol(char *string);
int chityvatel_stroki(char *string);
int check_priority(char symb);
void math(Stack *my_stack_for_number, Stack *my_stack_for_symbol);
double priority_6(double number);
double priority_5(double number_1, double number_2);
double priority_4(char symbol, double number_1, double number_2);
double priority_3(char symbol, double number_1);
double priority_2(char symbol, double number_1, double number_2);


// void check_unar_symbol(char *string, char *string_final);
// // char check_is_digit(char *string, Stack *my_steck, Data elem);
// int chityvatel_stroki(Stack *my_stack_for_number, Stack *my_stack_for_symbol, char *string, char* string_for_chityvatel);
// // void proverka_na_chislo(int i, int j, char *t, char *string);