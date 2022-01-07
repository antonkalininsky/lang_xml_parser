#include <QCoreApplication>
#include <string>
#include <regex>
#include <vector>
#include <iostream>

#include "regexcreator.h"

// visualiser
void visualiser(std::vector<std::string> x) {
    for (int i = 0; i < x.size(); i++) {
        std::cout << x[i] << " ";
    }
    std::cout << "\n";
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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


    return a.exec();
}
