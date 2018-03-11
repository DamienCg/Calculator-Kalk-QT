#ifndef BINARY_GRAPHIC_H
#define BINARY_GRAPHIC_H
#include "front_graphic.h"
#include "./Controller/binary_controller.h"
class QLineEdit;
class QComboBox;

class binary_graphic: public Front_graphic{
    Q_OBJECT
public slots:
void calcolaoperazioniprimarie();
void calcolaconversioneBtoType();
void calcolaconversioneDtoB();
void Calcolapercorsoresultop1op2();
void calcolapercorsoA();

private:    
    QLineEdit* op1;
    QLineEdit* op2;
    QLineEdit* inputB;
    QLineEdit* inputD;
    QLineEdit*inputpercorso;
    QComboBox* operazioni;
    QLineEdit* Result;
    QLineEdit* resultconvBtoDHO;
    QLineEdit* resultconvDtoB;
    QLineEdit* perorsoalbero;
    QComboBox* operazioniDiConversione;
    binary_controller ctrl;
    const static int OperationIndex = 0;

public:
    binary_graphic(QStackedWidget*, QWidget * = 0);
};

#endif // BINARY_GRAPHIC_H
