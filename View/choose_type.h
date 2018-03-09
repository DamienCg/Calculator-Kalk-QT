#ifndef CHOOSE_TYPE_H
#define CHOOSE_TYPE_H
#include <QWidget>
class QLabel;
class QComboBox;
class QVBoxLayout;

class Choose_Type: public QWidget{

    Q_OBJECT
private:
    QComboBox* listatipi;
    QLabel* labelscegli;
    QVBoxLayout* VB;
public slots:
    void riceviEdEmetti(int);
signals:
    void emetti(int);
public:
    Choose_Type(QWidget* = 0);
    void switchToType(int)const;
    virtual ~Choose_Type();
};

#endif // CHOOSE_TYPE_H
