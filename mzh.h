////
//// Created by 骆明宇 on 2022/11/3.
////
//
//#ifndef TOTAL_MZH_H
//#define TOTAL_MZH_H
//
//#include <iostream>
//#include <string>
//#include <cstring>
//#include <iomanip>
//#include <fstream>
//#include "functions.h"
//#include "time.h"
//
//using namespace std;
//#define wide 30
//#define WIDE 23
//#define DUAN 10
//#include <string>
//using namespace std;
//#define MAX 1000
//#define MAX_FILE 1000
//
//class Personc {
//private:
//    string BookName;
//    string ISBN;
//    string PublicCompany;
//    string BookUserName;
//    bool IsBorrowed;
//    string BookUserID;
//    string BorrowDate;
//    bool CanUse;
//public:
//    string GetBookName();
//    string GetISBN();
//    string GetPublicCompany();
//    string GetBookUserName();
//    bool GetIsBorrowed();
//    string GetBookUserID();
//    string GetBorrowDate();
//    bool GetCanUse();
//};
//
//class Person_1 {
//public:
//    string BookName;
//    string ISBN;
//    string PublicCompany;
//    string BookUserName;
//    bool IsBorrowed;
//    string BookUserID;
//    string BorrowDate;
//    bool CanUse;
//};
//
//
//
//
//
//
//struct Person {
//    string BookName;
//    string ISBN;
//    string PublicCompany;
//    string BookUserName;
//    bool IsBorrowed;
//    string BookUserID;
//    string BorrowDate;
//    bool CanUse;
//};
//
//struct ArrayBooks {
//    struct Person book[MAX];
//    int length;
//};
//
//long long InitAllBooksFromFile(ArrayBooks &books, string BookName_temp, string ISBN_temp, string PublicCompany_temp, string BookUserName_temp, string BookUserID_temp, string BorrowDate_temp ){
//    books.book[books.length].BookName = BookName_temp;
//    books.book[books.length].ISBN = ISBN_temp;
//    books.book[books.length].PublicCompany = PublicCompany_temp;
//    books.book[books.length].IsBorrowed = false;
//    books.book[books.length].BookUserName = BookUserName_temp;
//    books.book[books.length].BookUserID = BookUserID_temp;
//    books.book[books.length].BorrowDate = BorrowDate_temp;
//    books.book[books.length].CanUse = true;
//    books.length++;
//    return books.length;
//}
//
//
//
//void InitBooks(ArrayBooks &books){
//    long long n;
//    books.length = 0;
//    ifstream fin;
//    fin.open("bookInfo.dat");
//    if (fin.is_open()) {
//        for (int i = 0;;i++){
//            string BookName_temp, ISBN_temp, PublicCompany_temp, BookUserName_temp, BookUserID_temp, BorrowDate_temp;
//            fin >> BookName_temp >> ISBN_temp >> PublicCompany_temp >> BookUserName_temp >> BookUserID_temp >> BorrowDate_temp;
//            n = InitAllBooksFromFile(books, BookName_temp, ISBN_temp, PublicCompany_temp, BookUserName_temp, BookUserID_temp, BorrowDate_temp);
//            if (fin.eof())
//            {
//                cout << "图书系统共初始化" <<n<<"本书，初始化完毕。"<< endl;
//                break;
//            }
//        }
//        fin.close();
//    } else {
//        cout << "bookInfo.dat文件打开失败" << endl;
//    }
//}
//
//
//
//void ImportBook(ArrayBooks &books) {
//    if (books.length >= MAX) {
//        cout << "书籍已满" << endl;
//    }
//    else {
//        string name;
//        cout << "请输入书籍的名字: " << endl;
//        cin >> name;
//        books.book[books.length].BookName = name;
//        string num;
//        cout << "请输入书ISBN号： " << endl;
//        cin >> num;
//        books.book[books.length].ISBN = num;
//        string publicCompany_temp;
//        cout << "请输入出版社： " << endl;
//        cin >> publicCompany_temp;
//        books.book[books.length].PublicCompany = publicCompany_temp;
//        books.book[books.length].BookUserName = "NULL";
//        books.book[books.length].IsBorrowed = false;
//        books.book[books.length].BookUserID = "NULL";
//        string date = "NULL";
//        cout << "借阅日期：" << date <<endl;
//        books.book[books.length].BorrowDate = date;
//        bool use = true;
//        cout << "是否可用：是" <<endl;
//        books.book[books.length].CanUse = use;
//        ofstream fff;
//        fff.open("bookInfo.dat", ios::app);
//        fff << endl << books.book[books.length].BookName << " " << books.book[books.length].ISBN << " " << books.book[books.length].PublicCompany << " " << books.book[books.length].BookUserName << " " << books.book[books.length].BookUserID << " " << books.book[books.length].BorrowDate;
//        fff.close();
//        cout << "添加成功" << endl;
//        books.length++;
//    }
//}
//
//
//int isExist(ArrayBooks &books, string name) {
//    for (int i = 0; i < books.length; ++i) {
//        if (books.book[i].BookName == name) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//int isnumExist(ArrayBooks &books, string num) {
//    for (int i = 0; i < books.length; ++i) {
//        if (books.book[i].ISBN == num) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//void OutBook(ArrayBooks &books, string id, string name)
//{
//    string bookname;
//    cout << "输入你要借阅的图书" << endl;
//    cin >> bookname;
//    int ret = isExist(books, bookname);
//    if (ret != -1) {
//        books.book[ret].BookUserName = name;
//        books.book[ret].BookUserID = id;
//        books.book[ret].IsBorrowed = true;
//        books.book[ret].BorrowDate = GetDate();
//        cout << "借阅成功" << endl;
//        fstream fff;
//        fff.open("bookInfo.dat");
//        string fl[MAX_FILE];
//        int line = 0;
//        string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
//        if (fff.is_open()) {
//            while (true) {
//                fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
//                if (temp_name != bookname) {
//                    fl[line] = temp_name + white_space;
//                    fl[line] += temp_isbn;
//                    fl[line] += white_space;
//                    fl[line] += temp_public;
//                    fl[line] += white_space;
//                    fl[line] += temp_username;
//                    fl[line] += white_space;
//                    fl[line] += temp_userid;
//                    fl[line] += white_space;
//                    fl[line] += temp_date;
//                    line++;
//                } else {
//                    fl[line] = temp_name + white_space;
//                    fl[line] += temp_isbn;
//                    fl[line] += white_space;
//                    fl[line] += temp_public;
//                    fl[line] += white_space;
//                    fl[line] += name;
//                    fl[line] += white_space;
//                    fl[line] += id;
//                    fl[line] += white_space;
//                    fl[line] += GetDate();
//                    line++;
//                }
//                if (fff.eof()) {
//                    break;
//                }
//            }
//        }
//
//        fstream ff;
//        ff.open("bookInfo.dat", ios::out | ios::trunc);
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
//        cout << "数据库修改成功" << endl;
//    } else {
//        cout << "查无此书" << endl;
//    }
//}
//
//void UnableBook(ArrayBooks &books)
//{
//    cout << "请输入要标记不可用图书" << endl;
//    string name;
//    cin >> name;
//    int ret = isExist(books, name);
//    if (ret != -1) {
//        bool use = false; cout <<"已标记为不可用" << endl;
//        books.book[ret].CanUse = use;
//    }
//}
//
//void DeleteBook(ArrayBooks &books) {
//    cout << "请输入你要删除的书籍" << endl;
//    string name;
//    cin >> name;
//
//    int ret = isExist(books, name);
//    if (ret != -1) {
//        for (int i = 0; i < books.length; ++i) {
//            books.book[ret].BookName = books.book[i + 1].BookName;
//            books.book[ret].ISBN = books.book[i + 1].ISBN;
//            books.book[ret].BookUserName = books.book[i + 1].BookUserName;
//            books.book[ret].IsBorrowed = books.book[i + 1].IsBorrowed;
//            books.book[ret].BookUserID = books.book[i + 1].BookUserID;
//            books.book[ret].BorrowDate = books.book[i + 1].BorrowDate;
//            books.book[ret].CanUse = books.book[i + 1].CanUse;
//            books.length--;
//        }
//        fstream fff;
//        fff.open("bookInfo.dat");
//        string fl[MAX_FILE];
//        int line = 0;
//        string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
//        if (fff.is_open()) {
//            while (true) {
//                fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
//                if (temp_name != name) {
//                    fl[line] = temp_name + white_space;
//                    fl[line] += temp_isbn;
//                    fl[line] += white_space;
//                    fl[line] += temp_public;
//                    fl[line] += white_space;
//                    fl[line] += temp_username;
//                    fl[line] += white_space;
//                    fl[line] += temp_userid;
//                    fl[line] += white_space;
//                    fl[line] += temp_date;
//                    line++;
//                }
//                if (fff.eof()) {
//                    break;
//                }
//            }
//        }
//
//        fstream ff;
//        ff.open("bookInfo.dat", ios::out | ios::trunc);
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
//    else {
//        cout << "查无此书" << endl;
//    }
//}
//
//
//void FixBook(ArrayBooks &books) {
//    cout << "输入你要修改的图书" << endl;
//    string name_yuan;
//    cin >> name_yuan;
//    int ret = isExist(books, name_yuan);
//    if (ret != -1) {
//        cout << "请输入要修改的内容：1.书名 2.书ISBN号 3.借阅者姓名 4.借阅者学号 5.借阅日期 6.是否可用 7.出版社" << endl;
//        int m;cin >> m;
//        switch (m) {
//            case 1: {
//                cout << "请输入修改后名字： " << endl;
//                string name;
//                cin >> name;
//                books.book[ret].BookName = name;
//                fstream fff;
//                fff.open("bookInfo.dat");
//                string fl[MAX_FILE];
//                int line = 0;
//                string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
//                if (fff.is_open()) {
//                    while (true) {
//                        fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
//                        if (temp_name != name_yuan) {
//                            fl[line] = temp_name + white_space;
//                            fl[line] += temp_isbn;
//                            fl[line] += white_space;
//                            fl[line] += temp_public;
//                            fl[line] += white_space;
//                            fl[line] += temp_username;
//                            fl[line] += white_space;
//                            fl[line] += temp_userid;
//                            fl[line] += white_space;
//                            fl[line] += temp_date;
//                            line++;
//                        } else {
//                            fl[line] = name + white_space;
//                            fl[line] += temp_isbn;
//                            fl[line] += white_space;
//                            fl[line] += temp_public;
//                            fl[line] += white_space;
//                            fl[line] += temp_username;
//                            fl[line] += white_space;
//                            fl[line] += temp_userid;
//                            fl[line] += white_space;
//                            fl[line] += temp_date;
//                            line++;
//                        }
//                        if (fff.eof()) {
//                            break;
//                        }
//                    }
//                }
//                fff.close();
//                fstream ff;
//                ff.open("bookInfo.dat", ios::out | ios::trunc);
//                if (ff.is_open()) {
//                    for (int i = 0; i < line; ++i)
//                    {
//                        ff << fl[i];
//                        if (i != line - 1)
//                            ff << endl;
//                    }
//                } else {
//                    cout << "orz" << endl;
//                }
//                ff.close();
//                cout << "数据库已同步更新" << endl;
//            };
//                break;
//            case 2: {
//                cout << "请输入书ISBN号： " << endl;
//                string num;
//                cin >> num;
//                books.book[ret].ISBN = num;
//                fstream fff;
//                fff.open("bookInfo.dat");
//                string fl[MAX_FILE];
//                int line = 0;
//                string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
//                if (fff.is_open()) {
//                    while (true) {
//                        fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
//                        if (temp_name != name_yuan) {
//                            fl[line] = temp_name + white_space;
//                            fl[line] += temp_isbn;
//                            fl[line] += white_space;
//                            fl[line] += temp_public;
//                            fl[line] += white_space;
//                            fl[line] += temp_username;
//                            fl[line] += white_space;
//                            fl[line] += temp_userid;
//                            fl[line] += white_space;
//                            fl[line] += temp_date;
//                            line++;
//                        } else {
//                            fl[line] = temp_name + white_space;
//                            fl[line] += num;
//                            fl[line] += white_space;
//                            fl[line] += temp_public;
//                            fl[line] += white_space;
//                            fl[line] += temp_username;
//                            fl[line] += white_space;
//                            fl[line] += temp_userid;
//                            fl[line] += white_space;
//                            fl[line] += temp_date;
//                            line++;
//                        }
//                        if (fff.eof()) {
//                            break;
//                        }
//                    }
//                }
//                fff.close();
//                fstream ff;
//                ff.open("bookInfo.dat", ios::out | ios::trunc);
//                if (ff.is_open()) {
//                    for (int i = 0; i < line; ++i)
//                    {
//                        ff << fl[i];
//                        if (i != line - 1)
//                            ff << endl;
//                    }
//                } else {
//                    cout << "orz" << endl;
//                }
//                ff.close();
//                cout << "数据库已同步更新" << endl;
//            };break;
//            case 3: {
//                cout << "请输入借阅者姓名: " << endl;
//                string username;
//                cin >> username;
//                books.book[ret].BookUserName = username;
//                fstream fff;
//                fff.open("bookInfo.dat");
//                string fl[MAX_FILE];
//                int line = 0;
//                string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
//                if (fff.is_open()) {
//                    while (true) {
//                        fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
//                        if (temp_name != name_yuan) {
//                            fl[line] = temp_name + white_space;
//                            fl[line] += temp_isbn;
//                            fl[line] += white_space;
//                            fl[line] += temp_public;
//                            fl[line] += white_space;
//                            fl[line] += temp_username;
//                            fl[line] += white_space;
//                            fl[line] += temp_userid;
//                            fl[line] += white_space;
//                            fl[line] += temp_date;
//                            line++;
//                        } else {
//                            fl[line] = temp_name + white_space;
//                            fl[line] += temp_isbn;
//                            fl[line] += white_space;
//                            fl[line] += temp_public;
//                            fl[line] += white_space;
//                            fl[line] += username;
//                            fl[line] += white_space;
//                            fl[line] += temp_userid;
//                            fl[line] += white_space;
//                            fl[line] += temp_date;
//                            line++;
//                        }
//                        if (fff.eof()) {
//                            break;
//                        }
//                    }
//                }
//                fff.close();
//                fstream ff;
//                ff.open("bookInfo.dat", ios::out | ios::trunc);
//                if (ff.is_open()) {
//                    for (int i = 0; i < line; ++i)
//                    {
//                        ff << fl[i];
//                        if (i != line - 1)
//                            ff << endl;
//                    }
//                } else {
//                    cout << "orz" << endl;
//                }
//                ff.close();
//                cout << "数据库已同步更新" << endl;
//            };
//                break;
//            case 4: {
//                cout << "请输入借阅者学号: " << endl;
//                string usernum;
//                cin >> usernum;
//                books.book[ret].BookUserID = usernum;
//                fstream fff;
//                fff.open("bookInfo.dat");
//                string fl[MAX_FILE];
//                int line = 0;
//                string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
//                if (fff.is_open()) {
//                    while (true) {
//                        fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
//                        if (temp_name != name_yuan) {
//                            fl[line] = temp_name + white_space;
//                            fl[line] += temp_isbn;
//                            fl[line] += white_space;
//                            fl[line] += temp_public;
//                            fl[line] += white_space;
//                            fl[line] += temp_username;
//                            fl[line] += white_space;
//                            fl[line] += temp_userid;
//                            fl[line] += white_space;
//                            fl[line] += temp_date;
//                            line++;
//                        } else {
//                            fl[line] = temp_name + white_space;
//                            fl[line] += temp_isbn;
//                            fl[line] += white_space;
//                            fl[line] += temp_public;
//                            fl[line] += white_space;
//                            fl[line] += temp_username;
//                            fl[line] += white_space;
//                            fl[line] += usernum;
//                            fl[line] += white_space;
//                            fl[line] += temp_date;
//                            line++;
//                        }
//                        if (fff.eof()) {
//                            break;
//                        }
//                    }
//                }
//                fff.close();
//                fstream ff;
//                ff.open("bookInfo.dat", ios::out | ios::trunc);
//                if (ff.is_open()) {
//                    for (int i = 0; i < line; ++i)
//                    {
//                        ff << fl[i];
//                        if (i != line - 1)
//                            ff << endl;
//                    }
//                } else {
//                    cout << "orz" << endl;
//                }
//                ff.close();
//                cout << "数据库已同步更新" << endl;
//            };break;
//            case 5: {
//                cout << "更新借阅日期:" << endl;
//                books.book[ret].BorrowDate = GetDate();
//                fstream fff;
//                fff.open("bookInfo.dat");
//                string fl[MAX_FILE];
//                int line = 0;
//                string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
//                if (fff.is_open()) {
//                    while (true) {
//                        fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
//                        if (temp_name != name_yuan) {
//                            fl[line] = temp_name + white_space;
//                            fl[line] += temp_isbn;
//                            fl[line] += white_space;
//                            fl[line] += temp_public;
//                            fl[line] += white_space;
//                            fl[line] += temp_username;
//                            fl[line] += white_space;
//                            fl[line] += temp_userid;
//                            fl[line] += white_space;
//                            fl[line] += temp_date;
//                            line++;
//                        } else {
//                            fl[line] = temp_name + white_space;
//                            fl[line] += temp_isbn;
//                            fl[line] += white_space;
//                            fl[line] += temp_public;
//                            fl[line] += white_space;
//                            fl[line] += temp_username;
//                            fl[line] += white_space;
//                            fl[line] += temp_userid;
//                            fl[line] += white_space;
//                            fl[line] += GetDate();
//                            line++;
//                        }
//                        if (fff.eof()) {
//                            break;
//                        }
//                    }
//                }
//                fff.close();
//                fstream ff;
//                ff.open("bookInfo.dat", ios::out | ios::trunc);
//                if (ff.is_open()) {
//                    for (int i = 0; i < line; ++i)
//                    {
//                        ff << fl[i];
//                        if (i != line - 1)
//                            ff << endl;
//                    }
//                } else {
//                    cout << "orz" << endl;
//                }
//                ff.close();
//                cout << "借阅日期已更新至" << GetDate() << endl;
//                cout << "数据库已同步更新" << endl;
//            };break;
//            case 6: {
//                cout << "是否可用: " << endl;
//                bool use; cout << "是否可用：1.是  0.否" << endl;
//                cin >> use;
//                books.book[ret].CanUse = use;};break;
//            case 7: {
//                cout << "请输入出版社： " << endl;
//                string pub;
//                cin >> pub;
//                books.book[ret].ISBN = pub;
//                fstream fff;
//                fff.open("bookInfo.dat");
//                string fl[MAX_FILE];
//                int line = 0;
//                string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
//                if (fff.is_open()) {
//                    while (true) {
//                        fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
//                        if (temp_name != name_yuan) {
//                            fl[line] = temp_name + white_space;
//                            fl[line] += temp_isbn;
//                            fl[line] += white_space;
//                            fl[line] += temp_public;
//                            fl[line] += white_space;
//                            fl[line] += temp_username;
//                            fl[line] += white_space;
//                            fl[line] += temp_userid;
//                            fl[line] += white_space;
//                            fl[line] += temp_date;
//                            line++;
//                        } else {
//                            fl[line] = temp_name + white_space;
//                            fl[line] += temp_isbn;
//                            fl[line] += white_space;
//                            fl[line] += pub;
//                            fl[line] += white_space;
//                            fl[line] += temp_username;
//                            fl[line] += white_space;
//                            fl[line] += temp_userid;
//                            fl[line] += white_space;
//                            fl[line] += temp_date;
//                            line++;
//                        }
//                        if (fff.eof()) {
//                            break;
//                        }
//                    }
//                }
//                fff.close();
//                fstream ff;
//                ff.open("bookInfo.dat", ios::out | ios::trunc);
//                if (ff.is_open()) {
//                    for (int i = 0; i < line; ++i)
//                    {
//                        ff << fl[i];
//                        if (i != line - 1)
//                            ff << endl;
//                    }
//                } else {
//                    cout << "orz" << endl;
//                }
//                ff.close();
//                cout << "数据库已同步更新" << endl;
//        };break;
//        }
//    }
//    else {
//        cout << "查无此书" << endl;
//    }
//
//}
//
//void ShowBook(ArrayBooks &books) {
//    if (books.length == 0) {
//        cout << "书架为空" << endl;
//    }
//    else {
//        string a, b, c, d, e, f;
//        a = "书名";
//        b = "ISBN";
//        c = "出版社";
//        d = "借阅人姓名";
//        e = "借阅人学号";
//        f = "借阅日期";
//        cout << left <<setw(GetWidth(WIDE, a))<<a
//            <<setw(GetWidth(WIDE, b))<<left<<b
//            <<setw(GetWidth(WIDE, c))<<left<<c
//            //        <<setw(wide)<<left<<"借阅情况"
//            <<setw(GetWidth(WIDE, d))<<left<<d
//            <<setw(GetWidth(WIDE, e))<<left<<e
//            <<setw(GetWidth(WIDE, f))<<left<<f<<endl;
//        for (int i = 0; i < books.length; ++i) {
//            cout << setw(GetWidth(WIDE, books.book[i].BookName)) <<left<< books.book[i].BookName
//                 <<setw(GetWidth(WIDE, books.book[i].ISBN))<<left<<books.book[i].ISBN
//                 <<setw(GetWidth(WIDE, books.book[i].PublicCompany))<<left<<books.book[i].PublicCompany;
//            if(books.book[i].IsBorrowed){
////                cout<<setw(wide)<<left<<"借阅中"
//                cout<<setw(GetWidth(WIDE, books.book[i].BookUserName))<<left<<books.book[i].BookUserName
//                    <<setw(GetWidth(WIDE, books.book[i].BookUserID))<<left<<books.book[i].BookUserID
//                    <<setw(GetWidth(WIDE, books.book[i].BorrowDate))<<left<<books.book[i].BorrowDate;
//            }
//            else {
////                cout << setw(wide)<<left << "空闲中";
//            }
//            cout << endl;
//        }
//    }
//}
//
//void BackBook(ArrayBooks &books)
//{
//    cout << "输入你要归还的图书" << endl;
//    string name;
//    cin >> name;
//    int ret = isExist(books, name);
//    if (ret != -1) {
//        bool borrowed = false;
//        books.book[ret].IsBorrowed = borrowed;
//        string username="NULL";
//        books.book[ret].BookUserName = username;
//        string usernum = "NULL";
//        books.book[ret].BookUserID = usernum;
//        string date = "NULL";
//        books.book[ret].BorrowDate = date;
//
//        fstream fff;
//        fff.open("bookInfo.dat");
//        string fl[MAX_FILE];
//        int line = 0;
//        string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
//        if (fff.is_open()) {
//            while (true) {
//                fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
//                if (temp_name != name) {
//                    fl[line] = temp_name + white_space;
//                    fl[line] += temp_isbn;
//                    fl[line] += white_space;
//                    fl[line] += temp_public;
//                    fl[line] += white_space;
//                    fl[line] += temp_username;
//                    fl[line] += white_space;
//                    fl[line] += temp_userid;
//                    fl[line] += white_space;
//                    fl[line] += temp_date;
//                    line++;
//                } else {
//                    fl[line] = temp_name + white_space;
//                    fl[line] += temp_isbn;
//                    fl[line] += white_space;
//                    fl[line] += temp_public;
//                    fl[line] += white_space;
//                    fl[line] += username;
//                    fl[line] += white_space;
//                    fl[line] += usernum;
//                    fl[line] += white_space;
//                    fl[line] += date;
//                    line++;
//                }
//                if (fff.eof()) {
//                    break;
//                }
//            }
//        }
//        fff.close();
//        fstream ff;
//        ff.open("bookInfo.dat", ios::out | ios::trunc);
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
//        cout << "数据库已同步更新" << endl;
//
//    }
//}
//
//void LookUpBook(ArrayBooks &books)
//{
//    cout << "请选择查找方法：1.书名查找   2.ISBN号查找 " << endl;
//    int t;cin >> t;
//    switch (t) {
//        case 1: {cout << "输入你要查找的图书" << endl;
//            string name;
//            cin >> name;
//            int ret = isExist(books, name);
//            if (ret != -1) {
//                cout << "书籍名字 ： " << books.book[ret].BookName << "\t";
//                cout << "书的借阅情况 ： " << books.book[ret].IsBorrowed << "\t";
//                cout << "借阅者姓名 ： " << books.book[ret].BookUserName << "\t";
//                cout << "借阅者学号 ： " << books.book[ret].BookUserID << "\t";
//                cout << "书ISBN号 ： " << books.book[ret].ISBN << "\t";
//                cout << "借阅日期 ： " << books.book[ret].BorrowDate << "\t";
//                cout << " 是否可用：1.是  0.否 " << "  " << books.book[ret].CanUse << endl;
//            }};
//            break;
//        case 2: {cout << "输入你要查找的图书的ISBN号" << endl;
//            string num;
//            cin >> num;
//            int ret = isnumExist(books, num);
//            if (ret != -1) {
//                cout << "书籍名字 ： " << books.book[ret].BookName << "\t";
//                cout << "书的借阅情况 ： " << books.book[ret].IsBorrowed << "\t";
//                cout << "借阅者姓名 ： " << books.book[ret].BookUserName << "\t";
//                cout << "借阅者学号 ： " << books.book[ret].BookUserID << "\t";
//                cout << "书ISBN号 ： " << books.book[ret].ISBN << "\t";
//                cout << "借阅日期 ： " << books.book[ret].BorrowDate << "\t";
//                cout << " 是否可用：1.是  0.否 " << "  " << books.book[ret].CanUse << endl;
//            }};
//            break;
//    }
//}
//
//int outSystem() {
//    cout << "欢迎下次使用" << endl;
//    return 0;
//};
//
//#endif //TOTAL_MZH_H
