#ifndef FRMPRODUCTOSHERBOLARIO_H
#define FRMPRODUCTOSHERBOLARIO_H

#include <QDialog>
#include "global_includes.h"
#include "producto_herbolario.h"

namespace Ui {
class FrmProductosHerbolario;
}

class FrmProductosHerbolario : public QDialog
{
    Q_OBJECT
    
public:
    explicit FrmProductosHerbolario(QWidget *parent = 0);
    ~FrmProductosHerbolario();
    
private:
    Ui::FrmProductosHerbolario *ui;
    producto_herbolario oProd;
private slots:
    void anadir();
    void guardar();
    void baja();
    void llenarCampos();
    void llenarObjeto();
    void llenarTabla_productos();
    void tabla_producto_clicked(QModelIndex index);
};

#endif // FRMPRODUCTOSHERBOLARIO_H
