#ifndef XMLADDRESS
#define XMLADDRESS

#include <string>

struct xmlAddr {
    std::string textID,paraID,sentID,tokenID;
    std::string word;
    /*
    xmlAddr(std::string textID = "no ID",
            std::string paraTD = "no ID",
            std::string sentID = "no ID",
            std::string tokenID = "no ID") {
        this->textID = textID;
        this->paraTD = paraTD;
        this->sentID = sentID;
        this->tokenID = tokenID;
    }
    */
};

#endif // XMLADDRESS

