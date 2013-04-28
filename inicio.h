#ifndef INICIO_H
#define INICIO_H

#include <QMainWindow>
#include "frmproductosherbolario.h"

namespace Ui {
class Inicio;
}

class Inicio : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Inicio(QWidget *parent = 0);
    ~Inicio();
    
private:
    Ui::Inicio *ui;
private slots:
    void btnProd_herbolarios_clicked();
};

#endif // INICIO_H
