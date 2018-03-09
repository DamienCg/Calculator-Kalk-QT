#ifndef HEX_CONTROLLER_H
#define HEX_CONTROLLER_H
#include "./Controller/controller.h"
#include "./Controller/eccezioni.h"

class hex_controller:public Controller{
public:
    hex_controller();
    static QString CalcolaHtoOtherTypes(const QString &,const char);
    static QString CalcolaColore(QString);//da fare meglio!!!
    static QString CalcolaConversioneDtoH(const QString &);
};

#endif // HEX_CONTROLLER_H
