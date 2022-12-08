#ifndef FORM_X_H
#define FORM_X_H
#include <QChar>
#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextLine>
#include <QValidator>
#include <QWidget>

#include "mybutton.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Form_x;
}
QT_END_NAMESPACE

class Form_x : public QWidget {
  Q_OBJECT

 public:
  explicit Form_x(QWidget* parent = nullptr);
  ~Form_x();
  QString xxxx;

 signals:
  void firstWindow();

 private slots:
  void DigitClicked();
  void UnaryOperatorClicked();
  void DoubleOperatorClicked();
  void EqualClicked();
  void PointClicked();
  //    void ChangeSingClicked();
  void TrigonometryClicked();
  //    void AddFunctionsClicked();
  void Clear();
  void ClearAll();
  void AuxiliaryOperatorClicked();
  //    void AbortOperation();
  void CheckPoint();

 private:
  MyButton* CreateButton(const QString& text, const char* member);
  QVector<MyButton*> buttons;

  QLineEdit* display_for_x;

  int count = 0;

  MyButton* m_digitButtons[10];
  //    Ui::Form_x *ui;
};

#endif  // FORM_X_H
