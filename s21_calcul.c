#include "s21_calcul.h"
#define PI \
  3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091

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

void main() {
  // int priority;
  // double value;
  char *string = "cos(sin(P/2))-3*sin(2-2)+4";
  // char *string_for_chityvatel = calloc(strlen(string), sizeof(char));
  // char *string_for_unar = calloc(strlen(string), sizeof(char));
  // printf("string = %s\n", string);
  // Data elem;
  // elem.number = -3;
  // Stack *my_stack_for_number;
  // push_elem(my_stack_for_number, elem);
  // push_elem(my_stack_for_symbol, elem);
  // double result;
  // result = 2-2*3+1;
  // printf("%lf", result);

  reduction_of_variables(string);

  // check_unar_symbol(string_for_chityvatel, string_for_unar);
  // chityvatel_stroki(my_stack_for_number, my_stack_for_symbol,
  // string_for_unar, string_for_chityvatel);
  // pop_elem(my_stack_for_symbol);
  // priority = check_priority(pop_elem(my_stack_for_symbol));
  // sravnenie_prioritetov_symbols_in_stack(string, my_stack_for_number,
  //                                        my_stack_for_symbol);
  // printf("%c", my_stack_for_number->top->data.number);
}

void reduction_of_variables(char *string) {
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
      // } else if (string[i] == 'm') {
      //   string_final[j] = '%';
      //   j++;
      //   i += 2;
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
  // free(string);
  check_unar_symbol(string_final);
}

void check_unar_symbol(char *string) {
  char *string_final = calloc(strlen(string) + 1, sizeof(char));
  if (string[0] == '-') {
    string_final[0] = '~';
  } else {
    string_final[0] = string[0];
  }
  for (int i = 1; string[i] != '\0'; i++) {
    if (string_final[i - 1] == '(' && string[i] == '-') {
      string_final[i] = '~';
    } else {
      string_final[i] = string[i];
    }
  }

  // free(string);
  chityvatel_stroki(string_final);
}

int chityvatel_stroki(char *string) {
  char *string_final = calloc(strlen(string) + 1, sizeof(char));
  int temp_priority = 0;
  Stack *my_stack_for_number = create_stack();
  Stack *my_stack_for_symbol = create_stack();
  Data elem;
  double template;
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
    double template = strtod(t, &string_final);
    elem.number = template;
    if (if_isdigit_end == 1) {
      push_elem(my_stack_for_number, elem);
    }

    for (size_t ii = 0; ii < strlen(string) + 1; ++ii) t[ii] = '\0';
    j = 0;
    if ((isdigit(string[i]) == 0 || string[i] != '.') && string[i] != '\0') {
      if (string[i] == 'P') {
        elem.number = PI;
        push_elem(my_stack_for_number, elem);
        continue;
      }
      elem.symbol = string[i];
      if (string[i] == '(') {
        push_elem(my_stack_for_symbol, elem);
        temp_priority = check_priority(elem.symbol);
      } else if (string[i] == ')') {
        while (my_stack_for_symbol->top->data.symbol != '(') {
          math(my_stack_for_number, my_stack_for_symbol, &temp_priority);
          if (my_stack_for_symbol->top != NULL) {
            temp_priority =
                check_priority(my_stack_for_symbol->top->data.symbol);
          }
        }
        if (my_stack_for_symbol->top->data.symbol == '(') {
          pop_elem(my_stack_for_symbol);
          if (my_stack_for_symbol->top != NULL) {
            temp_priority =
                check_priority(my_stack_for_symbol->top->data.symbol);
          }
        }
        elem.symbol = my_stack_for_symbol->top->data.symbol;
      } else if (check_priority(elem.symbol) == 3) {
        push_elem(my_stack_for_symbol, elem);
        temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
      } else {
        stack_push(my_stack_for_number, my_stack_for_symbol, elem,
                   &temp_priority);
      }
    }
    // while (my_stack_for_symbol->top != NULL) {
    //   math(my_stack_for_number, my_stack_for_symbol, &temp_priority);
    // }
  }
  while (my_stack_for_symbol->top != NULL) {
    math(my_stack_for_number, my_stack_for_symbol, &temp_priority);
    // temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
  }
  printf("\n number = %lf\n", my_stack_for_number->top->data.number);
  return 0;
}

void stack_push(Stack *my_stack_for_number, Stack *my_stack_for_symbol,
                Data elem, int *temp_priority) {
  int template;
  if (my_stack_for_symbol->top == NULL) {
    push_elem(my_stack_for_symbol, elem);
    *temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
  } else {
    // printf("запушено наверху %c\n", my_stack_for_symbol->top->data.symbol);
    // printf("запушено после него %c\n",
    //        my_stack_for_symbol->top->next->data.symbol);
    // printf("в руках %c\n", elem.symbol);

    if (check_priority(elem.symbol) <= *temp_priority) {
      template = *temp_priority;
      // printf("запушено наверху %c\n", my_stack_for_symbol->top->data.symbol);
      // printf("запушено после него %c\n",
      //        my_stack_for_symbol->top->next->data.symbol);
      // printf("в руках %c\n", elem.symbol);

      while (
          (my_stack_for_symbol->top != NULL) &&
          (check_priority(my_stack_for_symbol->top->data.symbol) <= template)) {
        math(my_stack_for_number, my_stack_for_symbol, &template);
        // if (my_stack_for_symbol->top != NULL) {
        //   *temp_priority =
        //       check_priority(my_stack_for_symbol->top->data.symbol);
        // }
      }
      push_elem(my_stack_for_symbol, elem);
      *temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
    } else {
      push_elem(my_stack_for_symbol, elem);
      *temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
    }
  }
}

// проверяем на приоритетность
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
      priority = 6;
      break;
    default:
      // printf("OSHIPKA");
      break;
  }
  return priority;
}

void math(Stack *my_stack_for_number, Stack *my_stack_for_symbol,
          int *temp_priority) {
  double a, b, c;
  char t;
  Data elem;
  t = pop_elem(my_stack_for_symbol).symbol;
  printf("%c\n", t);
  printf("prioritet in math %d\n", check_priority(t));

  if (check_priority(t) == 6) {
    a = pop_elem(my_stack_for_number).number;
    c = priority_6(a);
    printf("number_1 %lf\n", a);

  } else if (check_priority(t) == 5) {
    a = pop_elem(my_stack_for_number).number;
    b = pop_elem(my_stack_for_number).number;
    c = priority_5(a, b);
    printf("number_1 %lf\n", a);
    printf("number_2 %lf\n", b);
  } else if (check_priority(t) == 4) {
    a = pop_elem(my_stack_for_number).number;
    b = pop_elem(my_stack_for_number).number;
    c = priority_4(t, a, b);
    printf("number_1 %lf\n", a);
    printf("number_2 %lf\n", b);

  } else if (check_priority(t) == 3) {
    a = pop_elem(my_stack_for_number).number;
    c = priority_3(t, a);
    printf("number_1 %lf\n", a);
  } else if (check_priority(t) == 2) {
    a = pop_elem(my_stack_for_number).number;
    b = pop_elem(my_stack_for_number).number;
    c = priority_2(t, a, b);
    printf("number_1 %lf\n", a);
    printf("number_2 %lf\n", b);
  }
  elem.number = c;
  printf("maaaathhh %lf\n\n", c);
  push_elem(my_stack_for_number, elem);
  // printf(" крокозябра\n");
  if (my_stack_for_symbol->top != NULL) {
    *temp_priority = check_priority(my_stack_for_symbol->top->data.symbol);
  }
  // printf(" %lf\n", my_stack_for_number->top->data.number);
  // printf("prioritet in END math %lf\n\n",
  //  my_stack_for_number->top->data.number);
}

double priority_6(double number) { return 0 - number; }

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
  // printf("aboba %lf", result);
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

// int priority_1() {

// }

// int resultativnyi_chet_is_stecka(double x, double a, double b, double result)
// {
//   if (x == '+') {
//     result = b + a;
//   } else if (x == '-') {
//     result = b - a;
//   } else if (x == '*') {
//     result = b * a;
//   } else if (x == '/') {
//     result = b / a;
//   } else if (x == '%') {
//     result = (int)b % (int)a;
//   } else if (x == '~') {
//     result = '____';
//   } else if (x == '^') {
//     result = pow(b, a);
//   } else if (x == 'S') {
//     result = sin();
//   } else if (x == 'C') {
//     result = cos();
//   } else if (x == 'T') {
//     result = tan();
//   } else if (x == 'I') {
//     result = atan();
//   } else if (x == 'B') {
//     result = asin();
//   } else if (x == 'O') {
//     result = acos();
//   } else if (x == 'L') {
//     result = ln();
//   } else if (x == 'G') {
//     result = log();
//   } else if (x == 'Q') {
//     result = sqrt();
//   }
//   return result;
// }

// int sravnenie_prioritetov_symbols_in_stack(char *string,
//                                            Stack *my_stack_for_number,
//                                            Stack *my_stack_for_symbol) {
//   for (int i = 0; string[i] != '\0'; i++) {
//     if () }
// }

// printf("Whole t: %s\n", t);
// while (is_empty(my_stack)) {
// printf("\n number   -   %.10lf\n", my_stack_for_number->top->data.number);
// printf("\n symbol   -   %c\n", my_stack_for_symbol->top->data.symbol);
// pop_elem(my_stack);
// }
// free(template);
// return 0;
// }
