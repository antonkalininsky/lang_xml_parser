#include "xml_parser.h"
#include <QFile>
#include <QDomDocument>
#include <QDomElement>
#include <vector>

#include <iostream>
#include <regex>
#include "regexcreator.h"

#include "xmladdress.h"

xml_parser::xml_parser() {

    // тут будем хранить результаты поиска
    std::vector<xmlAddr> rslt;

    // выделяем память
    QFile *f = new QFile("temp.xml");
    // файл существует
    if (!f->exists()) return;
    // успешное открытие на чтение
    if (!f->open(QIODevice::ReadOnly)) return;
    // чтение всей информации из файла в виде массива байтов
    QByteArray data = f->readAll();
    QDomDocument doc;
    // перевод массива байтов в xml формат
    if (!doc.setContent(data)) {
        f->close(); // если неуспешно
        return;
    }
    // корневой элемент xml
    QDomElement docElement = doc.documentElement();

    // дочерние элементы
    QDomElement textElement = docElement.firstChildElement("text");

    // search
    while (!textElement.isNull()) {
        QDomElement parasElement = textElement.firstChildElement("paragraphs");
        QDomElement paraElement = parasElement.firstChildElement("paragraph");
        while (!paraElement.isNull()) {
            QDomElement sentenceElement = paraElement.firstChildElement("sentence");
            while (!sentenceElement.isNull()) {
                QDomElement tokensElement = sentenceElement.firstChildElement("tokens");
                QDomElement tokenElement = tokensElement.firstChildElement("token");
                while(!tokenElement.isNull()) {
                    if (std::regex_search(tokenElement.attribute("text", "error").toStdString(),
                                          std::regex(regExCreator()("abc")))) {
                        std::cout << textElement.attribute("id", "error").toStdString() << "   ";
                        std::cout << paraElement.attribute("id", "error").toStdString() << "   ";
                        std::cout << sentenceElement.attribute("id", "error").toStdString() << "   ";
                        std::cout << tokenElement.attribute("id", "error").toStdString() << "   ";
                        std::cout << tokenElement.attribute("text", "error").toStdString() << "\n";
                    }
                    tokenElement = tokenElement.nextSiblingElement();
                }
                sentenceElement = sentenceElement.nextSiblingElement();
            }
            paraElement = paraElement.nextSiblingElement();
        }
        textElement = textElement.nextSiblingElement();
    }

    f->close();
    delete f;
    return;
}

