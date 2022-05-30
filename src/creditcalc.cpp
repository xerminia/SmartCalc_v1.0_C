#include "creditcalc.h"

#include "QtWidgets/qmessagebox.h"
#include "ui_creditcalc.h"

CreditCalc::CreditCalc(QWidget *parent)
    : QWidget(parent), ui(new Ui::CreditCalc) {
  ui->setupUi(this);
  ui->lineEdit_total_sum->setEnabled(false);
  ui->lineEdit_month->setEnabled(false);
  ui->lineEdit_prepay->setEnabled(false);
  ui->lineEdit_month_2->setEnabled(false);
  ui->lineEdit_total_sum->setStyleSheet("color: rgb(255, 255, 255)");
  ui->lineEdit_month->setStyleSheet("color: rgb(255, 255, 255)");
  ui->lineEdit_prepay->setStyleSheet("color: rgb(255, 255, 255)");
  ui->lineEdit_month_2->setStyleSheet("color: rgb(255, 255, 255)");
}

CreditCalc::~CreditCalc() { delete ui; }

void CreditCalc::on_pushButton_res_clicked() {
  QString str_sum = ui->lineEdit_sum->text();
  QString str_date = ui->lineEdit_date->text();
  QString str_date2 = ui->lineEdit_date_2->text();
  QString str_perc = ui->lineEdit_perc->text();
  bool ok1, ok2, ok3, ok4;
  double sum = str_sum.toDouble(&ok1);
  double date2 = str_date2.toDouble(&ok4);
  double date = str_date.toDouble(&ok2);
  double perc = str_perc.toDouble(&ok3);
  if (ui->lineEdit_sum->text().isEmpty()) {
    sum = 0;
    ok1 = 1;
  }
  if (ui->lineEdit_date_2->text().isEmpty()) {
    date2 = 0;
    ok4 = 1;
  }
  if (ui->lineEdit_date->text().isEmpty()) {
    ok2 = 1;
    date = 0;
  }
  if (ui->lineEdit_perc->text().isEmpty()) {
    ok3 = 1;
    perc = 0;
  }
  date = date2 + date * 12;
  if (ok4 && ok1 && ok2 && ok3 && sum > 0 && date > 0 && perc > 0 &&
      date < 600 && perc < 1000) {
    if (ui->radioButton_ann->isChecked()) {
      double PS = (perc / 100) / 12;
      double month = sum * (PS + (PS / (pow(1 + PS, date) - 1)));
      double total_sum = month * date;
      double prepay = total_sum - sum;
      QString month_str = QString::number(month, 'f', 2);
      QString prepay_str = QString::number(prepay, 'f', 2);
      QString total_sum_str = QString::number(total_sum, 'f', 2);
      ui->lineEdit_month->setText(month_str);
      ui->lineEdit_prepay->setText(prepay_str);
      ui->lineEdit_total_sum->setText(total_sum_str);
      ui->lineEdit_month_2->setText(month_str);
    } else if (ui->radioButton_diff->isChecked()) {
      double sum_on_month = sum / date;
      double PS = (perc / 100) / 12;
      double month = sum / date + sum * PS;
      double total_sum = month;
      double tmp_sum = sum;
      QString month_str = QString::number(month, 'f', 2);
      date -= 1;
      for (int i = 0; i < date;) {
        sum = sum - sum_on_month;
        month = sum / date + sum * PS;
        total_sum += month;
        date -= 1;
      }
      QString month_2 = QString::number(month, 'f', 2);
      ui->lineEdit_month_2->setText(month_2);
      double prepay = total_sum - tmp_sum;
      QString prepay_str = QString::number(prepay, 'f', 2);
      QString total_sum_str = QString::number(total_sum, 'f', 2);
      ui->lineEdit_prepay->setText(prepay_str);
      ui->lineEdit_month->setText(month_str);
      ui->lineEdit_total_sum->setText(total_sum_str);
    } else {
      QMessageBox *mb = new QMessageBox;
      mb->setWindowTitle("Error!");
      mb->setText("Не выбран тип расчета.");
      mb->show();
    }
  } else {
    QMessageBox *mb = new QMessageBox;
    mb->setWindowTitle("Fatal!");
    mb->setText("Error input!");
    mb->show();
    ui->lineEdit_month->clear();
    ui->lineEdit_month_2->clear();
    ui->lineEdit_date->clear();
    ui->lineEdit_date_2->clear();
    ui->lineEdit_perc->clear();
    ui->lineEdit_sum->clear();
    ui->lineEdit_prepay->clear();
    ui->lineEdit_total_sum->clear();
  }
}

void CreditCalc::slot() {}
