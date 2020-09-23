#include <iostream>
#include <string>
#include <vector>

using namespace std;





//Prototypes; For keeping main code at the top.
string encryptThis(string);
string decryptThis(string);
string convertDashesToSpaces(string);
string convertSpacesToDashes(string);

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
    //If user enters invalid input;
    if (input!=1 && input!=2){cout << "INVALID" << endl;return 0;}
    else {
        bool toEncrypt{input==1};
        cout << "NOTE :DO NOT use signs like '#!\"' as this would cause a decryption problem." << endl;
        cout << "Enter the message to " << ((toEncrypt) ? " encrypt " :  " decrypt ") << " : ";
        cin.ignore();
        getline(cin,inputFromUser);

        message = ((toEncrypt)? encryptThis(inputFromUser) : decryptThis(inputFromUser));
        cout << "Your " << ((toEncrypt) ? " encrypted " : " decrypted ") << " message is : " << endl;
        //Returning the encrypted||decrypted message according the to the requirement of the user;
        
        cout << "-----------------------------" << endl;
        cout <<'"' <<  message << '"' << endl;
        cout << "-----------------------------" << endl;
        cout << "Thanks!" << endl;
    };
    
}


//============================================================
//ENCRYPTION/DECRYPTION;
//Function to encrypt the given string;
string encryptThis(string message){
message = convertSpacesToDashes(message);
string encryptedMessage{};
int counter{1};
 //Boolean value set to decide whether to increment or decrement;
bool reverse{false};
for( char i : message){
    //If counter reaches 10 start incrementing/decrementing the char's ASCII value from 1 again; This number can be increased or decreased
    //to increase 
    //or decrease 
    // the difficulty of decryption;
    if (counter>5){
        counter = 1;
        };
    //Incrementing/Decrementing the ASCII value of the char ; Increment if reverse is false  || Decrement if reverse is true;
    encryptedMessage += ((reverse)?char(int(i)-counter):char(int(i)+counter));
    //Changing the value of reverse to increment or decrement alternatively;
    reverse = !reverse;
    //Incrementing counter to increment/decrement one more than the previous character; Would be set back to 1 when counter reaches 10;
    counter++;
};
return encryptedMessage;

}


//Function to decrypt the given string;
string decryptThis(string message){
    
    string decryptedMessage{};
    int counter{1};
    //Boolean value set to decide whether to increment or decrement; This is set opposite to the value of encryption;
    bool reverse{true};
    for( char i : message){
        
       //Same logic as before
    if (counter>5){
        counter = 1;
        }
    decryptedMessage += ((reverse)?char(int(i)-counter):char(int(i)+counter));
    reverse = !reverse;
    counter++;
};

return convertDashesToSpaces(decryptedMessage);
}

//====================================================

//CONVERSIONS;
string convertDashesToSpaces(string s){
string stringToReturn{};

for (auto i : s){
    if (i=='-'  || i=='_')stringToReturn+=" ";
    else stringToReturn+=i;
};
return stringToReturn;

}
string convertSpacesToDashes(string s){
    string stringToReturn{};
    for (auto i:s){
        if (i==' ')stringToReturn+='_';
        else stringToReturn+=i;
    };
    return stringToReturn;
}
