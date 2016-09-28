#ifndef TELADORANK_H
#define TELADORANK_H

#include <QDialog>

namespace Ui {
class telaDoRank;
}

class telaDoRank : public QDialog
{
    Q_OBJECT

public:
    explicit telaDoRank(QWidget *parent = 0);
    ~telaDoRank();
private:
    Ui::telaDoRank *ui;
};

#endif // TELADORANK_H
