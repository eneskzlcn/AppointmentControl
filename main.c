#include <stdio.h>
#include "stringOps.h"
#include "Appointment.h"
#include "Date.h"
/*
 * @filename main.c
 * @description The program is writed for help a psychologist to control his appointments in a basic way
 * @assignment Homework II
 * @date 25.12.2019
 * @author Nazif Enes Kızılcin //nazifeneskizilcin@stu.fsm.edu.tr
 */

int main(){
    int mainMenuOption = 0;
    int menuOption = 0;
    char tempString[20];
    while(mainMenuOption != 5){
        printMenuOptions(1);//Ana menu seceneklerini yazar.case:11
        gets(tempString);
        mainMenuOption = stringToInt(tempString);
        switch(mainMenuOption){
            case 0:
                printf("\nWrong Menu Option!. Turning Back To Menu\n");
                break;
            case 1:
                printAllAppointments();
                break;
            case 2:
                while(menuOption != 3){
                printMenuOptions(2); //Arama menusu seceneklerini yazar case:2
                gets(tempString);
                menuOption = stringToInt(tempString);
                switch(menuOption){
                    case 0:
                        printf("Wrong Menu Option!.Turning Back To Search Menu\n");
                        break;
                    case 1:
                        printAppointmentByName();
                        break;
                    case 2:
                        printAppointmentByDay();
                        break;
                    case 3:
                        printf("\n Turning Back To Main Menu\n");
                        menuOption=3;
                        break;
                }
                }
                menuOption = 0;
                break;
            case 3:
                giveAppointment();
                break;
            case 4:
                cancelAppointment();
                break;
            case 5:{
                mainMenuOption = 5;
                break;
            }
        }
    }
    return 0;
}
