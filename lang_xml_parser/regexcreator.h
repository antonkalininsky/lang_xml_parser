#ifndef REGEXCREATOR_H
#define REGEXCREATOR_H

#include <string>
#include <vector>

class regExCreator
{
public:
    regExCreator();
    std::string operator()(std::string w);
private:
    std::vector<std::string> searchRules(std::string w);
    std::string strCompiler(std::vector<std::string> sAdd);
};

#endif // REGEXCREATOR_H
