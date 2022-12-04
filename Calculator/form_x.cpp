#include "form_x.h"

#include "ui_form_x.h"

Form_x::Form_x(QWidget* parent)
    : QWidget(parent)
//    ui(new Ui::Form_x)
{
  display_for_x = new QLineEdit();
  QGridLayout* mainLayout = new QGridLayout;

  display_for_x->setText("0");
  display_for_x->setReadOnly(true);
  display_for_x->setAlignment(Qt::AlignRight);
  display_for_x->setMaxLength(255);

  for (int i = 0; i < 10; ++i) {
    m_digitButtons[i] = CreateButton(QString::number(i), SLOT(DigitClicked()));
  }

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

  mainLayout->addWidget(display_for_x, 0, 0, 2, 8);

  mainLayout->addWidget(var_pi, 4, 0);
  mainLayout->addWidget(var_sqrt, 4, 1);
  mainLayout->addWidget(var_open_bracket, 4, 3);
  mainLayout->addWidget(var_close_bracket, 4, 4);
  mainLayout->addWidget(var_cencel_symbol, 4, 5);
  mainLayout->addWidget(var_cencel_string, 4, 6);
  mainLayout->addWidget(var_degree, 4, 7);

  mainLayout->addWidget(var_ln, 5, 0);
  mainLayout->addWidget(var_log, 5, 1);
  mainLayout->addWidget(m_digitButtons[7], 5, 3);
  mainLayout->addWidget(m_digitButtons[8], 5, 4);
  mainLayout->addWidget(m_digitButtons[9], 5, 5);
  mainLayout->addWidget(var_div, 5, 6);
  mainLayout->addWidget(var_mod, 5, 7);

  mainLayout->addWidget(var_asin, 6, 0);
  mainLayout->addWidget(var_sin, 6, 1);
  mainLayout->addWidget(m_digitButtons[4], 6, 3);
  mainLayout->addWidget(m_digitButtons[5], 6, 4);
  mainLayout->addWidget(m_digitButtons[6], 6, 5);
  mainLayout->addWidget(var_mult, 6, 6);
  mainLayout->addWidget(var_result, 6, 7, 3, 1);

  mainLayout->addWidget(var_acos, 7, 0);
  mainLayout->addWidget(var_cos, 7, 1);
  mainLayout->addWidget(m_digitButtons[1], 7, 3);
  mainLayout->addWidget(m_digitButtons[2], 7, 4);
  mainLayout->addWidget(m_digitButtons[3], 7, 5);
  mainLayout->addWidget(var_minus, 7, 6);

  mainLayout->addWidget(var_atan, 8, 0);
  mainLayout->addWidget(var_tan, 8, 1);
  mainLayout->addWidget(var_00, 8, 3);
  mainLayout->addWidget(m_digitButtons[0], 8, 4);
  mainLayout->addWidget(var_point, 8, 5);
  mainLayout->addWidget(var_plus, 8, 6);

  setStyleSheet(
      "MyButton { font-family: Chalkduster; background-color: #D9C3F7; "
      "font-size: 15px; border-style: outset; border-width: 1px; color: "
      "#B693FA; "
      "border-radius: 10px; border-color: #D6D2D6; min-width: 2em; padding: "
      "1px }"
      "QLineEdit { font-family: Chalkduster; color: #AAABFA; background-color: "
      "#E1D7FA }"
      "Form_x { background-color: #F1E3FA }");
  //    MyButton { background-color: #FAB0CD; font-family: Chalkduster;
  //    font-size: 15px; color: #FA69CD; border-style: outset; border-width:
  //    1px;"
  //                      "border-radius: 10px; border-color: beige; min-width:
  //                      2em; padding: 1px; }"

  //    m_display_x->setFixedSize(150, 30);

  QFont font = display_for_x->font();
  font.setPointSize(font.pointSize() + 30);
  display_for_x->setFont(font);
  //    QFont siz = m_display_x->font();
  //    siz.setPointSize(siz.pointSize() + 7);
  //    m_display_x->setFont(siz);
  //    m_x->setFont(siz);

  setLayout(mainLayout);

  setWindowTitle("X");
}

MyButton* Form_x::CreateButton(const QString& text, const char* member) {
  MyButton* temp = new MyButton(text);
  buttons.push_back(temp);

  connect(temp, SIGNAL(clicked()), this, member);

  return temp;
}

void Form_x::DigitClicked() {
  MyButton* temp = (MyButton*)sender();
  QString digit = temp->text();
  QString last_elem = display_for_x->text().last(1);

  if (display_for_x->text() == "0") {
    display_for_x->setText(digit);
  } else if (last_elem == "+" || last_elem == "-" || last_elem == "*" ||
             last_elem == "/" || last_elem == "^" || last_elem == "%" ||
             last_elem == "(" ||
             isdigit(*last_elem.toStdString().data()) == 1 ||
             last_elem == ".") {
    display_for_x->setText(display_for_x->text() + digit);
  }

  qDebug() << "digit pressed" << digit;
}
void Form_x::UnaryOperatorClicked() {
  MyButton* temp = (MyButton*)sender();
  QString unary = temp->text();
  QString last_elem = display_for_x->text().last(1);

  if (unary == "00") {
    if ((last_elem == "." || isdigit(*last_elem.toStdString().data()) == 1) &&
        display_for_x->text() != "0") {
      display_for_x->setText(display_for_x->text() + unary);
    }
  } else if (unary == "(") {
    if (display_for_x->text() == "0") {
      display_for_x->setText(unary);
    } else if (last_elem == "+" || last_elem == "-" || last_elem == "*" ||
               last_elem == "/" || last_elem == "%" || last_elem == "^" ||
               last_elem == "(") {
      display_for_x->setText(display_for_x->text() + unary);
    }
  } else if (unary == ")") {
    int count_bracket_open = display_for_x->text().count('(');
    int count_bracked_closed = display_for_x->text().count(')');
    if (count_bracked_closed < count_bracket_open) {
      if (last_elem == "π" || isdigit(*last_elem.toStdString().data()) == 1 ||
          last_elem == ")" || last_elem == "x") {
        count = 0;
        display_for_x->setText(display_for_x->text() + unary);
      }
    }
  }

  qDebug() << "In unary" << unary;
}
void Form_x::DoubleOperatorClicked() {
  count = 0;
  MyButton* temp = (MyButton*)sender();
  QString double_operation = temp->text();
  QString last_elem = display_for_x->text().last(1);

  if (display_for_x->text() == "0" && double_operation == "-") {
    display_for_x->setText(double_operation);
  } else if (double_operation == "-" ||
             (double_operation == "+" && display_for_x->text() != "0")) {
    if (isdigit(*last_elem.toStdString().data()) == 1 || last_elem == "π" ||
        last_elem == "(" || last_elem == ")" || last_elem == "x") {
      display_for_x->setText(display_for_x->text() + double_operation);
    }
  }
}
void Form_x::EqualClicked() {
  //
  //  result_xxxxxxx = "123456";
  emit firstWindow();
}

void Form_x::CheckPoint() {
  MyButton* temp = (MyButton*)sender();
  QString point = temp->text();

  for (int i = 0; i < display_for_x->text().size(); ++i) {
    if (isdigit(display_for_x->text().toStdString()[i]) == 1 &&
        i == (display_for_x->text().size() - 1) && count == 0) {
      PointClicked();
    }
  }
  qDebug() << "In check point" << point;
}

void Form_x::PointClicked() {
  MyButton* temp = (MyButton*)sender();
  QString point = temp->text();

  display_for_x->setText(display_for_x->text() + point);
  count = 1;

  qDebug() << "In point" << point;
}

// void ChangeSingClicked() {

//}

void Form_x::TrigonometryClicked() {
  MyButton* temp = (MyButton*)sender();
  QString trigono = temp->text();
  QString last_elem = display_for_x->text().last(1);

  if (display_for_x->text() == "0") {
    display_for_x->setText(trigono + "(");
  } else if (isdigit(*last_elem.toStdString().data()) == 0 &&
             (last_elem == "+" || last_elem == "-" || last_elem == "/" ||
              last_elem == "*" || last_elem == "(")) {
    display_for_x->setText(display_for_x->text() + trigono + "(");
  }
  qDebug() << "In trigonometry" << trigono;
}
// void AddFunctionsClicked() {

//}
void Form_x::Clear() {
  QString text = display_for_x->text();
  text.chop(1);
  if (text.isEmpty()) {
    text = "0";
  }
  display_for_x->setText(text);
}
void Form_x::ClearAll() { display_for_x->setText("0"); }

void Form_x::AuxiliaryOperatorClicked() {
  MyButton* temp = (MyButton*)sender();
  QString auxiliary = temp->text();
  QString last_elem = display_for_x->text().last(1);

  if (auxiliary == "π") {
    if (display_for_x->text() == "0") {
      display_for_x->setText(auxiliary);
    } else if (last_elem == "+" || last_elem == "-" || last_elem == "*" ||
               last_elem == "/" || last_elem == "^" || last_elem == "%" ||
               last_elem == "(") {
      display_for_x->setText(display_for_x->text() + auxiliary);
    }
  } else if (auxiliary == "%" || auxiliary == "^" || auxiliary == "/" ||
             auxiliary == "*") {
    if (display_for_x->text() != "0" &&
        (last_elem == "π" || last_elem == ")" ||
         isdigit(*last_elem.toStdString().data()) == 1 || last_elem == "x")) {
      display_for_x->setText(display_for_x->text() + auxiliary);
      count = 0;
    }
  }

  qDebug() << "In auxiliary" << auxiliary;
}
// void AbortOperation() {

//}

Form_x::~Form_x() {
  //    delete ui;
}

//    MyButton*  temp = (MyButton*) sender();
//    QString x = temp->text();
//    QWidget window_for_x;
//    QString last_elem = new_widget_for_x->text().last(1);
//    if (new_widget_for_x->text() == "0") {
//        new_widget_for_x->setText(x);
//    } else if (last_elem == "(" || last_elem == "/" || last_elem == "*" ||
//    last_elem == "+" || last_elem == "-" || last_elem == "^" || last_elem ==
//    "%") {
//        new_widget_for_x->setText(new_widget_for_x->text() + x);
//    }
//    ui->setupUi(this);
