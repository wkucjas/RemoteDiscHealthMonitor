
#ifndef SMARTCTLOUTPUTPARSER_H
#define SMARTCTLOUTPUTPARSER_H

#include <QByteArray>
#include <map>

namespace SmartCtlOutputParser
{
    std::map<std::string, std::string> parse(const QByteArray &);
};

#endif
