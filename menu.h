//
// Created by 骆明宇 on 2022/12/2.
//

#include <iostream>
#include <string>
#include "mzhoop.h"
#include "ls.h"
#include "gm.h"
#include "gmoop.h"
using namespace std;

//void menu() {
//    cout << "**********1.加入图书**********" << endl; //OK
//    cout << "**********2.借出图书**********" << endl;//OK
//    cout << "**********3.标记不可用图书*****" << endl;//OK
//    cout << "**********4.删除图书**********" << endl;//OK
//    cout << "**********5.修改书籍信息*******" << endl;//OK
//    cout << "**********6.书架展示**********" << endl;
//    cout << "**********7.归还图书**********" << endl;
//    cout << "**********8.查找图书**********" << endl;
//    cout << "**********0.退出系统**********" << endl; //OK
//};

class Menu {
public:
    static void AdminMenu_Book(BookSystem bs, string &id, string &name);
    static void UserMenu_Book(BookSystem bs, string &id, string &name);
    static void AdminMenu_Seat(int seat[][col], student *cstu, string &id, string &name);
    static void UserMenu_Seat(int seat[][col], student *cstu, string &id, string &name);
    static void AdminMenu_UserMange(UserSystem us, string &id, string &name);
    static void UserMenu_UserMange(UserSystem us, string &id, string &name);
    static void AdminMenu(BookSystem bs, int seat[][col], student *cstu, UserSystem us, string &id, string &Name);
    static void UserMenu(BookSystem bs, int seat[][col], student *cstu, UserSystem us, string &id, string &Name);
};

void Menu::AdminMenu_Book(BookSystem bs, string &id, string &name) {
    int operate = 9;
    while (operate) {
        cout << "*****************************" << endl;
        cout << GetDate() << endl;
        cout << "欢迎管理员：" << name << endl;
        cout << "工号：" << id << endl;
        cout << "*****************************" << endl;
        cout << "**   图书管理系统（管理员端）  **" << endl;
        cout << "*****************************" << endl;
        cout << "**********1.加入图书**********" << endl;
        cout << "**********2.借出图书**********" << endl;
        cout << "**********3.标记图书**********" << endl;
        cout << "**********4.删除图书**********" << endl;
        cout << "**********5.修改图书**********" << endl;
        cout << "**********6.展示图书**********" << endl;
        cout << "**********7.归还图书**********" << endl;
        cout << "**********8.查找图书**********" << endl;
        cout << "**********0.返回上级**********" << endl;
        cout << "*****************************" << endl;
        cin >> operate;
        switch (operate) {
            case 1: bs.ImportBook(); break;
            case 2: bs.OutBook(id, name); break;
            case 3: bs.UnableBook(); break;
            case 4: bs.DeleteBook(); break;
            case 5: bs.FixBook(); break;
            case 6: bs.ShowBook(); break;
            case 7: bs.BackBook(); break;
            case 8: bs.LookUpBook(); break;
            case 0: break;
            default: cout << "你输入错了捏，请重新输入" << endl; break;
        }

    }
}

void Menu::UserMenu_Book(BookSystem bs, string &id, string &name) {
    int operate = 9;
    while (operate) {
        cout << "*****************************" << endl;
        cout << GetDate() << endl;
        cout << "欢迎用户：" << name << endl;
        cout << "学号：" << id << endl;
        cout << "*****************************" << endl;
        cout << "**    图书借阅系统（学生端）   **" << endl;
        cout << "*****************************" << endl;
        cout << "**********1.借出图书**********" << endl;
        cout << "**********2.展示图书**********" << endl;
        cout << "**********3.归还图书**********" << endl;
        cout << "**********4.查找图书**********" << endl;
        cout << "**********0.返回上级**********" << endl;
        cout << "*****************************" << endl;
        cin >> operate;
        switch (operate) {
            case 1: bs.OutBook(id, name); break;
            case 2: bs.ShowBook(); break;
            case 3: bs.BackBook(); break;
            case 4: bs.LookUpBook(); break;
            case 0: break;
            default: cout << "你输入错了捏，请重新输入" << endl; break;
        }

    }
}

void Menu::AdminMenu_Seat(int seat[][col], student *cstu, string &id, string &name) {
    int operate = 9;
    while (operate) {
        cout << "*****************************" << endl;
        cout << GetDate() << endl;
        cout << "欢迎管理员：" << name << endl;
        cout << "工号：" << id << endl;
        cout << "*****************************" << endl;
        cout << "**   座位管理系统（管理员端）  **" << endl;
        cout << "*****************************" << endl;
        cout << "**********1.设置座位**********" << endl;
        cout << "**********2.取消座位**********" << endl;
        cout << "**********3.显示某座位学生信息**" << endl;
        cout << "**********4.查询学生座位*******" << endl;
        cout << "**********5.显示座次表*********" << endl;
        cout << "**********0.返回上级***********" << endl;
        cout << "*****************************" << endl;
        cin>>operate;
        switch (operate) {
            case 1: SeatSystem::arrange_seat(seat, cstu, id, name);break;
            case 2: SeatSystem::cancel_seat(seat, cstu, id, name);break;
            case 3: SeatSystem::find_student(seat, cstu);break;
            case 4: SeatSystem::find_seat(seat, cstu);break;
            case 5: SeatSystem::display_seats(seat, cstu);break;
            case 0: break;
            default: cout << "你输入错了捏，请重新输入" << endl; break;
        }
    }
}

void Menu::UserMenu_Seat(int seat[][col], student *cstu, string &id, string &name) {
    int operate = 9;
    while (operate) {
        cout << "*****************************" << endl;
        cout << GetDate() << endl;
        cout << "欢迎用户：" << name << endl;
        cout << "学号：" << id << endl;
        cout << "*****************************" << endl;
        cout << "**   座位管理系统（学生端）  **" << endl;
        cout << "*****************************" << endl;
        cout << "**********1.设置座位**********" << endl;
        cout << "**********2.取消座位**********" << endl;
        cout << "**********3.显示座次表*********" << endl;
        cout << "**********0.返回上级***********" << endl;
        cout << "*****************************" << endl;
        cin>>operate;
        switch (operate) {
            case 1: SeatSystem::arrange_seat(seat, cstu, id, name);break;
            case 2: SeatSystem::cancel_seat(seat, cstu, id, name);break;
            case 3: SeatSystem ::display_seats(seat, cstu);break;
            case 0: break;
            default: cout << "你输入错了捏，请重新输入" << endl; break;
        }
    }
}


void Menu::AdminMenu_UserMange(UserSystem us, string &id, string &name) {
    int operate = 9;
    while (operate) {
        cout << "*****************************" << endl;
        cout << GetDate() << endl;
        cout << "欢迎管理员：" << name << endl;
        cout << "工号：" << id << endl;
        cout << "*****************************" << endl;
        cout << "**   人员管理系统（管理员端）  **" << endl;
        cout << "*****************************" << endl;
        cout << "**********1.添加学生账户*******" << endl;
        cout << "**********2.添加管理员账户*****" << endl;
        cout << "**********3.删除账户**********" << endl;
        cout << "**********4.修改密码**********" << endl;
        cout << "**********5.展示所有账户*******" << endl;
        cout << "**********6.账户查询**********" << endl;
        cout << "**********7.编辑账户信息*******" << endl;
        cout << "**********8.统计账户个数*******" << endl;
        cout << "**********0.返回上级**********" << endl;
        cout << "*****************************" << endl;
        cin >> operate;
        switch (operate) {
            case 1: us.add(); break;
            case 2: us.add_admin(); break;
            case 3: us.del(); break;
            case 4: us.Admin_ChangePassword(id); break;
            case 5: us.print_all(); break;
            case 6: us.find(); break;
            case 7: us.AdminFix(); break;
            case 8: us.count(); break;
            case 0: break;
            default: cout << "你输入错了捏，请重新输入" << endl; break;
        }
    }
}

void Menu::UserMenu_UserMange(UserSystem us, string &id, string &name) {
    int operate = 9;
    while (operate) {
        cout << "*****************************" << endl;
        cout << GetDate() << endl;
        cout << "欢迎用户：" << name << endl;
        cout << "学号：" << id << endl;
        cout << "*****************************" << endl;
        cout << "**    人员管理系统（学生端）   **" << endl;
        cout << "*****************************" << endl;
        cout << "**********1.修改密码**********" << endl;
        cout << "**********2.我的账户**********" << endl;
        cout << "**********3.修改姓名**********" << endl;
        cout << "**********0.返回上级**********" << endl;
        cout << "*****************************" << endl;
        cin >> operate;
        switch (operate) {
            case 1: us.User_ChangePassword(id); break;
            case 2: us.print_all(); break;
            case 3: us.UserFix(id); break;
            case 0: break;
            default: cout << "你输入错了捏，请重新输入" << endl; break;
        }
    }
}

void Menu::AdminMenu(BookSystem bs, int seat[][col], student *cstu, UserSystem us, string &id, string &Name) {
    int operate = 9;
    while (operate) {
        cout << "*****************************" << endl;
        cout << GetDate() << endl;
        cout << "欢迎管理员：" << Name << endl;
        cout << "工号：" << id << endl;
        cout << "*****************************" << endl;
        cout << "** 图书馆综合管理系统（管理员端）**" << endl;
        cout << "*****************************" << endl;
        cout << "**********1.图书管理**********" << endl;
        cout << "**********2.座位管理**********" << endl;
        cout << "**********3.人员管理**********" << endl;
        cout << "**********0.返回上级**********" << endl;
        cout << "*****************************" << endl;
        cin >> operate;
        switch (operate) {
            case 1: Menu::AdminMenu_Book(bs, id, Name); break;
            case 2: Menu::AdminMenu_Seat(seat, cstu, id, Name); break;
            case 3: Menu::AdminMenu_UserMange(us, id, Name); break;
            case 0: break;
            default: cout << "你输入错了捏，请重新输入" << endl; break;
        }
    }
}

void Menu::UserMenu(BookSystem bs, int seat[][col], student *cstu, UserSystem us, string &id, string &Name) {
    int operate = 9;
    while (operate) {
        cout << "*****************************" << endl;
        cout << GetDate() << endl;
        cout << "欢迎用户：" << Name << endl;
        cout << "学号：" << id << endl;
        cout << "*****************************" << endl;
        cout << "**  图书馆综合管理系统（学生端）**" << endl;
        cout << "*****************************" << endl;
        cout << "**********1.图书借阅**********" << endl;
        cout << "**********2.座位系统**********" << endl;
        cout << "**********3.我的信息**********" << endl;
        cout << "**********0.返回上级**********" << endl;
        cout << "*****************************" << endl;
        cin >> operate;
        switch (operate) {
            case 1: Menu::UserMenu_Book(bs, id, Name); break;
            case 2: Menu::UserMenu_Seat(seat, cstu, id, Name); break;
            case 3: Menu::UserMenu_UserMange(us, id, Name); break;
            case 0: break;
            default: cout << "你输入错了捏，请重新输入" << endl; break;
        }
    }
}
