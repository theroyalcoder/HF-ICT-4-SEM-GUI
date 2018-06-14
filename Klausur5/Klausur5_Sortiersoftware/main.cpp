#include "widget.h"
#include <QApplication>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

std::string function1(std::string str){

    std::vector<char> zres;
    std::string result;
    for(auto i : str){
    zres.push_back(i);
    std::sort (str.begin(), str.end());
    }
    for (auto x : zres){
        result += x;
    }
    std::cout << "hallo";
    //qDebug() << result;
    return result;
}

int function2(int val){
    if(val < 2){
        function2(val-1);
    }
    return val;
}


int main(int argc, char *argv[])
{
    // Bereich 1 aufgabe
    std::string hallo = "hello";
    std::string result = function1(hallo);

    // Bereich 2 aufgabe

    //function2(200);
    //return 0; //achtung ***********************************************************
    // Bereich 3 aufgabe

    QApplication a(argc, argv);
    Widget w;
    w.setMinimumSize(500,500);
    w.show();

    return a.exec();

}

