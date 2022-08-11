#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std ;

void displayString(char string[], char ans[]){
    int endIndex = strlen(ans);
    for (int index = 0; index < endIndex; index++){
        if(string[index] >= 97 && string[index] != ' ')  {
            ans[index] = tolower(ans[index]);
        }
    }
    printf("String output is %s\n", ans);
}

void setData(int *numberOfKey, char string[]){
    printf("Enter string: ");
    scanf("%[^\n]s", string); fflush(stdin);

    int data;
    printf("Enter a number of keys: ");
    scanf("%d", &data); fflush(stdin);
    *numberOfKey = data;
}

void setKeyString(int numberOfKey, char key[][26]){

    for(int index = 0; index < numberOfKey; index++){
    printf("Enter %d-key string: ",index+1);
    scanf("%s", key[index]); fflush(stdin);
    }
}

void encryption(int numberOfKey, char plainText[]){
    int index = 0;
    int round = 0;

    char key[numberOfKey][26];
    setKeyString(numberOfKey, key);

    int endIndex = strlen(plainText) - 1;
    char cipherText[strlen(plainText)];

    do{
        if(plainText[index] == ' '){
            cipherText[index] = ' ';
            index++;
            continue;
        }
        if(round >= numberOfKey){
            round = 0;
        }
    int position =  toupper(plainText[index]) - 65;
    cipherText[index] = toupper(key[round++][position]);
    index++;
    }while (index <= endIndex);
    displayString(plainText, cipherText);
}

void decryption(int numberOfKey, char cipherText[]){
    int index = 0;
    int round = 0;

    int endIndex = strlen(cipherText) - 1;
    char plainText[strlen(cipherText)];

    char key[numberOfKey][26];
    setKeyString(numberOfKey, key);

    do{
        if(cipherText[index] == ' '){
            plainText[index] = ' ';
            index++;
            continue;
        }
        if(round >= numberOfKey){
            round = 0;
        }

    for(int position = 0; position < 26; position++){
        if (toupper(cipherText[index]) == toupper(key[round][position])){
            plainText[index] = (char)('A' + position);
        }
    } 
    round++;    
    index++;
    }while (index <= endIndex);
    displayString(cipherText, plainText);
}

int main(){

    char type = 'E';
    char string[100];
    int numberOfKey;    
    
    const char alphabet[]  = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    printf("Welcome to A Polyalphabetic Substitution Cipher \n");

    do{
    printf("Enter type (E/D): ");
    scanf("%c", &type); fflush(stdin);
    } while(type != 'E' && type != 'D');



    switch (type){
        case 'E' : 
            setData(&numberOfKey , string);
            encryption(numberOfKey, string); break;
        case 'D' : 
            setData(&numberOfKey , string);
            decryption(numberOfKey, string); break;
        default:
            printf("Error");
            break;
    }
    
    return 0;
}