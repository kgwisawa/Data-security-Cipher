#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cmath> 
using namespace std;

void removeSpace(string *textInput){
    int count = 0;
    string text = *textInput;
    string ans ;
    for (int i = 0; text[i]; i++)
        if (text[i] != ' ')
            ans.push_back(text[i]); 
    *textInput = ans;
}

string inputString (string *textInput) {
    string text;
    cout << "Enter string: " ;
    getline(cin,text);
    *textInput = text;
    return text ;
}

void inputSecretKey (string textInput,string key[]) {
    int n = textInput.length();
    cout << "Enter key string ("<<n<< " bits): " ;

    for(int i = 0 ; i < n ; i++) {
            cin >> key[i] ;   
    }
}

string textToBits (char textInput) {
   
    int decimal, binary = 0, remainder, product = 1;
    int textDecimal ; 
    textDecimal = (textInput - 65) ;    

    while (textDecimal != 0) {
    remainder = textDecimal % 2;
    binary = binary + (remainder * product);
    textDecimal = textDecimal / 2;
    product *= 10;
    }
    string textBits =  to_string(binary);
    
    int len = textBits.length();
                                                //00101 01100 10101
    while(len < 5){
        textBits.insert(textBits.begin(), '0');
        len = textBits.length();
    }
    
     return textBits ;
}

int bitToDecimal(string decimal) { 

    int decimalNum=0 ;

    for(int i = 4; i >= 0 ; i--){
        if(decimal[i] == '1') {
            decimalNum += pow(2,4-i) ;
        }
    }
    
    return decimalNum ;
}

void encrypt(string textInput,string textCopy,string key[]) {

    string textBits[textInput.length()] ; 
    string result[textInput.length()] ; 

    for(int i = 0 ; i < textInput.length() ; i++) {
        textBits[i] = textToBits(textInput[i]);
    }


    for(int i = 0 ; i < textInput.length() ; i++) {
        for(int j = 0 ; j < 5 ; j++) {
            if(textBits[i][j] == key[i][j]) {
                result[i].push_back('0') ;
            }
            else if(textBits[i][j] != key[i][j]) {
                result[i].push_back('1') ;
            }
        }
    }
    
    int dec;
    string final ;
    cout << "String output is " ;

    for(int i = 0,j = 0 ; i < textCopy.length() ; i++) {
      if(textCopy[i] == ' '){
            final.push_back(' ');
      } else {
       dec = bitToDecimal(result[j++]);
       final.push_back(dec +65);   
      }
    }
        cout << final ;
    

}

void decrypt (string textInput,string textCopy,string key[]) {
    string textBits[textInput.length()] ; 
    string result[textInput.length()] ; 

    for(int i = 0 ; i < textInput.length() ; i++) {
        textBits[i] = textToBits(textInput[i]);
    }


    for(int i = 0 ; i < textInput.length() ; i++) {
        for(int j = 0 ; j < 5 ; j++) {
            if(textBits[i][j] != key[i][j]) {
                result[i].push_back('1') ;
            }
            else if(textBits[i][j] == key[i][j]) {
                result[i].push_back('0') ;
            }
        }
    }
    
    int dec;
    string final ;
    cout << "String output is " ;

    for(int i = 0,j = 0 ; i < textCopy.length() ; i++) {
      if(textCopy[i] == ' '){
            final.push_back(' ');
      } else {
       dec = bitToDecimal(result[j++]);
       final.push_back(dec +65);   
      }
    }
        cout << final ;
}

int main() {   

    char type ;
    string textInput ,textCopy ;
    
    cout << "Welcome to A One-time Pad" << endl ;

    do{
        cout << "Enter type (E/D): " ;
        cin >> type ;
        cin.ignore();

    }while(toupper(type)  != 'E' && toupper(type) != 'D');

    textCopy =  inputString(&textInput);
    removeSpace(&textInput) ;
    string key[textInput.length()];
    switch (type)
    {
    case 'E': 
        inputSecretKey(textInput,key);
        encrypt(textInput,textCopy,key);
        break;
    
    case 'D':
        inputSecretKey(textInput,key);
        decrypt(textInput,textCopy,key);
        break;
    }
        cout << "" << endl ;
    return 0;
}