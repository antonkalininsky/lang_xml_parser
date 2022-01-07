/* Идеиы:
 * 1) создание вектора всех возможных комбинаций, последовательное сравнение
 * 2) реализация масочной проверки введенного слова
 * 3) библиотека для регулярных выражений
 *
 */

#include <QCoreApplication>
#include <string>
#include <regex>
#include <vector>
#include <iostream>

// правило 1:
// изменена одна буква на любую "[a-z]bc" + "a[a-z]c" + "ab[a-z]"
std::vector<std::string> rule1(std::string w) {
    std::vector<std::string> r;
    std::string buf;
    std::string d = "[a-z]";
    for (int i = 0 ; i < w.length(); i++) {
        buf = w;
        buf.erase(buf.begin() + i);
        buf.insert(i, d);
        r.push_back(buf);
    }
    return r;
}

// правило 2:
// убрана любая буква "bc" + "ac" + "ab"
std::vector<std::string> rule2(std::string w) {
    std::vector<std::string> r;
    std::string buf;
    for (int i = 0 ; i < w.length(); i++) {
        buf = w;
        buf.erase(buf.begin() + i);
        r.push_back(buf);
    }
    return r;
}

// правило 3:
// добавлена любая буква в любое место "[a-z]abc" + "a[a-z]bc" + "ab[a-z]c" + "abc[a-z]"
std::vector<std::string> rule3(std::string w) {
    std::vector<std::string> r;
    std::string buf;
    std::string d = "[a-z]";
    for (int i = 0 ; i < w.length(); i++) {
        buf = w;
        buf.insert(i, d);
        r.push_back(buf);
    }
    buf = w + d;
    r.push_back(buf);
    return r;
}


std::string strCompiler(std::string s, std::vector<std::string> sAdd) {
    for (int i = 0; i < sAdd.size(); i++) {
        s += " " + sAdd[i];
    }
    return s;
}

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

    // слово к перебору "abc"
    std::string word;

    visualiser(rule1("abc"));
    visualiser(rule2("abc"));
    visualiser(rule3("abc"));


    /*
    // правило 0:
    // само слово "abc"
    std::regex rule0(word);

    // правило 1:
    // изменена одна буква на любую "[a-z]bc" + "a[a-z]c" + "ab[a-z]"
    std::regex rule1(word);

    // правило 2:
    // убрана любая буква "bc" + "ac" + "ab"
    std::regex rule2(word);

    // правило 3:
    // добавлена любая буква в любое место "[a-z]abc" + "a[a-z]bc" + "ab[a-z]c" + "abc[a-z]"
    std::regex rule3(word);
    */




    return a.exec();
}
