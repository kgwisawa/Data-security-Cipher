#include <stdio.h>
#include <stdbool.h>
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

void setData(int *key , char string[]){
    printf("Enter string: ");
    scanf("%[^\n]s", string);

    int data;
    printf("Enter key: ");
    scanf("%d", &data); 
    *key = data;
}

void encryption(int key, char plainText[]){
    int index = 0;
    int endIndex = strlen(plainText) - 1;
    char cipherText[strlen(plainText)];

    do{
        if(plainText[index] == ' '){
            cipherText[index] = ' ';
            index++;
            continue;
        }
    int m = toupper(plainText[index]) - 65;
    int c = (m + key) % 26; 
    cipherText[index] = (char)(c + 65);
    index++;
    }while (index <= endIndex);
    displayString(plainText, cipherText);
}

void decryption(int key, char cipherText[]){
    int index = 0;
    int endIndex = strlen(cipherText) - 1;
    char plainText[strlen(cipherText)];

    do{
        if(cipherText[index] == ' '){
            plainText[index] = ' ';
            index++;
            continue;
        }
    int m = toupper(cipherText[index]) - 65;
    int c;
    if(m - key >= 0){
        c = (m - key);
    } else {
        int sum = key - m;
        c = (26 - sum);
    }
    plainText[index] = (char)(c + 65);
    index++;
    }while (index <= endIndex);
    displayString(cipherText, plainText);
}

int main(){

    int key;
    char type;
    char string[100];

    printf("Welcome to the Caesar Cipher\n");

    do{
    printf("Enter type (E/D): ");
    scanf("%c", &type); fflush(stdin);
    } while(type != 'E' && type != 'D');
 
    switch (type){
    case 'E' : 
        setData(&key , string);
        encryption(key, string); break;
    case 'D' : 
        setData(&key , string);
        decryption(key, string); break;
    default:
        printf("Error");
        break;
    }

    return 0;
}