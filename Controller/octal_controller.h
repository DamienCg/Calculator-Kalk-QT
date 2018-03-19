#ifndef OCTAL_CONTROLLER_H
#define OCTAL_CONTROLLER_H
#include "./Model/octal.h"
#include "./Controller/eccezioni.h"
#include "./Controller/controller.h"

class octal_controller: public Controller{
public:
    octal_controller();
    static QString CalcolaConversioneDtoO(const QString &);
    static QString CalcolaEmanuel_Swedenborg(const QString&);
};

#endif // OCTAL_CONTROLLER_H
