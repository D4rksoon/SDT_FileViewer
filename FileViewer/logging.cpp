#include "logging.h"
#include <QDebug>

Logging::Logging()
{}

void Logging::logConsole(FileManager list)
{
    int size = list.vecFiles().size();
    qDebug() << "vector size: " << size;
    qDebug() << "Name          " << "Path          " << "Size         " << "           Existence";
    for(auto file : list.vecFiles()){
        QFileInfo fileInfo(file->fileName());
        QString fileName = fileInfo.fileName();
        QString filePath = fileInfo.filePath();

        if(file->open(QIODevice::ReadOnly)){
            qDebug() << fileName << "  " << filePath << "  " << file->size() << " bytes" << "    file existence";
            file->close();
        }
        else{
            qDebug() << fileName << "  " << filePath << "  " << file->size() << " bytes" << "    File does not exist";
            //qDebug() << "File: " << fileName << " does not exist";
        }
    }
}
