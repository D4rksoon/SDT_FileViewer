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
    void  wholeVector();

private:
    std::vector<File*> vecFiles;
};

#endif // FILEMANAGER_H
