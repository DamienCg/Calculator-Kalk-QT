#ifndef FRONTGRAPHIC_H
#define FRONTGRAPHIC_H
#include "choose_type.h"
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
protected:
    void setWindowIndex(int);
public:
    Front_graphic(QStackedWidget *, QWidget* = 0);
    bool checkBeforeContinue(const QString &,const QString &, const QString &)const;
    void showMessagebox(const QString &)const;
    void addLayout(QWidget*,int);
};

#endif // FRONTGRAPHIC_H
