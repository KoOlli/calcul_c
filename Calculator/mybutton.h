#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QToolButton>

class MyButton : public QToolButton
{
    Q_OBJECT

public:
    explicit MyButton(const QString &text, QWidget *parent = nullptr);
};

#endif // MYBUTTON_H
