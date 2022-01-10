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
//???
#include <QToolButton>

class GUI : public QWidget {
    Q_OBJECT
public:
    GUI(QApplication *app);
private:
    QPushButton *buttonSearch;
    QPushButton *buttonQuit;
    QLabel *labelFind;
    QLineEdit *lineEditFind;
    QLabel *labelRslt;
    QTextEdit *textRslt;
    QVBoxLayout *layoutButtons;
    QVBoxLayout *layoutIn;
    QVBoxLayout *layoutOut;
    QBoxLayout *mainLayout;
    QHBoxLayout *layoutGr;

private slots:
    void doSearch();


};

#endif // GUI_H
