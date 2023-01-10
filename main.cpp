//
// Created by 骆明宇 on 2022/11/1.
//

//#include <fstream>
#include <iostream>
//#include <string>
//#include <cstring>
//#include <string.h>
#include "test.h"
#include "menu.h"
#include "ls.h"
#include "log.h"
#include "gm.h"
#include "gmoop.h"
#include "mzhoop.h"
using namespace std;

int main() {
//    ArrayBooks books;
//    books.length = 0;
    BookSystem bs;
    UserSystem us;
    SeatSystem system;
    int seat[row][col];
    student cstu[64];//8*8=64个座位，用对象数组存储
//    student::InitSeat(seat, cstu);
//    InitBooks(books);
//    struct node *head;
//    head = InitUserData(head);
    cout << endl;
    cout<<"***欢迎使用本图书馆管理系统***"<<endl;
    cout << "当前时间为：" << GetDate() << endl;
    cout<<"************请登录************"<<endl;
//    print_all(head);
    while (true) {
        string id = us.login();
        string username = us.FindUserName(id);
        if (us.IsAdmin(id)) {
            cout << "登陆成功：欢迎管理员" << username << endl;
            Menu::AdminMenu(bs, seat, cstu, us, id, username);
        } else {
            if (username == "Index") us.FirstLogIn(id);
            username = us.FindUserName(id);
            cout << "登陆成功：欢迎" << username << endl;
            Menu::UserMenu(bs, seat, cstu, us, id, username);
        }
    }
//    cout << "登陆成功：" << endl;
//
//    ShowBook(books);

    return 0;
}

//#include <iostream>
//#include <string>
//#include <cstring>
//#include "picosha2.h"
//using namespace std;
//
//int main(){
//    string x="1";
//    cout<<picosha2::hash256_hex_string(x)<<endl;
//    return 0;
//}