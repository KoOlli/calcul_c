#include "calculator.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    w.show();
    w.setWindowIconText(":/img/icon.png");
    Form_x win;
    win.setWindowTitle("Calculator_X");
    return a.exec();
}
