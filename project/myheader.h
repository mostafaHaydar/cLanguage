

#ifndef MYHEADER_H
#define MYHEADER_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CLASS {
  int id;
  char name[50];
  int studentsNumber;
  char date[100];
};

struct STUDENT {
  int id;
  char firstName[50];
  char lastName[50];
  int age;
  char email[100];
  char className[50];
  char date[100];
};
void clearInputBuffer();
int backToMenu(void);
void createNewClass(struct CLASS *pClasses[100], int *pLastClassId);
void updateClass(struct CLASS *pClasses[100], struct STUDENT *pStudents[100]);
void deleteClass(struct CLASS *pClasses[100], struct STUDENT *pStudent[100],
                 int *pLastClassId, int *pLastStudentId);
void classInformation(struct CLASS *pClasses[100]);
void allClassesInformation(struct CLASS *pClasses[100]);
int choseOperation(void);
void createNewStudent(struct STUDENT *pStudent[100],
                      struct CLASS *pClasses[100], int *pLastStudentId,
                      struct CLASS classes[100]);
void updateStudent(struct STUDENT *pStudent[100], struct CLASS *pClasses[100]);
void deleteStudent(struct STUDENT *pStudent[100], struct CLASS *pClasses[100],
                   int *pLastStudentId);
void studentInformation(struct STUDENT *pStudents[100]);
void allStudentsInformation(struct STUDENT *pStudents[100]);
void getDataFromFileClasses(struct CLASS *pClasses[100], int *pLastClassId);
void getDataFromFileStudents(struct STUDENT *pStudent[100],
                             int *pLastStudentId);
void putDataIntoFileClasses(struct CLASS *pClasses[100]);
void putDataIntoFileStudents(struct STUDENT *pStudents[100]);
bool isClassNameValid(char name[100]);
bool isHummanNameValid(char name[100]);
bool isEmailValid(char email[100]);
#endif