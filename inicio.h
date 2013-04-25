#ifndef INICIO_H
#define INICIO_H

#include <QMainWindow>

namespace Ui {
class Inicio;
}

class Inicio : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Inicio(QWidget *parent = 0);
    ~Inicio();
    
private:
    Ui::Inicio *ui;
};

#endif // INICIO_H
