#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std ;

void displayString(char string[], char ans[]){
    int endIndex = strlen(string);
    for (int index = 0; index < endIndex; index++){
        if(string[index] >= 97 && string[index] != ' ')  {
            ans[index] = tolower(ans[index]);
        }
        // printf("%d = %c\n",index,string[index]);
    }
    printf("String output is %s\n", ans);
}

void setData(char key[], char string[]){
    printf("Enter string: ");
    scanf("%[^\n]s", string); fflush(stdin);

    printf("Enter key string: ");
    scanf("%s", key);

}

void encryption(char key[], char plainText[]){
    int index = 0;
    int round = 0;

    int keyLen = strlen(key);
    int endIndex = strlen(plainText) - 1;
    char cipherText[strlen(plainText)];

    do{
        if(plainText[index] == ' '){
            cipherText[index] = ' ';
            index++;
            continue;
        }
        if(round >= keyLen){
            round = 0;
        }
    int m = toupper(plainText[index]) - 65;
    int k = toupper(key[round++]) - 65;
    int c = (m + k) % 26; 
    cipherText[index++] = (char)(c + 65);
    }while (index <= endIndex);
    displayString(plainText, cipherText);
}

void decryption(char key[], char cipherText[]){
    int index = 0;
    int round = 0;

    int keyLen = strlen(key);
    int endIndex = strlen(cipherText) - 1;
    char plainText[strlen(cipherText)];

    do{
        if(cipherText[index] == ' '){
            plainText[index] = ' ';
            index++;
            continue;
        }
        if(round >= keyLen){
            round = 0;
        }
    int m = toupper(cipherText[index]) - 65;
    int k = toupper(key[round++]) - 65;
    int c;
    if(m - k >= 0){
        c = (m - k);
    } else {
        int sum = k - m;
        c = (26 - sum);
    }
    plainText[index++] = (char)(c + 65); 
    }while (index <= endIndex);
    displayString(cipherText, plainText);
}

int main(){

    char type = 'E';
    char string[100];
    char key[] = {'S','E','S','A','M','E'};
    const char alphabet[]  = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    //                       {'G','O','Y','D','S','I','P','E','L','U','A','V','C','R','J','W','X','Z','N','H','B','Q','F','T','M','K'};

    printf("Welcome to the Vigenère Cipher \n");

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