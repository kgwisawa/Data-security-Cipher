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

void setData(char key[], char string[]){
    printf("Enter string: ");
    scanf("%[^\n]s", string); fflush(stdin);

    printf("Enter key string [A-Z]: ");
    scanf("%s", key);

}

void encryption(char key[], char plainText[]){
    int index = 0;
    int endIndex = strlen(plainText) - 1;
    char cipherText[strlen(plainText)];

    do{
        if(plainText[index] == ' '){
            cipherText[index] = ' ';
            index++;
            continue;
        }
    int position =  toupper(plainText[index]) - 65;
    cipherText[index] = toupper(key[position]);
    index++;
    }while (index <= endIndex);
    displayString(plainText, cipherText);
}

void decryption(char key[], char cipherText[]){
    int index = 0;
    int endIndex = strlen(cipherText) - 1;
    char plainText[strlen(cipherText)];

    do{
        if(cipherText[index] == ' '){
            plainText[index] = ' ';
            index++;
            continue;
        }
    for(int position = 0; position < 26; position++){
        if (toupper(cipherText[index]) == toupper(key[position])){
            plainText[index] = (char)('A' + position);
        }
    }     
    index++;
    }while (index <= endIndex);
    displayString(cipherText, plainText);
}

int main(){

    char type = 'E';
    char string[100];
    char key[26] = {'G','O','Y','D','S','I','P','E','L','U','A','V','C','R','J','W','X','Z','N','H','B','Q','F','T','M','K'};
    const char alphabet[]  = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    //                       {'G','O','Y','D','S','I','P','E','L','U','A','V','C','R','J','W','X','Z','N','H','B','Q','F','T','M','K'};

    printf("Welcome to A Mono-alphabetic Substitution Cipher\n");

    do{
    printf("Enter type (E/D): ");
    scanf("%c", &type); fflush(stdin);
    } while(type != 'E' && type != 'D');

    switch (type){
        case 'E' : 
            setData(key , string);
            encryption(key, string); break;
        case 'D' : 
            setData(key , string);
            decryption(key, string); break;
        default:
            printf("Error");
            break;
    }
    
    return 0;
}