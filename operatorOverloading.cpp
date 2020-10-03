#include <iostream>
#include <string>

using namespace std;

class MyString{
    string mainString;

    public:
    MyString(string s) : mainString{s}{};
    MyString() : mainString{""}{};

    MyString operator-(){
        string temp{};
        for (char i : mainString){
            temp += tolower(i);
        };
        MyString t{temp};
        return t;
    };
    string getString()const{
        return mainString;
    };

    int getSize()const{
        return mainString.size();
    };

    bool operator==(const MyString &rhs){
        return (this->mainString == rhs.mainString);
    };
    bool operator!=(const MyString &rhs){
        return (this->mainString != rhs.mainString);
    };
    bool operator<(const MyString &rhs){
        if (this->mainString == rhs.mainString)return false;
        if (this->getSize() > rhs.getSize())return false;
        if (this->getSize() < rhs.getSize())return true;

        for (int i{};i<rhs.getSize();i++){
            if (rhs.mainString[i] > this->mainString[i])
            return true;

        };
        return false;
    }
    MyString &operator=(string &&rhs){
        this->mainString = rhs;
        return *this;
    };
    MyString operator+(const MyString &rhs){
        MyString temp;
        temp = (this->mainString + rhs.mainString);
        return temp;
    };

    MyString &operator+=(const MyString &rhs){
   *this = *this + rhs;
   return *this;
    };
    MyString &operator*(const int &rhs){
        string temp{this->mainString};
        for (int i{1};i<rhs;i++){
            *this +=  temp;
            
        };
       
        return *this;
    };
    MyString &operator *=(const int &rhs){
        (*this) = (*this) * rhs;
        return *this;
    }




};

ostream &operator<<(ostream &os,const MyString &rhs){
    os << rhs.getString() ;
    return os;
}


int main(){
    cout << boolalpha;
    cout << "----------------------------------------------------------------" << endl;
    cout << "TESTING UNARY -" << endl;
    MyString test{"ARYAMANN"};
    cout << test  << endl;
    cout << "Location of test -> " << &test << endl;
    cout << "Changing to lowercase..." << endl;
    MyString test2;
    test2 = -test;
    cout << "Location of test2 -> " << &test2 << endl;
    cout << test2  <<endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "TESTING ==" << endl;
    MyString test3{"aryamann"};
    MyString test4{"aryamann"};
    cout << "Test3 -> " << test3 << endl;
    cout << "Test4 -> " << test4  << endl;
    bool result{test3 == test4};
    cout << "Equal ? (3 and 4)" << result << endl;
    MyString test5{"ningombam"};
    cout << "Test5 -> " << test5  << endl;
    result = (test4 == test5);
    cout << "Equal ? (4 and 5) " << result << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "TESTING != " << endl;
    cout << "Test3 -> " << test3  << endl;
    cout << "Test4 -> " << test4  << endl;
    result = (test3!=test4);
    cout << "Not Equal ? (3 and 4) " << result << endl;
    cout << "Test5 -> " << test5  << endl;
    result = test5!=test3;
    cout << "Not Equal ? (5 and 3) " << result << endl;

    cout << "----------------------------------------------------------------" << endl;
    cout << "TESTING  < " << endl;
    test3 = "Aryamann";
    test4 = "aryamann";
    cout << test4  << " < " << test3  << "?" << endl;
    result = (test4 < test3);
    cout << result << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "TESTING +" << endl;
    cout << "Test4 -> " << test4 << endl;
    cout << "Test3 ->" << test3 << endl;
     cout << "Concatenation..." << endl;

     test4 = test4+test3;
     cout << test4 << endl;
    
    
    cout << "----------------------------------------------------------------" << endl;
    cout << "TESTING  += " << endl;
    cout << "Test4 -> " << test4 << endl;
    cout << "Test3 -> " << test3 << endl;
    test4 += test3;
    cout << "After using +=" << endl;
    cout << "Test4 -> ";
    cout << test4 << endl;
 cout << "----------------------------------------------------------------" << endl;
    cout << "TESTING *" << endl;
    test4 = "test";
    cout << "Test4 -> " << test4 << endl; 
    cout << "Using test4 = test4*4" << endl;
    test4 = test4 * 4;
    cout << test4 << endl;
    cout << "Using temp..." << endl;
    MyString temp;
    temp = test3*4;
    cout <<temp << endl;

cout << "----------------------------------------------------------------" << endl;

cout << "TESTING *=  " << endl;
test4 = "test";
cout << "Test4-> " <<test4 << endl;
cout << "Using *=4 " << endl;
test4 *=4;
cout << "Test4 -> " << test4 << endl;

 cout << "----------------------------------------------------------------" << endl;

    return 0;
};
