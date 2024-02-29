#include "MyString.h"
#include <cstring>
#include <ostream>

MyString::MyString(const char* String) {
    if (String == nullptr) {
        len = 0;
        data = new char[1];
        data[0] = '\0';
    } else {
        len = strlen(String);
        data = new char[len + 1];
        strcpy(data, String);
    }
}

MyString::MyString(const std::string& str): MyString(str.c_str()) {
}

//todo: there are 2 functions of coping
MyString::MyString(const MyString& other): MyString(other.data) {
}

MyString::MyString(MyString&& other): data(other.data), len(other.len) {
    other.data = nullptr;
    other.len = 0;
}

MyString::~MyString() {
    delete[]data;
}

int MyString::length() const {
    return len;
}

char* MyString::get() const {
    return data;
}

MyString MyString::operator+(const MyString& other) const {
    char* concat_mass = new char[len + other.len + 1];
    strcpy(concat_mass, data);
    strcat(concat_mass, other.data);
    MyString concat_res(concat_mass);
    delete[]concat_mass;
    return concat_res;
} //??????????
MyString MyString::operator-(const MyString& other) const {
    char* result=new char[len+1];
    int count=0;
    for(int i=0;i<len;i++) {
        bool shRem=false;
        for(int j=0;j<other.len;j++) {
            if(data[i]==other[j]) {
                shRem=true;
                break;
            }
        }
        if(!shRem) {
            result[count++]=data[i];
        }
    }
    result[count]='\0';
    MyString res(result);
    delete[]result;
    return res;

}

MyString MyString::operator*(int n) const {
    MyString res;
    for (int i = 0; i < n; i++) {
        res = res + *this;
    }
    return res;
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[]data;
        data = new char[other.len];
        for (int i = 0; i < other.len; i++) {
            data[i] = other[i];
        }
    }
    return *this;
}

MyString& MyString::operator=(MyString&& other) {
    if (this != &other) {
        delete[]data;
        data = other.data;
        len = other.len;
        other.data = nullptr;
        other.len = 0;
    }
    return *this;
}

//todo i dont know which of these operators i need to use in different cases


bool MyString::operator==(const MyString& other) const {
    return strcmp(data, other.data) == 0;
}

bool MyString::operator!=(const MyString& other) const {
    return strcmp(data, other.data) != 0;
}

bool MyString::operator>(const MyString& other) const {
    if (strcmp(data, other.data) > 0)
        return true;
    else
        return false;
}

bool MyString::operator<(const MyString& other) const {
    if (strcmp(data, other.data) < 0)
        return true;
    else
        return false;
}

bool MyString::operator>=(const MyString& other) const {
    if (strcmp(data, other.data) >= 0)
        return true;
    else
        return false;
}

bool MyString::operator<=(const MyString& other) const {
    if (strcmp(data, other.data) <= 0)
        return true;
    else
        return false;
}

MyString MyString::operator!() const {
    char *res=new char[len];
    strcpy(res,data);
    for (int i = 0; i < len; i++) {
        if (islower(res[i])) {
            res[i] = toupper(res[i]);
        } else if (isupper(res[i])) {
            res[i] = tolower(res[i]);
        } else {
            continue;
        }
    }
    MyString result(res);
    delete[]res;
    return result;
}

char MyString::operator[](int index) const {
    return data[index];
}

bool MyString::operator()(const char* substr) const {
    if ((strstr(data, substr)) != NULL)
        return true;
    else
        return false;
}

istream& operator>>(istream& is, MyString& other) {
    char mass[512];
    is >> mass;
    if (other.data != nullptr) {
        delete[]other.data;
    }
    other.data = new char[strlen(mass) + 1];
    strcpy(other.data, mass);
    return is;
}

ostream& operator<<(ostream& os, const MyString& str) {
    os<<str.data;
    return os;
}
