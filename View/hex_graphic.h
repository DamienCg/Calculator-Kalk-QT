#ifndef HEX_GRAPHIC_H
#define HEX_GRAPHIC_H
#include "front_graphic.h"
#include "./Controller/hex_controller.h"
class QPushButton;
class QStackedWidget;
class QLineEdit;

class Hex_Graphic: public Front_graphic {
    Q_OBJECT

public slots:
void calcolaoperazioniprimarie();
void calcolaconversioneHtoType();
void calcolaconversioneDtoH();
void CalcolaColoreRGBresultop1op2();
void CalcolaColoreRGB();//controllare se colore valido max 6 caratteri

private:
    QLineEdit* op1;
    QComboBox* operazioni;
    QLineEdit* op2;
    QLabel* labelresult;
    QLineEdit* Result;
    QLineEdit* inputH;
    QLineEdit* inputD;
    QLineEdit* resultconvHtoDBO;
    QLineEdit* resultconvDtoH;
    QLineEdit* inputcolore;
    QLabel*resultcolore;
    QComboBox* operazioniDiConversione;
    hex_controller ctrl;
    const static int OperationIndex = 1;
public:
    Hex_Graphic(QStackedWidget*, QWidget * = 0);
};

#endif // HEX_GRAPHIC_H
