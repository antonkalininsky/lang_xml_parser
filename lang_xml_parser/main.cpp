/* todo:
 * русский язык
 * парсер xml
 * регистр
 * ui
 */
#include <QCoreApplication>
#include <string>
#include <regex>
#include <vector>
#include <iostream>

#include <QFile>
#include <QDomDocument>
#include <QDomElement>

#include <QString>

#include "regexcreator.h"
#include "xml_parser.h"

#include <windows.h>
#include <locale>

#include <QLocale>

#include <QDebug>

#include <QTextCodec>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);


    xml_parser pp;

    return a.exec();
}
