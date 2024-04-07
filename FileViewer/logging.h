#ifndef LOGGING_H
#define LOGGING_H

#include "filemanager.h"

class Logging : public QObject
{
    Q_OBJECT
public:
    Logging();
    void logConsole();

public slots:
    void logC();
};

#endif // LOGGING_H
