#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
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

void removeSpacesFromStr(char *string)
{
    int non_space_count = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != ' ')
        {
            string[non_space_count] = string[i];
            non_space_count++;
        }    
    }
    string[non_space_count] = '\0';
}

void prepareData(int numberOfKey,char string[],char ans[]){

    const char alphabet[]  = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    removeSpacesFromStr(string);
    // printf("\nsum = %s\n",string);
    int endIndex = strlen(string);
    int ansIndex = endIndex;
    int spaces = 0;
    if(endIndex % numberOfKey != 0){
        spaces = numberOfKey - (endIndex % numberOfKey);
        ansIndex = endIndex+spaces;
    }
    
    int round = 1;
    int position = 0;
    int sumSpaces = (ansIndex / numberOfKey) - 1;
    ansIndex += sumSpaces;
    // printf("\nsumSpaces = %d",sumSpaces);
    char ansString[ansIndex]; 

    for (int index = 0; index < endIndex;){
        if(round > numberOfKey){
        ansString[position++] = ' ';
        round = 1;
        }else {
        ansString[position++] = string[index++];
        round++;
        } 
    }

    for (; position < ansIndex; position++){
        ansString[position] = alphabet[rand() % 26];
    }

    strcpy(ans,ansString);
    // printf("\nlen(ansString) = %d",strlen(ansString));
    printf("\nsum = %s\n",ans);
}

void setData(int *numberOfKey , char ans[]){
    printf("Enter string: ");
    char string[500];
    scanf("%[^\n]s", string);

    int data;
    printf("Enter a number of key: ");
    scanf("%d", &data); 
    *numberOfKey = data;

    prepareData(data, string, ans);


}

void setKeyPosition(int numberOfKey, int key[]){

    printf("Enter a set of keys: ");
    for(int index = 0; index < numberOfKey; index++){
    int data;
    scanf("%d", &data);
    key[index] = data;
    }

    // for(int index = 0; index < numberOfKey; index++){
    // printf("%d = %d\n",index+1,key[index]);
    // }
}

void encryption(int numberOfKey, char plainText[]){
    int index = 0;
    int round = 0;
    // printf("\nsum = %s\n",plainText);

    int endIndex = strlen(plainText) - 1;
    char cipherText[strlen(plainText)];

    int key[numberOfKey];
    setKeyPosition(numberOfKey, key);

    do{
        if(plainText[index] == ' '){
            cipherText[index] = ' ';
            index++;
            continue;
        }
        round = 0;
        for(int position = index; round < numberOfKey;round++){
            cipherText[position+key[round]-1] = plainText[index++];
        } 
    }while (index <= endIndex);
    displayString(plainText, cipherText);
}

void decryption(int numberOfKey, char cipherText[]){
    int index = 0;
    int round = 0;

    int endIndex = strlen(cipherText) - 1;
    char plainText[strlen(cipherText)];

    int key[numberOfKey];
    setKeyPosition(numberOfKey, key);

    do{
        if(cipherText[index] == ' '){
            plainText[index] = ' ';
            index++;
            continue;
        }
        round = 0;
        for(int position = index; round < numberOfKey;round++){
            plainText[position+key[round]-1] = cipherText[index++];
        } 
    }while (index <= endIndex);
    displayString(cipherText, plainText);
}

int main(){

    int numberOfKey;
    char type = 'E';
    char string[100];

    printf("Welcome to A Permutation Cipher \n");

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