#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QFile>
#include <QFileInfo>
#include <QString>
#include <vector>

class File : public QFile
{
public:
    File(const QString &name) : QFile(name){}
    ~File() = default;
};

class FileManager
{
public:
    FileManager(int size = 0);
    File* addFile(QString &name);
    std::vector<File*> vecFiles();

private:
    std::vector<File*> m_vecFiles;
};

#endif // FILEMANAGER_H
