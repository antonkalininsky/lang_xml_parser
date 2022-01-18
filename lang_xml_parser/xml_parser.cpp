#include "xml_parser.h"
#include <QFile>
#include <QTextStream>
#include <vector>
#include <QXmlStreamReader>
#include "regexcreator.h"
#include "xmladdress.h"
#include <QRegExp>

xml_parser::xml_parser() {}

int xml_parser::operator()(std::vector<xmlAddr> &v, QString file) {
    // очистка контейнера для хранения результата парсинга
    v.clear();

    // открываем файл
    QFile f(file);
    if (!f.exists()) return -1; // don't exist
    if (!f.open(QIODevice::ReadOnly)) return -2; // can't open

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
                // сохранение результата
                xmlAddr buf;
                buf.textID = textID;
                buf.textID = textID;
                buf.paraID = paragraphID;
                buf.sentID = sentenceID;
                buf.tokenID = tokenID;
                buf.word = text;
                v.push_back(buf);
            }
        }
    }
    return 0;
}
