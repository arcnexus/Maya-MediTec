#include "frm_plantas_medicinales.h"
#include "ui_frm_plantas_medicinales.h"
#include "configuracion.h"

Frm_Plantas_medicinales::Frm_Plantas_medicinales(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Frm_Plantas_medicinales)
{
    ui->setupUi(this);

    //-----------------------
    // CONEXIONES
    //-----------------------
    connect(ui->tabla_plantas,SIGNAL(clicked(QModelIndex)),this,SLOT(tabla_producto_clicked(QModelIndex)));
    connect(ui->btnAnadir_2,SIGNAL(clicked()),this,SLOT(anadir()));
    connect(ui->btnGuardar_2,SIGNAL(clicked()),this,SLOT(guardar()));
    connect(ui->btnDeshacer_2,SIGNAL(clicked()),this,SLOT(deshacer()));
     Configuracion::abrirbd();
    llenarTabla_productos();
}

Frm_Plantas_medicinales::~Frm_Plantas_medicinales()
{
    delete ui;
}

void Frm_Plantas_medicinales::anadir()
{
    oPlanta.anadirDatos();
    this->llenarCampos();
}


void Frm_Plantas_medicinales::tabla_producto_clicked(QModelIndex index)
{
    oPlanta.id =ui->tabla_plantas->model()->data(ui->tabla_plantas->model()->index(index.row(),0),Qt::EditRole).toInt();
    oPlanta.recuperarDatos(oPlanta.id);
    this->llenarCampos();
}


void Frm_Plantas_medicinales::llenarTabla_productos()
{
    QSqlQueryModel *productos = new QSqlQueryModel(this);
    productos->setQuery("select id, nombre_espanol_espana from fitoterapia_occidental where nombre_espanol_espana like'a%' ",QSqlDatabase::database("db_meditec"));
    ui->tabla_plantas->setModel(productos);
    ui->tabla_plantas->setColumnHidden(0,true);
    ui->tabla_plantas->setColumnWidth(1,200);
}


void Frm_Plantas_medicinales::llenarObjeto()
{


    oPlanta.nombre_espanol_espana = ui->txtNombre_esp_esp->text();
    oPlanta.nombre_espanol_mexico = ui->txtNombre_esp_mex->text();
    oPlanta.nombre_cientifico_latin = ui->txtNombre_lat->text();
    oPlanta.principiosactivos = ui->txtprincipios_activo->toPlainText();
    oPlanta.accion = ui->txtAccion->toPlainText();
    oPlanta.efectos_secundarios = ui->txtEfectos->toPlainText();
    oPlanta.posologia = ui->txtPosologia->toPlainText();
    oPlanta.nombre_catala = ui->txtNombre_cat->text();
    oPlanta.estados = ui->txtEstado->text();
}


void Frm_Plantas_medicinales::llenarCampos()
{

    ui->txtNombre_esp_esp->setText(oPlanta.nombre_espanol_espana);
    ui->txtNombre_esp_mex->setText(oPlanta.nombre_espanol_mexico);
    ui->txtNombre_lat->setText(oPlanta.nombre_cientifico_latin);
    ui->txtprincipios_activo->setText(oPlanta.principiosactivos);
    ui->txtAccion->setText(oPlanta.accion);
    ui->txtEfectos->setText(oPlanta.efectos_secundarios);
    ui->txtPosologia->setText(oPlanta.posologia);
    ui->txtNombre_cat->setText(oPlanta.nombre_catala);
    ui->txtEstado->setText(oPlanta.estados);
}


void Frm_Plantas_medicinales::baja()
{
}


void Frm_Plantas_medicinales::guardar()
{
    llenarObjeto();
    oPlanta.guardarDatos();
    oPlanta.recuperarDatos(oPlanta.id);
    llenarCampos();
    llenarTabla_productos();
}

void Frm_Plantas_medicinales::deshacer()
{
    oPlanta.recuperarDatos(oPlanta.id);
    llenarCampos();
}

void Frm_Plantas_medicinales::on_txtFiltrar_textEdited(const QString &arg1)
{
    QSqlQueryModel *productos = new QSqlQueryModel(this);
    productos->setQuery("select id, nombre_espanol_espana from fitoterapia_occidental where nombre_espanol_espana like'"+arg1+"%' ",QSqlDatabase::database("db_meditec"));
    ui->tabla_plantas->setModel(productos);
    ui->tabla_plantas->setColumnHidden(0,true);
    ui->tabla_plantas->setColumnWidth(1,200);
}
