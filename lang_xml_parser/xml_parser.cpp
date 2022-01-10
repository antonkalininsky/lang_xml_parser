#include "xml_parser.h"
#include <QFile>
#include <QTextStream>
#include <vector>
#include <QXmlStreamReader>
#include "regexcreator.h"
#include "xmladdress.h"
#include <QRegExp>

xml_parser::xml_parser() {}

std::vector<xmlAddr> xml_parser::operator()(QString word) {
    // контейнер для хранения результата поиска
    std::vector<xmlAddr> rslt;

    // регулярное выражение для поиска
    QRegExp rx(regExCreator()(word));

    // открываем файл
    QFile f("temp.xml");
    if (!f.exists()) return rslt;
    if (!f.open(QIODevice::ReadOnly)) return rslt;

    // готовимся к парсингу
    QXmlStreamReader reader(&f);
    QString textID,paragraphID,sentenceID,tokenID;

    // основной цикл парсинга
    while(!reader.atEnd()) {
        reader.readNext();
        if (reader.tokenType() == QXmlStreamReader::StartElement) {
            // чтение idшников
            QXmlStreamAttributes attr = reader.attributes();
            if (reader.name() == "text") {
                if (attr.hasAttribute("id")) {
                    textID = attr.value("id").toString();
                } else {
                    textID = "noID";
                }
            }
            if (reader.name() == "paragraph") {
                if (attr.hasAttribute("id")) {
                    paragraphID = attr.value("id").toString();
                } else {
                    paragraphID = "noID";
                }
            }
            if (reader.name() == "sentence") {
                if (attr.hasAttribute("id")) {
                    sentenceID = attr.value("id").toString();
                } else {
                    sentenceID = "noID";
                }
            }
            if (reader.name() == "token") {
                if (attr.hasAttribute("id")) {
                    tokenID = attr.value("id").toString();
                } else {
                    tokenID = "noID";
                }
                // получение текста
                QString text;
                if (attr.hasAttribute("text")) {
                    text = attr.value("text").toString();
                } else {
                    text = "no text";
                }
                // сравнение с регулярным выражением и сохранение результата
                if (rx.exactMatch(text.toLower())) {
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

    return rslt;
}
