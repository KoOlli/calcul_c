#ifndef DEPOSIT_CALCULATOR_H
#define DEPOSIT_CALCULATOR_H

#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QWidget>

#include "mybutton.h"

namespace Ui {
class Deposit_calculator;
}

class Deposit_calculator : public QWidget {
  Q_OBJECT

 signals:
  void firstWindow();
 private slots:
  void BackToCalculatorClicked();

 public:
  explicit Deposit_calculator(QWidget* parent = nullptr);
  ~Deposit_calculator();

 private:
  QLabel* sum_amount;
  QLineEdit* sum_amount_line;

  QLabel* placement_period;
  QSpinBox* placement_period_line;

  QLabel* interest_rate;
  QLineEdit* interest_rate_line;

  QLabel* tax_rate;
  QLineEdit* tax_rate_line;

  QLabel* perodicity_of_payments;
  QLineEdit* perodicity_of_payments_line;

  QLabel* interest_capitalization;
  QLineEdit* interest_capitalization_line;

  //  QLabel* repleshment_list;
  //  QLabel* list_of_partial_with_drawals;

  QLabel* interest_charges;
  QLabel* amount_of_taxes;
  QLabel* sum_amount_by_the_end;

  MyButton* CreateButton(const QString& text, const char* member);
  QVector<MyButton*> buttons;
  //  Ui::Deposit_calculator *ui;
};

#endif  // DEPOSIT_CALCULATOR_H
