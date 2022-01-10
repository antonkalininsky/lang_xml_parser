#ifndef XML_PARSER_H
#define XML_PARSER_H

#include <string>
#include <vector>
#include <xmladdress.h>

class xml_parser
{
public:
    xml_parser();
    QString operator()(QString word);
private:
    QString createString(std::vector<xmlAddr> r);
};

#endif // XML_PARSER_H
