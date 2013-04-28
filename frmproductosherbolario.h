#ifndef FRMPRODUCTOSHERBOLARIO_H
#define FRMPRODUCTOSHERBOLARIO_H

#include <QDialog>

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
};

#endif // FRMPRODUCTOSHERBOLARIO_H
