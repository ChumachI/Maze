#include "view.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    View w;
    w.setFixedSize(850, 600);
    w.show();
    return a.exec();
}
