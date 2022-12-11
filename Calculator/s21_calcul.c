#include "s21_calcul.h"
#define P 3.141592653589793238462643383279502884197169399375105820974944592

//#define x 1.0

Stack *create_stack() {
  Stack *s = malloc(sizeof(Stack));
  s->top = 0;
  return s;
}

Data pop_elem(Stack *s) {
  // создаем переменную к-ю будем возвращать
  Data result;
  // если вершины нет
  if (s->top == NULL) {
    // возвращаем конец строки/отсутствие эл-тов
    result.symbol = '\0';
    // иначе
  } else {
    // временная переменная, к-я принимает значение вершины
    Node *temp = s->top;
    // значению вершины присваивается следующее значение (ранее положенное)
    s->top = s->top->next;
    // возвращаемая переменная принимает значение того верхнего элемента, к-й мы
    // вытащили и будем возвращать
    result = temp->data;
    // очищаем временную переменную
    free(temp);
  }
  return result;
}

void push_elem(Stack *s, Data elem) {
  Node *elem_in_use_now = malloc(sizeof(Node));
  elem_in_use_now->data = elem;
  if (s->top) {
    elem_in_use_now->next = s->top;
  } else {
    elem_in_use_now->next = NULL;
  }
  s->top = elem_in_use_now;
}

void distroy(Stack *s) {
  while (is_empty(s) == 1) {
    pop_elem(s);
  }
}

int is_empty(Stack *s) {
  int result = 1;
  if (s == NULL || s->top == NULL) {
    result = 0;
  }
  return result;
}

//double reduction_string_with_x(char *string, double var_x) {
//  char *string_final = calloc(strlen(string) + 1, sizeof(char));
//  int j = 0, k = 0;

//}

double reduction_of_variables(char *string) {
  double resultat = 0.0;
  Stack *my_stack_for_number = create_stack();
  Stack *my_stack_for_symbol = create_stack();
  char *string_final = calloc(strlen(string) + 1, sizeof(char));
  for (int i = 0, j = 0; string[i] != '\0'; i++) {
    if (string[i] == 's' && string[i + 1] == 'i') {
      string_final[j] = 'S';
      j++;
      i += 2;
    } else if (string[i] == 'c') {
      string_final[j] = 'C';
      j++;
      i += 2;
    } else if (string[i] == 't') {
      string_final[j] = 'T';
      j++;
      i++;
    } else if (string[i] == 'a' && string[i + 1] == 't') {
      string_final[j] = 'I';
      j++;
      i += 3;
    } else if (string[i] == 'a' && string[i + 1] == 's') {
      string_final[j] = 'B';
      j++;
      i += 3;
    } else if (string[i] == 'a' && string[i + 1] == 'c') {
      string_final[j] = 'O';
      j++;
      i += 3;
    } else if (string[i] == 'l' && string[i + 1] == 'o') {
      string_final[j] = 'L';
      j++;
      i += 2;
    } else if (string[i] == 'l' && string[i + 1] == 'n') {
      string_final[j] = 'G';
      j++;
      i++;
    } else if (string[i] == 's' && string[i + 1] == 'q') {
      string_final[j] = 'Q';
      j++;
      i += 3;
    } else {
      string_final[j] = string[i];
      j++;
    }
  }
  check_unar_symbol(string_final, my_stack_for_number, my_stack_for_symbol);
  if (string_final != NULL) free(string_final);
  resultat = my_stack_for_number->top->data.number;
  return resultat;
}

double check_unar_symbol(char *string, Stack *my_stack_for_number, Stack *my_stack_for_symbol) {
  char *string_final = calloc(strlen(string) + 1, sizeof(char));
  if (string[0] == '-') {
    string_final[0] = '~';
  } else if (string[0] == '+') {
    string_final[0] = '#';
  } else {
    string_final[0] = string[0];
  }
  for (int i = 1; string[i] != '\0'; i++) {
    if (string_final[i - 1] == '(' && string[i] == '-') {
      string_final[i] = '~';
    } else if (string_final[i - 1] == '(' && string[i] == '+') {
      string_final[i] = '#';
    } else {
      string_final[i] = string[i];
    }
  }
  line_reader(string_final, my_stack_for_number, my_stack_for_symbol);
  return my_stack_for_number->top->data.number;
}

double line_reader(char *string, Stack *my_stack_for_number, Stack *my_stack_for_symbol) {
  char *string_final = calloc(strlen(string) + 1, sizeof(char));
  int temp_priority = 0;
  Data elem;
  double template = 0.0;
  char *t = calloc(strlen(string), sizeof(char));
  for (int i = 0, j = 0; string[i] != '\0'; i++) {
    int if_isdigit_end = 0;
    while (isdigit(string[i]) == 1 || string[i] == '.') {
      t[j] = string[i];
      i++;
      j++;
      if_isdigit_end = 1;
    }
    string_final = t;
    template = strtod(t, &string_final);
    elem.number = template;
    if (if_isdigit_end == 1) {
      push_elem(my_stack_for_number, elem);
    }
    for (size_t ii = 0; ii < strlen(string) + 1; ++ii) t[ii] = '\0';
    j = 0;
    character_check(string, my_stack_for_number, my_stack_for_symbol, &i, &temp_priority);
  }
  while (my_stack_for_symbol->top != NULL) {
    math(my_stack_for_number, my_stack_for_symbol, &temp_priority);
  }
  return my_stack_for_number->top->data.number;
}

int character_check(char *string, Stack *my_stack_for_number,
                    Stack *my_stack_for_symbol, int *i, int *temp_priority) {
  Data elem;
  if ((isdigit(string[*i]) == 0 || string[*i] != '.') && string[*i] != '\0') {
    if (string[*i] == 'P') {
      elem.number = P;
      push_elem(my_stack_for_number, elem);
      return 0;
    }
    elem.symbol = string[*i];
    if (string[*i] == '(') {
      push_elem(my_stack_for_symbol, elem);
      *temp_priority = check_priority(elem.symbol);
    } else if (string[*i] == ')') {
      while (my_stack_for_symbol->top->data.symbol != '(') {
        math(my_stack_for_number, my_stack_for_symbol, temp_priority);
        if (my_stack_for_symbol->top != NULL) {
          *temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
        }
      }
      if (my_stack_for_symbol->top->data.symbol == '(') {
        pop_elem(my_stack_for_symbol);
        if (my_stack_for_symbol->top != NULL) {
          *temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
        }
      }
      elem.symbol = my_stack_for_symbol->top->data.symbol;
    } else if (check_priority(elem.symbol) == 3) {
      push_elem(my_stack_for_symbol, elem);
      *temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
    } else {
      stack_push(my_stack_for_number, my_stack_for_symbol, elem,
                 temp_priority);
    }
  }
  return 0;
}

void stack_push(Stack *my_stack_for_number, Stack *my_stack_for_symbol,
                Data elem, int *temp_priority) {
  int template;
  if (my_stack_for_symbol->top == NULL) {
    push_elem(my_stack_for_symbol, elem);
    *temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
  } else {
    if ((check_priority(elem.symbol) <= *temp_priority) && !(check_priority(elem.symbol) == 5 && check_priority(my_stack_for_symbol->top->data.symbol) == 5)) {
      template = *temp_priority;
      while (
          (my_stack_for_symbol->top != NULL) &&
          (check_priority(my_stack_for_symbol->top->data.symbol) <= template)) {
        math(my_stack_for_number, my_stack_for_symbol, &template);
      }
      push_elem(my_stack_for_symbol, elem);
      *temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
    } else {
      push_elem(my_stack_for_symbol, elem);
      *temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
    }
  }
}


int check_priority(char symb) {
  int priority = 0;
  switch (symb) {
    case '(':
    case ')':
      priority = 1;
      break;
    case '+':
    case '-':
      priority = 2;
      break;
    case 'S':
    case 'C':
    case 'T':
    case 'I':
    case 'B':
    case 'O':
    case 'L':
    case 'G':
    case 'Q':
      priority = 3;
      break;
    case '%':
    case '*':
    case '/':
      priority = 4;
      break;
    case '^':
      priority = 5;
      break;
    case '~':
    case '#':
      priority = 6;
      break;
    default:
      break;
  }
  return priority;
}

void math(Stack *my_stack_for_number, Stack *my_stack_for_symbol,
          int *temp_priority) {
  double a, b, c = 0.0;
  char t;
  Data elem;
  t = pop_elem(my_stack_for_symbol).symbol;

  if (check_priority(t) == 6) {
    a = pop_elem(my_stack_for_number).number;
    c = priority_6(t, a);

  } else if (check_priority(t) == 5) {
    a = pop_elem(my_stack_for_number).number;
    b = pop_elem(my_stack_for_number).number;
    c = priority_5(a, b);
  } else if (check_priority(t) == 4) {
    a = pop_elem(my_stack_for_number).number;
    b = pop_elem(my_stack_for_number).number;
    c = priority_4(t, a, b);

  } else if (check_priority(t) == 3) {
    a = pop_elem(my_stack_for_number).number;
    c = priority_3(t, a);
  } else if (check_priority(t) == 2) {
    a = pop_elem(my_stack_for_number).number;
    b = pop_elem(my_stack_for_number).number;
    c = priority_2(t, a, b);
  }
  elem.number = c;
  push_elem(my_stack_for_number, elem);
  if (my_stack_for_symbol->top != NULL) {
    *temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
  }
}

double priority_6(char symbol, double number) {
  double result = 0.0;
  if (symbol == '~') {
    result = 0 - number;
  } else {
    result = number;
  }
  return result;
}

double priority_5(double number_1, double number_2) {
  double result = pow(number_2, number_1);
  return result;
}

double priority_4(char symbol, double number_1, double number_2) {
  double result = 0.0;
  if (symbol == '%') {
    result = fmod(number_2, number_1);
  } else if (symbol == '*') {
    result = number_2 * number_1;
  } else {
    result = number_2 / number_1;
  }
  return result;
}

double priority_3(char symbol, double number_1) {
  double result = 0.0;
  if (symbol == 'S') {
    result = sin(number_1);
  } else if (symbol == 'C') {
    result = cos(number_1);
  } else if (symbol == 'T') {
    result = tan(number_1);
  } else if (symbol == 'I') {
    result = atan(number_1);
  } else if (symbol == 'B') {
    result = asin(number_1);
  } else if (symbol == 'O') {
    result = acos(number_1);
  } else if (symbol == 'L') {
    result = log10(number_1);
  } else if (symbol == 'G') {
    result = log(number_1);
  } else {
    result = sqrt(number_1);
  }
  return result;
}

double priority_2(char symbol, double number_1, double number_2) {
  double result = 0.0;
  if (symbol == '-') {
    result = number_2 - number_1;
  } else {
    result = number_2 + number_1;
  }
  return result;
}
