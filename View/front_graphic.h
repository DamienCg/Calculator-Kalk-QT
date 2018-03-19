#ifndef FRONTGRAPHIC_H
#define FRONTGRAPHIC_H
#include "choose_type.h"
#include "./Controller/controller.h"
#include <QWidget>
class QStackedWidget;
class QMessageBox;
class QVBoxLayout;

class Front_graphic: public QWidget{
    Q_OBJECT
public slots:
virtual void OpenTypes(int);

private:
    Choose_Type* listatipi;
    QStackedWidget* Stack;
    QMessageBox* mex;
    QVBoxLayout* layout;
    int windowIndex;
    Controller ctrl;
protected:
    void setWindowIndex(int);
    void setController(const Controller&);
public:
    Front_graphic(QStackedWidget *, QWidget* = 0, Controller = Controller());
    bool checkBeforeContinue(const QString &,const QString &, const QString &)const;
    void showMessagebox(const QString &)const;
    void addLayout(QWidget*,int);
    QString frontcalcolaoperazioniprimarie(QString,QString,QString);
    QString frontcalcolaconversionetoType(QString,QString);
};

#endif // FRONTGRAPHIC_H
