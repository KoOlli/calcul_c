#include "credit_calculator.h"

#include <QButtonGroup>
#include <QGridLayout>
#include <QHeaderView>
#include <QMenu>
#include <QMenuBar>
#include <QRegularExpressionValidator>
#include <QtGui>

#include "ui_credit_calculator.h"

Credit_calculator::Credit_calculator(QWidget* parent) : QWidget(parent) {
  QGridLayout* mainLayout = new QGridLayout;

  //  QString time_format = "dd.MM.yyyy";
  data = new QLabel;
  data->setText("Дата");

  search_data = new QLineEdit;
  search_data->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^([0-9]{1,2}[.][0-9]{1,2}[.][0-9]{1,4})"), this));

  //  data = QDateTime::currentDateTime();
  //  QString data_smt = data->toString(time_format);

  MyButton* return_on_calculator =
      CreateButton("Вернуться к калькулятору", SLOT(BackToCalculatorClicked()));

  total_loan_amount = new QLabel;
  total_loan_amount->setText("Общая сумма кредита, в рублях");

  sum_credit = new QLineEdit;
  sum_credit->setAlignment(Qt::AlignRight);

  // валидация для ввода ТОЛЬКО чиселок
  sum_credit->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^([0-9]{1,9}[.][0-9]{1,2})"), this));
  sum_credit->setMaxLength(10);

  term = new QLabel;
  term->setText("Срок кредита, в месяцах");

  term_in_months = new QSpinBox;
  term_in_months->setMaximum(600);
  term_in_months->setAlignment(Qt::AlignRight);

  interest_rate = new QLabel;
  interest_rate->setText("Процентная ставка");

  percentage_rate = new QLineEdit;
  percentage_rate->setAlignment(Qt::AlignRight);
  percentage_rate->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^([0-9]{1,2}[,.][0-9]{1,2})"), this));

  type = new QLabel;
  type->setText("Тип ежемесячных платежей");

  annuitet = new QRadioButton;
  different = new QRadioButton;

  radio_button_group = new QButtonGroup;
  annuitet->setText("аннуитетный");
  different->setText("дифференцированный");

  MyButton* make_a_calculation =
      CreateButton("Рассчитать", SLOT(MakeCalculateClicked()));

  calculation_of_payments = new QTableWidget;
  calculation_of_payments->setEditTriggers(QAbstractItemView::NoEditTriggers);
  calculation_of_payments->setColumnCount(4);

  calculation_of_payments->setHorizontalHeaderItem(
      0, new QTableWidgetItem("Сумма платежа"));
  calculation_of_payments->setHorizontalHeaderItem(
      1, new QTableWidgetItem("Сумма в погашение тела кредита"));
  calculation_of_payments->setHorizontalHeaderItem(
      2, new QTableWidgetItem("Сумма в погашение процентов"));
  calculation_of_payments->setHorizontalHeaderItem(
      3, new QTableWidgetItem("Остаток долга"));

  overpayment_on_a_loan = new QLabel;
  overpayment_on_a_loan->setText("Переплата по кредиту");
  total_payment = new QLabel;
  total_payment->setText("Общая выплата по кредиту");
  result = new QLabel;

  mainLayout->addWidget(data, 0, 0);
  mainLayout->addWidget(search_data, 0, 1);
  mainLayout->addWidget(total_loan_amount, 1, 0);
  mainLayout->addWidget(sum_credit, 1, 1);
  mainLayout->addWidget(term, 2, 0);
  mainLayout->addWidget(term_in_months, 2, 1);

  mainLayout->addWidget(interest_rate, 3, 0);
  mainLayout->addWidget(percentage_rate, 3, 1);
  mainLayout->addWidget(type, 4, 0);
  mainLayout->addWidget(annuitet, 4, 1);
  mainLayout->addWidget(different, 4, 2);

  mainLayout->addWidget(make_a_calculation, 5, 1);
  mainLayout->addWidget(return_on_calculator, 5, 2);

  mainLayout->addWidget(calculation_of_payments, 12, 0, 3, 5);
  mainLayout->addWidget(overpayment_on_a_loan, 10, 0);
  mainLayout->addWidget(result, 11, 1);
  mainLayout->addWidget(total_payment, 11, 0);

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
      "#8AFFDC; font-size: 30px }"
      "QRadioButton { color: #00C994; font-size: 18px; font-family: Luminari "
      "}");

  QFont font = sum_credit->font();
  font.setPointSize(font.pointSize() + 5);
  sum_credit->setFont(font);
  term_in_months->setFont(font);
  percentage_rate->setFont(font);

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

void Credit_calculator::MakeCalculateClicked() {
  allButtons = findChildren<QRadioButton*>();
  for (int i = 0; i < allButtons.size(); ++i) {
    radio_button_group->addButton(allButtons[i], i);
  }
  //  qDebug() << radio_button_group->checkedId();
  if (radio_button_group->checkedId() == 0) {
    AnnuitetTable();
  } else {
    EstimationDifferent();
  }
}

void Credit_calculator::AnnuitetTable() {
  int year = 2022;
  //  int month = 6;

  calculation_of_payments->setRowCount(term_in_months->text().toInt());

  QTableWidgetItem* item;
  double balance = sum_credit->text().toDouble();

  for (int i = 0; i < term_in_months->text().toInt(); i++) {
    item = new QTableWidgetItem(QString::number(
        loan_annuitet_calculation(sum_credit->text().toDouble(),
                                  term_in_months->text().toInt(),
                                  percentage_rate->text().toDouble(), i),
        'f', 2));
    calculation_of_payments->setItem(i, 0, item);

    item = new QTableWidgetItem(QString::number(
        sum_percent(&balance, percentage_rate->text().toDouble(), i, year), 'f',
        2));
    calculation_of_payments->setItem(i, 2, item);

    item = new QTableWidgetItem(QString::number(
        sum_body(sum_credit->text().toDouble(), term_in_months->text().toInt(),
                 percentage_rate->text().toDouble(), i, &balance, year),
        'f', 2));
    calculation_of_payments->setItem(i, 1, item);

    item = new QTableWidgetItem(QString::number(
        balance_of_debt(sum_credit->text().toDouble(),
                        term_in_months->text().toInt(),
                        percentage_rate->text().toDouble(), i, &balance, year),
        'f', 2));
    calculation_of_payments->setItem(i, 3, item);
  }
}

void Credit_calculator::EstimationAnnuitet() {}
void Credit_calculator::EstimationDifferent() {
  int year = 2022;
  calculation_of_payments->setRowCount(term_in_months->text().toInt());

  QTableWidgetItem* item;
  double balance = sum_credit->text().toDouble();

  for (int i = 0; i < term_in_months->text().toInt(); i++) {
    item = new QTableWidgetItem(
        QString::number(part_of_the_principal(sum_credit->text().toDouble(),
                                              term_in_months->text().toInt()),
                        'f', 2));
    calculation_of_payments->setItem(i, 1, item);

    item = new QTableWidgetItem(QString::number(
        loan_different_calculation(sum_credit->text().toDouble(),
                                   term_in_months->text().toInt(), &balance,
                                   percentage_rate->text().toDouble(), i, year),
        'f', 2));
    calculation_of_payments->setItem(i, 0, item);

    item = new QTableWidgetItem(QString::number(
        sum_percent(&balance, percentage_rate->text().toDouble(), i, year), 'f',
        2));
    calculation_of_payments->setItem(i, 2, item);

    item = new QTableWidgetItem(QString::number(
        balance_of_debt(sum_credit->text().toDouble(),
                        term_in_months->text().toInt(),
                        percentage_rate->text().toDouble(), i, &balance, year),
        'f', 2));
    calculation_of_payments->setItem(i, 3, item);
  }
}
void Credit_calculator::BackToCalculatorClicked() {
  this->close();
  emit firstWindow();
}

Credit_calculator::~Credit_calculator() {}
