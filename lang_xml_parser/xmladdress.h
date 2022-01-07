#ifndef XMLADDRESS
#define XMLADDRESS

#include <string>

struct xmlAddr {
    int textID,paraTD,sentID,tokenID;
    std::string word;
    xmlAddr(int textID = -1,
            int paraTD = -1,
            int sentID = -1,
            int tokenID = -1) {
        this->textID = textID;
        this->paraTD = paraTD;
        this->sentID = sentID;
        this->tokenID = tokenID;
    }
};

#endif // XMLADDRESS

