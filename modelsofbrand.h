#ifndef MODELSOFBRAND_H
#define MODELSOFBRAND_H

#include <QDialog>

namespace Ui {
class ModelsOfBrand;
}

class ModelsOfBrand : public QDialog
{
    Q_OBJECT

public:
    explicit ModelsOfBrand(QWidget *parent = nullptr);
    ~ModelsOfBrand();

private:
    Ui::ModelsOfBrand *ui;
};

#endif // MODELSOFBRAND_H
