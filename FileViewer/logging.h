#ifndef LOGGING_H
#define LOGGING_H
#include "filemanager.h"

class Logging
{
public:
    Logging();
    void logConsole();
    void checkttt();
signals:
    void ttt();
public slots:
    void logC();
    void test();
};

#endif // LOGGING_H
