#ifndef FRMFECHABAJA_H
#define FRMFECHABAJA_H

#include <QDialog>
#include "global_includes.h"

namespace Ui {
class FrmFechaBaja;
}

class FrmFechaBaja : public QDialog
{
    Q_OBJECT
    
public:
    explicit FrmFechaBaja(QWidget *parent = 0);
    ~FrmFechaBaja();
    QDate fechabaja;
    
protected:
    void changeEvent(QEvent *e);
    
private:
    Ui::FrmFechaBaja *ui;
private slots:
    void baja();
};

#endif // FRMFECHABAJA_H
