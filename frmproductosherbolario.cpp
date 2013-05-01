#include "frmproductosherbolario.h"
#include "ui_frmproductosherbolario.h"
#include "configuracion.h"
#include "producto_herbolario.h"
#include "frmfechabaja.h"


FrmProductosHerbolario::FrmProductosHerbolario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmProductosHerbolario)
{
    ui->setupUi(this);
    Configuracion::abrirbd();
    llenarTabla_productos();

    //-----------------------
    // CONEXIONES
    //-----------------------
    connect(ui->tabla_productos,SIGNAL(clicked(QModelIndex)),this,SLOT(tabla_producto_clicked(QModelIndex)));


}

FrmProductosHerbolario::~FrmProductosHerbolario()
{
    delete ui;
}

void FrmProductosHerbolario::anadir()
{

    oProd.anadirDatos();
    this->llenarCampos();

}

void FrmProductosHerbolario::guardar()
{
    llenarObjeto();
    oProd.guardarDatos();
    llenarTabla_productos();
}

void FrmProductosHerbolario::baja()
{
    if(QMessageBox::question(qApp->activeWindow(),tr("Atención"),
    tr("¿Desea dar de baja este producto?\nLos productos dados de baja siguen en la BD \npero figuran con fecha de baja"),
    tr("Cancelar"),tr("Dar de baja"))==QMessageBox::Accepted)
    {
        FrmFechaBaja frmbaja(this);
       if(frmbaja.exec() == QDialog::Accepted){
           oProd.fechabaja = frmbaja.fechabaja;
           oProd.baja(oProd.id);
           ui->txtFechaBaja->setDate(oProd.fechabaja);

       }

    }


}

void FrmProductosHerbolario::llenarCampos()
{
    oProd.recuperarDatos(oProd.id);
    ui->txtNombre->setText(oProd.nombre);
    ui->txtDescripcion->setText(oProd.descripcion);
    ui->txtcontra_indicaciones->setText(oProd.contraindicaciones);
    ui->txtPVP->setText(QString::number(oProd.precio,'f',2));
    ui->txtindicaciones->setText(oProd.indicaciones);
    ui->txtprincipios_activos->setText(oProd.principios_activos);
    ui->txtcomposicion->setText(oProd.composicion);
    ui->txtpresentacion->setText(oProd.presentacion);
    ui->txtadvertencias->setText(oProd.advertencias);
    ui->txtLaboratorio->setText(oProd.laboratorio);
    ui->txtFechaBaja->setDate(oProd.fechabaja);
    ui->txtFechaAlta->setDate(oProd.fechaalta);
    if(oProd.esbaja) {
        ui->txtFechaBaja->setVisible(true);
        ui->lblFechaBaja->setVisible(true);
    } else
    {
        ui->txtFechaBaja->setVisible(false);
        ui->lblFechaBaja->setVisible(false);
    }


}

void FrmProductosHerbolario::llenarObjeto()
{
    oProd.nombre = ui->txtNombre->text();
    oProd.descripcion =  ui->txtDescripcion->toPlainText();
    oProd.contraindicaciones =  ui->txtcontra_indicaciones->toPlainText();
    oProd.precio = ui->txtPVP->text().toDouble();
    oProd.indicaciones = ui->txtindicaciones->toPlainText();
    oProd.composicion = ui->txtcomposicion->toPlainText();
    oProd.presentacion = ui->txtpresentacion->toPlainText();
    oProd.advertencias = ui->txtadvertencias->toPlainText();
    oProd.laboratorio = ui->txtLaboratorio->text();
    oProd.fechaalta = ui->txtFechaAlta->date();
    oProd.principios_activos = ui->txtprincipios_activos->toPlainText();
}

void FrmProductosHerbolario::llenarTabla_productos()
{
    QSqlQueryModel *productos = new QSqlQueryModel(this);
    productos->setQuery("Select id, nombre, laboratorio from productos where nombre like'a%' ",QSqlDatabase::database("db_meditec"));
    ui->tabla_productos->setModel(productos);
    ui->tabla_productos->setColumnHidden(0,true);
    ui->tabla_productos->setColumnWidth(1,200);
}

void FrmProductosHerbolario::tabla_producto_clicked(QModelIndex index)
{
    oProd.id =ui->tabla_productos->model()->data(ui->tabla_productos->model()->index(index.row(),0),Qt::EditRole).toInt();
    this->llenarCampos();
}



