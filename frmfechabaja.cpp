#include "frmfechabaja.h"
#include "ui_frmfechabaja.h"

FrmFechaBaja::FrmFechaBaja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmFechaBaja)
{
    ui->setupUi(this);
}

FrmFechaBaja::~FrmFechaBaja()
{
    delete ui;
}

void FrmFechaBaja::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
 void FrmFechaBaja::baja()
 {
     this->fechabaja = ui->txtfecha->date();
     QDialog::accept();
 }
