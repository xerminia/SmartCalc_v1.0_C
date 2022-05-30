#ifndef GRAFIKTOCALCASH_H
#define GRAFIKTOCALCASH_H

#include <QDialog>

namespace Ui {
class GrafikToCalcash;
}

class GrafikToCalcash : public QDialog {
  Q_OBJECT

 public:
  explicit GrafikToCalcash(QWidget *parent = nullptr);
  ~GrafikToCalcash();

 public slots:
  void slot(QString input_str);

 private slots:
  void on_pushButton_graf_clicked();

 private:
  Ui::GrafikToCalcash *ui;
  double X, xBegin, xEnd, h;
  QVector<double> x, y;
};

#endif  // GRAFIKTOCALCASH_H
