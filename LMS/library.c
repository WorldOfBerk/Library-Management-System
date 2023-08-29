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
            puts("Password: ");
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
            puts("Student number: ");
            scanf("%s", enteredNumber);
            puts("Password: ");
            scanf("%s", enteredPassword);

            int foundStudent_Index = -1;
            for (int i = 0; i < studentCount; i++) {
                if (strcmp(enteredNumber, students[i].number) == 0 && strcmp(enteredPassword, students[i].password) == 0) {
                    foundStudent_Index = i;
                    break;
                }
            }

            if (foundStudent_Index != -1) {
                printf("Student Login successful!\n");
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

    switch (register_Index)
    {
    case 1:
        if (teacherCount < MAX_TEACHERS)
        {
            Teacher newTeacher;
            puts("Teacher code: ");
            scanf("%s", newTeacher.code);
            puts("Name and Surname: ");
            scanf("%*c%[^\n]", newTeacher.name);
            puts("Enter a password: ");
            scanf("%s", newTeacher.password);

            teachers[teacherCount++] = newTeacher;
            puts("Teacher succesfully saved!");
            savedataToFiles();
        }
        else{
            puts("Reached to Maximum Teacher count!");
        }
        
        break;

    case 2:
        if(studentCount < MAX_STUDENTS){
            Student newStudent;
            puts("Student number: ");
            scanf("%s", newStudent.number);
            puts("Student name: ");
            scanf("%*c%[^\n]", newStudent.name);
            puts("Enter a password: ");
            scanf("%s", newStudent.password);

            students[studentCount++] = newStudent;
            puts("Student succesfully saved!");
            saveDataToFiles();
        }
        else{
            puts("Reached to Maximum Student count!");
        }

        break;
    
    default:
        puts("Invalid choice!");
    }
}

void teacherMenu(int teacher_Index){
    int teacherChoice;
    while (1)
    {
        puts("\nTeacher Menu\n");
        puts("1. Add Book\n");
        puts("2. Remove Book\n");
        puts("3. List All\n");
        puts("Quit\n");
        puts("Enter your choice: ");
        scanf("%d", &teacherChoice);

        switch (teacherChoice)
        {
        case 1:
            if (bookCount < MAX_BOOKS)
            {
                Book newbook;
                puts("Enter 12 digit serial number: ");
                scanf("%s", newbook.serialNumber);
                puts("Enter Book name");
                scanf("%*c%[^\n]", newbook.title);
                puts("Enter stock count: ");
                scanf("%d", &newbook.stock);

                books[bookCount++] = newbook;
                puts("The book added succesfully");
                saveDataToFiles();
            }
            else{
                puts("Reached maximum book count!");
            }
            
            break;

        case 2:
            char removeSerialNumber[13];
            puts("Enter the 12 digit serial number deletion: ");
            scanf("%s", removeSerialNumber);

            int found_Index = -1;
            for (int i = 0; i < bookCount; i++)
            {
                if (strcmp(removeSerialNumber, books[i].serialNumber) == 0)
                {
                    found_Index = i;
                    break;
                }
            }
                if (found_Index != -1)
                {
                    for (int i = 0; i < bookCount - 1; i++)
                    {
                        books[i] = books[i + 1];
                    }
                    bookCount--;
                    puts("Book removed succesfully");
                    saveDataToFiles();
                }else{
                    puts("There is no matched book!");
                }
            
            break;
        case 3:
            puts("\nAll Books\n");
            for (int i = 0; i < bookCount; i++)
            {
                printf("Serial Number: %s, Title: %s, Stock: %d", books[i].serialNumber, books[i].title, books[i].stock);
            }
            break;

        case 4:
            return;

        default:
            puts("Invalid choice");
        }
    }
    
}

void studentMenu(int student_Index){
    int studentChoice;

    while (1)
    {
        puts("\nStudent Menu\n");
        puts("1. List books and borrow!\n");
        puts("2. Quit!\n");
        puts("Enter your choice: ");
        scanf("%d", &studentChoice);

        switch (studentChoice)
        {
        case 1:
            puts("\nBooks\n");
            for (int i = 0; i < bookCount; i++)
            {
                printf("Serial Number: %s, Title: %s, Stock: %d", books[i].serialNumber, books[i].title, books[i].stock);
            }
            char choosenSerialNumber[13];
            puts("\nEnter the 12 digit of serial number you'd like to borrow: ");
            scanf("%s", choosenSerialNumber);

            int found_Index = -1;
            for (int i = 0; i < bookCount; i++)
            {
                if (strcmp(choosenSerialNumber, books[i].serialNumber) == 0)
                {
                    found_Index = i;
                    break;
                }
            }
            if (found_Index != -1 && books[found_Index].stock > 0)
            {
                books[found_Index].stock--;
                printf("Book has succesfully borrowed! New Stock: %d", books[found_Index].stock);
                saveDataToFiles();
            }else if (found_Index != -1 && books[found_Index].stock == 0)
            {
                puts("There is no stock left");
            }else {
                puts("Invalid Serial Number!");
            }
            break;
        case 2:
            return;

        default:
            puts("Invalid choice!");
        }
    }   
}

void saveDataToFiles(){
    //For teachers
    FILE *teacherFile = fopen("Teacher.txt", "w");
    if (teacherFile == NULL)
    {
        puts("File couldn't open!\n");
        exit(1);
    }

    for (int i = 0; i < teacherCount; i++)
    {
        fprintf(teacherFile, "%s %s %s\n", teachers[i].code, teachers[i].name, teachers[i].password);
    }
    fclose(teacherFile);

    //For Students
    FILE *studentFile = fopen("Student.txt", "w");
    if (studentFile == NULL)
    {
        puts("File couldn't open!\n");
        exit(1);
    }
    
    for (int i = 0; i < studentCount; i++)
    {
        fprintf(studentFile, "%s %s %s\n", students[i].number, students[i].name, students[i].password);
    }
    fclose(studentFile);
    
    //For Books
    FILE *bookFile = fopen("books.txt", "w");
    if (bookFile == NULL)
    {
        puts("File couldn't open!\n");
        exit(1);
    }

    for (int i = 0; i < bookCount; i++)
    {
        fprintf(bookFile, "%s %s %d\n", books[i].serialNumber, books[i].title, books[i].stock);
    }
    fclose(bookFile);
}

void loadDataFromFiles(){
    //Load Teachers
    FILE *teacherFile = fopen("Teacher.txt", "r");
    if (teacherFile == NULL)
    {
        return;
    }

    while (fscanf(teacherFile, "%s %s %s", teachers[teacherCount].code, teachers[teacherCount].name, teachers[teacherCount].password) != EOF)
    {
        teacherCount++;
    }
    
    fclose(teacherFile);

    //Load Students
    FILE *studentFile = fopen("Student.txt", "r");
    if (studentFile == NULL)
    {
        return;
    }

    while (fscanf(studentFile, "%s %s %s", students[studentCount].number, students[studentCount].name, students[studentCount].password) != EOF)
    {
        studentCount++;
    }
    
    fclose(studentFile);

    //Load Books
    FILE *bookFile = fopen("books.txt", "r");
    if (bookFile == NULL)
    {
        return;
    }

    while (fscanf(bookFile, "%s %s %d", books[bookCount].serialNumber, books[bookCount].title, books[bookCount].stock))
    {
        bookCount++;
    }
    
    fclose(bookCount);
}