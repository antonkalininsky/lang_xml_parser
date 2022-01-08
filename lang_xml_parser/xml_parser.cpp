#include "xml_parser.h"
#include <QFile>
#include <QDomDocument>
#include <QDomElement>
#include <QTextStream>
#include <vector>

#include <QXmlStreamReader>

#include <QDebug>

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
    QXmlStreamReader reader(f);
    std::string textID,paragraphID,sentenceID,tokenID;
    // the scan
    while(!reader.atEnd()) {
        reader.readNext();
        if (reader.tokenType() == QXmlStreamReader::StartElement) {
            // update ids
            QXmlStreamAttributes attr = reader.attributes();
            if (reader.name() == "text") {
                if (attr.hasAttribute("id")) {
                    textID = attr.value("id").toString().toStdString();
                } else {
                    textID = "noID";
                }
            }
            if (reader.name() == "paragraph") {
                if (attr.hasAttribute("id")) {
                    paragraphID = attr.value("id").toString().toStdString();
                } else {
                    paragraphID = "noID";
                }
            }
            if (reader.name() == "sentence") {
                if (attr.hasAttribute("id")) {
                    sentenceID = attr.value("id").toString().toStdString();
                } else {
                    sentenceID = "noID";
                }
            }
            if (reader.name() == "token") {
                if (attr.hasAttribute("id")) {
                    tokenID = attr.value("id").toString().toStdString();
                } else {
                    tokenID = "noID";
                }
            }
            // actual check
            if (reader.name() == "token") {
                // get text
                std::string text;
                if (attr.hasAttribute("text")) {
                    text = attr.value("text").toString().toStdString();
                } else {
                    text = "no text";
                }
                // check text
                if (std::regex_search(text, std::regex("Школа"))) {
                    rslt.push_back(xmlAddr());
                    rslt[rslt.size() - 1].textID = textID;
                    rslt[rslt.size() - 1].paraID = paragraphID;
                    rslt[rslt.size() - 1].sentID = sentenceID;
                    rslt[rslt.size() - 1].tokenID = tokenID;
                    rslt[rslt.size() - 1].word = text;
                }
            }
        }
    }

    // rslt
    std::cout << "found rslts:\n";
    for (int i = 0; i < rslt.size(); i++) {
        std::cout << rslt[i].textID << " ";
        std::cout << rslt[i].paraID << " ";
        std::cout << rslt[i].sentID << " ";
        std::cout << rslt[i].tokenID << " ";
        std::cout << rslt[i].word << "\n";
    }

    f->close();
    delete f;
    return;
}

