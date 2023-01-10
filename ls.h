//
// Created by 骆明宇 on 2022/12/2.
//

#ifndef INC_221202C___LS_H
#define INC_221202C___LS_H

#include <stdlib.h>
#include <time.h>//处理日期时间的头文件
#include <iostream>
#include <string>
#include <iomanip>
#define row 8
#define col 8
using namespace std;

//定义一个学生类
class student {
public:
    student()
    {
        UserID="";
        UserName="";

    };
    void setmessage(string &id, string &name)//存储信息
    {
        UserID = id;
        UserName = name;
    }
    string UserName;//姓名
    string UserID;//学号
//    static void InitSeat(int seat[][col], student *cstu);

};

class SeatSystem{
public:
    SeatSystem() {
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                seat[i][j] = 0;
        cout << "座位系统共初始化64个座位，初始化完毕。" << endl;
    };
    static void arrange_seat(int seat[][col], student *cstu, string &id, string &name);
    static void cancel_seat(int seat[][col], student *cstu, string &id, string &name);
    static void find_student(int seat[][col], student *cstu);
    static void find_seat(int seat[][col], student *cstu);
    static void display_seats(int seat[][col], student *cstu);
private:
    int seat[row][col];
};

//void arrange_seat(int seat[][col], student *cstu);  //设定教室座位
//void cancel_seat(int seat[][col]);  //取消教室座位
//void find_student(int seat[][col]); //显示某座位学生信息
//void find_seat(int seat[][col]);    // 查询学生座位
//void display_seats(int seat[][col]);//显示学生座次表



//选择1，为新来的学生安排座位，方法：用户输入学号和姓名，系统随机产生
//-------该考生座位的行号和列号，要求做到一个考生只有一个座位，而且在已有考生的位置不参与安排

void SeatSystem::arrange_seat(int seat[][col], student *cstu, string &id, string &name)
{
    time_t t;
    int newseat,r=0,c=0;
    srand((unsigned int)time(&t));//随机产生数的函数。
    for (r = 0; r < row; r++) {
        for (c = 0; c < col; c++) {
            if (seat[r][c] == 0) {
                break; //有空位子
            }
            if (r == row && c == col) {
                cout << "本教室学生已满!" << endl;
                return;
            }
        }
    }
    do
    {
        newseat = rand()%64; //产生座位号 //返回0-64范围内的数
        r = newseat/8; //行
        c = newseat - r*8; //列
    }while( seat[r][c] != 0); //座位已经有人重先产生座位号
//---------------------------------//
    seat[r][c]=newseat;
    cstu[newseat].setmessage(id, name); //把信息存储到学生类中
    for (int i=0; i<64; i++)
    {
        if ( i != newseat) //相同准考证号不能重复申请位子
        {
            if ( cstu[newseat].UserID == cstu[i].UserID )
            {
                cout<<"对不起!该学号已申请过座位,请您核对后再输入：";
                cstu[newseat].setmessage(id, name); //
                i--;
            }
        }
    }
    cout<<"操作成功!"<<endl;
}
/********************************************/
//选择2，取消某人教室座位（假设取消后的座位别人能坐）
void SeatSystem::cancel_seat(int seat[][col], student *cstu, string &id, string &name)
{
    int i,r,c;
    for (i=0; i<64; i++)
    {
        if (cstu[i].UserName == name)
        {
            r = i/8; //行
            c = i - r*8 ;//列
            seat[r][c]=0; //赋值为0代表此座位无人
            cstu[i].UserID = "";//清空存储信息
            cstu[i].UserName = "";
            cout<<"操作成功!"<<endl;
            return ;
        }
    }
    cout<<"该教室没有此人!"<<endl;
    cout<<endl;
}

//选择3，要求输入座位的行号和列号，然后显示该座位学生的信息；
void SeatSystem::find_student(int seat[][col], student *cstu)
{
    int r,c;
    cout<<"请输入行号row和列号col：";
    cin>>r>>c;
    r = r-1;
    c = c-1;
    if ( cstu[r*8+c].UserID =="" || cstu[r*8+c].UserName == "")
    {
        cout<<"该座位目前为空."<<endl;
    }
    else
    {
        cout<<"学号:"<<cstu[r*8+c].UserID<<", 姓名:"<<cstu[r*8+c].UserName<<endl;
    }
    cout<<endl;
}

//选择4，要求输入某考生学号，然后显示该学生的座位；
void SeatSystem::find_seat(int seat[][col], student *cstu)
{
    int r,c;
    string textnum;
    cout<<"请输入学号：";
    cin>>textnum;
    for ( r=0; r<row; r++)
    {
        for (c=0; c<col; c++)
        {
            if (textnum == cstu[r*8+c].UserID)
            {
                cout<<"查询结果： "<<"row:"<<r+1<<","<<"col:"<<c+1<<endl;
                return ;
            }
        }
    }
    cout<<"学号错误!"<<endl;
    cout<<endl;
}

//选择5，显示教室座次表，要求再每个座位对应的行列上显示该考生的学号。
void SeatSystem::display_seats(int seat[][col], student *cstu)
{
    int r,c;
    cout<<"本教室座位占用情况如下(*代表无人，数字代表学号/工号)："<<endl;
    for ( r=0; r<row; r++)
    {
        for (c=0; c<col; c++)
        {
            if (seat[r][c] != 0) //不为0则有人
            {
                //输出的行左对齐，列宽10
                cout.setf(ios::left);
                cout<<setw(10)<<(cstu[r*8+c].UserID);//有人输出学号
            }else
            {
                cout.setf(ios::left);
                cout<<setw(10)<<"********";//无人输出*******
            }
        }
        cout << endl;
    }
    cout<<endl<<endl;
}




#endif //INC_221202C___LS_H
