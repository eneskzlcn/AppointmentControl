#ifndef STRINGOPS_H
#define STRINGOPS_H
/*
 * @filename stringOps.h
 * @description The program is writed for help a psychologist to control his appointments in a basic way
 * @assignment Homework II
 * @date 25.12.2019
 * @author Nazif Enes Kızılcin //nazifeneskizilcin@stu.fsm.edu.tr
 */
int areStringsSame(char*,char*);
int lengthOfString(char *);
char * stringCopy(char*);
char * splitByIndex(char *,int,int);
char * splitByChar(char *,char);
int stringToInt(char *);
int isNumber(char*);
void printMenuOptions(int);


#endif