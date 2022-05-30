#include "calc.h"

char *calcash(char *arr, char *x) {
  static char result[400] = "\0";
  char s[300] = "#####";
  s21_strcat(s, arr);
  char *sup;
  Stack_chislo *headchislo = NULL;
  Stack_sim *headsym = NULL;
  int k = 5, error = 0;
  int error_chislo = 0, skobka = 0, error_znak = 0;
  while (s[k] != '\0') {
    if (to_sym_no_minus(s[k]) && to_sym(s[k - 1])) {
      error = 1;
      break;
    } else if (k == 5 && to_sym_no_minus(s[k])) {
      error = 1;
      break;
    } else if (s[k] == ')') {
      skobka--;
      if (skobka < 0 || to_sym(s[k - 1])) {
        error = 1;
        break;
      }
      while (headsym != NULL && headsym->Data != '(') {
        operating(&headsym, &headchislo);
      }
      pop_sim(&headsym);
      if (headsym != NULL) {
        if ((headsym->Data >= '1' && headsym->Data <= '9') ||
            (headsym->Data >= 'a' && headsym->Data <= 'i')) {
          operating(&headsym, &headchislo);
        }
      }
    } else if (s[k] == '(') {
      if (!to_sym(s[k - 1]) && s[k - 1] != '(' && s[k - 1] != '#' &&
          s[k - 1] != 's' && s[k - 1] != 'n' && s[k - 1] != 't' &&
          s[k - 1] != 'g' && s[k + 1] == ')') {
        error = 1;
        break;
      }
      push_sim(&headsym, s[k]);
      skobka++;
    } else if (to_sym(s[k]) && !to_sym(s[k - 1]) && s[k - 1] != '(' && k > 5) {
      error_znak++;
      if (priority(s[k]) == 2) {
        while (headsym != NULL && priority(headsym->Data) >= 2) {
          operating(&headsym, &headchislo);
        }
      } else if (priority(s[k]) == 3) {
        while (headsym != NULL && priority(headsym->Data) >= 3) {
          operating(&headsym, &headchislo);
        }
      }
      if (headsym != NULL && headsym->Data == '!') {
        error = 1;
        break;
      }
      push_sim(&headsym, s[k]);
    } else if ((s[k] >= '0' && s[k] <= '9') || s[k] == 'x' || s[k] == '.') {
      error_chislo++;
      int sign = 0;
      if (two_sim(s[k - 2]) && s[k - 1] == '-') {
        sign = 1;
      }
      char dest[256] = "\0";
      int check_point = 0;
      while ((s[k] >= '0' && s[k] <= '9') || s[k] == '.' || s[k] == 'x') {
        if (s[k] == '.') check_point++;
        if (check_point > 1 || s[k + 1] == 'x' || s[k + 1] == 'c' ||
            s[k + 1] == 's' || s[k + 1] == 't' || s[k + 1] == 'a' ||
            s[k + 1] == 'l') {
          error = 1;
          break;
        }
        if (s[k] == 'x') {
          if (check_x(x)) {
            error = 1;
            break;
          }
          s21_strcat(dest, x);
          double tmp_push_chislo = strtod(dest, &sup);
          if (sign) tmp_push_chislo *= -1;
          push_chislo(&headchislo, tmp_push_chislo);
          break;
        } else {
          strncat(dest, s + k, 1);
          k++;
        }
      }
      if (s[k] != 'x') {
        double tmp_push_chislo = strtod(dest, &sup);
        if (sign) tmp_push_chislo *= -1;
        push_chislo(&headchislo, tmp_push_chislo);
        memset(dest, 0, 256);
        k--;
      }
    } else if (s[k] == 'c' || s[k] == 's' || s[k] == 't' || s[k] == 'a' ||
               s[k] == 'l') {
      if (s[k] == 'c' && s[k + 1] == 'o' && s[k + 2] == 's') {
        if (two_sim(s[k - 2]) && s[k - 1] == '-') {
          push_sim(&headsym, 'a');
        } else {
          push_sim(&headsym, '1');
        }
        k += 2;
      } else if (s[k] == 's' && s[k + 1] == 'i' && s[k + 2] == 'n') {
        if (two_sim(s[k - 2]) && s[k - 1] == '-') {
          push_sim(&headsym, 'b');
        } else {
          push_sim(&headsym, '2');
        }
        k += 2;
      } else if (s[k] == 't' && s[k + 1] == 'a' && s[k + 2] == 'n') {
        if (two_sim(s[k - 2]) && s[k - 1] == '-') {
          push_sim(&headsym, 'c');
        } else {
          push_sim(&headsym, '3');
        }
        k += 2;
      } else if (s[k] == 'a' && s[k + 1] == 'c' && s[k + 2] == 'o' &&
                 s[k + 3] == 's') {
        if (two_sim(s[k - 2]) && s[k - 1] == '-') {
          push_sim(&headsym, 'd');
        } else {
          push_sim(&headsym, '4');
        }
        k += 3;
      } else if (s[k] == 'a' && s[k + 1] == 's' && s[k + 2] == 'i' &&
                 s[k + 3] == 'n') {
        if (two_sim(s[k - 2]) && s[k - 1] == '-') {
          push_sim(&headsym, 'e');
        } else {
          push_sim(&headsym, '5');
        }
        k += 3;
      } else if (s[k] == 'a' && s[k + 1] == 't' && s[k + 2] == 'a' &&
                 s[k + 3] == 'n') {
        if (two_sim(s[k - 2]) && s[k - 1] == '-') {
          push_sim(&headsym, 'f');
        } else {
          push_sim(&headsym, '6');
        }
        k += 3;
      } else if (s[k] == 's' && s[k + 1] == 'q' && s[k + 2] == 'r' &&
                 s[k + 3] == 't') {
        if (two_sim(s[k - 2]) && s[k - 1] == '-') {
          push_sim(&headsym, 'g');
        } else {
          push_sim(&headsym, '7');
        }
        k += 3;
      } else if (s[k] == 'l' && s[k + 1] == 'n') {
        if (two_sim(s[k - 2]) && s[k - 1] == '-') {
          push_sim(&headsym, 'h');
        } else {
          push_sim(&headsym, '8');
        }
        k++;
      } else if (s[k] == 'l' && s[k + 1] == 'o' && s[k + 2] == 'g') {
        if (two_sim(s[k - 2]) && s[k - 1] == '-') {
          push_sim(&headsym, 'i');
        } else {
          push_sim(&headsym, '9');
        }
        k += 2;
      } else {
        error = 1;
        break;
      }
      if (s[k + 1] != '(') {
        error = 1;
        break;
      }
    } else if (s[k] != '-' && s[k] != '+') {
      error = 1;
    }
    if (error) break;
    k++;
  }
  if (error_chislo <= error_znak || error == 1) {
    char arr_error[256] = "Error input!";
    result[0] = '\0';
    s21_strcat(result, arr_error);
    destroy(&headsym, &headchislo);

  } else {
    while (headsym != NULL) {
      if (headsym->Data == '(') {
        error = 1;
        break;
      }
      operating(&headsym, &headchislo);
    }
    if (error == 1) {
      char arr_error[256] = "Error input!";
      result[0] = '\0';
      s21_strcat(result, arr_error);
      destroy(&headsym, &headchislo);
    } else {
      double res = pop_chislo(&headchislo);
      snprintf(result, sizeof(result), "%.8f", res);
    }
  }
  destroy(&headsym, &headchislo);
  return result;
}

bool check_x_bool(char x) { return (x >= '0' && x <= '9'); }

int check_x(char *x) {
  int flag = 0, check_tochka = 0, check_znak = 0, check_chislo = 0;
  if (x[0] == '-' || x[0] == '+') check_znak++;
  for (int i = check_znak; x[i] != '\0'; i++) {
    if (x[i] == '.') check_tochka++;
    if (x[i] == '-' || x[i] == '+') check_znak = 2;
    if (check_x_bool(x[i])) check_chislo++;
    if ((x[i] != '.' && x[i] != '-' && x[i] != '+' && !check_x_bool(x[i])) ||
        check_znak > 1 || check_tochka > 1)
      flag = 1;
  }
  if (!check_chislo) flag = 1;
  if (x[0] == '\0') flag = 0;
  return flag;
}

void destroy(Stack_sim **headsym, Stack_chislo **head) {
  while (*headsym != NULL) {
    pop_sim(headsym);
  }
  while (*head != NULL) {
    pop_chislo(head);
  }
}

bool to_sym(char x) {
  return (x == '-' || x == '+' || x == '*' || x == '/' || x == '%' || x == '^');
}

bool to_sym_no_minus(char x) {
  return (x == '*' || x == '/' || x == '%' || x == '^');
}

int two_sim(char s) {
  int flag = 0;
  if (s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '%' ||
      s == '#' || s == '(')
    flag = 1;
  return flag;
}

int two_sim_no_skobka(char s) {
  int flag = 0;
  if (s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '%')
    flag = 1;
  return flag;
}

void operating(Stack_sim **headsym, Stack_chislo **head) {
  char sim = pop_sim(headsym);
  double y = 0;
  if (*head != NULL) y = pop_chislo(head);
  double x = 0;
  int error = 0;
  if (*head != NULL && two_sim_no_skobka(sim)) {
    x = pop_chislo(head);
  } else if ((sim >= '1' && sim <= '9') || (sim >= 'a' && sim <= 'i')) {
  } else {
    error = 1;
  }
  double res;
  switch (sim) {
    case '^':
      res = pow(x, y);
      break;
    case '*':
      res = x * y;
      break;
    case '/':
      res = x / y;
      break;
    case '%':
      res = fmod(x, y);
      break;
    case '-':
      res = x - y;
      break;
    case '+':
      res = x + y;
      break;
    case 'a':
    case '1':  // cos
      res = cos(y);
      break;
    case 'b':
    case '2':  // sin
      res = sin(y);
      break;
    case 'c':
    case '3':  // tan
      res = tan(y);
      break;
    case 'd':
    case '4':  // acos
      res = acos(y);
      break;
    case 'e':
    case '5':  // asin
      res = asin(y);
      break;
    case 'f':
    case '6':  // atan
      res = atan(y);
      break;
    case 'g':
    case '7':  // sqrt
      res = sqrt(y);
      break;
    case 'h':
    case '8':  // ln
      res = log(y);
      break;
    case 'i':
    case '9':  // log
      res = log10(y);
      break;
  }
  if (sim >= 'a' && sim <= 'i') res *= -1;
  if (error) {
    push_sim(headsym, '!');
  }
  push_chislo(head, res);
}

//======= Функция реализации приоритета операций =========

int priority(char a) {
  int flag = 0;
  switch (a) {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '^':
      flag = 4;
      break;
    case '*':
    case '/':
    case '%':
      flag = 3;
      break;
    case '-':
    case '+':
      flag = 2;
      break;
    case '(':
      flag = 1;
      break;
  }
  return flag;
}

// ============== Добавление элемента в стек =============

void push_chislo(Stack_chislo **t, double x) {
  Stack_chislo *t1 = malloc(sizeof(Stack_chislo));
  t1->Data = x;
  t1->Next = *t;
  *t = t1;
}

void push_sim(Stack_sim **t, char x) {
  Stack_sim *t1 = malloc(sizeof(Stack_sim));
  t1->Data = x;
  t1->Next = *t;
  *t = t1;
}

// ============== Извлечение элемента из стека ===============

double pop_chislo(Stack_chislo **t) {
  Stack_chislo *t1 = *t;
  double x = t1->Data;
  *t = t1->Next;
  free(t1);
  return x;
}

char pop_sim(Stack_sim **t) {
  Stack_sim *t1 = *t;
  char x = t1->Data;
  *t = t1->Next;
  free(t1);
  return x;
}

char *s21_strcat(char *dest, const char *src) {
  char *cln = dest;
  while (*dest) {
    dest++;
  }
  while (*src) {
    *dest++ = *src++;
  }
  *dest++ = '\0';
  return cln;
}
