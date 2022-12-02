#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QColor>
#include <QImage>

#include <QGridLayout>
#include <QPushButton>
#include <QTextLine>
#include <QChar>

#include <QValidator>
#include <QDebug>

#include "mybutton.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator();

private slots:
    void DigitClicked();
    void UnaryOperatorClicked();
    void DoubleOperatorClicked();
    void EqualClicked();
    int PointClicked();
    void ChangeSingClicked();
    void TrigonometryClicked();
    void AddFunctionsClicked();
    void Clear();
    void ClearAll();
    void AuxiliaryOperatorClicked();
    void AbortOperation();
    void CheckPoint();



private:
    MyButton* CreateButton(const QString& text, const char* member);
    QVector<MyButton*> buttons;

    QLineEdit* m_display_up;
    QLineEdit* m_display_x;
    QLabel* m_x;

    int count = 0;

    MyButton* m_digitButtons[10];

};

#endif // CALCULATOR_H
