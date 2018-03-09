#ifndef ECCEZIONI_H
#define ECCEZIONI_H
#include <QMessageBox>
#include <string>
using std::string;

class MyException{
private:
    QMessageBox* mex;
public:
    MyException(string);
};

#endif // ECCEZIONI_H
