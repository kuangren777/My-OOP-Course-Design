////
//// Created by 骆明宇 on 2022/12/2.
////
//
//#ifndef INC_221202C___GM_H
//#define INC_221202C___GM_H
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <cstring>
//#include "picosha2.h"
//#include <iomanip>
//#include "functions.h"
//
//#define WIDTH 15
//#define WIDTHCN 25
//#define DUANG 13
//#define MAX_FILE 10000
//
//#define size sizeof(struct node)
//using namespace std;
//
//typedef struct node{
//    string UserID;
//    string UserName;
//    string Password;
//    int UserBorrowBook;
//    bool HaveSeat;
//    string StuRoomID;
//    string StuSeatID;
//    bool IsAdmin;
//    struct node *next;
//}node;
//
////void menu()
////{
////    cout<<"******************欢迎使用本通讯录*******************"<<endl;
////    cout<<"%                  1.添加账户                    %"<<endl;
////    cout<<"%                  2.删除账户                    %"<<endl;
////    cout<<"%                  3.修改密码                    %"<<endl;
////    cout<<"%                  4.查询账户                    %"<<endl;
////    cout<<"%                  5.展示所有账户                    %"<<endl;
////    cout<<"%                  6.删除所有人（不要使用）                    %"<<endl;
////    cout<<"%                  7.退出系统（请直接按Ctrl+C）     %"<<endl;
////    cout<<"******************欢迎使用本通讯录*******************"<<endl;
////}
//
//struct node *create(struct node *head)
//{
//    struct node *p1;
//    head = NULL;
//    p1=(struct node*) malloc(size);
//    p1->UserID = "1";
//    p1->UserName = "test";
//    p1->Password = "6b86b273ff34fce19d6b804eff5a3f5747ada4eaa22f1d49c01e52ddb7875b4b";
//    p1->UserBorrowBook = 0;
//    p1->HaveSeat = false;
//    p1->StuRoomID = "NULL";
//    p1->StuSeatID = "NULL";
//    p1->IsAdmin = true;
////    cout << "**********管理员账户已初始化**********" << endl << endl;
//    head = p1;
////    while(p1->UserID!=0)
////    {
////        n=n+1;
////        if(n==1)
////            head = p1;
////        else
////            p2->next = p1;
////        p2=p1;
////        p1=(struct node*)malloc(size);
////        cout<<"请输入学号：";cin>>p1->UserID;//输入
////        cout<<"请输入名字：";cin>>p1->UserName;//输入
////        cout<<"请输入性别：";cin>>p1->Password;//输入
////        cout<<"请输入电话：";cin>>p1->StuSeatID;//输入
////        cout<<"请输入微信号：";cin>>p1->StuRoomID;//输入
////        cout<<"******************新的人已添加**********************"<<endl;
////    }
//    p1->next = NULL;
//    return head;
//}
//
//struct node *add(struct node *head)
//{
//    cout<<"添加账户"<<endl;
//    struct node *p1,*p3;
//    string password;
//    p3=(struct node*) malloc(size);//为p3申请一块空间
//    cout<<"请输入学号：";cin>>p3->UserID;//输入
//    cout<<"请输入用户名：";cin>>p3->UserName;//输入
//    cout<<"请输入密码（请放心输入，本系统采用SHA-256加密，保证您的用户安全）：";cin>>password;//输入
//    password = picosha2::hash256_hex_string(password);
//    p3->Password = password;
//    p3->UserBorrowBook = 0;
//    p3->HaveSeat = false;
//    p3->StuRoomID = "NULL";
//    p3->StuSeatID = "NULL";
//    p3->IsAdmin = false;
//    ofstream fff;
//    fff.open("UserData.dat", ios::app);
//    fff << endl << p3->UserID << " " << p3->UserName << " " << p3->Password << " " << p3->UserBorrowBook
//    << " " << p3->HaveSeat << " " << p3->StuRoomID << " " << p3->StuSeatID << " " << p3->IsAdmin;
//    fff.close();
//    p1 = head;
//    while (p1->next != NULL) {
//        p1 = p1->next;
//    }
//    p1->next = p3;
//    p3->next = NULL;
//    cout<<"**********新的人已添加***********"<<endl;
//    cout<<"**********数据库已更新***********"<<endl;
//
//    return head;//返回链表头部
//}
//
//
//struct node *add_admin(struct node *head)
//{
//    cout<<"添加账户"<<endl;
//    struct node *p1,*p3;
//    string password;
//    p3=(struct node*) malloc(size);//为p3申请一块空间
//    cout<<"请输入学号：";cin>>p3->UserID;//输入
//    cout<<"请输入用户名：";cin>>p3->UserName;//输入
//    cout<<"请输入密码（请放心输入，本系统采用SHA-256加密，保证您的用户安全）：";cin>>password;//输入
//    password = picosha2::hash256_hex_string(password);
//    p3->Password = password;
//    p3->UserBorrowBook = 0;
//    p3->HaveSeat = false;
//    p3->StuRoomID = "NULL";
//    p3->StuSeatID = "NULL";
//    p3->IsAdmin = true;
//    ofstream fff;
//    fff.open("UserData.dat", ios::app);
//    fff << endl << p3->UserID << " " << p3->UserName << " " << p3->Password << " " << p3->UserBorrowBook
//        << " " << p3->HaveSeat << " " << p3->StuRoomID << " " << p3->StuSeatID << " " << p3->IsAdmin;
//    fff.close();
//    p1 = head;
//    while (p1->next != NULL) {
//        p1 = p1->next;
//    }
//    p1->next = p3;
//    p3->next = NULL;
//    cout<<"**********新的人已添加***********"<<endl;
//    cout<<"**********数据库已更新***********"<<endl;
//
//    return head;//返回链表头部
//}
//
//
//struct node *del(struct node *head)
//{
//    int o = 9;
//    cout << "1.通过名字删除" << endl;
//    cout << "2.通过学号/工号删除" << endl;
//    cin >> o;
//    if (o == 1) {
//        string UserName;
//        cout << "请输入想删除的人的名字" << endl;
//        cin >> UserName;
//        struct node *p1,*p2;
//        p1=head;
//        p2=p1;
//        while(p1->next != NULL && p1->UserName != UserName)//搜索
//        {
//            p2=p1;
//            p1=p1->next;
//        }
//        if(p1->UserName == UserName)//判断字符串是否相等
//        {
//            if(p1==head)
//            {
//                head=head->next;
//                cout<<"删除联系人成功"<<endl;
//            }
//            else
//            {
//                p2->next=p1->next;
//                cout<<"删除联系人成功"<<endl;
//            }
//            fstream fff;
//            fff.open("UserData.dat");
//            string fl[MAX_FILE];
//            int line = 0;
//            string temp_id, temp_name, temp_password, temp_ubb, temp_hs, temp_sri, temp_ssi, temp_ia, white_space = " ";
//            if (fff.is_open()) {
//                while (true) {
//                    fff >> temp_id >> temp_name >> temp_password >> temp_ubb >> temp_hs >> temp_sri >> temp_ssi >> temp_ia;
//                    if (temp_name != UserName) {
//                        fl[line] = temp_id + white_space;
//                        fl[line] += temp_name;
//                        fl[line] += white_space;
//                        fl[line] += temp_password;
//                        fl[line] += white_space;
//                        fl[line] += temp_ubb;
//                        fl[line] += white_space;
//                        fl[line] += temp_hs;
//                        fl[line] += white_space;
//                        fl[line] += temp_sri;
//                        fl[line] += white_space;
//                        fl[line] += temp_ssi;
//                        fl[line] += white_space;
//                        fl[line] += temp_ia;
//                        line++;
//                    }
//                    if (fff.eof()) {
//                        break;
//                    }
//                }
//            }
//
//            fstream ff;
//            ff.open("UserData.dat", ios::out | ios::trunc);
//            if (ff.is_open()) {
//                for (int i = 0; i < line; ++i)
//                {
//                    ff << fl[i];
//                    if (i != line - 1)
//                        ff << endl;
//                }
//            } else {
//                cout << "orz" << endl;
//            }
//            ff.close();
//            cout << "*****数据库更新成功*****" << endl;
//        }
//        else
//        {
//            cout<<"查无此人"<<endl;
//        }
//        free(p1);
//
//    } else {
//        string Userid;
//        cout << "请输入想删除的人的学号" << endl;
//        cin >> Userid;
//        struct node *p1,*p2;
//        p1=head;
//        p2=p1;
//        while(p1->next != NULL && p1->UserID != Userid)//搜索
//        {
//            p2=p1;
//            p1=p1->next;
//        }
//        if(p1->UserID == Userid)//判断字符串是否相等
//        {
//            if(p1==head)
//            {
//                head=head->next;
//                cout<<"删除联系人成功"<<endl;
//            }
//            else
//            {
//                p2->next=p1->next;
//                cout<<"删除联系人成功"<<endl;
//            }
//        }
//        else
//        {
//            cout<<"查无此人"<<endl;
//        }
//        free(p1);
//        fstream fff;
//        fff.open("UserData.dat");
//        string fl[MAX_FILE];
//        int line = 0;
//        string temp_id, temp_name, temp_password, temp_ubb, temp_hs, temp_sri, temp_ssi, temp_ia, white_space = " ";
//        if (fff.is_open()) {
//            while (true) {
//                fff >> temp_id >> temp_name >> temp_password >> temp_ubb >> temp_hs >> temp_sri >> temp_ssi >> temp_ia;
//                if (temp_id != Userid) {
//                    fl[line] = temp_id + white_space;
//                    fl[line] += temp_name;
//                    fl[line] += white_space;
//                    fl[line] += temp_password;
//                    fl[line] += white_space;
//                    fl[line] += temp_ubb;
//                    fl[line] += white_space;
//                    fl[line] += temp_hs;
//                    fl[line] += white_space;
//                    fl[line] += temp_sri;
//                    fl[line] += white_space;
//                    fl[line] += temp_ssi;
//                    fl[line] += white_space;
//                    fl[line] += temp_ia;
//                    line++;
//                }
//                if (fff.eof()) {
//                    break;
//                }
//            }
//        }
//
//        fstream ff;
//        ff.open("UserData.dat", ios::out | ios::trunc);
//        if (ff.is_open()) {
//            for (int i = 0; i < line; ++i)
//            {
//                ff << fl[i];
//                if (i != line - 1)
//                    ff << endl;
//            }
//        } else {
//            cout << "orz" << endl;
//        }
//        ff.close();
//        cout << "删除成功" << endl;
//    }
//    return head;
//}
//
//struct node *AdminFix(struct node *head)//修改通讯录中的某个人
//{
//    string UserName;
//    cout << "请输入修改的账户的学号/工号：" << endl;
//    cin >> UserName;
//    struct node *p;
//    p=head;
//    while (p->next != NULL && p->UserName == UserName)//查找
//    {
//        p=p->next;
//    }
//    if(p->UserName == UserName)
//    {
//        string password;
//        cout << "************开始修改************" << endl;
//        cout <<"请输入更改后的名字：";cin>>p->UserName;//输入
//        cout<<"请输入新的密码：";cin>>password;//输入
//        password = picosha2::hash256_hex_string(password);
//        p->Password = password;
//        cout<<"请输入新的房间号：";cin>>p->StuRoomID;//输入
//        cout<<"请输入新的座位号：";cin>>p->StuSeatID;//输入
//        cout<< "************修改成功************" <<endl;
//
//        fstream fff;
//        fff.open("UserData.dat");
//        string fl[MAX_FILE];
//        int line = 0;
//        string temp_id, temp_name, temp_password, temp_ubb, temp_hs, temp_sri, temp_ssi, temp_ia, white_space = " ";
//        if (fff.is_open()) {
//            while (true) {
//                fff >> temp_id >> temp_name >> temp_password >> temp_ubb >> temp_hs >> temp_sri >> temp_ssi >> temp_ia;
//                if (temp_name != UserName) {
//                    fl[line] = temp_id + white_space;
//                    fl[line] += temp_name;
//                    fl[line] += white_space;
//                    fl[line] += temp_password;
//                    fl[line] += white_space;
//                    fl[line] += temp_ubb;
//                    fl[line] += white_space;
//                    fl[line] += temp_hs;
//                    fl[line] += white_space;
//                    fl[line] += temp_sri;
//                    fl[line] += white_space;
//                    fl[line] += temp_ssi;
//                    fl[line] += white_space;
//                    fl[line] += temp_ia;
//                    line++;
//                } else {
//                    fl[line] = temp_id + white_space;
//                    fl[line] += p->UserName;
//                    fl[line] += white_space;
//                    fl[line] += p->Password;
//                    fl[line] += white_space;
//                    fl[line] += temp_ubb;
//                    fl[line] += white_space;
//                    fl[line] += temp_hs;
//                    fl[line] += white_space;
//                    fl[line] += p->StuRoomID;
//                    fl[line] += white_space;
//                    fl[line] += p->StuSeatID;
//                    fl[line] += white_space;
//                    fl[line] += temp_ia;
//                    line++;
//                }
//                if (fff.eof()) {
//                    break;
//                }
//            }
//        }
//        fff.close();
//        fstream ff;
//        ff.open("UserData.dat", ios::out | ios::trunc);
//        if (ff.is_open()) {
//            for (int i = 0; i < line; ++i)
//            {
//                ff << fl[i];
//                if (i != line - 1)
//                    ff << endl;
//            }
//        } else {
//            cout << "orz" << endl;
//        }
//        ff.close();
//        cout << "******数据库已更新*******" << endl;
//    }
//    else
//    {
//        cout<<"查无此人"<<endl;
//    }
//    return head;
//}
//
//struct node *UserFix(struct node *head, string &id)
//{
//    struct node *p;
//    p=head;
//    while (p->next != NULL && p->UserID != id)//查找
//    {
//        p=p->next;
//    }
//    if(p->UserID == id)
//    {
//        cout<<"请输入名字：";cin>>p->UserName;//输入
//        cout<<"********************人已修改************************"<<endl;
//
//        fstream fff;
//        fff.open("UserData.dat");
//        string fl[MAX_FILE];
//        int line = 0;
//        string temp_id, temp_name, temp_password, temp_ubb, temp_hs, temp_sri, temp_ssi, temp_ia, white_space = " ";
//        if (fff.is_open()) {
//            while (true) {
//                fff >> temp_id >> temp_name >> temp_password >> temp_ubb >> temp_hs >> temp_sri >> temp_ssi >> temp_ia;
//                if (temp_id != id) {
//                    fl[line] = temp_id + white_space;
//                    fl[line] += temp_name;
//                    fl[line] += white_space;
//                    fl[line] += temp_password;
//                    fl[line] += white_space;
//                    fl[line] += temp_ubb;
//                    fl[line] += white_space;
//                    fl[line] += temp_hs;
//                    fl[line] += white_space;
//                    fl[line] += temp_sri;
//                    fl[line] += white_space;
//                    fl[line] += temp_ssi;
//                    fl[line] += white_space;
//                    fl[line] += temp_ia;
//                    line++;
//                } else {
//                    fl[line] = temp_id + white_space;
//                    fl[line] += p->UserName;
//                    fl[line] += white_space;
//                    fl[line] += temp_password;
//                    fl[line] += white_space;
//                    fl[line] += temp_ubb;
//                    fl[line] += white_space;
//                    fl[line] += temp_hs;
//                    fl[line] += white_space;
//                    fl[line] += temp_sri;
//                    fl[line] += white_space;
//                    fl[line] += temp_ssi;
//                    fl[line] += white_space;
//                    fl[line] += temp_ia;
//                    line++;
//                }
//                if (fff.eof()) {
//                    break;
//                }
//            }
//        }
//        fff.close();
//        fstream ff;
//        ff.open("UserData.dat", ios::out | ios::trunc);
//        if (ff.is_open()) {
//            for (int i = 0; i < line; ++i)
//            {
//                ff << fl[i];
//                if (i != line - 1)
//                    ff << endl;
//            }
//        } else {
//            cout << "orz" << endl;
//        }
//        ff.close();
//        cout << "******数据库已更新*******" << endl;
//
//    }
//    else
//    {
//        cout<<"查无此人"<<endl;
//    }
//    return head;
//}
//
//struct node *Admin_ChangePassword(struct node *head, string &name) {
//    struct node *p;
//    p=head;
//    int o = 9;
//    cout << "1.修改本管理员密码" << endl;
//    cout << "2.通过学号/工号修改学生密码" << endl;
//    cin >> o;
//    if (o == 1) {
//        while (p->next != NULL && p->UserName != name)//查找
//        {
//            p=p->next;
//        }
//        if(p->UserName == name)
//        {
//            string password;
//            cout<<"请输入修改的密码：";cin>>password;//输入
//            p->Password = picosha2::hash256_hex_string(password);
//            cout<<"密码已修改"<<endl;
//
//            fstream fff;
//            fff.open("UserData.dat");
//            string fl[MAX_FILE];
//            int line = 0;
//            string temp_id, temp_name, temp_password, temp_ubb, temp_hs, temp_sri, temp_ssi, temp_ia, white_space = " ";
//            if (fff.is_open()) {
//                while (true) {
//                    fff >> temp_id >> temp_name >> temp_password >> temp_ubb >> temp_hs >> temp_sri >> temp_ssi >> temp_ia;
//                    if (temp_name != name) {
//                        fl[line] = temp_id + white_space;
//                        fl[line] += temp_name;
//                        fl[line] += white_space;
//                        fl[line] += temp_password;
//                        fl[line] += white_space;
//                        fl[line] += temp_ubb;
//                        fl[line] += white_space;
//                        fl[line] += temp_hs;
//                        fl[line] += white_space;
//                        fl[line] += temp_sri;
//                        fl[line] += white_space;
//                        fl[line] += temp_ssi;
//                        fl[line] += white_space;
//                        fl[line] += temp_ia;
//                        line++;
//                    } else {
//                        fl[line] = temp_id + white_space;
//                        fl[line] += temp_name;
//                        fl[line] += white_space;
//                        fl[line] += p->Password;
//                        fl[line] += white_space;
//                        fl[line] += temp_ubb;
//                        fl[line] += white_space;
//                        fl[line] += temp_hs;
//                        fl[line] += white_space;
//                        fl[line] += temp_sri;
//                        fl[line] += white_space;
//                        fl[line] += temp_ssi;
//                        fl[line] += white_space;
//                        fl[line] += temp_ia;
//                        line++;
//                    }
//                    if (fff.eof()) {
//                        break;
//                    }
//                }
//            }
//            fff.close();
//            fstream ff;
//            ff.open("UserData.dat", ios::out | ios::trunc);
//            if (ff.is_open()) {
//                for (int i = 0; i < line; ++i)
//                {
//                    ff << fl[i];
//                    if (i != line - 1)
//                        ff << endl;
//                }
//            } else {
//                cout << "orz" << endl;
//            }
//            ff.close();
//            cout << "******数据库已更新*******" << endl;
//
//        }
//        else
//        {
//            cout<<"查无此人"<<endl;
//        }
//        return head;
//    } else {
//        string temp;
//        cout << "请输入需要修改的账户的学号/工号：" << endl;
//        cin >> temp;
//        while (p->next != NULL && p->UserID != temp)//查找
//        {
//            p=p->next;
//        }
//        if(p->UserID == temp)
//        {
//            cout << "你要修改的是" << p->UserName << "的密码：" << endl;
//            string password;
//            cout<<"请输入修改的密码：";cin>>password;//输入
//            p->Password = picosha2::hash256_hex_string(password);
//            cout<<"密码已修改"<<endl;
//
//            fstream fff;
//            fff.open("UserData.dat");
//            string fl[MAX_FILE];
//            int line = 0;
//            string temp_id, temp_name, temp_password, temp_ubb, temp_hs, temp_sri, temp_ssi, temp_ia, white_space = " ";
//            if (fff.is_open()) {
//                while (true) {
//                    fff >> temp_id >> temp_name >> temp_password >> temp_ubb >> temp_hs >> temp_sri >> temp_ssi >> temp_ia;
//                    if (temp_id != temp) {
//                        fl[line] = temp_id + white_space;
//                        fl[line] += temp_name;
//                        fl[line] += white_space;
//                        fl[line] += temp_password;
//                        fl[line] += white_space;
//                        fl[line] += temp_ubb;
//                        fl[line] += white_space;
//                        fl[line] += temp_hs;
//                        fl[line] += white_space;
//                        fl[line] += temp_sri;
//                        fl[line] += white_space;
//                        fl[line] += temp_ssi;
//                        fl[line] += white_space;
//                        fl[line] += temp_ia;
//                        line++;
//                    } else {
//                        fl[line] = temp_id + white_space;
//                        fl[line] += temp_name;
//                        fl[line] += white_space;
//                        fl[line] += p->Password;
//                        fl[line] += white_space;
//                        fl[line] += temp_ubb;
//                        fl[line] += white_space;
//                        fl[line] += temp_hs;
//                        fl[line] += white_space;
//                        fl[line] += temp_sri;
//                        fl[line] += white_space;
//                        fl[line] += temp_ssi;
//                        fl[line] += white_space;
//                        fl[line] += temp_ia;
//                        line++;
//                    }
//                    if (fff.eof()) {
//                        break;
//                    }
//                }
//            }
//            fff.close();
//            fstream ff;
//            ff.open("UserData.dat", ios::out | ios::trunc);
//            if (ff.is_open()) {
//                for (int i = 0; i < line; ++i)
//                {
//                    ff << fl[i];
//                    if (i != line - 1)
//                        ff << endl;
//                }
//            } else {
//                cout << "orz" << endl;
//            }
//            ff.close();
//            cout << "******数据库已更新*******" << endl;
//
//
//        }
//        else
//        {
//            cout<<"查无此人"<<endl;
//        }
//        return head;
//    }
//}
//
//
//struct node *User_ChangePassword(struct node *head, string &name) {
//    struct node *p;
//    p=head;
//    while (p->next != NULL && p->UserName != name)//查找
//    {
//        p=p->next;
//    }
//    if(p->UserName == name)
//    {
//        string password;
//        cout<<"请输入修改的密码：";cin>>password;//输入
//        password = picosha2::hash256_hex_string(password);
//        p->Password = password;
//        cout<<"密码已修改"<<endl;
//
//        fstream fff;
//        fff.open("UserData.dat");
//        string fl[MAX_FILE];
//        int line = 0;
//        string temp_id, temp_name, temp_password, temp_ubb, temp_hs, temp_sri, temp_ssi, temp_ia, white_space = " ";
//        if (fff.is_open()) {
//            while (true) {
//                fff >> temp_id >> temp_name >> temp_password >> temp_ubb >> temp_hs >> temp_sri >> temp_ssi >> temp_ia;
//                if (temp_name != name) {
//                    fl[line] = temp_id + white_space;
//                    fl[line] += temp_name;
//                    fl[line] += white_space;
//                    fl[line] += temp_password;
//                    fl[line] += white_space;
//                    fl[line] += temp_ubb;
//                    fl[line] += white_space;
//                    fl[line] += temp_hs;
//                    fl[line] += white_space;
//                    fl[line] += temp_sri;
//                    fl[line] += white_space;
//                    fl[line] += temp_ssi;
//                    fl[line] += white_space;
//                    fl[line] += temp_ia;
//                    line++;
//                } else {
//                    fl[line] = temp_id + white_space;
//                    fl[line] += temp_name;
//                    fl[line] += white_space;
//                    fl[line] += p->Password;
//                    fl[line] += white_space;
//                    fl[line] += temp_ubb;
//                    fl[line] += white_space;
//                    fl[line] += temp_hs;
//                    fl[line] += white_space;
//                    fl[line] += temp_sri;
//                    fl[line] += white_space;
//                    fl[line] += temp_ssi;
//                    fl[line] += white_space;
//                    fl[line] += temp_ia;
//                    line++;
//                }
//                if (fff.eof()) {
//                    break;
//                }
//            }
//        }
//        fff.close();
//        fstream ff;
//        ff.open("UserData.dat", ios::out | ios::trunc);
//        if (ff.is_open()) {
//            for (int i = 0; i < line; ++i)
//            {
//                ff << fl[i];
//                if (i != line - 1)
//                    ff << endl;
//            }
//        } else {
//            cout << "orz" << endl;
//        }
//        ff.close();
//        cout << "******数据库已更新*******" << endl;
//
//
//    }
//    else
//    {
//        cout<<"查无此人"<<endl;
//    }
//    return head;
//}
//
//void find(struct node *head)//查找一个人，并输出
//{
//    while (true) {
//        string a;
//        cout << "请输入关键字，支持模糊搜索" << endl;
//        cin >> a;
//        struct node *p;
//        p=head->next;
//        bool flag = false;
//        cout.fill(' ');
//        string aa = "学号或工号";
//        string b = "用户名";
//        string c = "借阅图书数量";
//        string d = "是否有座位";
//        string e = "房间";
//        string f = "座位号";
//        string g = "是否管理员";
//        cout << left << setw(GetWidth(WIDTH, aa)) << aa <<setw(GetWidth(WIDTH, b)) << b <<setw(GetWidth(DUANG, c))<< c <<setw(GetWidth(DUANG, d))<<d<<setw(GetWidth(DUANG, e))<<e<<setw(GetWidth(DUANG, f))<<f<<setw(GetWidth(DUANG, g))<<g<<endl;
//        while(p->next!=NULL && (FuzzySearch(p->UserName, a)|| FuzzySearch(p->UserID, a)))
//        {
//            if(FuzzySearch(p->UserName, a)|| FuzzySearch(p->UserID, a))
//            {
//                cout.fill(' ');
//                cout << left << setw(GetWidth(WIDTH, p->UserID))<<p->UserID;
//                cout << left << setw(GetWidth(WIDTH, p->UserName)) << p->UserName;
//                cout << left << setw(DUANG) << p->UserBorrowBook;
//                cout << left << setw(DUANG) << p->HaveSeat;
//                cout << left << setw(GetWidth(DUANG, p->StuRoomID)) << p->StuRoomID;
//                cout << left << setw(GetWidth(DUANG, p->StuSeatID)) << p->StuSeatID;
//                cout << left << setw(DUANG) << p->IsAdmin<<endl;
//                flag = true;
//            }
//            p=p->next;
//        }
//        if (!flag) cout << "请换个关键词进行搜索" << endl;
//        else break;
//    }
//}
//
//void print_all(struct node *head)
//{
//    struct node *p;
//    cout.fill(' ');
//    string a = "学号或工号";
//    string b = "用户名";
//    string c = "借阅图书数量";
//    string d = "是否有座位";
//    string e = "房间";
//    string f = "座位号";
//    string g = "是否管理员";
//    cout << left << setw(GetWidth(WIDTH, a)) << a <<setw(GetWidth(WIDTH, b)) << b <<setw(GetWidth(DUANG, c))<< c <<setw(GetWidth(DUANG, d))<<d<<setw(GetWidth(DUANG, e))<<e<<setw(GetWidth(DUANG, f))<<f<<setw(GetWidth(DUANG, g))<<g<<endl;
//    for(p=head;;p=p->next)
//    {
//        cout.fill(' ');
//        cout << left << setw(GetWidth(WIDTH, p->UserID))<<p->UserID;
//        cout << left << setw(GetWidth(WIDTH, p->UserName)) << p->UserName ;
//        cout << left << setw(DUANG) << p->UserBorrowBook;
//        cout << left << setw(DUANG) << p->HaveSeat;
//        cout << left << setw(GetWidth(DUANG, p->StuRoomID)) << p->StuRoomID;
//        cout << left << setw(GetWidth(DUANG, p->StuSeatID)) << p->StuSeatID;
//        cout << left << setw(DUANG) << p->IsAdmin<<endl;
//        if(p->next==NULL)
//            break;
//    }
//}
//
//void count(struct node *head)
//{
//    int c=0, admin = 0;
//    struct node *p;
//    for(p=head;;p=p->next)
//    {
//        c++;
//        if(p->IsAdmin) admin++;
//        if(p->next==NULL) break;
//    }
//    cout<<"人员管理系统内中有"<<c<<"个用户，其中"<< admin << "个管理员" << endl;
//}
//
//void Initcount(struct node *head)
//{
//    int c=0, admin = 0;
//    struct node *p;
//    for(p=head;;p=p->next)
//    {
//        c++;
//        if(p->IsAdmin) admin++;
//        if(p->next==NULL)
//        {
//            break;
//        }
//    }
//    cout << "人员管理系统共初始化" << c << "个账户，其中" << admin << "个管理员账户，初始化完毕。" << endl;
//}
//
//bool IsAdmin(struct node *head, string &Username) {
//    struct node *p;
//    p = head;
//    while(p->UserName != Username) {
//        p = p->next;
//    }
//    if (p->IsAdmin) return true;
//    else return false;
//}
//
//struct node *InitUserData(struct node *head){
//    head = create(head);
//    int count = 0;
//    int admin_count = 0;
//    struct node *p, *p1;
//    p1 = head;
//    ifstream fin;
//    fin.open("UserData.dat");
//    if (fin.is_open()) {
//        string UserID_temp, UserName_temp, Password_temp, StuRoomID_temp, StuSeatID_temp;
//        int UserBorrowBook_temp;
//        bool HaveSeat_temp, IsAdmin_temp;
//        while (!fin.eof()) {
//            p=(struct node*) malloc(size);//为p申请一块空间
//            fin >> UserID_temp >> UserName_temp >> Password_temp >> UserBorrowBook_temp >> HaveSeat_temp
//                >> StuRoomID_temp >> StuSeatID_temp >> IsAdmin_temp;
//            p->UserID = UserID_temp;
//            p->UserName = UserName_temp;
//            p->Password = Password_temp;
//            p->UserBorrowBook = UserBorrowBook_temp;
//            p->HaveSeat = HaveSeat_temp;
//            p->StuRoomID = StuRoomID_temp;
//            p->StuSeatID = StuSeatID_temp;
//            p->IsAdmin = IsAdmin_temp;
//            while (p1->next != NULL) {
//                p1 = p1->next;
//            }
//            p1->next = p;
//            p->next = NULL;
//            count ++;
//            if (IsAdmin_temp) admin_count++;
//        }
//        fin.close();
////        print_all(head);
//    } else {
//        cout << "UserData.dat文件打开失败" << endl;
//    }
//    Initcount(head);
//    return head;
//}
//
//string login(struct node *head){
//    string usernameid;
//    string password;
//    while (true) {
//        cout<<"请输入学号/工号：";
//        cin>>usernameid;
//        cout<<"请输入密码：";
//        cin>>password;
//        password = picosha2::hash256_hex_string(password);
//        struct node *p;
//        p = head;
//        while (p->UserID != usernameid && p != NULL) {
//            p = p->next;
//        }
//        if (p->UserID != usernameid) {
//            string c = "LoginWithoutAccount";
//            log(c, usernameid, password);
//            cout << "没有此账户，是否新建：1.是  2.否：" << endl;
//            int temp = 5;
//            while(true) {
//                cin >> temp;
//                if (temp == 1){
//                    add(head);
//                    break;
//                }
//                else if (temp == 2) break;
//                else cout << "指令输入错误请重新输入" << endl;
//            }
//        } else {
//            if (p->Password == password && p->IsAdmin) {
//                string c = "AdminLogin";
//                log(c, usernameid, password);
//                return usernameid;
//            }
//            else if (p->Password == password && !p->IsAdmin) {
//                string c = "UserLogin";
//                log(c, usernameid, password);
//                return usernameid;
//            }
//            else {
//                string c = "LoginFailed";
//                log(c, usernameid, password);
//                cout << "密码错误，请重新登陆" << endl;
//            }
//        }
//    }
//}
//
//string FindUserName(struct node *head, string &id) {
//    struct node *p;
//    p=head;
//    while(p->next!=NULL && p->UserID != id) p=p->next;
//    return p->UserName;
//}
//
//struct node *FirstLogIn(struct node *head, string &id) {
//    struct node *p;
//    p=head;
//    while (p->next != NULL && p->UserID != id)//查找
//    {
//        p=p->next;
//    }
//    if(p->UserID == id)
//    {
//        string password,name;
//        cout << "请输入你的名字";cin >> name;p->UserName = name;
//        cout<<"请输入修改的密码：";cin>>password;//输入
//        password = picosha2::hash256_hex_string(password);
//        p->Password = password;
//        cout<<"密码已修改"<<endl;
//
//        fstream fff;
//        fff.open("UserData.dat");
//        string fl[MAX_FILE];
//        int line = 0;
//        string temp_id, temp_name, temp_password, temp_ubb, temp_hs, temp_sri, temp_ssi, temp_ia, white_space = " ";
//        if (fff.is_open()) {
//            while (true) {
//                fff >> temp_id >> temp_name >> temp_password >> temp_ubb >> temp_hs >> temp_sri >> temp_ssi >> temp_ia;
//                if (temp_id != id) {
//                    fl[line] = temp_id + white_space;
//                    fl[line] += temp_name;
//                    fl[line] += white_space;
//                    fl[line] += temp_password;
//                    fl[line] += white_space;
//                    fl[line] += temp_ubb;
//                    fl[line] += white_space;
//                    fl[line] += temp_hs;
//                    fl[line] += white_space;
//                    fl[line] += temp_sri;
//                    fl[line] += white_space;
//                    fl[line] += temp_ssi;
//                    fl[line] += white_space;
//                    fl[line] += temp_ia;
//                    line++;
//                } else {
//                    fl[line] = temp_id + white_space;
//                    fl[line] += p->UserName;
//                    fl[line] += white_space;
//                    fl[line] += p->Password;
//                    fl[line] += white_space;
//                    fl[line] += temp_ubb;
//                    fl[line] += white_space;
//                    fl[line] += temp_hs;
//                    fl[line] += white_space;
//                    fl[line] += temp_sri;
//                    fl[line] += white_space;
//                    fl[line] += temp_ssi;
//                    fl[line] += white_space;
//                    fl[line] += temp_ia;
//                    line++;
//                }
//                if (fff.eof()) {
//                    break;
//                }
//            }
//        }
//        fff.close();
//        fstream ff;
//        ff.open("UserData.dat", ios::out | ios::trunc);
//        if (ff.is_open()) {
//            for (int i = 0; i < line; ++i)
//            {
//                ff << fl[i];
//                if (i != line - 1)
//                    ff << endl;
//            }
//        } else {
//            cout << "orz" << endl;
//        }
//        ff.close();
//        cout << "******数据库已更新*******" << endl;
//
//    }
//    else
//    {
//        cout<<"查无此人"<<endl;
//    }
//    return head;
//}
//
//
//
//#endif //INC_221202C___GM_H
