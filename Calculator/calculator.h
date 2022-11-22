#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QColor>
#include <QImage>
#include <mybutton.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator();

private slots:
    void digitClicked();
    void unaryOperatorClicked();
    void doubleOperatorClicked();
    void equalClicked();
    void pointClicked();
    void changeSingClicked();
    void trigonometryClicked();
    void addFunctionsClicked();
    void clear();
    void clearAll();

private:
    MyButton* createButton(const QString& text, const char* member);
    double m_sum_in_memory;

    QString m_pending_operation;

    QLineEdit* m_display_up;
    QLineEdit* m_display_x;
    QLabel* m_x;

    MyButton* m_digitButtons[10];

};

#endif // CALCULATOR_H
