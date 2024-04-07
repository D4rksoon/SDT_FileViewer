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
    instance.fillVectorDates();
    log.logConsole();

    while(1){
        instance.checkChanges();
        std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );
    }



    return a.exec();
}