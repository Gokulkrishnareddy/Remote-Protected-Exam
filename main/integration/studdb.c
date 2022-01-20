#include <stdio.h>
#include <string.h>
#define N 1000000
#include "studdb.h"

char checkstu(char *n,char *pass) {
    char name[][40]={"Hrithik","Sandeep"};
    char password[][30]={"12345678","12345678"};
    int index=2;
    char i;
    for(int i=0;i<sizeof(name)/sizeof(name[1]);i++){
        if(strcmp(n,name[i])==0){
            index=0;
            break;}
    }
    if(index>1){
        i='1';
    }
    else{
        if(strcmp(pass,password[index])==0){
            i='0';
        }
        else{
            i='1';
        }
    }
    return i;
}




struct teachers{
    char name[40];
    char password[10];
    char email[20];
};
struct teachers records[]={
            {"Krishnaveni","12345678","kr1234@srmist.edu.in"},
            {"Amudha","12345678","am6789@srmist.edu.in"},
            {"Margatham","12345678","ma1133@srmist.edu.in"}
            };    

int chck_teacher(char* n,char* p){
    int size=sizeof(records)/sizeof(records[0]);
    int index=size+1;
    for(int i=0;i<size;i++){
        if (strcmp(n,records[i].name)==0){
            index=i;
        }
    }
    if(index>size){
        return 0;
        }
    else{
        if(strcmp(p,records[index].password)==0){
             return 1;
        }
        else{
            return 0;
        }
    }
}