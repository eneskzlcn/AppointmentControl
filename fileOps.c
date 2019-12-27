
#include "fileOps.h"
#include <stdio.h>
#include <stdlib.h>
/*
 * @filename fileOps.c
 * @description The program is writed for help a psychologist to control his appointments in a basic way
 * @assignment Homework II
 * @date 25.12.2019
 * @author Nazif Enes Kızılcin //nazifeneskizilcin@stu.fsm.edu.tr
 */


int isDocNull(FILE * f){
    int isNull = 0;
    if((f = fopen("randevular.txt","r"))==NULL){
            isNull = 1;
        }
    fclose(f);
    return isNull;
}
void printfFNullFaultAndExit(){
    printf("\nThere is a problem about opening the file \n");
    printf("Program is closing...");
    exit(1);
}
