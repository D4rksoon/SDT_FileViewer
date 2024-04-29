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

class FileManager : public QObject  // Сделать с помощью паттерна SingleTon (один экземпляр)
{
    Q_OBJECT
public: // private (конструктор деструктор), отсутсвие констр. копирования. static - живет на протяжении работы программы
    static FileManager &Instance();

    File* addFile(QString &name);
    bool removeFile(QString &name);
    std::vector<File*> vecFiles();
    std::vector<QDateTime> vecDates();
    void fillVectorDates();
    void checkChanges();

signals:
    void changed();
    void changed2(QString fileName, int size, bool existence);

private:
    FileManager();
    ~FileManager();
    FileManager(FileManager const&);
    FileManager& operator= (FileManager const&);

    std::vector<File*> m_vecFiles;
    std::vector<QDateTime> m_dates;
};

#endif // FILEMANAGER_H
