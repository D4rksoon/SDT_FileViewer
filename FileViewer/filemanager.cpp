#include "filemanager.h"
#include <QDebug>

FileManager::FileManager(int size) :
    vecFiles(size, nullptr) {}

File* FileManager::addFile(QString &name)
{
    File* newFile = new File(name);
    vecFiles.push_back(newFile);
}

void FileManager::wholeVector()
{
    int size = vecFiles.size();
    qDebug() << "vector size: " << size;
    qDebug() << "Name          " << "Path          " << "Size         " << "           Existence";
    for(auto file : vecFiles){
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
