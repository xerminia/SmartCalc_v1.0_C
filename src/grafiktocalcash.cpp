#include "grafiktocalcash.h"

#include <iostream>

#include "mainwindow.h"
#include "ui_grafiktocalcash.h"

GrafikToCalcash::GrafikToCalcash(QWidget *parent)
    : QDialog(parent), ui(new Ui::GrafikToCalcash) {
  ui->setupUi(this);
}

GrafikToCalcash::~GrafikToCalcash() { delete ui; }

void GrafikToCalcash::slot(QString input_str) { ui->label->setText(input_str); }

void GrafikToCalcash::on_pushButton_graf_clicked() {
  x.clear();
  y.clear();
  QString tmp_x_b = ui->lineEdit_xb->text();
  QString tmp_x_e = ui->lineEdit_xe->text();
  bool ok1, ok2;
  double x_b = tmp_x_b.toDouble(&ok1);
  double x_e = tmp_x_e.toDouble(&ok2);
  if (ok1 && ok2 && x_b < x_e) {
    h = fabs(x_b - x_e) / 100000;
    xBegin = x_b;
    xEnd = x_e + h;
    for (X = x_b; X <= x_e; X += h) {
      char tmp_str_x[255] = "\0";
      std::cout << sprintf(tmp_str_x, "%.10f", X);
      x.push_back(X);
      char *buf;
      QString input_str_for_calcash = ui->label->text();
      std::string tmp_input_str;
      tmp_input_str.clear();
      tmp_input_str = input_str_for_calcash.toUtf8().data();
      char input_str[255];
      input_str[0] = '\0';
      strcpy(input_str, tmp_input_str.c_str());
      setlocale(LC_NUMERIC, "C");
      double Y = strtod(calcash(input_str, tmp_str_x), &buf);
      y.push_back(Y);
    }
  } else {
    QMessageBox *error = new QMessageBox;
    error->setWindowTitle("Fatal!");
    error->setText("Error input!");
    error->show();
  }
  ui->widget->addGraph();
  ui->widget->graph(0)->setData(x, y);
  ui->widget->xAxis->setLabel("x");
  ui->widget->yAxis->setLabel("y");
  ui->widget->xAxis->setRange(x_b, x_e);
  ui->widget->yAxis->setRange(x_b / 10, x_e / 10);
  ui->widget->replot();
  ui->lineEdit_xb->clear();
  ui->lineEdit_xe->clear();
}
