#include "./View/binary_graphic.h"
#include "./View/hex_graphic.h"
#include "./View/choose_type.h"
#include "./View/octal_graphic.h"
#include <QStackedWidget>
#include <QApplication>
#include <QPixmap>
int main(int argc, char *argv[]){

    QApplication Kalk(argc, argv);

    QStackedWidget* Stack=new QStackedWidget();
    binary_graphic* BinaryGrap=new binary_graphic(Stack);
    Hex_Graphic* HexGrap = new Hex_Graphic(Stack);
    octal_graphic* OctalGrap= new octal_graphic(Stack);

    Stack->setFixedSize(600,620);
    QPixmap bkgnd(":/bg1.jpg");
    bkgnd = bkgnd.scaled(Stack->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);

    Stack->setWindowIcon(QIcon(":/icon.png"));
    Stack->setPalette(palette);
    Stack->addWidget(BinaryGrap);
    Stack->addWidget(HexGrap);
    Stack->addWidget(OctalGrap);
    Stack->show();
    return Kalk.exec();

}
