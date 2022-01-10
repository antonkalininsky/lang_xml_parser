#ifndef XML_PARSER_H
#define XML_PARSER_H

#include <string>
#include <vector>
#include <xmladdress.h>

class xml_parser
{
public:
    xml_parser();
    std::vector<xmlAddr> operator()(QString word);
};

#endif // XML_PARSER_H
