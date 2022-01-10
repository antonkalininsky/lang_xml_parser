#include "gui.h"
#include "xml_parser.h"

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
    layoutInOut = new QVBoxLayout();
    layoutInOut->addWidget(labelFind);
    layoutInOut->addWidget(lineEditFind);
    layoutInOut->addWidget(labelRslt);
    layoutInOut->addWidget(textRslt);
    layoutInOut->addStretch();

    // main layout
    mainLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLayout->addLayout(layoutInOut);
    mainLayout->addLayout(layoutButtons);
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
    textRslt->insertPlainText(searchRslt);
}

