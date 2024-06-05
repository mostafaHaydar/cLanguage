

#ifndef MYHEADER_H
#define MYHEADER_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CLASS_LINKED_LISTS {
  int id;
  char name[50];
  int studentsNumber;
  char date[100];
  struct CLASS_LINKED_LISTS *next;
};

struct STUDENT_LINKED_LISTS {
  int id;
  char firstName[50];
  char lastName[50];
  int age;
  char email[100];
  char className[50];
  char date[100];
  struct STUDENT_LINKED_LISTS *next;
};

struct CLASS_LINKED_LISTS *first = NULL;
struct CLASS_LINKED_LISTS *current = NULL;
struct CLASS_LINKED_LISTS *previous = NULL;

struct STUDENT_LINKED_LISTS *first_s = NULL;
struct STUDENT_LINKED_LISTS *current_s = NULL;
struct STUDENT_LINKED_LISTS *previous_s = NULL;
void clearInputBuffer();
int backToMenu(void);
void createNewClass(int *pLastClassId);
void updateClass();
void deleteClass();
void classInformation();
void allClassesInformation();
int choseOperation(void);
void createNewStudent(int *pLastStudentId);
void updateStudent();
void deleteStudent();
void studentInformation();
void allStudentsInformation();
void getDataFromFileClasses(int *pLastClassIdd);
void getDataFromFileStudents(int *pLastStudentId);
void putDataIntoFileClasses();
void putDataIntoFileStudents();
bool isClassNameValid(char name[100]);
bool isHummanNameValid(char name[100]);
bool isEmailValid(char email[100]);
#endif