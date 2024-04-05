#include <QCoreApplication>
#include "filemanager.h"
#include <thread>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileManager list;
    QStringList files = { "C:/QTproject/Files/f1.txt",
                          "C:\\QTproject\\Files\\f2.txt",
                          "C:\\QTproject\\allProject\\main.cpp",
                          "C:\\QTproject\\allProject\\allProject.pro.user",
                          "D:\\PotPlayer\\d3dx9_43.dl"
    };


    for(auto file : files){
        list.addFile(file);
    }

    while(1){
        system("cls");
        list.wholeVector();
        std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
    }







    return a.exec();
}
