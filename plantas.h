#ifndef PLANTAS_H
#define PLANTAS_H

#include <QObject>
#include "global_includes.h"

class Plantas : public QObject
{
    Q_OBJECT
public:
    explicit Plantas(QObject *parent = 0);
    int id;

    QString nombre_espanol_espana;
    QString nombre_espanol_mexico;
    QString nombre_cientifico_latin;
    QString principiosactivos;
    QString accion;
    QString efectos_secundarios;
    QString posologia;
    QString nombre_catala;
    QString estados;

    void recuperarImagen();
    void guardarImagen();
    void anadirDatos();
    void guardarDatos();
    void recuperarDatos(int id_planta);
    void baja(int id_planta);
    void clear();
    
signals:
    
public slots:
    
};

#endif // PLANTAS_H
