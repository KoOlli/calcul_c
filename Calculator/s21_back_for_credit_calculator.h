#include <math.h>
#include <stdio.h>

double loan_annuitet_calculation(double sum_credit, int number_of_payment,
                                 double percent);
int check_year(int year);
int check_days_on_month(int month, int year);
double sum_percent(double percent, int year, double sum_credit, int term,
                   int month, int number_of_payment);
double balance_of_debt(double sum_credit, int term, int number_of_payment,
                       int percent);
double sum_body(int year, int term, double sum_credit, int number_of_payment,
                double percent, int month);
double total_loan_payment(int number_of_payment, double sum_credit,
                          int percent);
double overpayment_on_a_loan(double sum_credit, int number_of_payment,
                             int percent);