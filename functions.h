//
// Created by luo on 2022/11/4.
//

#ifndef TOTAL_FUNCTIONS_H
#define TOTAL_FUNCTIONS_H

#include <fstream>
#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
#include "mzh.h"
#include "picosha2.h"

using namespace std;

class Function {
public:
    static bool InString(string &a, string &b);
    static bool FuzzySearch(string a, string b);
    static int GetWidth(int num, string a);
};

void initUsers();
bool login();
bool InString(string &a, string &b);
void log(string &a, string &b, string &c);


void initUsers(){
    ifstream fin;
    fin.open("userInfo.dat");

    fin.close();
}

bool Function::InString(string &a, string &b){
    for(int i = 0;i<a.length();i++){
        for(int j = 0;j<b.length();j++){
            if (a[i]==b[j] && a[i+1] == b[j+1] && a[i+2] == b[j+2] && a[i+3] == b[j+3] && a[i+4] == b[j+4])
                return true;
        }
    }
    return false;
}

bool Function::FuzzySearch(string a, string b) {
    string::size_type idx;
    idx = a.find(b);
    if (idx == string::npos) return false;
    else return true;
}

int Function::GetWidth(int num, string a) {
    if ((a[0] >= 65 && a[0] <= 90) || (a[0] >= 97 && a[0] <= 122) || (a[0] >= 48 && a[0] <= 57)) return num;
    else return int(num + (0.48 * a.length()));
}




//long long GetDay(){
//    SYSTEMTIME st;//定义本地时间变量，该变量为结构体
//    GetLocalTime(&st);
//    long long day, time;
//    day = st.wYear * 10000 + st.wMonth * 100 + st.wDay;
//    return day;
//}

//long long GetTime(){
//    SYSTEMTIME st;//定义本地时间变量，该变量为结构体
//    GetLocalTime(&st);
//    long long time;
//    time = st.wHour * 10000 + st.wMinute * 100 + st.wSecond;
//    return time;
//}

//string LogDay(){
//    SYSTEMTIME st;//定义本地时间变量，该变量为结构体
//    GetLocalTime(&st);
//    long long day, time;
//    string year_s = itos(st.wYear);
//    string month_s = itos(st.wMonth);
//    string day_s = itos(st.wDay);
//    string hour_s = itos(st.wHour);
//    string minute_s = itos(st.wMinute);
//    string second_s = itos(st.wSecond);
//    string milliseconds_s = itos(st.wMilliseconds);
////    char day_c = char(day);
////    char time_c = char(time);
////    string day_s(8,day_c);
////    string time_s(8,time_c);
//    string AllTime = year_s + "-" + month_s + "-" + day_s + " " + hour_s + ":" + minute_s + ":" + second_s + ":" + milliseconds_s;
//    return AllTime;
//}


#endif //TOTAL_FUNCTIONS_H
