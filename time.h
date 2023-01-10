//
// Created by 骆明宇 on 2022/12/2.
//

#ifndef INC_221202C___TIME_H
#define INC_221202C___TIME_H

#include <ctime>
#include <cstring>
#include <string>
using namespace std;



string GetDate() {
    struct tm *newtime;
    char tmpbuf[128];
    string a;
    time_t lt1;

    time( &lt1 );
    newtime=localtime(&lt1);

    strftime( tmpbuf, 128, "%F@%T", newtime);
    a = tmpbuf;
    return a;
}

string GetYear() {
    struct tm *newtime;
    char tmpbuf[128];
    string a;
    time_t lt1;

    time( &lt1 );
    newtime=localtime(&lt1);

    strftime( tmpbuf, 128, "%Y", newtime);
    a = tmpbuf;
    return a;
}

string LogDate() {
    struct tm *newtime;
    char tmpbuf[128];
    string a;
    time_t lt1;

    time( &lt1 );
    newtime=localtime(&lt1);

    strftime( tmpbuf, 128, "[%F@%T]", newtime);
    a = tmpbuf;
    return a;
}


#endif //INC_221202C___TIME_H
