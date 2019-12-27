#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Date.h"
/*
 * @filename Appointment.h
 * @description The program is writed for help a psychologist to control his appointments in a basic way
 * @assignment Homework II
 * @date 25.12.2019
 * @author Nazif Enes Kızılcin //nazifeneskizilcin@stu.fsm.edu.tr
 */

typedef struct Appointment{
    int hour;
    char * patientName;
    Days day;
}Appointment;

void printAllAppointments(); //Butun randevulari bastirir...
void writeAppointment(Appointment);//Dosyaya bir randevu yazar;
void printAppointmentByName(); // Girilen hasta adina sahip randevuyu ekrana basar.
void printAppointmentByDay(); // Girilen gundeki randevulari ekrana basar
void printAppointmentFormatted(Appointment); // Parametre olarak verilen randevuyu ekrana formatli sekilde yazar.
int deleteAppointment(char *); //Bir randevuyu siliyor.Eger bir randevu silindiyse 1 silinmediyse 0 donduruyor
char * readNameFromString(char *); // Verilen bir stringden isim olusturur.fgets den donen string formatina gore tasarlanmis bir metot.Her string icin calismaz.
int readDayFromString(char *,int); //Verilen bir stringden gun olusturur.fgets den donen string  formatina gore tasarlanmis bir metot.Her string icin calismaz
int  readHourFromString(char *,int);//Verilen bir stringden gun olusturur. fgets den donen string  formatina gore tasarlanmis bir metot.Her string icin calismaz
Appointment readAppointmentFromStr(char*); // Verilen bir stringden bir randevu olusturur. fgets den donen string  formatine gore tasarlanmis metot.Her string icin calismaz.
void giveAppointment();//Girilen randevu degerlerine gore eger mumkunse randevuyu alır ve kaydeder.
void cancelAppointment();//Girilen parametreler ile silme islemini gerceklesitiriyor.

#endif
