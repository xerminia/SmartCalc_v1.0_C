#include "mainwindow.h"

#include "./ui_mainwindow.h"
#include "grafiktocalcash.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->lineEdit_exp->setEnabled(false);
  ui->lineEdit_x->setEnabled(false);
  vizivay_tebya = new GrafikToCalcash;
  connect(this, &MainWindow::signal, vizivay_tebya, &GrafikToCalcash::slot);
  vizivay_credit = new CreditCalc;
  connect(this, &MainWindow::signal2, vizivay_credit, &CreditCalc::slot);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_point, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_closeb, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_openb, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(digits_numbers()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label, new_label_x;
  new_label = 0;
  new_label_x = 0;
  QString tmp = ui->lineEdit_exp->text();
  QString tmp_x = ui->lineEdit_x->text();
  new_label = button->text();
  new_label_x = button->text();
  tmp += new_label;
  tmp_x += new_label_x;
  if (ui->radioButton_exp->isChecked()) {
    ui->lineEdit_exp->setText(tmp);
  } else if (ui->radioButton_x->isChecked()) {
    ui->lineEdit_x->setText(tmp_x);
  }
  if (ui->radioButton_x->isChecked())
    if (!ui->lineEdit_x->text().isEmpty())
      ui->pushButton_minus->setEnabled(false);
}

void MainWindow::on_pushButton_clear_clicked() {
  if (ui->radioButton_exp->isChecked()) {
    ui->lineEdit_exp->clear();
  } else if (ui->radioButton_x->isChecked()) {
    ui->lineEdit_x->clear();
    ui->pushButton_point->setEnabled(true);
    ui->pushButton_minus->setEnabled(true);
  } else {
    ui->lineEdit_exp->clear();
    ui->lineEdit_x->clear();
    ui->pushButton_point->setEnabled(true);
    ui->pushButton_minus->setEnabled(true);
  }
}

void MainWindow::on_pushButton_equals_clicked() {
  QString res_str = ui->lineEdit_exp->text();
  QString res_x = ui->lineEdit_x->text();
  if (res_str.isEmpty()) {
  } else {
    std::string tmp_input_str = res_str.toUtf8().data();
    char input_str[256] = "\0";
    strcpy(input_str, tmp_input_str.c_str());
    std::string tmp_input_x = res_x.toUtf8().data();
    char input_x[256] = "\0";
    strcpy(input_x, tmp_input_x.c_str());
    setlocale(LC_NUMERIC, "C");
    QString result;
    result = QString("%1").arg(calcash(input_str, input_x));
    if (result.contains("Error input!")) {
      QMessageBox *error = new QMessageBox;
      error->setMaximumSize(2500, 2500);
      error->setWindowTitle("Fatal!");
      error->setText("Error input!");
      error->show();
      on_pushButton_clear_clicked();
      ui->lineEdit_exp->clear();
      ui->lineEdit_x->clear();
    } else if (ui->lineEdit_exp->text().contains('x') &&
               ui->lineEdit_x->text().isEmpty()) {
      vizivay_tebya->setWindowTitle("График");
      vizivay_tebya->show();
      emit signal(ui->lineEdit_exp->text());
    } else {
      ui->lineEdit_exp->setText(result);
    }
  }
}

void MainWindow::on_radioButton_exp_pressed() {
  ui->pushButton_plus->setEnabled(true);
  ui->pushButton_x->setEnabled(true);
  ui->pushButton_mult->setEnabled(true);
  ui->pushButton_div->setEnabled(true);
  ui->pushButton_mod->setEnabled(true);
  ui->pushButton_closeb->setEnabled(true);
  ui->pushButton_openb->setEnabled(true);
  ui->pushButton_pow->setEnabled(true);
  ui->pushButton_cos->setEnabled(true);
  ui->pushButton_sin->setEnabled(true);
  ui->pushButton_tan->setEnabled(true);
  ui->pushButton_acos->setEnabled(true);
  ui->pushButton_asin->setEnabled(true);
  ui->pushButton_atan->setEnabled(true);
  ui->pushButton_sqrt->setEnabled(true);
  ui->pushButton_ln->setEnabled(true);
  ui->pushButton_log->setEnabled(true);
  ui->pushButton_point->setEnabled(true);
  ui->pushButton_minus->setEnabled(true);
}

void MainWindow::on_radioButton_x_pressed() {
  ui->pushButton_plus->setEnabled(false);
  ui->pushButton_x->setEnabled(false);
  ui->pushButton_mult->setEnabled(false);
  ui->pushButton_div->setEnabled(false);
  ui->pushButton_mod->setEnabled(false);
  ui->pushButton_closeb->setEnabled(false);
  ui->pushButton_openb->setEnabled(false);
  ui->pushButton_pow->setEnabled(false);
  ui->pushButton_cos->setEnabled(false);
  ui->pushButton_sin->setEnabled(false);
  ui->pushButton_tan->setEnabled(false);
  ui->pushButton_acos->setEnabled(false);
  ui->pushButton_asin->setEnabled(false);
  ui->pushButton_atan->setEnabled(false);
  ui->pushButton_sqrt->setEnabled(false);
  ui->pushButton_ln->setEnabled(false);
  ui->pushButton_log->setEnabled(false);
  if (ui->lineEdit_x->text().contains('-'))
    ui->pushButton_minus->setEnabled(false);
  if (ui->lineEdit_x->text().contains('.'))
    ui->pushButton_point->setEnabled(false);
}

void MainWindow::on_pushButton_point_clicked() {
  if (ui->radioButton_x->isChecked()) ui->pushButton_point->setEnabled(false);
}

void MainWindow::on_pushButton_minus_clicked() {
  if (ui->radioButton_x->isChecked()) ui->pushButton_minus->setEnabled(false);
}

void MainWindow::on_action_triggered() {
  vizivay_credit->setWindowTitle("Кредитный Калькулятор");
  vizivay_credit->show();
  emit signal2();
}

void MainWindow::on_pushButton_clear_one_sym_clicked() {
  if (ui->radioButton_exp->isChecked()) {
    QString tmp_exp;
    tmp_exp = ui->lineEdit_exp->text();
    if (tmp_exp.endsWith("acos") || tmp_exp.endsWith("asin") ||
        tmp_exp.endsWith("atan") || tmp_exp.endsWith("sqrt")) {
      tmp_exp.chop(4);
    } else if (tmp_exp.endsWith("cos") || tmp_exp.endsWith("sin") ||
               tmp_exp.endsWith("tan") || tmp_exp.endsWith("log")) {
      tmp_exp.chop(3);
    } else if (tmp_exp.endsWith("ln")) {
      tmp_exp.chop(2);
    } else {
      tmp_exp.chop(1);
    }
    ui->lineEdit_exp->setText(tmp_exp);
  } else if (ui->radioButton_x->isChecked()) {
    QString tmp_x = ui->lineEdit_x->text();
    tmp_x.chop(1);
    ui->lineEdit_x->setText(tmp_x);
    if (ui->lineEdit_x->text().contains('-')) {
      ui->pushButton_minus->setEnabled(false);
    } else {
      ui->pushButton_minus->setEnabled(true);
    }
    if (ui->lineEdit_x->text().contains('.')) {
      ui->pushButton_point->setEnabled(false);
    } else {
      ui->pushButton_point->setEnabled(true);
    }
  }
}
