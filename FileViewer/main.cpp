#include <QCoreApplication>
#include "filemanager.h"
#include "logging.h"
#include <thread>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileManager& instance = FileManager::Instance();
    Logging log;

    //QObject::connect(instance, &FileManager::changed, log, &Logging::test);
    //QObject::connect(instance, &FileManager::changed, log, &Logging::test);

    QStringList files = { "C:/QTproject/Files/f1.txt",
                          "C:\\QTproject\\Files\\f2.txt",
                          "C:\\QTproject\\allProject\\main.cpp",
                          "C:\\QTproject\\FileM\\main.cpp",
                          "D:\\PotPlayer\\d3dx9_43.dll",
                          "C:\\dsadsadas\\asdsa"                        //Не существует
    };

    for(auto file : files){
        instance.addFile(file);
    }

    while(1){
        system("cls");
        log.logConsole();
        std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
        //instance.checkChanges();
    }







    return a.exec();
}
