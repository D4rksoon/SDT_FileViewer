#include "filemanager.h"
#include <QDebug>

FileManager::FileManager(int size) :
    m_vecFiles(size, nullptr) {}

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



