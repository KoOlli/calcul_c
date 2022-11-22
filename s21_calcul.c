#include "s21_calcul.h"

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
  char *string = "S*12.234-234523*S";
  char *string_for_chityvatel = calloc(strlen(string), sizeof(char));
  printf("string = %s\n", string);
  Stack *my_stack_for_number = create_stack();
  Stack *my_stack_for_symbol = create_stack();
  chityvatel_stroki(my_stack_for_number, my_stack_for_symbol, string,
                    string_for_chityvatel);
}

void reduction_of_variables(char *string, char *string_final) {
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
    } else if (string[i] == 'm') {
      string_final[j] = '%';
      j++;
      i += 2;
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
}

// проверяем на приоритетность
int check_priority(char b) {
  int priority = 0;
  switch (b) {
    case '(':
    case ')':
      priority = 1;
      break;
    case '+':
    case '-':
      priority = 2;
      break;
    case '%':
    case '*':
    case '/':
      priority = 4;
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
    case '^':
      priority = 5;
      break;
    case '~':
      priority = 6;
      break;
    default:
      printf("OSHIPKA");
      break;
  }
  return priority;
}

void check_unar_symbol(char *string, char *string_final) {
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
}



int chityvatel_stroki(Stack *my_stack_for_number, Stack *my_stack_for_symbol,
                      char *string, char *string_for_chityvatel) {
  Data elem;

  // t = string;
  double template;
  // char temp = 0;
  char *t = calloc(strlen(t), sizeof(char));
  for (int i = 0, j = 0; string[i] != '\0'; i++) {
    int j = 0;
    while (isdigit(string[i]) == 1 || string[i] == '.') {
      t[j] = string[i];
      j++;
      i++;
    }
    string_for_chityvatel = t;
    double template = strtold(t, &string_for_chityvatel);
    // while (isdigit(string[i]) == 1 || string[i] == '.') {
    //   if (isdigit(string[i + 1]) == 1 || string[i + 1] == '.') {
    //     t[j] = string[i];
    //     printf("\nt = %c\n", t[j]);
    //     j++;
    //   }
    //   if (isdigit(string[i + 1]) == 0 || string[i + 1] != '.') {
    //     t[j] = string[i];
    //     string_for_chityvatel = t;
    // printf("\nstring_for_chityvatel_final = %s\n", t);
    // printf("%lf\n", strtod(string, &string_for_chityvatel));
    // for (int i = 0; string[i] != '\0'; i++) {
    //   printf("string_for_chityvatel = %c\n", string_for_chityvatel[i]);
    //   printf("--------\n");
    // }
    if (isdigit(string[i]) == 0 && string[i] != '.') {
      // temp = string[i];
      elem.symbol = string[i];
      // push_elem(my_stack_for_symbol, elem);
      // printf("\nelem.symbol = %c\n", elem.symbol);
    }
    // printf("\n %lf\n", template);
    elem.number = template;
    push_elem(my_stack_for_number, elem);
  }
  while (t) {
    template = strtod(t, &string_for_chityvatel);

    while (isdigit(*t) == 0 && *t) t++;

    break;
  }

  free(t);
}
// printf("Whole t: %s\n", t);
// while (is_empty(my_stack)) {
// printf("\n number   -   %.10lf\n", my_stack_for_number->top->data.number);
// printf("\n symbol   -   %c\n", my_stack_for_symbol->top->data.symbol);
// pop_elem(my_stack);
// }
// free(template);
// return 0;
// }
