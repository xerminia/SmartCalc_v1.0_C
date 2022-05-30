#ifndef SRC_MAINWINDOW_H_
#define SRC_MAINWINDOW_H_
#ifdef __cplusplus
extern "C" {
#endif
#include "calc.h"
#ifdef __cplusplus
}
#endif
#include <grafiktocalcash.h>

#include <QMainWindow>
#include <QMessageBox>
#include <clocale>

#include "creditcalc.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  GrafikToCalcash *vizivay_tebya;
  CreditCalc *vizivay_credit;

 signals:
  void signal(QString);
  void signal2();

 private slots:
  void digits_numbers();
  void on_pushButton_clear_clicked();
  void on_pushButton_equals_clicked();

  void on_radioButton_exp_pressed();
  void on_radioButton_x_pressed();

  void on_pushButton_point_clicked();
  void on_pushButton_minus_clicked();
  void on_action_triggered();
  void on_pushButton_clear_one_sym_clicked();
};
#endif  // SRC_MAINWINDOW_H_
