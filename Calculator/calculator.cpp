#include <calculator.h>

#include <QGridLayout>
#include <QToolButton>
#include <QTextLine>
#include <QChar>

#include <QDebug>






Calculator::Calculator()
{
    m_display_up =            new QLineEdit();
    m_display_x =             new QLineEdit();
    m_x =                     new QLabel;
    QGridLayout* mainLayout = new QGridLayout;


    m_display_up->setText("0");


    m_display_up->setReadOnly(true);
    m_x->setText("    x = ");

    m_display_up->setAlignment(Qt::AlignRight);
    m_display_x-> setAlignment(Qt::AlignRight);


    m_display_up->setMaxLength(30);
    m_display_x-> setMaxLength(30);







    for (int i = 0; i < 10; ++i) {
        m_digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked()));
}

    MyButton* var_point =  createButton(".", SLOT(pointClicked()));

    MyButton* var_cencel_symbol = createButton("CE", SLOT(clear()));
    MyButton* var_cencel_string = createButton("C", SLOT(clearAll()));

    MyButton* var_div =    createButton("/", SLOT(doubleOperatorClicked()));
    MyButton* var_mult =   createButton("*", SLOT(doubleOperatorClicked()));
    MyButton* var_minus =  createButton("-", SLOT(doubleOperatorClicked()));
    MyButton* var_plus =   createButton("+", SLOT(doubleOperatorClicked()));


    MyButton* var_sqrt =          createButton("sqrt", SLOT(unaryOperatorClicked()));
    MyButton* var_pi =            createButton("π", SLOT(unaryOperatorClicked()));
    MyButton* var_mod =           createButton("%", SLOT(unaryOperatorClicked()));
    MyButton* var_degree =        createButton("^", SLOT(unaryOperatorClicked()));
    MyButton* var_open_bracket =  createButton("(", SLOT(unaryOperatorClicked()));
    MyButton* var_close_bracket = createButton(") ", SLOT(unaryOperatorClicked()));
    MyButton* var_00 =            createButton("00", SLOT(unaryOperatorClicked()));


    MyButton* var_deposit = createButton("dep", SLOT(addFunctionsClicked()));
    MyButton* var_cred =    createButton("cred", SLOT(addFunctionsClicked()));
    MyButton* var_graf =    createButton("graf", SLOT(addFunctionsClicked()));

    MyButton* var_ln =     createButton("ln", SLOT(trigonometryClicked()));
    MyButton* var_log =    createButton("log", SLOT(trigonometryClicked()));
    MyButton* var_asin =   createButton("asin", SLOT(trigonometryClicked()));
    MyButton* var_sin =    createButton("sin", SLOT(trigonometryClicked()));
    MyButton* var_acos =   createButton("acos", SLOT(trigonometryClicked()));
    MyButton* var_cos =    createButton("cos", SLOT(trigonometryClicked()));
    MyButton* var_atan =   createButton("atan", SLOT(trigonometryClicked()));
    MyButton* var_tan =    createButton("tan", SLOT(trigonometryClicked()));

    MyButton* var_result = createButton("=", SLOT(equalClicked()));



    QFont font = m_display_up->font();
    QFont display = m_display_x->font();
    font.setPointSize(font.pointSize() + 8);
    display.setPointSize(display.pointSize() + 24);

    m_display_up->setFont(display);

    m_x-> setFont(font);
    m_display_x-> setFont(font);
    var_open_bracket-> setFont(font);
    var_close_bracket-> setFont(font);
    var_cencel_symbol-> setFont(font);
    var_cencel_string-> setFont(font);
    var_deposit-> setFont(font);

    var_ln-> setFont(font);
    var_log-> setFont(font);
    var_degree-> setFont(font);
    m_digitButtons[7]-> setFont(font);
    m_digitButtons[8]-> setFont(font);
    m_digitButtons[9]-> setFont(font);
    var_div-> setFont(font);
    var_cred-> setFont(font);

    var_asin-> setFont(font);
    var_sin-> setFont(font);
    var_mod-> setFont(font);
    m_digitButtons[4]-> setFont(font);
    m_digitButtons[5]-> setFont(font);
    m_digitButtons[6]-> setFont(font);
    var_mult-> setFont(font);
    var_graf-> setFont(font);

    var_acos-> setFont(font);
    var_cos-> setFont(font);
    var_pi-> setFont(font);
    m_digitButtons[3]-> setFont(font);
    m_digitButtons[2]-> setFont(font);
    m_digitButtons[1]-> setFont(font);
    var_minus-> setFont(font);
    var_result-> setFont(font);

    var_atan-> setFont(font);
    var_tan-> setFont(font);
    var_sqrt-> setFont(font);
    var_00-> setFont(font);
    m_digitButtons[0]-> setFont(font);
    var_point-> setFont(font);
    var_plus-> setFont(font);



    mainLayout->addWidget(m_display_up,      0, 0, 2, 16);

    mainLayout->addWidget(m_x,               4, 0, 2, 2);
    mainLayout->addWidget(m_display_x,       4, 2, 2, 4);
    mainLayout->addWidget(var_open_bracket,  4, 6, 2, 2);
    mainLayout->addWidget(var_close_bracket, 4, 8, 2, 2);
    mainLayout->addWidget(var_cencel_symbol, 4, 10, 2, 2);
    mainLayout->addWidget(var_cencel_string, 4, 12, 2, 2);
    mainLayout->addWidget(var_deposit,       4, 14, 2, 2);

    mainLayout->addWidget(var_ln,            6, 0, 2, 2);
    mainLayout->addWidget(var_log,           6, 2, 2, 2);
    mainLayout->addWidget(var_degree,        6, 4, 2, 2);
    mainLayout->addWidget(m_digitButtons[7], 6, 6, 2, 2);
    mainLayout->addWidget(m_digitButtons[8], 6, 8, 2, 2);
    mainLayout->addWidget(m_digitButtons[9], 6, 10, 2, 2);
    mainLayout->addWidget(var_div,           6, 12, 2, 2);
    mainLayout->addWidget(var_cred,          6, 14, 2, 2);

    mainLayout->addWidget(var_asin,          8, 0, 2, 2);
    mainLayout->addWidget(var_sin,           8, 2, 2, 2);
    mainLayout->addWidget(var_mod,           8, 4, 2, 2);
    mainLayout->addWidget(m_digitButtons[4], 8, 6, 2, 2);
    mainLayout->addWidget(m_digitButtons[5], 8, 8, 2, 2);
    mainLayout->addWidget(m_digitButtons[6], 8, 10, 2, 2);
    mainLayout->addWidget(var_mult,          8, 12, 2, 2);
    mainLayout->addWidget(var_graf,          8, 14, 2, 2);

    mainLayout->addWidget(var_acos,          10, 0, 2, 2);
    mainLayout->addWidget(var_cos,           10, 2, 2, 2);
    mainLayout->addWidget(var_pi,            10, 4, 2, 2);
    mainLayout->addWidget(m_digitButtons[1], 10, 6, 2, 2);
    mainLayout->addWidget(m_digitButtons[2], 10, 8, 2, 2);
    mainLayout->addWidget(m_digitButtons[3], 10, 10, 2, 2);
    mainLayout->addWidget(var_minus,         10, 12, 2, 2);
    mainLayout->addWidget(var_result,        10, 14, 4, 2);

    mainLayout->addWidget(var_atan,          12, 0, 2, 2);
    mainLayout->addWidget(var_tan,           12, 2, 2, 2);
    mainLayout->addWidget(var_sqrt,          12, 4, 2, 2);
    mainLayout->addWidget(var_00,            12, 6, 2, 2);
    mainLayout->addWidget(m_digitButtons[0], 12, 8, 2, 2);
    mainLayout->addWidget(var_point,         12, 10, 2, 2);
    mainLayout->addWidget(var_plus,          12, 12, 2, 2);




    setLayout(mainLayout);

    setWindowTitle("Calculator");

}



MyButton* Calculator::createButton(const QString& text, const char* member) {
    MyButton* btn = new MyButton(text);

    connect(btn, SIGNAL(clicked()), this, member);
    return btn;
}

void Calculator::digitClicked() {
    MyButton*  btn = (MyButton*) sender();
    QString digit = btn->text();
    if (m_display_up->text() == "0") {
        m_display_up->setText(digit);
    } else {
        m_display_up->setText(m_display_up->text() + digit);
    }
    qDebug() << "digit pressed" << digit;

//    if (m_display_up->text() == "0") {
//        m_display_up->clear();
//    }

//    m_display_up->setText(m_display_up->text() + digit);
}

void Calculator::unaryOperatorClicked() {

}

void Calculator::doubleOperatorClicked() {

}

void Calculator::equalClicked() {

}

void Calculator::pointClicked() {

}

void Calculator::changeSingClicked() {

}

void Calculator::trigonometryClicked() {

}

void Calculator::addFunctionsClicked() {

}

void Calculator::clear() {

}

void Calculator::clearAll() {

}
