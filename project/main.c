#include "myFunctions.c"
#include "myheader.h"
#include <stdbool.h>
#include <stdlib.h>

int main(void) {

  int lastClassId = 0;
  int *pLastClassId = &lastClassId;

  int lastStudentId = 0;
  int *pLastStudentId = &lastStudentId;

  getDataFromFileClasses(pLastClassId);

  getDataFromFileStudents(pLastStudentId);

  while (true) {
    int userNumber;
    userNumber = choseOperation();
    switch (userNumber) {
    case 0:
      createNewClass(pLastClassId);
      if (backToMenu() == 0)
        break;
      break;
    case 1:
      updateClass();
      if (backToMenu() == 0)
        break;
      break;
    case 2:
      deleteClass();
      if (backToMenu() == 0)
        break;
      break;
    case 3:
      classInformation();
      if (backToMenu() == 0)
        break;
      break;
    case 4:
      allClassesInformation();
      if (backToMenu() == 0)
        break;
      break;
    case 5:
      createNewStudent(pLastStudentId);
      if (backToMenu() == 0)
        break;
      break;
    case 6:
      updateStudent();
      if (backToMenu() == 0)
        break;
      break;
    case 7:
      deleteStudent();
      if (backToMenu() == 0)
        break;
      break;
    case 8:
      studentInformation();
      if (backToMenu() == 0)
        break;
      break;
    case 9:
      allStudentsInformation();
      if (backToMenu() == 0)
        break;
      break;
    case 10:
      system("cls");
      putDataIntoFileClasses();
      putDataIntoFileStudents();
      exit(1);
      break;
    default:
      userNumber = choseOperation();
      break;
    }
  }
  return 0;
}
