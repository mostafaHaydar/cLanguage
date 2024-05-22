#include "functionsMain.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  struct CLASS classes[100];
  struct CLASS *pClasses[100];

  for (int i = 0; i < 100; i++) {
    pClasses[i] = &classes[i];
  }

  for (int i = 0; i < 100; i++) {
    classes[i].id = -1;
    strcpy_s(classes[i].name, sizeof(classes[i].name), "null");
  }

  int tmpClassId;

  struct STUDENT students[100];
  struct STUDENT *pStudents[100];

  for (int i = 0; i < 100; i++) {
    pStudents[i] = &students[i];
  }

  for (int i = 0; i < 100; i++) {
    students[i].id = -1;
  }

  int tmpStudentId;

  while (true) {
    int userNumber;
    userNumber = choseOperation();

    switch (userNumber) {
    case 0:
      createNewClass(pClasses, pLastClassId);
      if (backToMenu() == 0) {
        break;
      }

      break;
    case 1:
      updateClass(pClasses, pStudents);
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 2:
      deleteClass(pClasses, pStudents, pLastClassId, pLastStudentId);
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 3:
      classInformation(pClasses);
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 4:

      allClassesInformation(pClasses);
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 5:
      createNewStudent(pStudents, pLastStudentId, classes);
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 6:
      updateStudent(pStudents);
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 7:
      deleteStudent(pStudents, pLastStudentId);
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 8:
      studentInformation(pStudents);
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 9:
      allStudentsInformation(pStudents);
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 10:
      system("cls");
      exit(1);
      break;
    default:
      userNumber = choseOperation();
      break;
    }
  }
  return 0;
}
