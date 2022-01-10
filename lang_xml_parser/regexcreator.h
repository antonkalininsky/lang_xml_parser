#ifndef REGEXCREATOR_H
#define REGEXCREATOR_H

#include <QString>
#include <vector>

class regExCreator
{
public:
    regExCreator();
    QString operator()(QString w);
private:
    std::vector<QString> searchRules(QString w);
    QString strCompiler(std::vector<QString> sAdd);
};

#endif // REGEXCREATOR_H
