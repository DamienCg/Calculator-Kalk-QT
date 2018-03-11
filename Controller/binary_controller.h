#ifndef BINARY_CONTROLLER_H
#define BINARY_CONTROLLER_H
#include "./Controller/eccezioni.h"
#include "./Model/binary.h"
#include "./Controller/controller.h"

class binary_controller: public Controller{
public:
    binary_controller();
    static QString CalcolaBtoOtherTypes(const QString &,const char&);
    static QString Calcolapercorsoalbero(const QString &);
    static QString CalcolaConversioneDtoB(const QString &);
};

#endif // BINARY_CONTROLLER_H
