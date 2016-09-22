#include "teladorank.h"
#include "ui_teladorank.h"

telaDoRank::telaDoRank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::telaDoRank)
{
    ui->setupUi(this);
    ui->table_rank->set
}

telaDoRank::~telaDoRank()
{
    delete ui;
}
