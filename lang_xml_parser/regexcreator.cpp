#include "regexcreator.h"

regExCreator::regExCreator() {}

QString regExCreator::operator()(QString w) {
    return strCompiler(searchRules(w));
}

std::vector<QString> regExCreator::searchRules(QString w) {
    std::vector<QString> r;
    QString buf;
    QString d = "[а-я]";

    // правило 0:
    // само слово "abc"
    r.push_back(w);

    // правило 1:
    // изменена одна буква на любую "[a-z]bc" + "a[a-z]c" + "ab[a-z]"
    for (int i = 0 ; i < w.length(); i++) {
        buf = w;
        //buf.erase(buf.begin() + i);
        buf.remove(i, 1);
        buf.insert(i, d);
        r.push_back(buf);
    }

    // правило 2:
    // убрана любая буква "bc" + "ac" + "ab"
    for (int i = 0 ; i < w.length(); i++) {
        buf = w;
        //buf.erase(buf.begin() + i);
        buf.remove(i, 1);
        r.push_back(buf);
    }

    // правило 3:
    // добавлена любая буква в любое место "[a-z]abc" + "a[a-z]bc" + "ab[a-z]c" + "abc[a-z]"
    for (int i = 0 ; i < w.length(); i++) {
        buf = w;
        buf.insert(i, d);
        r.push_back(buf);
    }
    buf = w + d;
    r.push_back(buf);

    return r;
}

QString regExCreator::strCompiler(std::vector<QString> sAdd) {
    QString s;
    for (int i = 0; i < sAdd.size(); i++) {
        s += sAdd[i];
        if (i < sAdd.size() - 1) {
            s += "|";
        }
    }
    return s;
}

