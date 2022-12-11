#include <math.h>
#include <stdio.h>

double loan_annuitet_calculation(double sum_credit, int number_of_payment,
                                 double percent, int i);
int check_year(int year);
int check_days_on_month(int month, int year);
double balance_of_debt(double sum_credit, int number_of_payment, double percent,
                       int i, double *result);
double overpayment(double sum_credit, int number_of_payment, double percent,
                   int i);
double sum_percent(double *result, double percent, int i, int year);
double sum_body(double sum_credit, int number_of_payment, double percent, int i,
                double *result, int year);
