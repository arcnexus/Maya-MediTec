#include "plantas.h"

Plantas::Plantas(QObject *parent) :
    QObject(parent)
{
}

void Plantas::recuperarImagen()
{

}

void Plantas::guardarImagen()
{

}

void Plantas::anadirDatos()
{
    QSqlQuery producto(QSqlDatabase::database("db_meditec"));
    if(producto.exec("INSERT INTO fitoterapia_occidental (nombre_espanol_espana) VALUES ('');")){
        this->clear();
        this->id = producto.lastInsertId().toInt();

    }
}

void Plantas::guardarDatos()
{
    QSqlQuery producto(QSqlDatabase::database("db_meditec"));
    producto.prepare("UPDATE fitoterapia_occidental SET "
                     "nombre_espanol_espana =:nombre_espanol_espana,"
                     "nombre_espanol_mexico =:nombre_espanol_mexico,"
                     "nombre_cientifico_latin =:nombre_cientifico_latin,"
                     "principiosactivos =:principiosactivos,"
                     "accion =:accion,"
                     "efectos_secundarios =:efectos_secundarios,"
                     "posologia =:posologia,"
                     "nombre_catala =:nombre_catala,"
                     "estado =:estado "
                     "WHERE id =:id;");


    producto.bindValue(":nombre_espanol_espana",this->nombre_espanol_espana);
    producto.bindValue(":nombre_espanol_mexico",this->nombre_espanol_mexico);
    producto.bindValue(":nombre_cientifico_latin",this->nombre_cientifico_latin);
    producto.bindValue(":principiosactivos",this->principiosactivos);
    producto.bindValue(":accion",this->accion);
    producto.bindValue(":efectos_secundarios",this->efectos_secundarios);
    producto.bindValue(":posologia",this->posologia);
    producto.bindValue(":nombre_catala",this->nombre_catala);
    producto.bindValue(":estados",this->estados);
    producto.bindValue(":id",this->id);

    if(!producto.exec()){
        QMessageBox::warning(qApp->activeWindow(),tr("ERROR"),
                             tr("No se pudo guardar la información: %1").arg(producto.lastError().text()),
                             tr("Aceptar"));
    } else {
        QMessageBox::information(qApp->activeWindow(),tr("MODIFICAR PRODUCTO"),
                                 tr("El producto ha sido correctamente actualizado"),tr("Aceptar"));
    }
}

void Plantas::recuperarDatos(int id_planta)
{
    QSqlQuery producto(QSqlDatabase::database("db_meditec"));
    producto.prepare("select * from fitoterapia_occidental where id = :id");
    producto.bindValue(":id",id_planta);
    if(!producto.exec()){
        QMessageBox::warning(qApp->activeWindow(),tr("ERROR"),
                             tr("Error al recuperar los datos: %1").arg(producto.lastError().text()),
                             tr("Aceptar"));
    } else {
        producto.next();
        this->id = producto.record().value("id").toInt();
        this->nombre_espanol_espana = producto.record().value("nombre_espanol_espana").toString();
        this->nombre_espanol_mexico = producto.record().value("nombre_espanol_mexico").toString();
        this->nombre_cientifico_latin = producto.record().value("nombre_cientifico_latin").toString();
        this->principiosactivos = producto.record().value("principiosactivos").toString();
        this->accion = producto.record().value("accion").toString();
        this->efectos_secundarios  = producto.record().value("efectos_secundarios").toString();
        this->posologia = producto.record().value("posologia").toString();
        this->nombre_catala = producto.record().value("nombre_catala").toString();
        this->estados = producto.record().value("estado").toString();


    }

}

void Plantas::baja(int id_planta)
{

}

void Plantas::clear()
{
    this->id =0;
    this->nombre_espanol_espana = "";
    this->nombre_espanol_mexico = "";
    this->nombre_cientifico_latin = "";
    this->principiosactivos = "";
    this->accion ="";
    this->efectos_secundarios  = "";
    this->posologia = "";
    this->nombre_catala = "";
    this->estados = "";
}
