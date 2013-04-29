#include "producto_herbolario.h"



producto_herbolario::producto_herbolario(QObject *parent) :
    QObject(parent)
{

}

void producto_herbolario::recuperarImagen()
{

}

void producto_herbolario::guardarImagen()
{

}

void producto_herbolario::anadirDatos()
{
    QSqlQuery producto(QSqlDatabase::database("db_meditec"));
    if(producto.exec("INSERT INTO productos_herbolario (nombre) VALUES ('');")){
        this->id = producto.lastInsertId().toInt();
        this->clear();
    }
}

void producto_herbolario::guardarDatos()
{
    QSqlQuery producto(QSqlDatabase::database("db_meditec"));
    producto.prepare("UPDATE productos_herbolario SET "
                     "nombre = :nombre,"
                     "descripcion = :descripcion,"
                     "contraindicaciones = :contraindicaciones,"
                     "precio = :precio,"
                     "indicaciones = :indicaciones,"
                     "composicion = :composicion,"
                     "presentacion = :presentacion,"
                     "advertencias = :advertencias,"
                     "id_laboratorio = :id_laboratorio "
                     "WHERE id =:id;");
    producto.bindValue(":nombre",this->nombre);
    producto.bindValue(":descripcion",this->descripcion);
    producto.bindValue(":contraindicaciones",this->contraindicaciones);
    producto.bindValue(":precio",this->precio);
    producto.bindValue(":indicaciones",this->indicaciones);
    producto.bindValue(":composicion",this->composicion);
    producto.bindValue(":presentacion",this->presentacion);
    producto.bindValue(":advertencias",this->advertencias);
    producto.bindValue(":id_laboratorio",this->id_laboratorio);
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

void producto_herbolario::recuperarDatos(int id_producto)
{
    QSqlQuery producto(QSqlDatabase::database("db_meditec"));
    producto.prepare("select * from productos_herbolario where id = :id");
    producto.bindValue(":id",id_producto);
    if(!producto.exec()){
        QMessageBox::warning(qApp->activeWindow(),tr("ERROR"),
                             tr("Error al recuperar los datos: %1").arg(producto.lastError().text()),
                             tr("Aceptar"));
    } else {
        producto.next();
        this->id = id_producto;
        this->nombre = producto.record().value("nombre").toString();
        this->descripcion = producto.record().value("descripcion").toString();
        this->contraindicaciones = producto.record().value("contraindicaciones").toString();
        this->precio = producto.record().value("precio").toDouble();
        this->indicaciones = producto.record().value("indicaciones").toString();
        this->composicion = producto.record().value("composicion").toString();
        this->presentacion = producto.record().value("presentacion").toString();
        this->advertencias = producto.record().value("advertencias").toString();
        this->id_laboratorio = producto.record().value("id_laboratorio").toInt();
        this->laboratorio = this->devolver_laboratorio(this->id_laboratorio);
    }


}

void producto_herbolario::borrarDatos()
{

}

void producto_herbolario::clear()
{
    this->id = 0;
    this->nombre = "";
    this->descripcion = "";
    this->contraindicaciones = "";
    this->precio = 0;
    this->indicaciones = "";
    this->composicion = "";
    this->presentacion = "";
    this->advertencias = "";
    this->id_laboratorio = -1;
    this->laboratorio = "";

}

QString producto_herbolario::devolver_laboratorio(int id_laboratorio)
{
    QSqlQuery querylaboratorio(QSqlDatabase::database("db_meditec"));
    if(querylaboratorio.exec("select laboratorio from laboratorios where id = "+QString::number(id_laboratorio)))
    {
        querylaboratorio.next();
        return querylaboratorio.record().value("laboratorio").toString();
    }
    return "";
}

int producto_herbolario::devolver_id_laboratorio(QString laboratorio)
{
    QSqlQuery querylaboratorio(QSqlDatabase::database("db_meditec"));
    if(querylaboratorio.exec("select id from laboratorios where laboratorio = '"+laboratorio.trimmed()+"'"))
    {
        querylaboratorio.next();
        return querylaboratorio.record().value("id").toInt();
    }
    return -1;
}
