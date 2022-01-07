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

#include "regexcreator.h"
#include "xml_parser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    xml_parser pp;



/*
    // demo 1
    std::cout << regExCreator()("abc") << "\n";

    // demo 2
    std::regex RE(regExCreator()("abc"));

    if (std::regex_search("abcdefg", RE)) {
        std::cout << "true";
    } else {
        std::cout << "false";
    }
    std::cout << "\n";

    if (std::regex_search("efg", RE)) {
        std::cout << "true";
    } else {
        std::cout << "false";
    }
    std::cout << "\n";
    */



    return a.exec();
}
