#include "configuracion.h"
#include <QMessageBox>

Configuracion::Configuracion(QObject *parent) :
    QObject(parent)
{
}

void Configuracion::abrirbd()
{
    // Abro bdInformación técnica de medicina
    QSqlDatabase DB_MediTec = QSqlDatabase::addDatabase("QMYSQL","db_meditec");

        DB_MediTec.setDatabaseName("maya_meditec");
        DB_MediTec.setHostName("www.mayasoftware.es");
        DB_MediTec.open("maya_maya","PatataBullida_99");

    if (DB_MediTec.lastError().isValid())
    {
        QMessageBox::critical(QApplication::activeWindow(), "error:", DB_MediTec.lastError().text());
    }
}

