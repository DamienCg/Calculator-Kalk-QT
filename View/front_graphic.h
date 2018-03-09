#ifndef FRONTGRAPHIC_H
#define FRONTGRAPHIC_H
#include <QWidget>
#include "choose_type.h"
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QStackedWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPixmap>

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
    bool checkHex(const QString &)const;
    bool checkDecimal(const QString &)const;
    bool checkOctal(const QString &)const;
    void showMessagebox(const QString &)const;
    void addLayout(QWidget*,int);
    virtual ~Front_graphic();

};

#endif // FRONTGRAPHIC_H
