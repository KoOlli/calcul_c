#ifndef CREDIT_CALCULATOR_H
#define CREDIT_CALCULATOR_H

#include <QLabel>
#include <QLineEdit>
#include <QMenuBar>
#include <QPixmap>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

#include "mybutton.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Credit_calculator;
}
QT_END_NAMESPACE

class Credit_calculator : public QWidget {
  Q_OBJECT

 signals:
  void firstWindow();
 private slots:
  void BackToCalculatorClicked();

 public:
  explicit Credit_calculator(QWidget* parent = nullptr);
  ~Credit_calculator();

 private:
  QLabel* total_loan_amount;
  QLineEdit* sum_credit;

  QLabel* term;
  QSpinBox* term_in_months;
  //    QLabel* in_months;

  QLabel* interest_rate;
  QLineEdit* percentage_rate;

  //    QLabel* picture_dino;

  QLabel* type;

  QLabel* monthly_payment;

  QLabel* overpayment_on_a_loan;

  QLabel* total_payment;

  QVBoxLayout* layout;
  QMenuBar* menubar;
  QMenu* menu;
  QAction* action1;

  MyButton* CreateButton(const QString& text, const char* member);
  QVector<MyButton*> buttons;
};

#endif  // CREDIT_CALCULATOR_H
