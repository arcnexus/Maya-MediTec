#ifndef PRODUCTO_HERBOLARIO_H
#define PRODUCTO_HERBOLARIO_H

#include <QObject>
#include "global_includes.h"

class producto_herbolario : public QObject
{
    Q_OBJECT
public:
    explicit producto_herbolario(QObject *parent = 0);
    int id;
    QString nombre;
    QString descripcion;
    QString contraindicaciones;
    double precio;
    QString indicaciones;
    QString composicion;
    QString presentacion;
    QString advertencias;
    int id_laboratorio;
    QString laboratorio;

    void recuperarImagen();
    void guardarImagen();
    void anadirDatos();
    void guardarDatos();
    void recuperarDatos(int id_producto);
    void borrarDatos();
    void clear();
    QString devolver_laboratorio(int id_laboratorio);
    int devolver_id_laboratorio(QString laboratorio);

signals:
    
public slots:
    
};

#endif // PRODUCTO_HERBOLARIO_H
