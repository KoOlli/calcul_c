#include "s21_back_for_credit_calculator.h"

//int main() {
//  double sum_credit = 300000.0;
//  int number_of_payment = 18;
//  double percent = 15.0;
//  int month = 06;
//  int year = 2022;
//  // платежей совершенно
//  int term = 1;
//  loan_annuitet_calculation(sum_credit, number_of_payment, percent);
//  check_year(year);
//  check_days_on_month(month, year);
//  sum_percent(percent, year, sum_credit, term, month, number_of_payment);
//  balance_of_debt(sum_credit, term, number_of_payment, percent);
//  sum_body(year, term, sum_credit, number_of_payment, percent, month);
//  total_loan_payment(number_of_payment, sum_credit, percent);
//}

//double loan_different_calculation(double sum_credit, double percent, int year, int term, int month, int number_of_payment) {
//  double part_of_the_principal = sum_credit / number_of_payment;
//  return part_of_the_principal + sum_percent(percent, year, sum_credit, term, month, number_of_payment);
//}
// сумма платежа в месяц
double loan_annuitet_calculation(double sum_credit, int number_of_payment,
                                 double percent) {
  double monthy_interest_ratio = percent / 1200;
  printf("%lf\n", monthy_interest_ratio);

  double annuitet_ratio =
      (monthy_interest_ratio *
       pow((1 + monthy_interest_ratio), number_of_payment)) /
      (pow((1 + monthy_interest_ratio), number_of_payment) - 1);


  return sum_credit * annuitet_ratio;
}

//// чекаем високосный год или нет
//int check_year(int year) {
//  // int year = 2022;
//  int days;
//  if ((year % 4) == 0) {
//    days = 366;
//  } else {
//    days = 365;
//  }
//  return days;
//}

//// чекаем количество дней в месяце
//int check_days_on_month(int month, int year) {
//  int days;
//  switch (month) {
//    case '01':
//    case '03':
//    case '05':
//    case '07':
//    case '08':
//    case '10':
//    case '12':
//      days = 31;
//      break;
//    case '04':
//    case '06':
//    case '09':
//    case '11':
//      days = 30;
//    case '02':
//      if (check_year(year) == 0) {
//        days = 28;
//      } else {
//        days = 29;
//      }
//  }
//  return days;
//}

//// сумма погашения в проценты
//double sum_percent(double percent, int year, double sum_credit, int term,
//                   int month, int number_of_payment) {
//  // double month_pay = loan_calculation(sum_credit, number_of_payment,
//  // percent);
//  int days = check_days_on_month(month, year);
//  int days_in_year = check_year(year);
//  double balance_debt =
//      balance_of_debt(sum_credit, term, number_of_payment, percent);
//  return balance_debt * percent * days / days_in_year / 100;
//}

//// остаток задолжности
//double balance_of_debt(double sum_credit, int term, int number_of_payment,
//                       int percent) {
//  double month_pay = loan_annuitet_calculation(sum_credit, number_of_payment, percent);
//  return sum_credit - month_pay * term;
//}

//// сумма погашения в тело
//double sum_body(int year, int term, double sum_credit, int number_of_payment,
//                double percent, int month) {
//  // double month_pay = loan_calculation(sum_credit, number_of_payment,
//  // percent);
////  int days = check_days_on_month(month, year);
//  double sum_in_month =
//      loan_annuitet_calculation(sum_credit, number_of_payment, percent);
//  double sum_perc =
//      sum_percent(percent, year, sum_credit, term, month, number_of_payment);
//  double sum_in_body = sum_in_month - sum_perc;
//  return sum_in_body;
//}

//double total_loan_payment(int number_of_payment, double sum_credit,
//                          int percent) {
//  double month_pay = loan_annuitet_calculation(sum_credit, number_of_payment, percent);
//  return number_of_payment * month_pay;
//}

//double overpayment_on_a_loan(double sum_credit, int number_of_payment,
//                             int percent) {
//  // double month_pay = loan_calculation(sum_credit, number_of_payment,
//  // percent);
//  double result =
//      total_loan_payment(number_of_payment, sum_credit, percent) - sum_credit;
//  return result;
//}
