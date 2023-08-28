#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

typedef struct{
    char code[7];
    char name[50];
    char password[9];
} Teacher;

typedef struct{
    char number[7];
    char name[50];
    char password[9];
} Student;

typedef struct
{
    char serialNumber[13];
    char title[50];
    int stock;
} Book;

Teacher* teachers = NULL;
Student* students = NULL;
Book* books = NULL;

int teacherCount = 0;
int studentCount = 0;
int bookCount = 0;

void init_Library(){

}

void loginMenu(){
    
    int login_Index;
    
    printf("1. Teacher Login\n");
    printf("2. Student Login\n");
    printf("QUIT!\n");
    printf("Enter your choice: ");

    scanf("%d", &login_Index);

    switch (login_Index)
    {
        case 1:
            char enteredCode[7];
            char enteredPassword[9];
            puts("Teacher code: ");
            scanf("%s", enteredCode);
            puts("\nPassword: ");
            scanf("%s", enteredPassword);

            int foundTeacher_Index = -1;
            for (int i = 0; i < teacherCount; i++)
            {
                if (strcmp(enteredCode, teachers[i].code) == 0 && strcmp(enteredPassword, teachers[i].password) == 0)
                {
                    foundTeacher_Index = i;
                    break;
                }
            }
            
            if (foundTeacher_Index != -1)
            {
                puts("\nTeacher login successful!");
                teacherMenu(foundTeacher_Index);
            }
            else{
                puts("\nInvalid teacher code or password!");
            }
            break;

        case 2:
            char enteredNumber[7];
            char enteredPassword[9];
            puts("\nStudent number: ");
            scanf("%s", enteredNumber);
            puts("\nPassword: ");
            scanf("%s", enteredPassword);

            int foundStudent_Index = -1;
            for (int i = 0; i < studentCount; i++) {
                if (strcmp(enteredNumber, students[i].number) == 0 && strcmp(enteredPassword, students[i].password) == 0) {
                    foundStudent_Index = i;
                    break;
                }
            }

            if (foundStudent_Index != -1) {
                printf("Studen Login successful!\n");
                studentMenu(foundStudent_Index);
            } else {
                printf("Invalid student number or password!\n");
            }
            break;

        default:
            puts("\nInvalid choice!");
    }
}

void registerMenu(){

    int register_Index;
    printf("1. Teacher Registiration\n");
    printf("2. Student Registiration\n");
    printf("Enter your choice: ");
    
    scanf("%d", &register_Index);
}

void teacherMenu(int teacher_Index){

}

void studentMenu(int student_Index){

}