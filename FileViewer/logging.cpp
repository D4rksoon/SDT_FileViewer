#include "logging.h"
#include <QDebug>

Logging::Logging()
{}

void Logging::logConsole()
{
    system("cls");
    FileManager& instance = FileManager::Instance();
    //int size = instance.vecFiles().size();
    //qDebug() << "vector size: " << size;
    qDebug() << " Name  " << "    Size      " << "     Existence";
    for(auto file : instance.vecFiles()){
        QFileInfo fileInfo(file->fileName());
        QString fileName = fileInfo.fileName();
        bool existence = fileInfo.exists();

        if(existence){
            qDebug() << fileName << "  " << file->size() << " bytes" << "      file exist";
        }
        else{
            qDebug() << fileName << "  " << file->size() << " bytes" << "      file not exist";
        }
    }
}

void Logging::logConsole2(QString fileName, int size, bool existence)
{
    //system("cls");

    qDebug() << "File is changed";
    if(existence){
        qDebug() << fileName << "  " << size << " bytes" << "     file exist";
    }
    else{
        qDebug() << fileName << "  " << size << " bytes" << "     file not exist";
    }
}

void Logging::logC()
{
    logConsole();
}

void Logging::logC2(QString fileName, int size, bool existence)
{
    logConsole2(fileName, size, existence);
}
