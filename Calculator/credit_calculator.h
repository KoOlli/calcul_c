#ifndef CREDIT_CALCULATOR_H
#define CREDIT_CALCULATOR_H

#include <QLabel>
#include <QLineEdit>
#include <QMenuBar>
#include <QPixmap>
#include <QRadioButton>
#include <QSpinBox>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QWidget>

#include "mybutton.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "s21_back_for_credit_calculator.h"
#ifdef __cplusplus
}
#endif

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
  void MakeCalculateClicked();
  void AnnuitetTable();
  void EstimationAnnuitet();
  void EstimationDifferent();

 public:
  explicit Credit_calculator(QWidget* parent = nullptr);
  QLabel* result;

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
  //  QDateTime* data;
  QLabel* data;
  QLineEdit* search_data;
  QLabel* type;
  QButtonGroup* radio_button_group;
  QRadioButton* annuitet;
  QRadioButton* different;

  QTableWidget* calculation_of_payments;
  //  QLabel* monthly_payment;
  QLabel* overpayment_on_a_loan;
  QLabel* total_payment;

  QVBoxLayout* layout;
  QMenuBar* menubar;
  QMenu* menu;
  QAction* action1;

  MyButton* CreateButton(const QString& text, const char* member);
  QVector<MyButton*> buttons;
  QList<QRadioButton*> allButtons;
};

#endif  // CREDIT_CALCULATOR_H
