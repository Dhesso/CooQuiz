#ifndef LOGUIN_H
#define LOGUIN_H

#include <QWidget>
#include <QMessageBox>
#include "usuario.h"
/*CLASSE PADRÃO DO QT que manipula a janela de login*/

namespace Ui {
class loguin;
}

class loguin : public QWidget
{
    Q_OBJECT

public:
    explicit loguin(QWidget *parent = 0);
    ~loguin();
private slots:
    void on_pushButton_enviar_clicked();

private:
    Ui::loguin *ui;
    usuario *user;
};

#endif // LOGUIN_H
