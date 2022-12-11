#include "s21_back_for_credit_calculator.h"

// сумма платежа в месяц аннуитетный калькуль
double loan_annuitet_calculation(double sum_credit, int number_of_payment,
                                 double percent, int i) {
  double resultat = 0.0;
  double monthy_interest_ratio = percent / 12 / 100;
  double annuitet_ratio =
      (monthy_interest_ratio *
       pow((1 + monthy_interest_ratio), number_of_payment)) /
      (pow((1 + monthy_interest_ratio), number_of_payment) - 1);
  double sum_payment = annuitet_ratio * sum_credit;
  double total_loan_amount = sum_payment * number_of_payment;

  if (i == (number_of_payment - 1)) {
    resultat = total_loan_amount - (sum_payment * i);
  } else {
    resultat = sum_payment;
  }
  return resultat;
}

double sum_body(double sum_credit, int number_of_payment, double percent, int i,
                double *result, int year) {
  double result_for_body;
  result_for_body =
      loan_annuitet_calculation(sum_credit, number_of_payment, percent, i) -
      sum_percent(result, percent, i, year);
  return result_for_body;
}

double sum_percent(double *result, double percent, int i, int year) {
  double sum_for_percent_return =
      *result * percent / 100 * check_days_on_month(i, year) / check_year(year);
  return sum_for_percent_return;
}

double balance_of_debt(double sum_credit, int number_of_payment, double percent,
                       int i, double *result, int year) {
  if (i == 0) {
    *result =
        sum_credit -
          sum_body(sum_credit, number_of_payment, percent, i,
                          result, year);
  } else if (sum_body(sum_credit, number_of_payment, percent, i,
                      result, year) > *result) {
    *result = *result - *result;
  } else {
    *result = *result - sum_body(sum_credit, number_of_payment, percent, i,
                                           result, year);
  }
  return *result;
}

double overpayment(double sum_credit, int number_of_payment, double percent,
                   int i) {
  double result =
      loan_annuitet_calculation(sum_credit, number_of_payment, percent, i) *
      number_of_payment;
  return result;
}


double part_of_the_principal(double sum_credit, int number_of_payment) {
  double result_for_part = sum_credit / number_of_payment;
  return result_for_part;
}

double loan_different_calculation(double sum_credit, int number_of_payment, double *result, double percent, int i, int year) {
  double result_for_loan_dif = part_of_the_principal(sum_credit, number_of_payment) + sum_percent(result, percent, i, year);
  return result_for_loan_dif;
}

// чекаем високосный год или нет
int check_year(int year) {
  // int year = 2022;
  int days;
  if ((year % 4) == 0) {
    days = 366;
  } else {
    days = 365;
  }
  return days;
}

// чекаем количество дней в месяце
int check_days_on_month(int i, int year) {
  int days;
  int templ;
  if (i > 12) {
    templ = i % 12;
  } else {
    templ = i;
  }
  switch (templ) {
    case 4:
    case 6:
    case 9:
    case 11:
      days = 30;
      break;
    case 2:
      if (check_year(year) == 0) {
        days = 28;
      } else {
        days = 29;
      }
      break;
    default:
      days = 31;
      break;
  }
  return days;
}
