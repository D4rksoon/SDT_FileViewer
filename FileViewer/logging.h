#ifndef LOGGING_H
#define LOGGING_H

#include "filemanager.h"

class Logging : public QObject
{
    Q_OBJECT
public:
    Logging();
    void logConsole();
    void logConsole2(QString fileName, int size, bool existence);

public slots:
    void logC();
    void logC2(QString fileName, int size, bool existence);
};

#endif // LOGGING_H
