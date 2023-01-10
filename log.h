//
// Created by 骆明宇 on 2022/12/3.
//

#ifndef INC_221202C___LOG_H
#define INC_221202C___LOG_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "time.h"
using namespace std;

void log(string &a, string &b, string &c){
    ofstream fout;
    fout.open("log.dat", ios::app);
    fout << LogDate() << " " << a << " " << b << " " << c << endl;
    fout.close();
}


#endif //INC_221202C___LOG_H
