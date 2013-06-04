#include "inicio.h"
#include "ui_inicio.h"

Inicio::Inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);
    connect(ui->btnProducto_herbolario,SIGNAL(clicked()),this,SLOT(btnProd_herbolarios_clicked()));
    connect(ui->actionBD_Productos_herbolario,SIGNAL(triggered()),this,SLOT(btnProd_herbolarios_clicked()));
}

Inicio::~Inicio()
{
    delete ui;
}

void Inicio::btnProd_herbolarios_clicked()
{
    FrmProductosHerbolario herbol(this);
    herbol.setWindowState(Qt::WindowMaximized);
    herbol.exec();
}

void Inicio::on_btn_fitoterapia_occidental_clicked()
{
    Frm_Plantas_medicinales pm(this);
    pm.setWindowState(Qt::WindowMaximized);
    pm.exec();
}
