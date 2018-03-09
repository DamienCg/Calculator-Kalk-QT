#ifndef OCTAL_GRAPHIC_H
#define OCTAL_GRAPHIC_H
#include "front_graphic.h"
#include "./Controller/octal_controller.h"
class QStackedWidget;
class QLineEdit;

class octal_graphic: public Front_graphic{
    Q_OBJECT

public slots:
void calcolaoperazioniprimarie();
void calcolaconversioneOtoType();
void calcolaconversioneDtoO();
void calcola_Emanuel_Swedenborg();
void calcolaNumESsultop1op2();

private:
    QLineEdit* op1;
    QComboBox* operazioni;
    QLineEdit* op2;
    QLabel* labelresult;
    QLineEdit* Result;
    QLineEdit* inputO;
    QLineEdit* inputD;
    QLineEdit* resultconvOtoDHB;
    QLineEdit* resultconvDtoO;
    QComboBox* operazioniDiConversione;
    QLineEdit* resultES;
    QLineEdit* inputES;
    octal_controller ctrl;
    const static int OperationIndex = 2;

public:
    octal_graphic(QStackedWidget*, QWidget * = 0);
    void setlabelerror(QString);
};

#endif // OCTAL_GRAPHIC_H
