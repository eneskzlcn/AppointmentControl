
#ifndef FILEOPS_H
#define FILEOPS_H
#include <stdio.h>
#include <stdlib.h>
/*
 * @filename fileOps.h
 * @description The program is writed for help a psychologist to control his appointments in a basic way
 * @assignment Homework II
 * @date 25.12.2019
 * @author Nazif Enes Kızılcin //nazifeneskizilcin@stu.fsm.edu.tr
 */


int isDocNull(FILE *f);//Dosya null sa 1 degilse 0 dondurur
void printfFNullFaultAndExit();//Null bir dosyaya rastlandiginda cagiriliyor.Hata mesajı basarak programdan cikiliyor.
#endif
