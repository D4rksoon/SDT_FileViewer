#include <QCoreApplication>

#include "filemanager.h"
#include "logging.h"
#include <thread>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileManager& instance = FileManager::Instance();
    Logging log;

    QObject::connect(&instance, FileManager::changed, &log, Logging::logC);
    //QObject::connect(&instance, FileManager::changed2, &log, Logging::logC2);

    QStringList files = { "../Files/f1.txt",
        "../Files/f2.txt",
        "../FileViewer/main.cpp",
        "../UML.png",
        "C:/dsadsadas/asdsa"                                          //Не существует
    };

    for(auto file : files){
        instance.addFile(file);
    }
    instance.fillVectorDates();
    log.logConsole();

    while(1){
        instance.checkChanges();
        std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
    }



    return a.exec();
}
