#include <iostream>
#include <string>

using namespace std;
string returnReverse(long int);
string returnReverseString(string s);
int main(){
    cout << boolalpha;
    long int number{};
    cout << "Enter the number you want to reverse : ";
    cin >> number;
    cout << "The number after reversing it is : ";
    cout <<  returnReverse(number) << endl;;
    return 0;
}





string returnReverse(long int number){
string numberToString{to_string(number)};
bool isNumberNegative{};
isNumberNegative = (numberToString[0] == '-');
numberToString = ((isNumberNegative) ? numberToString.substr(1) : numberToString);
numberToString = returnReverseString(numberToString);
if (isNumberNegative)numberToString  = '-' + numberToString;

return numberToString;

}

string returnReverseString(string s){
string reversedString{};
long int i{};
for (i = s.size()-1;i>-1;i--){
    reversedString += s[i];
}



for (i=0;i<reversedString.size();i++){
    if (reversedString[i]=='0'){
            continue;
    }else break;
}
reversedString = reversedString.substr(i);


return reversedString;
}
