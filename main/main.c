#include "myFunctions.c"
#include "myheader.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int lastClassId = 0;
  int *pLastClassId = &lastClassId;

  int lastStudentId = 0;
  int *pLastStudentId = &lastStudentId;

  struct CLASS classes[100];
  struct CLASS *pClasses[100];

  struct STUDENT students[100];
  struct STUDENT *pStudents[100];

  for (size_t i = 0; i < 100; i++) {
    pClasses[i] = &classes[i];
    classes[i].id = -1;
    strcpy_s(classes[i].name, sizeof(classes[i].name), "null");
    classes[i].studentsNumber = 0;
  }

  for (int i = 0; i < 100; i++) {
    pStudents[i] = &students[i];
    students[i].id = -1;
  }

  getDataFromFileClasses(pClasses, pLastClassId);
  getDataFromFileStudents(pStudents, pLastStudentId);

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
      createNewStudent(pStudents, pClasses, pLastStudentId, classes);
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 6:
      updateStudent(pStudents, pClasses);
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 7:
      deleteStudent(pStudents, pClasses, pLastStudentId);
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

      putDataIntoFileClasses(pClasses);
      putDataIntoFileStudents(pStudents);
      exit(1);
      break;
    default:
      userNumber = choseOperation();
      break;
    }
  }
  return 0;
}
