#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <string>
using namespace std ;

int prepareData(string inputText,string sum[]) {
    string copy = inputText;
    copy.push_back('-');

    int count = 0;
    for(int i = 0 ; i < copy.length() ; i++) {
        if(copy[i] == '-') {
            count++;
        }
    } 
    
    string ans[count];
    int round = 0;

    string text;

    for(int i = 0 ; i < copy.length() ; i++) {
        if(copy[i] != '-') {
            text.push_back(copy[i]);
        } else {
            sum[round++] = text;
            // cout << text << " = " << ans[round] << endl;
            text = "";
            
        }
    } 

    return count ;

}

void inputString(string *inputText) {
    string text;
    getline(cin,text);
    *inputText = text;
}

int findPrivateKey(int coprime , int sum) {

    int privateKey = 2 ;

    while((privateKey * coprime) % sum != 1) {
        privateKey++ ;
    }
    cout << "the private key d is " << privateKey << endl;
    return privateKey ;
}

void encrypt(string inputText,int n , int e) {

    int ans[inputText.length()] ;
    int i ;
    for(i = 0 ; i < inputText.length() ; i++) {
        int plainCode = inputText[i] - 65 ;
        int sum = pow(plainCode,e);
        ans[i] =  sum % n ;
    } 

    for(i = 0 ; i < inputText.length()-1 ; i++) {
        cout << ans[i] << "-";
    } 
        cout << ans[i];

}

int ModularExpo(long long x, unsigned int y, int p)
{
    int res = 1;
 
    x = x % p;
  
    if (x == 0) return 0;
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
            
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

void decrypt(string inputText[],int n , int privateKey,int count) {

    int len = count;
    
    string ans ;
    int i ;
    for(i = 0 ; i < len ; i++) {
        int plainCode = stoi(inputText[i]) ;
        
        int sum = ModularExpo(plainCode,privateKey,n);
        // cout << "sum =" << sum << endl;
        int data = (sum % n) + 65;
        char m = data;
        
        ans.push_back(m);
    } 

    for(i = 0 ; i < ans.length() ; i++) {
        cout << ans[i] ;
    } 
}

int main() {
    int p , q , n , coprime ;
    cout << "Welcome to RSA!" << endl ;
    cout << "Enter prime p: " ; 
    cin >> p ;
    cout << "Enter prime q: " ;
    cin >> q ;  
    n = p*q ;
    cout << "the value of n is " << p << "x" << q <<"= " << n << endl ;

    int sum = (p-1)*(q-1) ;
    int checkGcd = 0 ;

    do{
        if(checkGcd) {
        printf("Sorry! %d is not co-prime of (%d-1)(%d-1)= %d \n" , coprime, p , q ,sum);
        }
        cout << "Enter co-prime e ]1"<<","<<sum<<"[: " ;
        cin >> coprime ;
        cin.ignore();
        checkGcd = 1 ; 
    }while(__algo_gcd(coprime,sum) != 1);


    char type ;

    string inputText ; 

    do{
        cout << "Enter the progress type (E/D): " ;
        cin >> type ;
        cin.ignore();

    }while(toupper(type)  != 'E' && toupper(type) != 'D');

    string cipherCode[200];
    int count ; 
    switch (type)
    {
    case 'E': 
        cout << "Enter the plaintext: " ;
        inputString(&inputText) ;
        encrypt(inputText, n , coprime);
        break;
    
    case 'D':
        cout << "Enter the ciphertext: " ;
        inputString(&inputText) ;
        count = prepareData(inputText,cipherCode); 
        decrypt(cipherCode, n , findPrivateKey(coprime,sum),count);
        break;
    }
        cout << "" << endl ;
    return 0;

}