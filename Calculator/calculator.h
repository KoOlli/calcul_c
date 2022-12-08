#ifndef CALCULATOR_H
#define CALCULATOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "s21_calcul.h"

#ifdef __cplusplus
}
#endif

#include <QChar>
#include <QColor>
#include <QDebug>
#include <QGridLayout>
#include <QImage>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextLine>
#include <QValidator>
#include <QWidget>

#include "credit_calculator.h"
#include "deposit_calculator.h"
#include "form_x.h"
#include "mybutton.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class Calculator : public QWidget {
  Q_OBJECT

 public:
  Calculator();
  //  Form_x forrrrrm_x;

 private slots:
  void DigitClicked();
  void UnaryOperatorClicked();
  void DoubleOperatorClicked();
  void EqualClicked();
  int PointClicked();
  void ChangeSingClicked();
  void TrigonometryClicked();
  void CreditClicked();
  void DepositClicked();
  void GraphsClicked();
  void Clear();
  void ClearAll();
  void AuxiliaryOperatorClicked();
  void AbortOperation();
  void CheckPoint();
  void CheckClickedX();

 private:
  Form_x* new_widget_for_x;
  //    new_widget_for_graphs;
  Deposit_calculator* new_widget_for_deposit;
  Credit_calculator* new_widget_for_credit;
  MyButton* CreateButton(const QString& text, const char* member);
  QVector<MyButton*> buttons;

  QLineEdit* m_display_up;

  int count = 0;

  MyButton* m_digitButtons[10];
};

#endif  // CALCULATOR_H
