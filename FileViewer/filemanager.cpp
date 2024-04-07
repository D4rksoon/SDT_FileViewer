#include "filemanager.h"
#include <QDebug>

FileManager::FileManager() :
    m_vecFiles(0, nullptr) {}

FileManager::~FileManager(){}

FileManager &FileManager::Instance()
{
    static FileManager s;
    return s;
}

File* FileManager::addFile(QString &name)
{
    File* newFile = new File(name);
    m_vecFiles.push_back(newFile);
    return newFile;
}

std::vector<File *> FileManager::vecFiles()
{
    return m_vecFiles;
}

bool FileManager::checkChanges()
{
//    for(auto file : vecFiles()){
//        QFileInfo fileInfo(file);
//        auto a = fileInfo.lastModified();
//    }
//    for()

//    int size = vecFiles().size();
//    if(size > 1){
//        emit changed();
//        return true;
//    }

    return false;
}



