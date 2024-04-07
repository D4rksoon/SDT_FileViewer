#include "logging.h"
#include <QDebug>

Logging::Logging()
{}

void Logging::logConsole()
{
    system("cls");
    FileManager& instance = FileManager::Instance();
    int size = instance.vecFiles().size();
    qDebug() << "vector size: " << size;
    qDebug() << " Name       " << "Path                " << "         Size      " << "     Existence";
    for(auto file : instance.vecFiles()){
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

void Logging::logC()
{
    system("cls");
    FileManager& instance = FileManager::Instance();
    qDebug() << " Name       " << "Path                " << "         Size      " << "     Existence";
    for(auto file : instance.vecFiles()){
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

