//
// Created by 骆明宇 on 2022/12/20.
//

#ifndef INC_221202C___MZHOOP_H
#define INC_221202C___MZHOOP_H
#define MAXX 10000
#define WIDEE 23
#define MAXX_FILE 10000

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include "functions.h"
#include "time.h"

using namespace std;

class Books {
private:
    string BookName;
    string ISBN;
    string PublicCompany;
    string BookUserName;
    bool IsBorrowed;
    string BookUserID;
    string BorrowDate;
    bool CanUse;
public:
    void ImportBook(string &BookName_temp, string &ISBN_temp, string &PublicCompany_temp, string &BookUserName_temp,
                    string &BookUserID_temp, string &BorrowDate_temp) {
        BookName = BookName_temp;
        ISBN = ISBN_temp;
        PublicCompany = PublicCompany_temp;
        BookUserName = BookUserName_temp;
        if (BookUserID_temp != "NULL") IsBorrowed = true;
        else IsBorrowed = false;
        BookUserID = BookUserID_temp;
        BorrowDate = BorrowDate_temp;
        CanUse = true;};
    string GetBookName() {return BookName;};
    string GetISBN() {return ISBN;};
    string GetPublicCompany() {return PublicCompany;};
    string GetBookUserName() {return BookUserName;};
    bool GetIsBorrowed() {return IsBorrowed;};
    string GetBookUserID() {return BookUserID;};
    string GetBorrowDate() {return BorrowDate;};
    bool GetCanUse() {return CanUse;};
    void SetBookName(string t) {BookName = t;};
    void SetISBN(string t) {ISBN = t;};
    void SetPublicCompany(string t) {PublicCompany = t;};
    void SetBookUserName(string t) {BookUserName = t;};
    void SetIsBorrowed(bool t) {IsBorrowed = t;};
    void SetBookUserID(string t) {BookUserID = t;};
    void SetBorrowDate(string t) {BorrowDate = t;};
    void SetCanUse(bool t) {CanUse = t;};
};

class BookSystem: public Books {
    void InitBooks();
    Books book[MAXX];
    int length;
public:
    BookSystem() {
        length = 0;
        InitBooks();
    }
    void ImportBook();
    int IsExist(string &name);
    int IsNumExist(string &num);
    void OutBook(string id, string name);
    void WriteFileADD(string &BookName_temp, string &ISBN_temp, string &PublicCompany_temp,
                      string &BookUserName_temp, string &BookUserID_temp, string BorrowDate_temp);
    void Rewrite(string fl[], int line);
    void UnableBook();
    void DeleteBook();
    void FixBook();
    void ShowBook();
    void BackBook();
    void LookUpBook();
};


void BookSystem::InitBooks(){
    long long n;
    ifstream fin;
    fin.open("bookInfo.dat");
    if (fin.is_open()) {
        for (int i = 0;;i++){
            string BookName_temp, ISBN_temp, PublicCompany_temp, BookUserName_temp, BookUserID_temp, BorrowDate_temp;
            fin >> BookName_temp >> ISBN_temp >> PublicCompany_temp >> BookUserName_temp >>BookUserID_temp >> BorrowDate_temp;
            book[length++].ImportBook(BookName_temp, ISBN_temp, PublicCompany_temp, BookUserName_temp,
                                      BookUserID_temp, BorrowDate_temp);
            if (fin.eof())
            {
                cout << "图书系统共初始化" << length <<"本书，初始化完毕。"<< endl;
                break;
            }
        }
        fin.close();
        string a = "BookSystemInitSuccess", b = "NULL", c = "NULL";
        log(a, b, c);
    } else {
        string a = "BookSystemInitFailed", b = "NULL", c = "NULL";
        log(a, b, c);
        cout << "bookInfo.dat文件打开失败" << endl;
    }
}

void BookSystem::ImportBook() {
    if (length >= MAXX) {
        cout << "书籍已满" << endl;
    }
    else {
        string null = "NULL";
        string name; cout << "请输入书籍的名字: " << endl; cin >> name;
        string num; cout << "请输入书ISBN号： " << endl; cin >> num;
        string publicCompany_temp; cout << "请输入出版社： " << endl; cin >> publicCompany_temp;
        string date = GetDate();
        book[length++].ImportBook(name, num, publicCompany_temp, null, null, null);
        cout << "导入日期：" << date <<endl;
        cout << "添加成功" << endl;
        WriteFileADD(name, num, publicCompany_temp, null, null, null);
    }
}

int BookSystem::IsExist(string &name) {
    for (int i = 0; i < length; ++i) {
        if (book[i].GetBookName() == name) {
            return i;
        }
    }
    return -1;
}

int BookSystem::IsNumExist(string &num) {
    for (int i = 0; i < length; ++i) {
        if (book[i].GetISBN() == num) {
            return i;
        }
    }
    return -1;
}

void BookSystem::OutBook(string id, string name) {
    string bookname;
    cout << "输入你要借阅的图书" << endl;
    cin >> bookname;
    int ret = IsExist(bookname);
    if (ret != -1) {
        book[ret].SetBookUserName(name);
        book[ret].SetBookUserID(id);
        book[ret].SetIsBorrowed(true);
        book[ret].SetBorrowDate(GetDate());
        cout << "借阅成功" << endl;
        stringstream ss;
        fstream fff;
        fff.open("bookInfo.dat");
        string fl[MAXX_FILE];
        int line = 0;
        string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
        if (fff.is_open()) {
            while (true) {
                fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
                if (temp_name != bookname) {
                    ss << temp_name << " " << temp_isbn << " " << temp_public << " " << temp_username << " " <<
                    temp_userid << " " << temp_date;
                    fl[line++] = ss.str();
                } else {
                    ss << temp_name << " " << temp_isbn << " " << temp_public << " " << name << " " <<
                    id << " " << GetDate();
                    fl[line++] = ss.str();
                }
                if (fff.eof()) {
                    break;
                }
            }
        }
        Rewrite(fl, line);
        string a = "BookSystemOutBookSuccess", b = id, c = name;
        log(a, b, c);
    } else {
        cout << "查无此书" << endl;
        string a = "BookSystemOutBookFailed-Error:BookNameNotExist", b = id, c = name;
        log(a, b, c);
    }
}

void BookSystem::WriteFileADD(string &BookName_temp, string &ISBN_temp, string &PublicCompany_temp,
                              string &BookUserName_temp, string &BookUserID_temp, string BorrowDate_temp) {
    ofstream fff;
    fff.open("bookInfo.dat", ios::app);
    fff << endl << BookName_temp << " " << ISBN_temp << " " << PublicCompany_temp << " " << BookUserName_temp << " " <<
    BookUserID_temp << " " << BorrowDate_temp;
    fff.close();
    cout << "数据库添加成功" << endl;
}

void BookSystem::Rewrite(string fl[], int line) {
    fstream ff;
    ff.open("bookInfo.dat", ios::out | ios::trunc);
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

void BookSystem::UnableBook() {
    cout << "请输入要标记不可用图书" << endl;
    string name;
    cin >> name;
    int ret = IsExist(name);
    if (ret != -1) {
        cout <<"已标记为不可用" << endl;
        string a = "BookSystemUnableBookSuccess", b = name, c = "NULL";
        log(a, b, c);
        book[ret].SetCanUse(false);
    } else {
        cout << "查无此书" << endl;
        string a = "BookSystemUnableBookFailed-Error:BookNameNotExist", b = name, c = "NULL";
        log(a, b, c);
    }
}

void BookSystem::DeleteBook() {
    cout << "请输入你要删除的书籍" << endl;
    string name;
    cin >> name;

    int ret = IsExist(name);
    if (ret != -1) {
        for (int i = 0; i < length; ++i) {
            book[ret].SetBookName(book[i + 1].GetBookName());
            book[ret].SetISBN(book[i + 1].GetISBN());
            book[ret].SetBookUserName(book[i + 1].GetBookUserName());
            book[ret].SetIsBorrowed(book[i + 1].GetIsBorrowed());
            book[ret].SetBookUserID(book[i + 1].GetBookUserID());
            book[ret].SetBorrowDate(book[i + 1].GetBorrowDate());
            book[ret].SetCanUse(book[i + 1].GetCanUse());
            length--;
        }

        fstream fff;
        fff.open("bookInfo.dat");
        string fl[MAXX_FILE];
        stringstream ss;
        int line = 0;
        string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
        if (fff.is_open()) {
            while (true) {
                fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
                if (temp_name != name) {
                    ss << temp_name << " " << temp_isbn << " " << temp_public << " " << temp_username << " " <<
                       temp_userid << " " << temp_date;
                    fl[line++] = ss.str();
                }
                if (fff.eof()) {
                    break;
                }
            }
        }
        fff.close();
        Rewrite(fl, line);
        string a = "BookSystemDeleteBookSuccess", b = name, c = "NULL";
        log(a, b, c);
    }
    else {
        cout << "查无此书" << endl;
        string a = "BookSystemDeleteBookFailed-Error:BookNameNotExist", b = name, c = "NULL";
        log(a, b, c);
    }
}

void BookSystem::FixBook() {
    stringstream ss;
    cout << "输入你要修改的图书" << endl;
    string name_yuan;
    cin >> name_yuan;
    int ret = IsExist(name_yuan);
    if (ret != -1) {
        cout << "请输入要修改的内容：1.书名 2.书ISBN号 3.借阅者姓名 4.借阅者学号 5.借阅日期 6.是否可用 7.出版社" << endl;
        int m;cin >> m;
        switch (m) {
            case 1: {
                cout << "请输入修改后名字： " << endl;
                string name;
                cin >> name;
                book[ret].SetBookName(name);
                fstream fff;
                fff.open("bookInfo.dat");
                string fl[MAXX_FILE];
                int line = 0;
                string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
                if (fff.is_open()) {
                    while (true) {
                        fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
                        if (temp_name != name_yuan) {
                            ss << temp_name << " " << temp_isbn << " " << temp_public << " " << temp_username << " " <<
                               temp_userid << " " << temp_date;
                            fl[line++] = ss.str();
                        } else {
                            ss << name << " " << temp_isbn << " " << temp_public << " " << temp_username << " " <<
                               temp_userid << " " << temp_date;
                            fl[line++] = ss.str();
                        }
                        if (fff.eof()) {
                            break;
                        }
                    }
                }
                fff.close();
                Rewrite(fl, line);
            };
                break;
            case 2: {
                cout << "请输入书ISBN号： " << endl;
                string num;
                cin >> num;
                book[ret].SetISBN(num);
                fstream fff;
                fff.open("bookInfo.dat");
                string fl[MAXX_FILE];
                int line = 0;
                string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
                if (fff.is_open()) {
                    while (true) {
                        fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
                        if (temp_name != name_yuan) {
                            ss << temp_name << " " << temp_isbn << " " << temp_public << " " << temp_username << " " <<
                               temp_userid << " " << temp_date;
                            fl[line++] = ss.str();
                        } else {
                            ss << temp_name << " " << num << " " << temp_public << " " << temp_username << " " <<
                               temp_userid << " " << temp_date;
                            fl[line++] = ss.str();
                        }
                        if (fff.eof()) {
                            break;
                        }
                    }
                }
                Rewrite(fl, line);
            };break;
            case 3: {
                cout << "请输入借阅者姓名: " << endl;
                string username;
                cin >> username;
                book[ret].SetBookUserName(username);
                fstream fff;
                fff.open("bookInfo.dat");
                string fl[MAXX_FILE];
                int line = 0;
                string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
                if (fff.is_open()) {
                    while (true) {
                        fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
                        if (temp_name != name_yuan) {
                            ss << temp_name << " " << temp_isbn << " " << temp_public << " " << temp_username << " " <<
                               temp_userid << " " << temp_date;
                            fl[line++] = ss.str();
                        } else {
                            ss << temp_name << " " << temp_isbn << " " << temp_public << " " << username << " " <<
                               temp_userid << " " << temp_date;
                            fl[line++] = ss.str();
                        }
                        if (fff.eof()) {
                            break;
                        }
                    }
                }
                fff.close();
                Rewrite(fl, line);
            };
                break;
            case 4: {
                cout << "请输入借阅者学号: " << endl;
                string usernum;
                cin >> usernum;
                book[ret].SetBookUserID(usernum);
                fstream fff;
                fff.open("bookInfo.dat");
                string fl[MAXX_FILE];
                int line = 0;
                string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
                if (fff.is_open()) {
                    while (true) {
                        fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
                        if (temp_name != name_yuan) {
                            ss << temp_name << " " << temp_isbn << " " << temp_public << " " << temp_username << " " <<
                               temp_userid << " " << temp_date;
                            fl[line++] = ss.str();
                        } else {
                            ss << temp_name << " " << temp_isbn << " " << temp_public << " " << temp_username << " " <<
                            usernum << " " << temp_date;
                            fl[line++] = ss.str();
                        }
                        if (fff.eof()) {
                            break;
                        }
                    }
                }
                fff.close();
                Rewrite(fl, line);
            };break;
            case 5: {
                cout << "更新借阅日期:" << endl;
                book[ret].SetBorrowDate(GetDate());
                fstream fff;
                fff.open("bookInfo.dat");
                string fl[MAXX_FILE];
                int line = 0;
                string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
                if (fff.is_open()) {
                    while (true) {
                        fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
                        if (temp_name != name_yuan) {
                            ss << temp_name << " " << temp_isbn << " " << temp_public << " " << temp_username << " " <<
                            temp_userid << " " << temp_date;
                            fl[line++] = ss.str();
                        } else {
                            ss << temp_name << " " << temp_isbn << " " << temp_public << " " << temp_username << " " <<
                               temp_userid << " " << GetDate();
                            fl[line++] = ss.str();
                        }
                        if (fff.eof()) {
                            break;
                        }
                    }
                }
                fff.close();
                Rewrite(fl, line);
                cout << "借阅日期已更新至" << GetDate() << endl;
            };break;
            case 6: {
                cout << "是否可用: " << endl;
                bool use; cout << "是否可用：1.是  0.否" << endl;
                cin >> use;
                book[ret].SetCanUse(use);};break;
            case 7: {
                cout << "请输入出版社： " << endl;
                string pub;
                cin >> pub;
                book[ret].SetISBN(pub);
                fstream fff;
                fff.open("bookInfo.dat");
                string fl[MAXX_FILE];
                int line = 0;
                string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
                if (fff.is_open()) {
                    while (true) {
                        fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
                        if (temp_name != name_yuan) {
                            ss << temp_name << " " << temp_isbn << " " << temp_public << " " << temp_username << " " <<
                               temp_userid << " " << temp_date;
                            fl[line++] = ss.str();
                        } else {
                            ss << temp_name << " " << temp_isbn << " " << pub << " " << temp_username << " " <<
                               temp_userid << " " << temp_date;
                            fl[line++] = ss.str();
                        }
                        if (fff.eof()) {
                            break;
                        }
                    }
                }
                fff.close();
                Rewrite(fl, line);
            };break;
        }
    }
    else {
        cout << "查无此书" << endl;
    }
}

void BookSystem::ShowBook() {
    if (length == 0) {
        cout << "书架为空" << endl;
    }
    else {
        string a, b, c, d, e, f;
        a = "书名";
        b = "ISBN";
        c = "出版社";
        d = "借阅人姓名";
        e = "借阅人学号";
        f = "借阅日期";
        cout << left <<setw(Function::GetWidth(WIDEE, a))<<a
             <<setw(Function::GetWidth(WIDEE, b))<<left<<b
             <<setw(Function::GetWidth(WIDEE, c))<<left<<c
             <<setw(Function::GetWidth(WIDEE, d))<<left<<d
             <<setw(Function::GetWidth(WIDEE, e))<<left<<e
             <<setw(Function::GetWidth(WIDEE, f))<<left<<f<<endl;
        for (int i = 0; i < length; ++i) {
            cout << setw(Function::GetWidth(WIDEE, book[i].GetBookName())) <<left<< book[i].GetBookName()
                 <<setw(Function::GetWidth(WIDEE, book[i].GetISBN()))<<left<<book[i].GetISBN()
                 <<setw(Function::GetWidth(WIDEE, book[i].GetPublicCompany()))<<left<<book[i].GetPublicCompany();
            if(book[i].GetIsBorrowed()){
                cout<<setw(Function::GetWidth(WIDEE, book[i].GetBookUserName()))<<left<<book[i].GetBookUserName()
                    <<setw(Function::GetWidth(WIDEE, book[i].GetBookUserID()))<<left<<book[i].GetBookUserID()
                    <<setw(Function::GetWidth(WIDEE, book[i].GetBorrowDate()))<<left<<book[i].GetBorrowDate();
            }
            cout << endl;
        }
    }
}

//void BookSystem::ShowBook() {
//    if (length == 0) {
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
//        cout << left <<setw(WIDEE)<<a
//             <<setw(WIDEE)<<left<<b
//             <<setw(WIDEE)<<left<<c
//             <<setw(WIDEE)<<left<<d
//             <<setw(WIDEE)<<left<<e
//             <<setw(WIDEE)<<left<<f<<endl;
//        for (int i = 0; i < length; ++i) {
//            cout << setw(WIDEE) <<left<< book[i].GetBookName()
//                 <<setw(WIDEE)<<left<<book[i].GetISBN()
//                 <<setw(WIDEE)<<left<<book[i].GetPublicCompany();
//            if(book[i].GetIsBorrowed()){
//                cout<<setw(WIDEE)<<left<<book[i].GetBookUserName()
//                    <<setw(WIDEE)<<left<<book[i].GetBookUserID()
//                    <<setw(WIDEE)<<left<<book[i].GetBorrowDate();
//            }
//            cout << endl;
//        }
//    }
//}

void BookSystem::BackBook()
{
    stringstream ss;
    cout << "输入你要归还的图书" << endl;
    string name;
    cin >> name;
    int ret = IsExist(name);
    if (ret != -1) {
        bool borrowed = false;
        string null = "NULL";
        book[ret].SetIsBorrowed(borrowed);
        book[ret].SetBookUserName(null);
        book[ret].SetBookUserID(null);
        book[ret].SetBorrowDate(null);

        fstream fff;
        fff.open("bookInfo.dat");
        string fl[MAXX_FILE];
        int line = 0;
        string temp_name, temp_isbn, temp_public, temp_username, temp_userid, temp_date, white_space = " ";
        if (fff.is_open()) {
            while (true) {
                fff >> temp_name >> temp_isbn >> temp_public >> temp_username >> temp_userid >> temp_date;
                if (temp_name != name) {
                    ss << temp_name << " " << temp_isbn << " " << temp_public << " " << temp_username << " " <<
                       temp_userid << " " << temp_date;
                    fl[line++] = ss.str();
                } else {
                    ss << temp_name << " " << temp_isbn << " " << temp_public << " " << null << " " <<
                    null << " " << null;
                    fl[line++] = ss.str();
                }
                if (fff.eof()) {
                    break;
                }
            }
        }
        fff.close();
        Rewrite(fl, line);
        string a = "BookSystemOutBookSuccess", b = name, c = "NULL";
        log(a, b, c);
    } else {
        cout << "查无此书" << endl;
        string a = "BookSystemBackBookFailed-Error:BookNameNotExist", b = name, c = "NULL";
        log(a, b, c);
    }
}

void BookSystem::LookUpBook()
{
    cout << "输入你要查找的图书的关键字，支持模糊查找" << endl;
    string a;
    cin >> a;
    string aa, b, c, d, e, f;
    aa = "书名";
    b = "ISBN";
    c = "出版社";
    d = "借阅人姓名";
    e = "借阅人学号";
    f = "借阅日期";
    cout << left << setw(Function::GetWidth(WIDEE, a)) << aa
         << setw(Function::GetWidth(WIDEE, b)) << left << b
         << setw(Function::GetWidth(WIDEE, c)) << left << c
         << setw(Function::GetWidth(WIDEE, d)) << left << d
         << setw(Function::GetWidth(WIDEE, e)) << left << e
         << setw(Function::GetWidth(WIDEE, f)) << left << f << endl;
    for (int i = 0; i < length; ++i){
        if (Function::FuzzySearch(book[i].GetISBN(), a) || Function::FuzzySearch(book[i].GetBookName(), a) ||
        Function::FuzzySearch(book[i].GetBookUserName(), a) || Function::FuzzySearch(book[i].GetPublicCompany(), a)) {
            cout << setw(Function::GetWidth(WIDEE, book[i].GetBookName())) << left << book[i].GetBookName()
                 << setw(Function::GetWidth(WIDEE, book[i].GetISBN())) << left << book[i].GetISBN()
                 << setw(Function::GetWidth(WIDEE, book[i].GetPublicCompany())) << left << book[i].GetPublicCompany();
            if (book[i].GetIsBorrowed()) {
                cout << setw(Function::GetWidth(WIDEE, book[i].GetBookUserName())) << left << book[i].GetBookUserName()
                     << setw(Function::GetWidth(WIDEE, book[i].GetBookUserID())) << left << book[i].GetBookUserID()
                     << setw(Function::GetWidth(WIDEE, book[i].GetBorrowDate())) << left << book[i].GetBorrowDate();
            }
            cout << endl;
        }
    }
}
#endif //INC_221202C___MZHOOP_H
