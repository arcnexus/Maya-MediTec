#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <QObject>
#include "global_includes.h"

class Configuracion : public QObject
{
    Q_OBJECT

public:
    explicit Configuracion(QObject *parent = 0);
    static void abrirbd();
private:

signals:
    
public slots:
    
};

#endif // CONFIGURACION_H
