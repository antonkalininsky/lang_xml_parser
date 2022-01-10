/* todo:
 * ui
 */

#include <QCoreApplication>
#include "xml_parser.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // настройка русского языка для работы regEx
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    // непосредственно поиск
    std::vector<xmlAddr> abc = xml_parser()("Школа");

    return a.exec();
}
