#include <QCoreApplication>
#include "filemanager.h"
#include "logging.h"
#include <thread>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileManager list;
    Logging log;
    QStringList files = { "C:/QTproject/Files/f1.txt",
                          "C:\\QTproject\\Files\\f2.txt",
                          "C:\\QTproject\\allProject\\main.cpp",
                          "C:\\QTproject\\allProject\\allProject.pro.user",
                          "D:\\PotPlayer\\d3dx9_43.dll",
                          "C:\\dsadsadas\\asdsa"                        //Не существует
    };


    for(auto file : files){
        list.addFile(file);
    }

    while(1){
        system("cls");
        //list.wholeVector();
        log.logConsole(list);
        std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
    }







    return a.exec();
}
