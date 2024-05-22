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
    strcpy(classes[i].name, "null");
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
    int crudOperationNumber;
    crudOperationNumber = choseOperation();
    switch (crudOperationNumber) {
    case 0:

      for (int i = 0; i < 100; i++) {
        if (classes[i].id == -1) {
          classes[i] = createNewClass(pLastClassId);
          if (backToMenu() == 0) {
            break;
          }
        }
      }
      
      break;
    case 1:
      system("cls");
      printf("Pour modifier les informations d'une class, il faut d'abord l'ID "
             "de cet class : ");
      scanf("%d", &tmpClassId);
      clearInputBuffer();
      for (int i = 0; i < 100; i++) {
        if (classes[i].id == tmpClassId) {
          int tmpClassNameForUpdateStudents[50];
          strcpy(tmpClassNameForUpdateStudents, classes[i].name);
          updateClass(pClasses[i]);
          for (size_t x = 0; x < 100; x++) {
            if (students[x].id != -1) {
              if (!strcmp(students[x].className,
                          tmpClassNameForUpdateStudents)) {
                strcpy(students[x].className, classes[i].name);
              } else {
                continue;
              }
            }
          }
        }
      }
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 2:
      system("cls");

      printf("Pour supprimer une class , il faut l'ID de cet class avant la "
             "suppression : ");
      scanf("%d", &tmpClassId);
      clearInputBuffer();
      char tmpClassNameForDeleteStudents[50];
      for (int i = 0; i < 100; i++) {
        if (classes[i].id == tmpClassId) {
          strcpy(tmpClassNameForDeleteStudents, classes[i].name);
          printf("%s", classes[i].name);
          printf("%s", tmpClassNameForDeleteStudents);
          for (int j = i; j < 100; j++) {
            classes[j] = classes[j + 1];
            classes[99].id = -1;
          }

          for (size_t x = 0; x < 100; x++) {
            if (students[x].id != -1) {
              if (!strcmp(students[x].className,
                          tmpClassNameForDeleteStudents)) {
                for (int y = x; y < 100; y++) {
                  students[x] = students[x + 1];
                  students[99].id = -1;
                }
              } else {
                continue;
              }
            }
          }
        }
      }
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 3:

      system("cls");

      printf("Pour voir les informations d'une class, il faut l'ID de cet "
             "class : ");
      scanf("%d", &tmpClassId);
      clearInputBuffer();
      system("cls");
      for (int i = 0; i < 100; i++) {
        if (classes[i].id == tmpClassId) {
          printf("_______________________________________________________\n\n");
          printf("id                 :: %d\n", classes[i].id);
          printf("nom de class       :: %s\n", classes[i].name);
          printf("_______________________________________________________\n\n");
        }
      }
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 4:
      system("cls");
      for (int i = 0; i < 100; i++) {
        if (classes[i].id != -1) {
          printf("_______________________________________________________\n\n");
          printf("class                :: %d\n", i);
          printf("id                   :: %d\n", classes[i].id);
          printf("nom de class         :: %s\n", classes[i].name);
          printf("_______________________________________________________\n\n");
        }
      }
      if (backToMenu() == 0) {
        break;
      }
      break;
      break;

    case 5:
      system("cls");

      for (int i = 0; i < 100; i++) {
        if (students[i].id == -1) {
          students[i] = createNewStudent(pLastStudentId, classes);
          if (backToMenu() == 0) {
            break;
          }
        }
      }
      break;
    case 6:
      system("cls");

      printf("Pour modifier les informations d'un etudiant, il faut d'abord "
             "l'ID de cet etudiant : ");

      scanf("%d", &tmpStudentId);
      clearInputBuffer();
      for (int i = 0; i < 100; i++) {
        if (students[i].id == tmpStudentId) {
          updateStudent(pStudents[i]);
        }
      }
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 7:
      system("cls");

      printf("Pour supprimer un etudiant, il faut l'ID de cet etudiant avant "
             "la suppression : ");
      scanf("%d", &tmpStudentId);
      clearInputBuffer();
      for (int i = 0; i < 100; i++) {
        if (students[i].id == tmpStudentId) {
          for (int j = i; j < 100; j++) {
            students[j] = students[j + 1];
            students[99].id = -1;
          }
        }
      }
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 8:
      system("cls");

      printf("Pour voir les informations d'un etudiant, il faut l'ID de cet "
             "etudiant : ");
      scanf("%d", &tmpStudentId);
      clearInputBuffer();
      system("cls");
      for (int i = 0; i < 100; i++) {
        if (students[i].id == tmpStudentId) {
          printf("_______________________________________________________\n\n");
          printf("id                   :: %d\n", students[i].id);
          printf("prenom               :: %s\n", students[i].firstName);
          printf("nom de famille       :: %s\n", students[i].lastName);
          printf("age                  :: %d\n", students[i].age);
          printf("mail                 :: %s\n", students[i].email);
          printf("class                :: %s\n", students[i].className);
          printf("_______________________________________________________\n\n");
        }
      }
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 9:
      system("cls");
      for (int i = 0; i < 100; i++) {
        if (students[i].id != -1) {
          printf("_______________________________________________________\n\n");
          printf("etudiant :: %d\n", i);
          printf("id                   :: %d\n", students[i].id);
          printf("prenom               :: %s\n", students[i].firstName);
          printf("nom de famille       :: %s\n", students[i].lastName);
          printf("age                  :: %d\n", students[i].age);
          printf("mail                 :: %s\n", students[i].email);
          printf("class                :: %s\n", students[i].className);
          printf("_______________________________________________________\n\n");
        }
      }
      if (backToMenu() == 0) {
        break;
      }
      break;
    case 10:
      system("cls");
      exit(1);
      break;
    default:
      crudOperationNumber = choseOperation();
      break;
    }
  }
  return 0;
}
