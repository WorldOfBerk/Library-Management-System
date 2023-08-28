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