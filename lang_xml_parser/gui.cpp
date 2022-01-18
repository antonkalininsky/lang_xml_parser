#include "gui.h"
#include "xml_parser.h"
#include <windows.h>
#include <QFileDialog>
#include "regExCreator.h"

GUI::GUI() {
    // buttons
    buttonFile = new QPushButton("Choose file");
    buttonSearch = new QPushButton("Search");
    QObject::connect(buttonSearch, SIGNAL(clicked()), this, SLOT(doSearch()));
    QObject::connect(buttonFile, SIGNAL(clicked()), this, SLOT(chooseFile()));

    // in out
    labelFind = new QLabel("Find what:");
    lineEditFind = new QLineEdit();
    labelRslt = new QLabel("Search results:");
    textRslt = new QTextEdit();
    textRslt->setReadOnly(true);
    textRslt->setOverwriteMode(false);

    // buttons layout
    layoutButtons = new QVBoxLayout();
    layoutButtons->addWidget(buttonFile);
    layoutButtons->addWidget(buttonSearch);
    layoutButtons->addStretch();

    // input and output layout
    layoutIn = new QVBoxLayout();
    layoutIn->addWidget(labelFind);
    layoutIn->addWidget(lineEditFind);
    layoutIn->addStretch();

    // input and output layout
    layoutOut = new QVBoxLayout();
    layoutOut->addWidget(labelRslt);
    layoutOut->addWidget(textRslt);
    layoutOut->addStretch();

    // layout group
    layoutGr = new QHBoxLayout();
    layoutGr->addLayout(layoutIn);
    layoutGr->addLayout(layoutButtons);

    // main layout
    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    mainLayout->addLayout(layoutGr);
    mainLayout->addLayout(layoutOut);
    setLayout(mainLayout);
}

QString GUI::createString(std::vector<xmlAddr> r) {
    QString str;
    int cou = 1;
    for (auto i : r) {
        str += "# " + QString::number(cou++) +
                "   " + "textID: " + i.textID +
                "   " + "parID: " + i.paraID +
                "   " + "sentID: " + i.sentID +
                "   " + "tokenID: " + i.tokenID +
                "   " + "word: " + i.word +
                "\n";
    }
    return str;
}

std::vector<xmlAddr> GUI::theSearch(QString in) {
    QRegExp rx(regExCreator()(in));
    std::vector<xmlAddr> r;
    for (auto it: parsingRslt) {
        if (rx.exactMatch(it.word.toLower())) {
            r.push_back(it);
        }
    }
    return r;
}

void GUI::doSearch() {
    if (fileName.isEmpty()) {
        textRslt->insertPlainText("Please choose file first!");
        return;
    }
    textRslt->clear();
    QString userInput = lineEditFind->text();
    if (userInput.isEmpty()) {
        textRslt->insertPlainText("Please enter word for search!");
        return;
    }
    if (userInput.contains(" ", Qt::CaseInsensitive)) {
        textRslt->insertPlainText("Please enter ONE word for search!");
        return;
    }
    //QString searchRslt = xml_parser()(userInput);
    QString searchRslt = createString(theSearch(userInput));
    textRslt->clear();
    if (searchRslt.isEmpty()) {
        textRslt->insertPlainText("No results!");
    } else {
        textRslt->insertPlainText(searchRslt);
    }
}

void GUI::chooseFile() {
    textRslt->clear();
    fileName = QFileDialog::getOpenFileName(this,
                                            tr("Choose xml file"),
                                            "",
                                            tr("Xml file (*.xml)"));
    int r = xml_parser()(parsingRslt, fileName);
    if (r == -1) {
        textRslt->insertPlainText("Choosen file doesn't exist!");
        return;
    }
    if (r == -2) {
        textRslt->insertPlainText("Choosen file wasn't opened!");
        return;
    }
    textRslt->insertPlainText("File scanned! Do your search!");
}

