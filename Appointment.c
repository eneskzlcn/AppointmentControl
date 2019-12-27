#include "stringOps.h"
#include "fileOps.h"
#include "Appointment.h"
#include <stdlib.h>
/*
 * @filename Appointment.c
 * @description The program is writed for help a psychologist to control his appointments in a basic way
 * @assignment Homework II
 * @date 25.12.2019
 * @author Nazif Enes Kızılcin //nazifeneskizilcin@stu.fsm.edu.tr
 */

FILE * f;
char * filePath = "randevular.txt";
void printAllAppointments(){ //Dosyadaki tum randevulari bastirir..
    f= fopen(filePath,"r");
    if(!isDocNull(f)){ //null degilse...
        while(!feof(f)){
            Appointment ap;
            char *tempString = calloc(50,sizeof(char)); //Normal char * da olabilirdi ama gets le atama yapabilmek icin size i belli olmasi gerekiyor
            fgets(tempString,40,f);//Dosyadan max 40 bayt ve maximumu 1 satir veri okur.
            ap = readAppointmentFromStr(tempString); //Gonderilen stringin icinden split fonksiyonlariyla ismi,gunu,saati ayirip randevu olarak dondurur.
            printAppointmentFormatted(ap); // parametre olarak girilen randevuyu formatli bir bicimde ekrana basar;
            free(tempString);
        }
    }
    else{
        printfFNullFaultAndExit();
    }

    fclose(f);
}
int deleteAppointment(char * name){
    f= fopen(filePath,"r");
    Appointment * appArray = calloc(50,sizeof(Appointment));//Randevu tutan bir array...
    int i = 0;
    int numberOfApps = 0;
    int whichIndex = 0;//Silme talep edilen randevunun indexini tutmak icin
    int isAnyAppDeleted = 0; //Hic silme islemi yapildimi kontrol amacli.
    if(!isDocNull(f)) {
        while (!feof(f)) {
            Appointment app;
            char *tempString = calloc(30, sizeof(char));
            fgets(tempString, 30, f);
            app = readAppointmentFromStr(tempString);
            if (areStringsSame(name, app.patientName)) {
                whichIndex = i;//silinecek randevu indexi
                isAnyAppDeleted = 1;//silme islemi yapildi...
            }
            (*(appArray + i)) = app;
            i++;
            free(tempString);

        }
    }
    else{
        printfFNullFaultAndExit();
    }
    if(whichIndex != 0) {
        fclose(f);
        numberOfApps = i;
        f = fopen(filePath, "w");
        if (!isDocNull(f)) {
            int rowControl = 1; //sonuncu basilan satirin sonunda \n olmamasini kontrol amacli yazdim.Toplamda 35 tane app varsa biri haric 34 u tekrar yazılcak
            for (i = 0; i <
                        numberOfApps; i++) { // yani eger satirKontrolu her yazildiginda arttirirsam ve 34 oldugunu kontrol edip \n siz bastirirsam sikinti cozulur
                if (i != whichIndex) {
                    Appointment ap = (*(appArray + i));
                    char *name = (*(appArray + i)).patientName;
                    int day = (*(appArray + i)).day;
                    int hour = (*(appArray + i)).hour;
                    if (rowControl != numberOfApps - 1) {
                        fprintf(f, "%s,%d,%d\n", name, day, hour);
                        rowControl++;
                    } else {
                        fprintf(f, "%s,%d,%d", name, day,
                                hour);//son randevuyu basiyoruz o yuzden \n basip bir null randevu olusmasini engelliyoruz.
                    }
                }
            }
        } else {
            printfFNullFaultAndExit();
        }
    }
    else{
        isAnyAppDeleted = 0;
    }
    fclose(f);
    return isAnyAppDeleted;
}
void writeAppointment(Appointment  app){//Dosyaya istenen formatta randevu kaydetme
    f = fopen(filePath,"a");
    if(!isDocNull(f)){
        fprintf(f,"\n%s,%d,%d",app.patientName,app.day,app.hour);
    }
    else{
        printfFNullFaultAndExit();
    }
    fclose(f);
}
void printAppointmentByName(){
    char name[30];
    printf("Input A Name To Search In Current Appointments : ");
    gets(name);
    f = fopen(filePath,"r");
    int isPrinted = 0;//Herhangi bir randevu ekrana bastirildimi.Kontrol amacli.
    if(!isDocNull(f)){
        while(!feof(f)){
            Appointment ap;
            char * tempString = calloc(30, sizeof(char));
            fgets(tempString,30,f);
            ap = readAppointmentFromStr(tempString);
            if(areStringsSame(ap.patientName,name)){//Eger dosyadaki herhangi bir isme esitse printle...
                printAppointmentFormatted(ap);//Formatli olarak ekrana bastir.
                isPrinted = 1;//ekrana basildi
                }
            free(tempString);
        }
    }
    else{
        printfFNullFaultAndExit();
    }
    if(!isPrinted){
        printf("There is no patient saved as this name ! Turning Back To Search Menu");
    }
    fclose(f);
}
void printAppointmentByDay(){//Input olarak alinan isme gore rendevuyu ekrana bastirir
    int day = 0;
    char tempStr[20];
    int isThereAnApp = 0;
    printf("\nEnter A Day To Search In Current Appointments :");
    gets(tempStr);
    day = convertDayToNumber(tempStr); //gun ismi olarak girilen stringi int gune cevirmek amacli...
    if((day <1)|| (day>7)){
        printf("\nYou did not enter a valid day.It must be like(Monday,Tuesday...Sunday). Turning Back To Search Menu");
    }
    else {
        f = fopen(filePath, "r");
        if (!isDocNull(f)) {
            while (!feof(f)) {
                Appointment ap;
                char *tempString = calloc(30, sizeof(char));
                fgets(tempString, 30, f);
                ap = readAppointmentFromStr(tempString); //verilen stringden bir randevu olustur...
                if (ap.day == day) {
                    printAppointmentFormatted(ap);//randevuyu formatli yaz
                    isThereAnApp = 1;
                }
                free(tempString);
            }
        } else {
            fclose(f);
            printfFNullFaultAndExit();
        }
        if(!isThereAnApp){
            printf("\n There Is No Appointment In This Day");
        }
    }
    fclose(f);
}
void printAppointmentFormatted(Appointment app){//saati formatli yazabilmek icin iki basamakliysa basina 0 koyma degilse koy...
    char * dayString;
    dayString = convertNumberToDay(app.day); // Parametre olarak alinan randevunun gununu -> gun ismi seklinde stringe donusturme
    if(app.hour < 10){
        printf("\nThere Is An Appointment Of %s On %s at 0%d:00",app.patientName,dayString,app.hour);
    }
    if(app.hour >10){
        printf("\nThere Is An Appointment Of %s On %s at %d:00",app.patientName,dayString,app.hour);
    }
}
char * readNameFromString(char * row){
    char * name = splitByChar(row,','); // virgule kadar
    return name;
}
int  readDayFromString(char *row,int startIndex){
    char * tempString;
    tempString = splitByIndex(row,startIndex+1,startIndex+5);
    int day = atoi(tempString);
    return day;
}
int  readHourFromString(char *row,int startIndex){
    char * tempString;
    tempString = splitByIndex(row,startIndex+3,startIndex+5);
    int hour = atoi(tempString);
    return hour;
}
Appointment readAppointmentFromStr(char * string){
    Appointment app;
    app.patientName = readNameFromString(string);
    int length = lengthOfString(app.patientName);
    app.day = readDayFromString(string,length);
    app.hour = readHourFromString(string,length);
    return app;
}
void giveAppointment(){
    Appointment app;
    char tempString[30];
    printf("\nInput A Name :");
    gets(tempString);
    app.patientName = stringCopy(tempString);
    printf("\nInput A Day :");
    gets(tempString);
    if(convertDayToNumber(tempString) != 10){
        app.day = convertDayToNumber(tempString);
        printf("\nInput A Hour :");
        gets(tempString);
        int counter = 0;
        if(stringToInt(tempString)==0){
            printf("\n Wrong Hour! Hour Must Be Like (8,9,...17) From 8 To 17. Turning Back To Main Menu");
            counter=1;
        } else{
            if(isHourValid(stringToInt(tempString))){
                app.hour = stringToInt(tempString);
            }
            else{
              printf("Wrong Hour! Hour Must Be (8,9,....17) From 8 To 17. Turning Back To Main Menu");
              counter=1;
            }
        }
        if(!counter){
        if(isDateFree(app.day,app.hour)){
            writeAppointment(app);
            printf("\nAppointment has saved. Turning Back To Main Menu");
        } else{
            printf("\n There Is An Appointment In This Date. Turning Back To Main Menu");
        }
        }
    }
    else{
        printf("\nWrong Day! Day Must Be Like (Monday,Tuesday...Sunday).Turning Back To Menu");
    }

}
void cancelAppointment(){
    char tempString[30];
    printf("\nInput The Name Of The Patient Of The Appointment :");
    gets(tempString);
    if(deleteAppointment(tempString)){
        printf("\nAppointment has deleted succesfully! Turning Back To Menu");
    }
    else{
        printf("\nThere Is No Patient Has This Name. Turning Back To Menu");
    }
}
