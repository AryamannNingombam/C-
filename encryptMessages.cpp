#include <iostream>
#include <string>
#include <vector>

using namespace std;

string encryptThis(string message){
string encryptedMessage{};
int counter{1};
bool reverse{false};
for( char i : message){
    if (counter>10){
        counter = 1;
        }
    encryptedMessage += ((reverse)?char(int(i)-counter):char(int(i)+counter));
    reverse = !reverse;
    counter++;
};
return encryptedMessage;

}

string decryptThis(string message){
    string decryptedMessage{};
    int counter{1};
    bool reverse{true};
    for( char i : message){
    if (counter>10){
        counter = 1;
        }
    decryptedMessage += ((reverse)?char(int(i)-counter):char(int(i)+counter));
    reverse = !reverse;
    counter++;
};
return decryptedMessage;
}




int main(){
    string inputFromUser{};
    string tempString{};
    string message{};
    int input{};
    cout << "Enter whether you want to encrypt or decrypt : " <<endl;
    cout << "1. Encrypt"  << endl;
    cout << "2. Decrypt" << endl;
    cout << "Enter your choice : ";
    cin >> input;
    if (input!=1 && input!=2){cout << "INVALID" << endl;return 0;}
    else {
        bool toEncrypt{input==1};
        cout << "NOTE : Use '-' instead of spaces to avoid successful decryptions if you're encrypting." << endl;
        cout << "Enter the message to " << ((toEncrypt) ? " encrypt " :  " decrypt ") << " : ";
        cin.ignore();
        getline(cin,inputFromUser);

        message = ((toEncrypt)? encryptThis(inputFromUser) : decryptThis(inputFromUser));
        cout << "Your " << ((toEncrypt) ? " encrypted " : " decrypted ") << " message is : " << endl;
        cout << "-----------------------------" << endl;
        cout <<'"' <<  message << '"' << endl;
        cout << "-----------------------------" << endl;
        cout << "Thanks!" << endl;
    };
    
}