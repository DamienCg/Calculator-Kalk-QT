#ifndef HEX_CONTROLLER_H
#define HEX_CONTROLLER_H
#include "./Controller/controller.h"
#include "./Controller/eccezioni.h"

class hex_controller:public Controller{
public:
    hex_controller();
    static QString CalcolaColore(const QString&);
    static QString CalcolaConversioneDtoH(const QString &);
};

#endif // HEX_CONTROLLER_H
