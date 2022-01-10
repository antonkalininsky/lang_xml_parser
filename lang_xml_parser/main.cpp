#include <QApplication>
#include <QTextCodec>
#include <QMainWindow>

#include "xml_parser.h"
#include "gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // настройка русского языка для работы regEx
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    // main window
    QMainWindow window;
    window.resize(500, 300);

    // gui
    GUI *userInter = new GUI(&a);

    // main window visualisation
    window.setCentralWidget(userInter);
    window.setWindowTitle("Word Finder");
    window.show();

    return a.exec();
}
