#ifndef FRM_PLANTAS_MEDICINALES_H
#define FRM_PLANTAS_MEDICINALES_H

#include "global_includes.h"
#include <QDialog>
#include "plantas.h"

namespace Ui {
class Frm_Plantas_medicinales;
}

class Frm_Plantas_medicinales : public QDialog
{
    Q_OBJECT
    
public:
    explicit Frm_Plantas_medicinales(QWidget *parent = 0);
    ~Frm_Plantas_medicinales();
    
private:
    Ui::Frm_Plantas_medicinales *ui;
    Plantas oPlanta;

private slots:
    void anadir();
    void guardar();
    void deshacer();
    void baja();
    void llenarCampos();
    void llenarObjeto();
    void llenarTabla_productos();
    void tabla_producto_clicked(QModelIndex index);
    void on_txtFiltrar_textEdited(const QString &arg1);
};

#endif // FRM_PLANTAS_MEDICINALES_H
