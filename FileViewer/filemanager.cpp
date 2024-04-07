#include "filemanager.h"

#include <QDebug>
#include <QDateTime>
FileManager::FileManager(){}

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

bool FileManager::removeFile(QString &name)
{
    QString cname = QFile(name).fileName();
    if(!m_vecFiles.empty()){
        for(auto file : m_vecFiles){
            if(cname == file->fileName()){
                emit del(cname);
                m_vecFiles.erase(std::remove(m_vecFiles.begin(), m_vecFiles.end(), file), m_vecFiles.end());
                return true;
            }
        }
    }
    return false;
}

std::vector<File *> FileManager::vecFiles()
{
    return m_vecFiles;
}

std::vector<QDateTime> FileManager::vecDates()
{
    return m_dates;
}

void FileManager::fillVectorDates()
{
    int size = m_vecFiles.size();
    m_dates.resize(size);
    for(int i = 0; i < size; i++){
        QFileInfo fileInfo(m_vecFiles[i]->fileName());
        m_dates.at(i) = fileInfo.lastModified();
    }
}

void FileManager::checkChanges()
{
    FileManager& instance = FileManager::Instance();
    for(int i = 0; i < m_vecFiles.size(); i++){
        QFileInfo fileInfo(m_vecFiles[i]->fileName());
        QDateTime temp = fileInfo.lastModified();
        if(temp != m_dates[i]){
            m_dates.at(i) = temp;
            emit changed();
            //qDebug() << "Changed!!!";
            break;
        }
    }
}



