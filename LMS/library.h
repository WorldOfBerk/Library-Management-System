#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_TEACHERS 100
#define MAX_STUDENTS 100
#define MAX_BOOKS 100

typedef struct {
    char code[7];
    char name[50];
    char password[9];
} Teacher;

typedef struct {
    char number[7];
    char name[50];
    char password[9];
} Student;

typedef struct {
    char serialNumber[13];
    char title[50];
    int stock;
} Book;

extern Teacher* teachers;
extern Student* students;
extern Book* books;

extern int teacherCount;
extern int studentCount;
extern int bookCount;

void init_Library();
void loginMenu();
void registerMenu();
void teacherMenu(int teacher_Index);
void studentMenu(int student_Index);
void saveDataToFiles();
void loadDataFromFiles();

#endif
