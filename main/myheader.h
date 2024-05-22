

#ifndef MYHEADER_H
#define MYHEADER_H

struct CLASS {
  int id;
  char name[50];
};

struct STUDENT {
  int id;
  char firstName[50];
  char lastName[50];
  int age;
  char email[100];
  char className[50];
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
void createNewStudent(struct STUDENT *pStudent[100], int *pLastStudentId,
                      struct CLASS classes[100]);
void updateStudent(struct STUDENT *pStudent[100]);
void deleteStudent(struct STUDENT *pStudent[100], int *pLastStudentId);
void studentInformation(struct STUDENT *pStudents[100]);
void allStudentsInformation(struct STUDENT *pStudents[100]);
#endif