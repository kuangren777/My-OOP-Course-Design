//
// Created by 骆明宇 on 2022/12/20.
//

#ifndef INC_221202C___GMOOP_H
#define INC_221202C___GMOOP_H


#include <iostream>
#include <cstring>
#include <string>
#include "picosha2.h"
#include "time.h"
#include "functions.h"
#include "log.h"
#define MAX_PERSON 1000
#define MAX_FILE 1000
#define WIDTH 15
#define DUANG 13
using namespace std;

class Users {
    string UserID;
    string UserName;
    string Password;
    int UserBorrowBook;
    bool HaveSeat;
    string StuRoomID;
    string StuSeatID;
    bool IsAdmin;
public:
    void ImportUsers(string &UserID_temp, string &UserName_temp, string &Password_temp,
                     int UserBorrowBook_temp, bool HaveSeat_temp, string &StuRoomID_temp,
                     string &StuSeatID_temp, bool IsAdmin_temp) {
        UserID = UserID_temp;
        UserName = UserName_temp;
        Password = Password_temp;
        UserBorrowBook = UserBorrowBook_temp;
        HaveSeat = HaveSeat_temp;
        StuRoomID = StuRoomID_temp;
        StuSeatID = StuSeatID_temp;
        IsAdmin = IsAdmin_temp;
    };
    string GetUserID() {return UserID;};
    string GetUserName() {return UserName;};
    string GetPassword() {return Password;};
    int GetUserBorrowBook() {return UserBorrowBook;};
    bool GetHaveSeat() {return HaveSeat;};
    string GetStuRoomID() {return StuRoomID;};
    string GetStuSeatID() {return StuSeatID;};
    bool GetIsAdmin() {return IsAdmin;};
    void SetUserID(string t) {UserID = t;};
    void SetUserName(string t) {UserName = t;};
    void SetPassword(string t) {Password = t;};
    void SetUserBorrowBook(int t) {UserBorrowBook = t;};
    void SetHaveSeat(bool t) {HaveSeat = t;};
    void SetStuRoomID(string t) {StuRoomID = t;};
    void SetStuSeatID(string t) {StuSeatID = t;};
    void SetIsAdmin(bool t) {IsAdmin = t;};
};

class UserSystem: public Users {
    void InitUsers();
    Users user[MAX_PERSON];
    int length;
public:
    UserSystem() {
        length = 0;
        InitUsers();
    }
    void add();
    void Rewrite(string fl[], int line);
    void WriteFileADD(string &temp_id, string &temp_name, string &temp_password, int temp_ubb, bool temp_hs,
                                  string &temp_sri, string &temp_ssi, bool temp_ia);
    void add_admin();
    void del();
    int IsExist(string &name);
    int NumIsExist(string &id);
    void UserFix(string &id);
    void Admin_ChangePassword(string &name);
    void find();
    void print_all();
    void count();
    bool IsAdmin(string &id);
    string login();
    string FindUserName(string &id) {return user[NumIsExist(id)].GetUserName();};
    void FirstLogIn(string &id);
    void AdminFix();
    void User_ChangePassword(string &id);
};

void UserSystem::InitUsers(){
    long long n;
    ifstream fin;
    int admin_count = 0;
    fin.open("UserData.dat");
    if (fin.is_open()) {
        for (int i = 0;;i++){
            string UserID_temp, UserName_temp, Password_temp, StuRoomID_temp,
            StuSeatID_temp;
            int UserBorrowBook_temp;
            bool HaveSeat_temp, IsAdmin_temp;
            fin >> UserID_temp >> UserName_temp >> Password_temp >> UserBorrowBook_temp >>HaveSeat_temp >> StuRoomID_temp
            >> StuSeatID_temp >> IsAdmin_temp;
            user[length++].ImportUsers(UserID_temp, UserName_temp, Password_temp, UserBorrowBook_temp,
                                       HaveSeat_temp, StuRoomID_temp, StuSeatID_temp, IsAdmin_temp);
            if (IsAdmin_temp) admin_count++;
            if (fin.eof())
            {
                cout << "人员管理系统共初始化" << length <<"个用户共计" << admin_count << "个管理员，初始化完毕。"<< endl;
                break;
            }
        }
        fin.close();
        string a = "UserSystemInitSuccess", b = "NULL", c = "NULL";
        log(a, b, c);
    } else {
        cout << "UserData.dat文件打开失败" << endl;
        string a = "UserSystemInitFailed-Error:FileNotExist", b = "NULL", c = "NULL";
        log(a, b, c);
    }
}

void UserSystem::add() {
    if (length >= MAX_PERSON) {
        cout << "账户已满" << endl;
    }
    else {
        string null = "NULL";
        string id; cout << "请输入学号: " << endl; cin >> id;
        string name; cout << "请输入姓名: " << endl; cin >> name;
        string password; cout << "请输入密码（请放心输入，本系统采用SHA-256加密，保证您的用户安全）： " << endl; cin >> password;
        password = picosha2::hash256_hex_string(password);
        user[length++].ImportUsers(id, name, password, 0, false, null, null, false);
        cout << "导入日期：" << GetDate() <<endl;
        cout << "添加成功" << endl;
        WriteFileADD(id, name, password, 0, false, null, null, false);
        string a = "UserSystemUserAddSuccess", b = name, c = password;
        log(a, b, c);
    }
}

void UserSystem::add_admin() {
    if (length >= MAX_PERSON) {
        cout << "账户已满" << endl;
    }
    else {
        string null = "NULL";
        string id; cout << "请输入学号: " << endl; cin >> id;
        string name; cout << "请输入姓名: " << endl; cin >> name;
        string password; cout << "请输入密码（请放心输入，本系统采用SHA-256加密，保证您的用户安全）： " << endl; cin >> password;
        password = picosha2::hash256_hex_string(password);
        user[length++].ImportUsers(id, name, password, 0, false, null, null, true);
        cout << "导入日期：" << GetDate() <<endl;
        cout << "添加成功" << endl;
        WriteFileADD(id, name, password, 0, false, null, null, true);
        string a = "UserSystemAdminAddSuccess", b = name, c = password;
        log(a, b, c);
    }
}

void UserSystem::WriteFileADD(string &temp_id, string &temp_name, string &temp_password, int temp_ubb, bool temp_hs,
                              string &temp_sri, string &temp_ssi, bool temp_ia) {
    ofstream fff;
    fff.open("UserData.dat", ios::app);
    fff << endl << temp_id << " " << temp_name << " " << temp_password << " " << temp_ubb << " " << temp_hs << " "
    << temp_sri  << " " << temp_ssi << " " << temp_ia;
    fff.close();
    cout << "数据库添加成功" << endl;
}

void UserSystem::Rewrite(string fl[], int line) {
    fstream ff;
    ff.open("UserData.dat", ios::out | ios::trunc);
    if (ff.is_open()) {
        for (int i = 0; i < line; ++i)
        {
            ff << fl[i];
            if (i != line - 1)
                ff << endl;
        }
    } else {
        cout << "orz" << endl;
    }
    ff.close();
    cout << "数据库更新成功" << endl;
}

int UserSystem::IsExist(string &name) {
    for (int i = 0; i < length; ++i) {
        if (user[i].GetUserName() == name) {
            return i;
        }
    }
    return -1;
}

int UserSystem::NumIsExist(string &id) {
    for (int i = 0; i < length; ++i) {
        if (user[i].GetUserID() == id) {
            return i;
        }
    }
    return -1;
}

void UserSystem::del() {
    stringstream ss;
    int o = 9;
    cout << "1.通过名字删除" << endl;
    cout << "2.通过学号/工号删除" << endl;
    cin >> o;
    if (o == 1) {
        string UserName;
        cout << "请输入想删除的人的名字" << endl;
        cin >> UserName;
        int ret;
        ret = IsExist(UserName);
        if (ret != -1) {
            for (int i = 0; i < length; ++i) {
                user[ret].SetUserID(user[i + 1].GetUserID());
                user[ret].SetUserName(user[i + 1].GetUserName());
                user[ret].SetPassword(user[i + 1].GetPassword());
                user[ret].SetUserBorrowBook(user[i + 1].GetUserBorrowBook());
                user[ret].SetHaveSeat(user[i + 1].GetHaveSeat());
                user[ret].SetStuRoomID(user[i + 1].GetStuRoomID());
                user[ret].SetStuSeatID(user[i + 1].GetStuSeatID());
                user[ret].SetIsAdmin(user[i + 1].GetIsAdmin());
                length--;
            }

            fstream fff;
            fff.open("UserData.dat");
            string fl[MAX_FILE];
            int line = 0;
            string temp_id, temp_name, temp_password, temp_ubb, temp_hs, temp_sri, temp_ssi, temp_ia, white_space = " ";
            if (fff.is_open()) {
                while (true) {
                    fff >> temp_id >> temp_name >> temp_password >> temp_ubb >> temp_hs >> temp_sri >> temp_ssi
                        >> temp_ia;
                    if (temp_name != UserName) {
                        ss << temp_id << " " << temp_name << " " << temp_password << " " << temp_ubb << " " <<
                        temp_hs << " " << temp_sri << " " << temp_ssi << " " << temp_ia;
                        fl[line++] = ss.str();
                    }
                    if (fff.eof()) {
                        break;
                    }
                }
            }
            Rewrite(fl, line);
            string a = "UserSystemDeleteSuccess", b = "name", c = UserName;
            log(a, b, c);
        } else {
            cout << "查无此人" << endl;
            string a = "UserSystemDeleteFailed-Error:NameNotExist", b = "name", c = UserName;
            log(a, b, c);
        }

    } else {
        string Userid;
        cout << "请输入想删除的人的学号" << endl;
        cin >> Userid;
        int ret;
        ret = NumIsExist(Userid);
        if (ret != -1) {
            for (int i = 0; i < length; ++i) {
                user[ret].SetUserID(user[i + 1].GetUserID());
                user[ret].SetUserName(user[i + 1].GetUserName());
                user[ret].SetPassword(user[i + 1].GetPassword());
                user[ret].SetUserBorrowBook(user[i + 1].GetUserBorrowBook());
                user[ret].SetHaveSeat(user[i + 1].GetHaveSeat());
                user[ret].SetStuRoomID(user[i + 1].GetStuRoomID());
                user[ret].SetStuSeatID(user[i + 1].GetStuSeatID());
                user[ret].SetIsAdmin(user[i + 1].GetIsAdmin());
                length--;
            }
            fstream fff;
            fff.open("UserData.dat");
            string fl[MAX_FILE];
            int line = 0;
            string temp_id, temp_name, temp_password, temp_ubb, temp_hs, temp_sri, temp_ssi, temp_ia, white_space = " ";
            if (fff.is_open()) {
                while (true) {
                    fff >> temp_id >> temp_name >> temp_password >> temp_ubb >> temp_hs >> temp_sri >> temp_ssi
                        >> temp_ia;
                    if (temp_id != Userid) {
                        ss << temp_id << " " << temp_name << " " << temp_password << " " << temp_ubb << " " <<
                           temp_hs << " " << temp_sri << " " << temp_ssi << " " << temp_ia;
                        fl[line++] = ss.str();
                    }
                    if (fff.eof()) {
                        break;
                    }
                }
            }

            fstream ff;
            ff.open("UserData.dat", ios::out | ios::trunc);
            if (ff.is_open()) {
                for (int i = 0; i < line; ++i) {
                    ff << fl[i];
                    if (i != line - 1)
                        ff << endl;
                }
            } else {
                cout << "orz" << endl;
            }
            ff.close();
            string a = "UserSystemDeleteSuccess", b = "id", c = Userid;
            log(a, b, c);
            cout << "删除成功" << endl;
        } else {
            cout << "查无此人" << endl;
            string a = "UserSystemDeleteFailed-Error:NameNotExist", b = "id", c = Userid;
            log(a, b, c);
        }
    }
}

void UserSystem::UserFix(string &id) {
    stringstream ss;
    int ret = NumIsExist(id);
    if (ret != -1) {
        string name;
        string temp_id, temp_name, temp_password, temp_ubb, temp_hs, temp_sri, temp_ssi, temp_ia, white_space = " ";
        cout << "请输入新的的用户名:"; cin >> name;
        user[ret].SetUserName(name);

        fstream fff;
        fff.open("UserData.dat");
        string fl[MAX_FILE];
        int line = 0;
        if (fff.is_open()) {
            while (true) {
                fff >> temp_id >> temp_name >> temp_password >> temp_ubb >> temp_hs >> temp_sri >> temp_ssi >> temp_ia;
                if (temp_id != id) {
                    ss << temp_id << " " << temp_name << " " << temp_password << " " << temp_ubb << " " <<
                       temp_hs << " " << temp_sri << " " << temp_ssi << " " << temp_ia;
                    fl[line++] = ss.str();
                } else {
                    ss << temp_id << " " << name << " " << temp_password << " " << temp_ubb << " " <<
                       temp_hs << " " << temp_sri << " " << temp_ssi << " " << temp_ia;
                    fl[line++] = ss.str();
                }
                if (fff.eof()) {
                    break;
                }
            }
        }
        fff.close();

        Rewrite(fl, line);
        string a = "UserSystemChangeNameSuccess", b = id, c = name;
        log(a, b, c);
    }
    else
    {
        cout<<"查无此人"<<endl;
        string a = "UserSystemChangeNameFailed-Error:NameNotExist", b = id, c = "NULL";
        log(a, b, c);
    }
}

void UserSystem::Admin_ChangePassword(string &id) {
    stringstream ss;
    int o = 9;
    cout << "1.修改本管理员密码" << endl;
    cout << "2.通过学号/工号修改学生密码" << endl;
    cin >> o;
    if (o == 1) {
        int ret = NumIsExist(id);
        string pw; cout << "请输入新的密码:(请放心输入，本系统采用SHA-256加密)" << endl; cin >> pw;
        pw = picosha2::hash256_hex_string(pw);
        user[ret].SetPassword(pw);
        cout<<"密码已修改"<<endl;

        fstream fff;
        fff.open("UserData.dat");
        string fl[MAX_FILE];
        int line = 0;
        string temp_id, temp_name, temp_password, temp_ubb, temp_hs, temp_sri, temp_ssi, temp_ia, white_space = " ";
        if (fff.is_open()) {
            while (true) {
                fff >> temp_id >> temp_name >> temp_password >> temp_ubb >> temp_hs >> temp_sri >> temp_ssi >> temp_ia;
                if (temp_id != id) {
                    ss << temp_id << " " << temp_name << " " << temp_password << " " << temp_ubb << " " <<
                       temp_hs << " " << temp_sri << " " << temp_ssi << " " << temp_ia;
                    fl[line++] = ss.str();
                } else {
                    ss << temp_id << " " << temp_name << " " << pw << " " << temp_ubb << " " <<
                       temp_hs << " " << temp_sri << " " << temp_ssi << " " << temp_ia;
                    fl[line++] = ss.str();
                }
                if (fff.eof()) {
                    break;
                }
            }
        }
        fff.close();
        Rewrite(fl, line);
        string a = "UserSystemChangePasswordSuccess", b = id, c = pw;
        log(a, b, c);
    } else {
        string temp;
        cout << "请输入需要修改的账户的学号/工号：" << endl;
        cin >> temp;
        int ret = NumIsExist(temp);

        if (ret != -1) {
            string pw;
            cout << "请输入修改账户的密码:(请放心输入，本系统采用SHA-256加密)" << endl;
            cin >> pw;
            pw = picosha2::hash256_hex_string(pw);
            user[ret].SetPassword(pw);
            cout << "密码已修改!" << endl;

            fstream fff;
            fff.open("UserData.dat");
            string fl[MAX_FILE];
            int line = 0;
            string temp_id, temp_name, temp_password, temp_ubb, temp_hs, temp_sri, temp_ssi, temp_ia, white_space = " ";
            if (fff.is_open()) {
                while (true) {
                    fff >> temp_id >> temp_name >> temp_password >> temp_ubb >> temp_hs >> temp_sri >> temp_ssi >> temp_ia;
                    if (temp_id != temp) {
                        ss << temp_id << " " << temp_name << " " << temp_password << " " << temp_ubb << " " <<
                           temp_hs << " " << temp_sri << " " << temp_ssi << " " << temp_ia;
                        fl[line++] = ss.str();
                    } else {
                        ss << temp_id << " " << temp_name << " " << pw << " " << temp_ubb << " " <<
                           temp_hs << " " << temp_sri << " " << temp_ssi << " " << temp_ia;
                        fl[line++] = ss.str();
                    }
                    if (fff.eof()) {
                        break;
                    }
                }
            }
            fff.close();

            Rewrite(fl, line);

            string a = "UserSystemChangePasswordSuccess", b = temp, c = pw;
            log(a, b, c);
        } else {cout << "查无此人" << endl;}
    }
}

void UserSystem::find()
{
    while (true) {
        string aa;
        cout << "请输入关键字，支持模糊搜索" << endl;
        cin >> aa;
        bool flag = false;
        cout.fill(' ');
        string a = "学号或工号";
        string b = "用户名";
        string c = "借阅图书数量";
        string d = "是否有座位";
        string e = "房间";
        string f = "座位号";
        string g = "是否管理员";
        cout << left << setw(Function::GetWidth(WIDTH, a)) << aa <<setw(Function::GetWidth(WIDTH, b)) << b <<setw(Function::GetWidth(DUANG, c))<< c <<setw(Function::GetWidth(DUANG, d))<<d<<setw(Function::GetWidth(DUANG, e))<<e<<setw(Function::GetWidth(DUANG, f))<<f<<setw(Function::GetWidth(DUANG, g))<<g<<endl;
        for (int i = 0; i < length; i ++)
        {
            if(Function::FuzzySearch(user[i].GetUserID(), aa)|| Function::FuzzySearch(user[i].GetUserName(), aa))
            {
                cout.fill(' ');
                cout << left << setw(Function::GetWidth(WIDTH, user[i].GetUserID())) << user[i].GetUserID();
                cout << left << setw(Function::GetWidth(WIDTH, user[i].GetUserName())) << user[i].GetUserName();
                cout << left << setw(DUANG) << user[i].GetUserBorrowBook();
                cout << left << setw(DUANG) << user[i].GetHaveSeat();
                cout << left << setw(Function::GetWidth(DUANG, user[i].GetStuRoomID())) << user[i].GetStuRoomID();
                cout << left << setw(Function::GetWidth(DUANG, user[i].GetStuSeatID())) << user[i].GetStuSeatID();
                cout << left << setw(DUANG) << user[i].GetIsAdmin() << endl;
                flag = true;
            }
        }
        string aaa = "UserSystemFind", bb = aa, cc = "NULL";
        log(aaa, bb, cc);
        if (!flag) cout << "请换个关键词进行搜索" << endl;
        else break;
    }
}

void UserSystem::print_all() {
    struct node *p;
    cout.fill(' ');
    string a = "学号或工号";
    string b = "用户名";
    string c = "借阅图书数量";
    string d = "是否有座位";
    string e = "房间";
    string f = "座位号";
    string g = "是否管理员";
    cout << left << setw(Function::GetWidth(WIDTH, a)) << a <<setw(Function::GetWidth(WIDTH, b)) << b <<setw(Function::GetWidth(DUANG, c))<< c <<setw(Function::GetWidth(DUANG, d))<<d<<setw(Function::GetWidth(DUANG, e))<<e<<setw(Function::GetWidth(DUANG, f))<<f<<setw(Function::GetWidth(DUANG, g))<<g<<endl;
    for(int i = 0; i < length; ++i)
    {
        cout.fill(' ');
        cout << left << setw(Function::GetWidth(WIDTH, user[i].GetUserID())) << user[i].GetUserID();
        cout << left << setw(Function::GetWidth(WIDTH, user[i].GetUserName())) << user[i].GetUserName();
        cout << left << setw(DUANG) << user[i].GetUserBorrowBook();
        cout << left << setw(DUANG) << user[i].GetHaveSeat();
        cout << left << setw(Function::GetWidth(DUANG, user[i].GetStuRoomID())) << user[i].GetStuRoomID();
        cout << left << setw(Function::GetWidth(DUANG, user[i].GetStuSeatID())) << user[i].GetStuSeatID();
        cout << left << setw(DUANG) << user[i].GetIsAdmin() << endl;
    }
}

void UserSystem::count()
{
    int t = 0;
    for (int i = 0; i < length; ++i) {if(user[i].GetIsAdmin()) ++t;}
    cout << "人员管理系统内中有" << length << "个用户，其中" << t << "个管理员" << endl;
}

bool UserSystem::IsAdmin(string &id) {
    int ret = NumIsExist(id);
    if (user[ret].GetIsAdmin()) return true;
    else return false;
}

string UserSystem::login(){
    string userid;
    string password;
    while (true) {
        cout<<"请输入学号/工号：";
        cin>>userid;
        cout<<"请输入密码：";
        cin>>password;
        password = picosha2::hash256_hex_string(password);
        if (password == "8d969eef6ecad3c29a3a629280e686cf0c3f5d5a86aff3ca12020c923adc6c92") {
            FirstLogIn(userid);
            continue;
        }
        int ret = NumIsExist(userid);
        if (ret != -1) {
            if (user[ret].GetPassword() != password) {
                string c = "LoginFailed";
                log(c, userid, password);
                cout << "密码错误，请重新登陆" << endl;
            } else {
                if (user[ret].GetIsAdmin()) {
                    string c = "AdminLogin";
                    log(c, userid, password);
                } else {
                    string c = "UserLogin";
                    log(c, userid, password);
                }
                return userid;
            }
        } else {
            string c = "LoginWithoutAccount";
            log(c, userid, password);
            cout << "没有此账户，是否新建：1.是  2.否：" << endl;
            int temp = 5;
            while(true) {
                cin >> temp;
                if (temp == 1){
                    add();
                    break;
                }
                else if (temp == 2) break;
                else cout << "指令输入错误请重新输入" << endl;
            }
        }
    }
}

void UserSystem::FirstLogIn(string &id) {
    cout << "第一次登录，请修改密码" << endl;
    User_ChangePassword(id);
    string a = "UserFirstLogIn", b = id, c = "NULL";
    log(a, b, c);
}


void UserSystem::AdminFix() {
    stringstream ss;
    string UserName;
    cout << "请输入修改的账户的学号/工号：" << endl;
    cin >> UserName;
    int ret = IsExist(UserName);
    if(ret != -1) {
        string password, name, a, b;
        cout << "************开始修改************" << endl;
        cout <<"请输入更改后的名字：";cin>>name;user[ret].SetUserName(name);
        cout<<"请输入新的密码：";cin>>password;
        password = picosha2::hash256_hex_string(password);
        user[ret].SetPassword(password);
        cout<<"请输入新的房间号：";cin>>a;user[ret].SetStuRoomID(a);
        cout<<"请输入新的座位号：";cin>>b;user[ret].SetStuSeatID(b);
        cout<< "************修改成功************" <<endl;

        fstream fff;
        fff.open("UserData.dat");
        string fl[MAX_FILE];
        int line = 0;
        string temp_id, temp_name, temp_password, temp_ubb, temp_hs, temp_sri, temp_ssi, temp_ia, white_space = " ";
        if (fff.is_open()) {
            while (true) {
                fff >> temp_id >> temp_name >> temp_password >> temp_ubb >> temp_hs >> temp_sri >> temp_ssi >> temp_ia;
                if (temp_name != UserName) {
                    ss << temp_id << " " << temp_name << " " << temp_password << " " << temp_ubb << " " <<
                       temp_hs << " " << temp_sri << " " << temp_ssi << " " << temp_ia;
                    fl[line++] = ss.str();
                } else {
                    ss << temp_id << " " << name << " " << password << " " << temp_ubb << " " <<
                       temp_hs << " " << a << " " << b << " " << temp_ia;
                    fl[line++] = ss.str();
                }
                if (fff.eof()) {
                    break;
                }
            }
        }
        fff.close();
        Rewrite(fl, line);
        string aa = "UserSystemFixSuccess", bb = UserName, cc = "NULL";
        log(aa, bb, cc);
    } else {
        cout<<"查无此人"<<endl;
        string aa = "UserSystemFixFailedFailed-Error:NameNotExist", bb = UserName, cc = "NULL";
        log(aa, bb, cc);
    }
}

void UserSystem::User_ChangePassword(string &id) {
    stringstream ss;
    int ret = NumIsExist(id);
    if(ret != -1)
    {
        string password;
        cout<<"请输入修改的密码：";cin>>password;//输入
        password = picosha2::hash256_hex_string(password);
        user[ret].SetPassword(password);
        cout<<"密码已修改"<<endl;

        fstream fff;
        fff.open("UserData.dat");
        string fl[MAX_FILE];
        int line = 0;
        string temp_id, temp_name, temp_password, temp_ubb, temp_hs, temp_sri, temp_ssi, temp_ia, white_space = " ";
        if (fff.is_open()) {
            while (true) {
                fff >> temp_id >> temp_name >> temp_password >> temp_ubb >> temp_hs >> temp_sri >> temp_ssi >> temp_ia;
                if (temp_id != id) {
                    ss << temp_id << " " << temp_name << " " << temp_password << " " << temp_ubb << " " <<
                       temp_hs << " " << temp_sri << " " << temp_ssi << " " << temp_ia;
                    fl[line++] = ss.str();
                } else {
                    ss << temp_id << " " << temp_name << " " << password << " " << temp_ubb << " " <<
                       temp_hs << " " << temp_sri << " " << temp_ssi << " " << temp_ia;
                    fl[line++] = ss.str();
                }
                if (fff.eof()) {
                    break;
                }
            }
        }
        fff.close();

        Rewrite(fl, line);
        string a = "UserSystemAdminChangePasswordSuccess", b = id, c = password;
        log(a, b, c);
    }
}

#endif //INC_221202C___GMOOP_H
