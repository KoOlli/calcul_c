#include "calculator.h"

#include <QChar>
#include <QDebug>
#include <QGridLayout>
#include <QPushButton>
#include <QTextLine>
#include <QValidator>

#include "mainwindow.cpp"

Calculator::Calculator() {
  m_display_up = new QLineEdit();
  QGridLayout* mainLayout = new QGridLayout;

  new_widget_for_x = new Form_x();
  connect(new_widget_for_x, &Form_x::firstWindow, this, &Form_x::show);

  new_widget_for_credit = new Credit_calculator();
  connect(new_widget_for_credit, &Credit_calculator::firstWindow, this,
          &Calculator::show);

  new_widget_for_deposit = new Deposit_calculator();
  connect(new_widget_for_deposit, &Deposit_calculator::firstWindow, this,
          &Calculator::show);

  m_display_up->setText("0");
  m_display_up->setReadOnly(true);
  m_display_up->setAlignment(Qt::AlignRight);
  m_display_up->setMaxLength(255);

  for (int i = 0; i < 10; ++i) {
    m_digitButtons[i] = CreateButton(QString::number(i), SLOT(DigitClicked()));
  }
  MyButton* var_x = CreateButton("x", SLOT(CheckClickedX()));

  MyButton* var_point = CreateButton(".", SLOT(CheckPoint()));

  MyButton* var_cencel_symbol = CreateButton("CE", SLOT(Clear()));
  MyButton* var_cencel_string = CreateButton("C", SLOT(ClearAll()));

  MyButton* var_minus = CreateButton("-", SLOT(DoubleOperatorClicked()));
  MyButton* var_plus = CreateButton("+", SLOT(DoubleOperatorClicked()));

  MyButton* var_div = CreateButton("/", SLOT(AuxiliaryOperatorClicked()));
  MyButton* var_mult = CreateButton("*", SLOT(AuxiliaryOperatorClicked()));
  MyButton* var_pi = CreateButton("π", SLOT(AuxiliaryOperatorClicked()));
  MyButton* var_mod = CreateButton("%", SLOT(AuxiliaryOperatorClicked()));
  MyButton* var_degree = CreateButton("^", SLOT(AuxiliaryOperatorClicked()));

  MyButton* var_open_bracket = CreateButton("(", SLOT(UnaryOperatorClicked()));
  MyButton* var_close_bracket = CreateButton(")", SLOT(UnaryOperatorClicked()));
  MyButton* var_00 = CreateButton("00", SLOT(UnaryOperatorClicked()));

  MyButton* var_deposit = CreateButton("dep", SLOT(DepositClicked()));
  MyButton* var_cred = CreateButton("cred", SLOT(CreditClicked()));
  MyButton* var_graf = CreateButton("graf", SLOT(GraphsClicked()));

  MyButton* var_sqrt = CreateButton("sqrt", SLOT(TrigonometryClicked()));
  MyButton* var_ln = CreateButton("ln", SLOT(TrigonometryClicked()));
  MyButton* var_log = CreateButton("log", SLOT(TrigonometryClicked()));
  MyButton* var_asin = CreateButton("asin", SLOT(TrigonometryClicked()));
  MyButton* var_sin = CreateButton("sin", SLOT(TrigonometryClicked()));
  MyButton* var_acos = CreateButton("acos", SLOT(TrigonometryClicked()));
  MyButton* var_cos = CreateButton("cos", SLOT(TrigonometryClicked()));
  MyButton* var_atan = CreateButton("atan", SLOT(TrigonometryClicked()));
  MyButton* var_tan = CreateButton("tan", SLOT(TrigonometryClicked()));

  MyButton* var_result = CreateButton("=", SLOT(EqualClicked()));

  mainLayout->addWidget(m_display_up, 0, 0, 2, 9);

  mainLayout->addWidget(var_x, 4, 0, 1, 3);
  mainLayout->addWidget(var_open_bracket, 4, 4);
  mainLayout->addWidget(var_close_bracket, 4, 5);
  mainLayout->addWidget(var_cencel_symbol, 4, 6);
  mainLayout->addWidget(var_cencel_string, 4, 7);
  mainLayout->addWidget(var_deposit, 4, 8);

  mainLayout->addWidget(var_ln, 5, 0);
  mainLayout->addWidget(var_log, 5, 1);
  mainLayout->addWidget(var_degree, 5, 2);
  mainLayout->addWidget(m_digitButtons[7], 5, 4);
  mainLayout->addWidget(m_digitButtons[8], 5, 5);
  mainLayout->addWidget(m_digitButtons[9], 5, 6);
  mainLayout->addWidget(var_div, 5, 7);
  mainLayout->addWidget(var_cred, 5, 8);

  mainLayout->addWidget(var_asin, 6, 0);
  mainLayout->addWidget(var_sin, 6, 1);
  mainLayout->addWidget(var_mod, 6, 2);
  mainLayout->addWidget(m_digitButtons[4], 6, 4);
  mainLayout->addWidget(m_digitButtons[5], 6, 5);
  mainLayout->addWidget(m_digitButtons[6], 6, 6);
  mainLayout->addWidget(var_mult, 6, 7);
  mainLayout->addWidget(var_graf, 6, 8);

  mainLayout->addWidget(var_acos, 7, 0);
  mainLayout->addWidget(var_cos, 7, 1);
  mainLayout->addWidget(var_pi, 7, 2);
  mainLayout->addWidget(m_digitButtons[1], 7, 4);
  mainLayout->addWidget(m_digitButtons[2], 7, 5);
  mainLayout->addWidget(m_digitButtons[3], 7, 6);
  mainLayout->addWidget(var_minus, 7, 7);
  mainLayout->addWidget(var_result, 7, 8, 2, 1);

  mainLayout->addWidget(var_atan, 8, 0);
  mainLayout->addWidget(var_tan, 8, 1);
  mainLayout->addWidget(var_sqrt, 8, 2);
  mainLayout->addWidget(var_00, 8, 4);
  mainLayout->addWidget(m_digitButtons[0], 8, 5);
  mainLayout->addWidget(var_point, 8, 6);
  mainLayout->addWidget(var_plus, 8, 7);

  setStyleSheet(
      "MyButton { background-color: #FAB0CD; font-family: Chalkduster; "
      "font-size: 15px; color: #FA69CD; border-style: outset; border-width: "
      "1px;"
      "border-radius: 10px; border-color: #D6D2D6; min-width: 2em; padding: "
      "1px; }"
      "QLineEdit { font-family: Chalkduster; color: #FA79CD; background-color: "
      "#FFCBD3 }"
      "Calculator { background-color: #FFDAD3 }");

  QFont font = m_display_up->font();
  font.setPointSize(font.pointSize() + 30);
  m_display_up->setFont(font);

  setLayout(mainLayout);

  setWindowTitle("Calculator");
}

void Calculator::CheckClickedX() {
  MyButton* temp = (MyButton*)sender();
  QString x_clicked = temp->text();
  QString last_elem = m_display_up->text().last(1);

  if (m_display_up->text() == "0") {
    new_widget_for_x->show();
    m_display_up->setText(x_clicked);
  } else if (last_elem == "(" || last_elem == "/" || last_elem == "*" ||
             last_elem == "+" || last_elem == "-" || last_elem == "^" ||
             last_elem == "%") {
    if (new_widget_for_x->xxxx.isEmpty()) {
      new_widget_for_x->show();
      m_display_up->setText(m_display_up->text() + x_clicked);
    } else if (!new_widget_for_x->xxxx.isEmpty()) {
      m_display_up->setText(m_display_up->text() + x_clicked);
    }
  }
}

MyButton* Calculator::CreateButton(const QString& text, const char* member) {
  MyButton* temp = new MyButton(text);
  buttons.push_back(temp);

  connect(temp, SIGNAL(clicked()), this, member);

  return temp;
}

void Calculator::DigitClicked() {
  MyButton* temp = (MyButton*)sender();
  QString digit = temp->text();
  QString last_elem = m_display_up->text().last(1);

  if (m_display_up->text() == "0") {
    m_display_up->setText(digit);
  } else if (last_elem == "+" || last_elem == "-" || last_elem == "*" ||
             last_elem == "/" || last_elem == "^" || last_elem == "%" ||
             last_elem == "(" ||
             isdigit(*last_elem.toStdString().data()) == 1 ||
             last_elem == ".") {
    m_display_up->setText(m_display_up->text() + digit);
  }

  qDebug() << "digit pressed" << digit;

  //    if (m_display_up->text() == "0") {
  //        m_display_up->Clear();
  //    }

  //    m_display_up->setText(m_display_up->text() + digit);
}

void Calculator::UnaryOperatorClicked() {
  MyButton* temp = (MyButton*)sender();
  QString unary = temp->text();
  QString last_elem = m_display_up->text().last(1);

  if (unary == "00") {
    if ((last_elem == "." || isdigit(*last_elem.toStdString().data()) == 1) &&
        m_display_up->text() != "0") {
      m_display_up->setText(m_display_up->text() + unary);
    }
  } else if (unary == "(") {
    if (m_display_up->text() == "0") {
      m_display_up->setText(unary);
    } else if (last_elem == "+" || last_elem == "-" || last_elem == "*" ||
               last_elem == "/" || last_elem == "%" || last_elem == "^" ||
               last_elem == "(") {
      m_display_up->setText(m_display_up->text() + unary);
    }
  } else if (unary == ")") {
    int count_bracket_open = m_display_up->text().count('(');
    int count_bracked_closed = m_display_up->text().count(')');
    if (count_bracked_closed < count_bracket_open) {
      if (last_elem == "π" || isdigit(*last_elem.toStdString().data()) == 1 ||
          last_elem == ")" || last_elem == "x") {
        count = 0;
        m_display_up->setText(m_display_up->text() + unary);
      }
    }
  }

  qDebug() << "In unary" << unary;
}

void Calculator::AuxiliaryOperatorClicked() {
  MyButton* temp = (MyButton*)sender();
  QString auxiliary = temp->text();
  QString last_elem = m_display_up->text().last(1);

  if (auxiliary == "π") {
    if (m_display_up->text() == "0") {
      m_display_up->setText(auxiliary);
    } else if (last_elem == "+" || last_elem == "-" || last_elem == "*" ||
               last_elem == "/" || last_elem == "^" || last_elem == "%" ||
               last_elem == "(") {
      m_display_up->setText(m_display_up->text() + auxiliary);
    }
  } else if (auxiliary == "%" || auxiliary == "^" || auxiliary == "/" ||
             auxiliary == "*") {
    if (m_display_up->text() != "0" &&
        (last_elem == "π" || last_elem == ")" ||
         isdigit(*last_elem.toStdString().data()) == 1 || last_elem == "x")) {
      m_display_up->setText(m_display_up->text() + auxiliary);
      count = 0;
    }
  }

  qDebug() << "In auxiliary" << auxiliary;
}

void Calculator::DoubleOperatorClicked() {
  count = 0;
  MyButton* temp = (MyButton*)sender();
  QString double_operation = temp->text();
  QString last_elem = m_display_up->text().last(1);

  if (m_display_up->text() == "0" &&
      (double_operation == "-" || double_operation == "+")) {
    m_display_up->setText(double_operation);
  } else if ((double_operation == "-" || double_operation == "+") &&
             m_display_up->text() != "0") {
    if (isdigit(*last_elem.toStdString().data()) == 1 || last_elem == "π" ||
        last_elem == "(" || last_elem == ")" || last_elem == "x") {
      m_display_up->setText(m_display_up->text() + double_operation);
    }
  }
}

void Calculator::EqualClicked() {
  char* equal;
  QString templ = m_display_up->text();
  templ.replace(QString("π"), QString("P"));
  templ.replace(QString("x"), new_widget_for_x->xxxx);

  qDebug() << "templ" << templ;

  int count_bracket_open = m_display_up->text().count('(');
  int count_bracked_closed = m_display_up->text().count(')');
  if (count_bracked_closed == count_bracket_open) {
    QByteArray result = templ.toLatin1();
    equal = result.data();
    reduction_of_variables(equal);
    m_display_up->setText(QString::number(reduction_of_variables(equal)));
  }
}

void Calculator::CheckPoint() {
  MyButton* temp = (MyButton*)sender();
  QString point = temp->text();

  for (int i = 0; i < m_display_up->text().size(); ++i) {
    if (isdigit(m_display_up->text().toStdString()[i]) == 1 &&
        i == (m_display_up->text().size() - 1) && count == 0) {
      PointClicked();
    }
  }
  qDebug() << "In check point" << point;
}

int Calculator::PointClicked() {
  MyButton* temp = (MyButton*)sender();
  QString point = temp->text();

  m_display_up->setText(m_display_up->text() + point);
  count = 1;

  qDebug() << "In point" << point;
  return 0;
}

void Calculator::ChangeSingClicked() {}

void Calculator::TrigonometryClicked() {
  MyButton* temp = (MyButton*)sender();
  QString trigono = temp->text();
  QString last_elem = m_display_up->text().last(1);

  if (m_display_up->text() == "0") {
    m_display_up->setText(trigono + "(");
  } else if (isdigit(*last_elem.toStdString().data()) == 0 &&
             (last_elem == "+" || last_elem == "-" || last_elem == "/" ||
              last_elem == "*" || last_elem == "(")) {
    m_display_up->setText(m_display_up->text() + trigono + "(");
  }
  qDebug() << "In trigonometry" << trigono;
}

void Calculator::DepositClicked() {
  new_widget_for_deposit->show();
  this->close();
}

void Calculator::CreditClicked() {
  new_widget_for_credit->show();
  this->close();
}

void Calculator::GraphsClicked() {
  //    new_widget_for_graphs->show();
}

void Calculator::Clear() {
  QString text = m_display_up->text();
  text.chop(1);
  if (text.isEmpty()) {
    text = "0";
  }
  m_display_up->setText(text);
}

void Calculator::ClearAll() { m_display_up->setText("0"); }

void Calculator::AbortOperation() {}
