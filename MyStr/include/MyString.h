#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <string>
#include <ostream>
using namespace std;
class MyString {
private:
    char* data;
    int len;

public:
    MyString(const char* str = nullptr);
    MyString(const std::string& str);
    MyString(const MyString& other);
    MyString(MyString&& other);
    ~MyString();

    int length() const;
    char* get() const;

    MyString operator+(const MyString& other) const;
    MyString operator-(const MyString& other) const;
    MyString operator*(int n) const;
    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other);
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator>=(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    MyString operator!() const;
    char operator[](int index) const;
    bool operator()(const char* substr) const;
    friend istream&operator>>(istream& is,  MyString& str);
    friend ostream&operator<<(ostream& os, const MyString& str);

};


#endif
