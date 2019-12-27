#include "Date.h"
#include "stringOps.h"
#include <stdio.h>
#include "fileOps.h"
#include "Appointment.h"
/*
 * @filename Date.c
 * @description The program is writed for help a psychologist to control his appointments in a basic way
 * @assignment Homework II
 * @date 25.12.2019
 * @author Nazif Enes Kızılcin //nazifeneskizilcin@stu.fsm.edu.tr
 */
                    //Buradaki dizileri asagidaki fonksiyonlarda tekrar tekrar yazmamak,kod tekrari yapmamak adina global olarak olusturdum.
char  * day1 = "Monday";
char  * day2 = "Tuesday";
char  * day3 = "Wednesday";
char  * day4 = "Thursday";
char  * day5= "Friday";
char  * day6 = "Saturday";
char  * day7 = "Sunday";
int isHourValid(int hour){//calisma saatlerimiz sabah 8 aksam 5 :) Randevular bu aralikta olmali.Bunu kontrol eden fonk.
    int isValid = 1;
    if(hour > 17 || hour < 8){
        isValid = 0;
    }
 return isValid;
}
int convertDayToNumber(char * day){ //String olan gun degerini ornegin "Monday" int degerine yani haftanin 1.gunu oldugundan 1 degerine ceviriyor.
    int dayToInt = 0;
    if(areStringsSame(day,day1)){
        dayToInt =Monday;
    }
    else if(areStringsSame(day,day2)){
        dayToInt = Tuesday;
    }
    else if(areStringsSame(day,day3)){
        dayToInt = Wednesday;
    }
    else if(areStringsSame(day,day4)){
        dayToInt = Thursday;
    }
    else if(areStringsSame(day,day5)){
        dayToInt = Friday;
    }
    else if(areStringsSame(day,day6)){
        dayToInt = Saturday;
    }
    else if(areStringsSame(day,day7)){
        dayToInt = Sunday;
    }
    else{
        dayToInt = 10; // Bu esitleme sayesinde eger 10 sa yalnis bir input alinmis...
    }

    return dayToInt;
}
char * convertNumberToDay(int dayToInt){//Int olarak tuttugumuz gun degerini kullaniciya string dondurebilmek icin. Ornegin 1-Monday,2-Tuesday donusumleri
    char * whichDay = calloc(10, sizeof(char));
    if(dayToInt ==Monday){
        whichDay = day1;
    }
    else if(dayToInt == Tuesday){
        whichDay = day2;
    }
    else if(dayToInt == Wednesday){
        whichDay = day3;
    }
    else if(dayToInt == Thursday){
        whichDay = day4;
    }
    else if(dayToInt == Friday){
        whichDay = day5;
    }
    else if(dayToInt == Saturday){
        whichDay = day6;
    }
    else if(dayToInt == Sunday){
        whichDay = day7;
    }
    return whichDay;
}
int isDateFree(int day, int hour){
    FILE * f;
    f = fopen("C:\\Users\\DELL\\Desktop\\bpPsikologProject\\randevular.txt","r");
    int isFree = 1;
    while(!feof(f)){
        Appointment app;
        char * tempString = calloc(20, sizeof(char));
        fgets(tempString,20,f);
        app = readAppointmentFromStr(tempString);//Bu fonksiyonla randevuyu dosyadan okuyor
        if(app.day == day){ // eger gun ayni degilse saati kontrol etmeye gerek yok. Bu yuzden once dayi kontrol ediyoruz.
            if(app.hour == hour){ //eger saatte ayniysa bos degil yani isFree = 0 atamasi yapiliyor
                isFree = 0;
                break;
            }
        }
    }
    return isFree;

}