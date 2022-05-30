#ifndef CREDITCALC_H
#define CREDITCALC_H

#include <math.h>

#include <QWidget>

namespace Ui {
class CreditCalc;
}

class CreditCalc : public QWidget {
  Q_OBJECT

 public:
  explicit CreditCalc(QWidget *parent = nullptr);
  ~CreditCalc();
 public slots:
  void slot();

 private slots:
  void on_pushButton_res_clicked();

 private:
  Ui::CreditCalc *ui;
};

#endif  // CREDITCALC_H
