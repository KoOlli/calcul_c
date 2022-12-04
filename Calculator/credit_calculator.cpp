#include "credit_calculator.h"

#include <QGridLayout>
#include <QMenu>
#include <QMenuBar>
#include <QRegularExpressionValidator>

#include "ui_credit_calculator.h"

Credit_calculator::Credit_calculator(QWidget* parent) : QWidget(parent) {
  QGridLayout* mainLayout = new QGridLayout;

  MyButton* return_on_calculator =
      CreateButton("Вернуться к калькулятору", SLOT(BackToCalculatorClicked()));

  total_loan_amount = new QLabel;
  total_loan_amount->setText("Общая сумма кредита");

  sum_credit = new QLineEdit;
  sum_credit->setAlignment(Qt::AlignRight);
  // валидация для ввода ТОЛЬКО чиселок
  sum_credit->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^([0-9]{1,2}[,.][0-9]{1,2})"), this));
  sum_credit->setMaxLength(10);

  term = new QLabel;
  term->setText("Срок кредита");

  //    term_in_months = new QLineEdit;
  //    term_in_months->setAlignment(Qt::AlignRight);
  //    term_in_months->setValidator(new
  //    QRegularExpressionValidator(QRegularExpression("^([1-9][0-9]*|0)"),
  //    this));
  term_in_months = new QSpinBox;
  term_in_months->setMaximum(60);
  term_in_months->setAlignment(Qt::AlignRight);
  //    term_in_months->setReadOnly(true);

  //    in_months = new QLabel;
  //    in_months->setText("(В месяцах)");

  //  layout = new QVBoxLayout(this);
  //  this->setLayout(layout);
  //  menubar = new QMenuBar(this);
  //  layout->setMenuBar(menubar);

  //  menu = new QMenu("Type", this);
  //  action1 = new QAction("smth", this);
  //  menu->addAction(action1);

  //  menubar->addMenu(menu);

  //  QMenuBar* mb = new QMenuBar(this);
  //  QMenu* menu_type_credit = new QMenu("выберите тип платежа");
  //  menu_type_credit->addAction("аннуитетный");
  //  menu_type_credit->addAction("дифференцированный");
  //  mb->addMenu(menu_type_credit);
  //  QVBoxLayout* layout = new QVBoxLayout;
  //  layout->setMenuBar(menu_type_credit);

  interest_rate = new QLabel;
  interest_rate->setText("Процентная ставка");

  percentage_rate = new QLineEdit;
  percentage_rate->setAlignment(Qt::AlignRight);
  percentage_rate->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^([0-9]{1,2}[,.][0-9]{1,2})"), this));

  type = new QLabel;
  type->setText("Тип ежемесячных платежей");

  MyButton* make_a_calculation =
      CreateButton("Расчитать", SLOT(MakeCalculateClicked()));

  monthly_payment = new QLabel;
  monthly_payment->setText("Ежемесячный платеж");

  overpayment_on_a_loan = new QLabel;
  overpayment_on_a_loan->setText("Переплата по кредиту");

  total_payment = new QLabel;
  total_payment->setText("Общая выплата по кредиту");

  mainLayout->addWidget(total_loan_amount, 1, 0);
  mainLayout->addWidget(sum_credit, 1, 1);
  mainLayout->addWidget(term, 2, 0);
  mainLayout->addWidget(term_in_months, 2, 1);
  //    mainLayout->addWidget(in_months,             2, 2);
  mainLayout->addWidget(interest_rate, 3, 0);
  mainLayout->addWidget(percentage_rate, 3, 1);
  mainLayout->addWidget(type, 4, 0);
  //  mainLayout->addWidget(menubar, 4, 1);
  //    mainLayout->addWidget(menu,                  4, 2);
  mainLayout->addWidget(make_a_calculation, 5, 1);
  mainLayout->addWidget(return_on_calculator, 5, 2);

  mainLayout->addWidget(monthly_payment, 7, 0);
  mainLayout->addWidget(overpayment_on_a_loan, 8, 0);
  mainLayout->addWidget(total_payment, 9, 0);

  setStyleSheet(
      "MyButton { background-color: #81FFDF; font-family: Luminari; font-size: "
      "15px; color: #00C994; border-style: outset; border-width: 2px;"
      "border-radius: 10px; border-color: #D6D2D6; min-width: 2em; padding: "
      "2px; }"
      "QLineEdit { font-family: Chalkduster; color: #00C994; background-color: "
      "#8AFFDC }"
      "Credit_calculator { background-color: #BEFFDE }"
      "QLabel { font-family: Luminari; color: #00C994; font-size: 18px }"
      "QSpinBox { font-family: Chalkduster; color: #00C994; background-color: "
      "#8AFFDC; font-size: 30px }");

  QFont font = sum_credit->font();
  font.setPointSize(font.pointSize() + 5);
  sum_credit->setFont(font);
  term_in_months->setFont(font);
  percentage_rate->setFont(font);
  //    term_in_months->setFont(font);

  setLayout(mainLayout);

  setWindowTitle("Credit Calculator");
}

MyButton* Credit_calculator::CreateButton(const QString& text,
                                          const char* member) {
  MyButton* temp = new MyButton(text);
  buttons.push_back(temp);

  connect(temp, SIGNAL(clicked()), this, member);

  return temp;
}

void Credit_calculator::BackToCalculatorClicked() {
  this->close();
  emit firstWindow();
}

Credit_calculator::~Credit_calculator() {}
