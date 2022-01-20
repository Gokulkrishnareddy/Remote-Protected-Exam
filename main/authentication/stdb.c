#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 256
#define BUFFER_SIZE 1000
void create();
void view();
void delet();
void modi();
void end();
int wel=0;
struct user{
     char name[50];
     char email[50];
     char password[50];
     char regno[50];
}records[50];
void main1(int a){
  if(a==0)
  printf("\t\t==================Welcome to Pariksha=====================\n");
}

int main(){
  main1(wel);
  wel=2;
  int lines=0;
  FILE *fp;
  fp=fopen("stdb.txt","r");
  int t=1,n;
    
  char ch[50];
  while (fscanf(fp, "%s\t%s\t%s\t%s\n",records[lines].name,records[lines].password,records[lines].email,records[lines].regno) != EOF)
    {
      lines++;
    }
  fclose(fp);
  printf("\nEnter 1 to view existing Details");
  printf("\nEnter 2 to add student Details");
  printf("\nEnter 3 to delete existing Student");
  printf("\nEnter 4 to modify details of a student");
  printf("\nEnter 0 to exit Db");
  printf("\nEnter your choice : ");
  scanf("%d",&t);
  printf("\n");
  switch(t){
    case 1:
        view();
        break;
    case 2:
        create();
        break;
    case 3:
        delet();
        break;
    case 4:
        modi();
        break;
    case 0 :
        end();
        break;
    }
}

// Function for veiwing the data stored in the struct 
void view(){
  int lines=0;
  FILE *fp;
  int j=0;
  fp = fopen("stdb.txt","r");
  while (fscanf(fp, "%s\t%s\t%s\t%s\n",records[lines].name,records[lines].password,records[lines].email,records[lines].regno) != EOF)
    {
      lines++;
    }
  while ( j<lines)
    {
      printf("%d) Username : %s\t Password : %s\t Email : %s\t RollNumber : %s\n\n",j,records[j].name,records[j].password,records[j].email,records[j].regno);
      j++;
    }
  fclose(fp);
  main();
}

//Function for creating 
void create(){
  FILE *fp;
  int lines=0;
  int a;
  int j=0;
  fp = fopen("stdb.txt","r");
  while (fscanf(fp, "%s\t%s\t%s\t%s\n",records[lines].name,records[lines].password,records[lines].email,records[lines].regno) != EOF)
    {
        lines++;
    }
  j=0;
  fclose(fp);
  printf("To go back to menu enter 0 or enter 1 to continue\n");
  printf("Enter Your Choice : ");
  scanf("%d",&a);
  printf("\n");
  if(a==0){
      main();
    }
  else{
  printf("How many students : ");
  scanf("%d",&a);
  for(int i=0;i<a;i++){
	  printf("\nEnter The Student Name: ");
	  scanf("%s",records[lines].name);
    printf("\nEnter The Student Password: ");
	  scanf("%s",records[lines].password);
	  printf("\nEnter The Student Email: ");
	  scanf("%s",records[lines].email);
    printf("\nEnter The Student Rollnumber: ");
	  scanf("%s",records[lines].regno);
    lines++;
    }    
    // updating the new stored data in the struct to the text file 
    fp = fopen("stdb.txt","w");
    while (j<lines)
    {
      fprintf(fp,"%s",records[j].name);
      fprintf(fp,"\t%s",records[j].password);
      fprintf(fp,"\t%s",records[j].email);
      fprintf(fp,"\t%s\n",records[j].regno);
      j++;
      }
      j=0;
    while ( j<lines){
      printf("%d) Username : %s\t Password : %s\t Email : %s\t RollNumber : %s\n\n",j,records[j].name,records[j].password,records[j].email,records[j].regno);
      j++;
      }
    fclose(fp);
	  printf("\nData Added Sucessfully\n");
	  main();}
}

//function to delete data from the txt file 
void delet(){
  int lines=0;
    FILE *fptr1, *fptr2;
    char file1[] ="stdb.txt";
    char file2[] ="test.txt";
    FILE *fp;
    char curr;
    int i=1;
    int j=0;
    int del, line_number = 0;
    fp=fopen("stdb.txt","r");
    while (fscanf(fp, "%s\t%s\t%s\t%s\n",records[lines].name,records[lines].password,records[lines].email,records[lines].regno) != EOF)
    {
      lines++;
    }

    while ( j<lines)
    {
     printf("%d) Username : %s\t Password : %s\t Email : %s\t RollNumber : %s\n\n",i,records[j].name,records[j].password,records[j].email,records[j].regno);
      j++;
      i++;
    }
    fclose(fp);
    j=0;
    i=1;
    lines=0;
    printf("Please enter the line number you want to delete : ");
    scanf("%d", &del);
    fptr1 = fopen(file1,"r");
    fptr2 = fopen(file2, "w");
    curr = getc(fptr1);
    
    lines=0;
    if(curr!=EOF) {line_number =1;}
    while(1){
      if(del != line_number)
        putc(curr, fptr2);
        curr = getc(fptr1);
        if(curr =='\n') line_number++;
        if(curr == EOF) break;
    }
    fclose(fptr1);
    fclose(fptr2);
    remove("stdb.txt");
    rename("test.txt", "stdb.txt");
    fp=fopen("stdb.txt","r");
    while (fscanf(fp, "%s\t%s\t%s\t%s\n",records[lines].name,records[lines].password,records[lines].email,records[lines].regno) != EOF)
    {
      lines++;
    }
    fclose(fp);
    j=0;
    fp=fopen("stdb.txt","w");
    while (j<lines)
    {
    fprintf(fp,"%s",records[j].name);
    fprintf(fp,"\t%s",records[j].password);
    fprintf(fp,"\t%s",records[j].email);
    fprintf(fp,"\t%s\n",records[j].regno);
      j++;
    }j=0;
    fclose(fp);
    printf("\nModified Data is displayed Below  :\n\n\n");
    while ( j<lines)
    {
     printf("%d) Username : %s\t Password : %s\t Email : %s\t RollNumber : %s\n\n",i,records[j].name,records[j].password,records[j].email,records[j].regno);
      j++;
      i++;}
    main();
}

void modi(){
    FILE *fp;
    int i=0,j=0,cho,line;
    char ch[50];
    fp=fopen("stdb.txt","r");
    while (fscanf(fp, "%s\t%s\t%s\t%s\n",records[i].name,records[i].password,records[i].email,records[i].regno) != EOF)
    {
      i++;
    }
    while ( j<i)
    {
      printf("%d) Username : %s\t Password : %s\t Email : %s\t RollNumber : %s\n\n",j,records[j].name,records[j].password,records[j].email,records[j].regno);
      j++;
    }j=0;
    printf("Enter line number : ");
    scanf("%d",&line);
    printf("Enter 1 to change Username\n");
    printf("Enter 2 to change Passsword\n");
    printf("Enter 3 to change Email\n");
    printf("Enter 4 to change RollNumber\n");
    printf("Enter your choice : ");
    scanf("%d",&cho);
    fclose(fp);
    switch(cho){
      case 1:
        printf("Enter your Username : ");
        scanf("%s",records[line].name);
        break;
      case 2:
        printf("\nEnter your Password : ");
        scanf("%s",records[line].password);
        break;
      case 3:
        printf("\nEnter your Email : ");
        scanf("%s",records[line].email);
        break;
      case 4:
        printf("\nEnter your rollnumber : ");
        scanf("%s",records[line].regno);
        break;
    }

    fp=fopen("stdb.txt","w");
    while (j<i)
    {
    fprintf(fp,"%s",records[j].name);
    fprintf(fp,"\t%s",records[j].password);
    fprintf(fp,"\t%s",records[j].email);
    fprintf(fp,"\t%s\n",records[j].regno);
    j++;
    }
    j=0;
    while ( j<i)
    {
      printf("%d) Username : %s\t Password : %s\t Email : %s\t RollNumber : %s\n\n",j,records[j].name,records[j].password,records[j].email,records[j].regno);
      j++;
    }
    fclose(fp);
    main();
}

void end(){
  printf("\n=========================Thank You=============================\n");
  printf("======================For Using Pariksha=======================\n");
}