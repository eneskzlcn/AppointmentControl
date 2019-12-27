#include "stringOps.h"
#include <stdlib.h>
#include <stdio.h>
/*
 * @filename stringOps.c
 * @description The program is writed for help a psychologist to control his appointments in a basic way
 * @assignment Homework II
 * @date 25.12.2019
 * @author Nazif Enes Kızılcin //nazifeneskizilcin@stu.fsm.edu.tr
 */
int lengthOfString(char * string){//girilen stringin lengthini bulur.
    int length = 0;
    while(*string != '\0'){
        ++length;
        ++string;
    }
    return length;
}
int areStringsSame(char * string1,char * string2){//Girilen stringler ayniysa 1 farkliysa 0 dondurur
    int areSame = 1;
    int string1Length = lengthOfString(string1);
    int string2Length = lengthOfString(string2);
    if(string1Length != string2Length){//eger lengthleri farkliysa kalan kontrolleri yapmaya gerek yok
        areSame = 0;
        return areSame;
    }
    while((*string1) != '\0'){
        if((*string1) != (*string2)){
            areSame = 0;
            break;
        }
        ++string1; //pointerlari arttirarak donuyoruz
        ++string2;
    }
    return areSame;
}
char * stringCopy(char * string){//bir kere gerek var mi ona bak gerek varsa da calisiyormu ona bak
    int upperLimit = lengthOfString(string);
    char * newString =calloc(upperLimit, sizeof(char));
    int i = 0;
    for(i=0;i<upperLimit;i++){
        newString[i] = string[i];
    }
    return newString;
}
char * splitByIndex(char * string,int firstIndex,int lastIndex){//Girilen string in girilen ilk ve son indis arasindaki kismini dondurur.
    char * newString = calloc(lastIndex-firstIndex+1, sizeof(char));
    int i = 0;
    int j = 0;
    for (i = firstIndex;  i<= lastIndex; i++) {
        *(newString+j) = *(string+i);
        j++;
    }

    return newString;
}
char * splitByChar(char * string,char splitChar){//Girilen stringin girilen chara denk gelene kadar olan kismi dondurur.
    int i =0;
    char  *newString = calloc(30, sizeof(char));
    while(i<lengthOfString(string)){
        if((*(string+i)) == splitChar){
            break;
        }
        else{
            (*(newString+i)) = (*(string+i));
        }
        ++i;
    }
    return newString;
}
int stringToInt(char * string){ //Verilen stringi inte ceviriyor. Eger bir sayi formatinda degilse 0 dondurur.
    int menuOption = 0;
    if(isNumber(string)){
        menuOption = atoi(string);
    }
    return menuOption;
}
int isNumber(char * string){ //girilen string sayi mi onu kontrol eder.
    int isValid = 1;
    int length = lengthOfString(string);
    int i = 0;
    while(i<length){
        if((int)(*(string+i)) < 48 || (int)(*(string+i)) > 57){
            isValid=0;
        }
        ++i;
    }
    return isValid;
}
void printMenuOptions(int cases){//Menu okunurlugunu kolaylastirmak adına tasarlandi. Case 1 icin Ana Menu case 2 icinse Randevu Aradaki secenekler printleniyor.
    switch(cases){
        case 1:
            printf("\n\n1.Show All Appointments\n");
            printf("2.Search Appointment(2.1 ...By Name,2.2 ... By Day\n");
            printf("3.Give Appointment \n");
            printf("4.Delete Appointment \n");
            printf("5.Exit \n");
            break;
        case 2:
            printf("\n2.1.Search By Name\n");
            printf("2.2.Search By Day\n");
            printf("2.3.Turn Back To Menu\n");
            break;
    }
}

