#include "frmproductosherbolario.h"
#include "ui_frmproductosherbolario.h"

FrmProductosHerbolario::FrmProductosHerbolario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmProductosHerbolario)
{
    ui->setupUi(this);
}

FrmProductosHerbolario::~FrmProductosHerbolario()
{
    delete ui;
}
