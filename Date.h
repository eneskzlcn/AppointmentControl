#ifndef DATE_H
#define DATE_H
#include <stdio.h>
/*
 * @filename Date.h
 * @description The program is writed for help a psychologist to control his appointments in a basic way
 * @assignment Homework II
 * @date 25.12.2019
 * @author Nazif Enes Kızılcin //nazifeneskizilcin@stu.fsm.edu.tr
 */
typedef enum Days{
    Monday = 1,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday
}Days;

int convertDayToNumber(char *); //Kullanicidan aldigimiz stringi Sayiya ceviriyor
char * convertNumberToDay(int); // Girilen Sayiyi 1-Monday,2-Tuesday .... 7-Sunday cevirme islemi;
int isHourValid(int); // Calisma saati 8 - den 17 ye kadar. Bunu kontrol ediyor bu araliktaysa 1 degilse 0 donduruyor.
int isDateFree(int,int); // Parametre olarak girilen gun ve saat degerlerini dosyadaki randevularla karsilastiriyor.Eger o tarih doluysa 0 bossa 1 donduruyor

#endif
