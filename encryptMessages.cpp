#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Function to encrypt the given string;
string encryptThis(string message){
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
        }
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
    //If user enters invalid input;
    if (input!=1 && input!=2){cout << "INVALID" << endl;return 0;}
    else {
        bool toEncrypt{input==1};
        //This is a flaw in the program and using spaces in the sentence cannot lead to a successful decryption; Using '-' or '_' would 
        //decrypt successfully;
        cout << "NOTE : Use '-' or '_' instead of spaces to avoid successful decryptions if you're encrypting." << endl;
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
