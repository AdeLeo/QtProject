#include "starwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StarWidget w;
    w.show();

    return a.exec();
}
