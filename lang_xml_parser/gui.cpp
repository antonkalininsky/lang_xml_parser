#include "gui.h"
#include "xml_parser.h"
#include <windows.h>

GUI::GUI(QApplication *app) {
    // buttons
    buttonSearch = new QPushButton("Search");
    buttonQuit = new QPushButton("Quit");
    QObject::connect(buttonQuit, SIGNAL(clicked()), app, SLOT(quit()));
    QObject::connect(buttonSearch, SIGNAL(clicked()), this, SLOT(doSearch()));

    // in out
    labelFind = new QLabel("Find what:");
    lineEditFind = new QLineEdit();
    labelRslt = new QLabel("Search results:");
    textRslt = new QTextEdit();
    textRslt->setReadOnly(true);
    textRslt->setOverwriteMode(false);

    // buttons layout
    layoutButtons = new QVBoxLayout();
    layoutButtons->addWidget(buttonSearch);
    layoutButtons->addWidget(buttonQuit);
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

void GUI::doSearch() {
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
    textRslt->insertPlainText("Search in process! Please wait...");
    QString searchRslt = xml_parser()(userInput);
    textRslt->clear();
    if (searchRslt.isEmpty()) {
        textRslt->insertPlainText("No results!");
    } else {
        textRslt->insertPlainText(searchRslt);
    }
}

