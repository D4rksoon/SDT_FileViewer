#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QFile>
#include <QFileInfo>
#include <QString>
#include <vector>
#include "logging.h"

class File : public QFile
{
public:
    File(const QString &name) : QFile(name){}
    ~File() = default;
};
// UML диграмма. Класс зависит от других классов
class FileManager  // Сделать с помощью паттерна SingleTon (один экземпляр)
{
public: // private (конструктор деструктор), отсутсвие констр. копирования. static - живет на протяжении работы программы
    static FileManager &Instance();
    File* addFile(QString &name);
    std::vector<File*> vecFiles();
    bool checkChanges();

signals:
    void changed();

private:
    FileManager();
    ~FileManager();
    FileManager(FileManager const&);
    FileManager& operator= (FileManager const&);

    std::vector<File*> m_vecFiles;
    // Сделать вектор дат изменения??
};

#endif // FILEMANAGER_H
