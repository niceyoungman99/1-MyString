#include <iostream>
#include <ostream>
#include "MyString.h"
using namespace std;
int main() {
    MyString first("test is ");
    cout << first << endl;
    string second = "successfully";
    MyString myS2(second);
    cout << myS2 << endl;
    MyString emptyString;
    cout << emptyString << endl;
    cout << first.length() << endl;
    printf("Pointer: %x", first.get());
    cout<<endl;
    cout << first + myS2 << endl;
    cout<<first-myS2<<endl;
    cout<<first*3<<endl;
    MyString s3="successfullyRes";
    cout << (first == myS2) << endl;
    cout << (first < myS2) << endl;
    cout << (myS2 <= myS2) << endl;
    cout << (s3 <= myS2) << endl;
    cout << !first << endl;
    cout<<first[0]<<endl;
    cout << myS2("full") << endl;
    cout << first("pol") << endl;
    MyString str1;
    cout<<"Give a string:";
    cin >> str1;
    cout << "You've entered:" << str1 << endl;
    return 0;
}