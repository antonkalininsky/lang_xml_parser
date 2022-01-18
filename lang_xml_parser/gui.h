#ifndef GUI_H
#define GUI_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <vector>
#include "xmladdress.h"

class GUI : public QWidget {
    Q_OBJECT
public:
    GUI();
private:
    QPushButton *buttonFile;
    QPushButton *buttonSearch;
    QLabel *labelFind;
    QLineEdit *lineEditFind;
    QLabel *labelRslt;
    QTextEdit *textRslt;
    QVBoxLayout *layoutButtons;
    QVBoxLayout *layoutIn;
    QVBoxLayout *layoutOut;
    QBoxLayout *mainLayout;
    QHBoxLayout *layoutGr;
    QString fileName;

    std::vector<xmlAddr> parsingRslt;

    QString createString(std::vector<xmlAddr> r);
    std::vector<xmlAddr> theSearch(QString in);



private slots:
    void doSearch();
    void chooseFile();


};

#endif // GUI_H
