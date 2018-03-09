#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "./Model/arithmetic_types.h"
#include "./Model/calcola.h"
class QString;

class Controller{
private:
    Calcola calcolatrice;
public:
  Controller(Arithmetic_Types* a = 0, Arithmetic_Types* b = 0);
  QString CostruisciEcalcolaEConvertiop1op2(const QString &, const QString &, const QString &);
  QString CostruisciEcalcolaConversioneTtoD(const QString&);
  QString CostruisciEcalcolaConversioneDtoT(const QString&);
  QString CotruisciECalcolaRadice(const QString&);
  virtual ~Controller()=default;
};

#endif // CONTROLLER_H
