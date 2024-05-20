#include "functionsMain.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{

  struct CLASS classes[100];
  struct CLASS *pClasses[100];
  for (int i = 0; i < 100; i++)
  {
    pClasses[i] = &classes[i];
  }

  for (int i = 0; i < 100; i++)
  {
    classes[i].id = -1;
    strcpy(classes[i].name, "null");
  }

  int tmpClassId;
  struct STUDENT students[100];
  struct STUDENT *pStudents[100];
  for (int i = 0; i < 100; i++)
  {
    pStudents[i] = &students[i];
  }

  for (int i = 0; i < 100; i++)
  {
    students[i].id = -1;
  }

  int tmpStudentId;

  while (true)
  {
    int crudOperationNumber;
    crudOperationNumber = choseOperation();
    switch (crudOperationNumber)
    {
    case 0:
      for (int i = 0; i < 100; i++)
      {
        if (students[i].id == -1)
        {
          students[i] = createNewStudent(pLastStudentId, classes);
          if (backToMenu() == 0)
          {
            break;
          }
        }
      }
      break;
    case 1:
      printf("Pour modifier les informations d'un étudiant, il faut d'abord l'ID de cet étudiant : ");

      scanf("%d", &tmpStudentId);
      clearInputBuffer();
      for (int i = 0; i < 100; i++)
      {
        if (students[i].id == tmpStudentId)
        {
          updateStudent(pStudents[i]);
        }
      }
      if (backToMenu() == 0)
      {
        break;
      }
      break;
    case 2:
      printf("Pour supprimer un étudiant, il faut l'ID de cet étudiant avant la suppression : ");
      scanf("%d", &tmpStudentId);
      clearInputBuffer();
      for (int i = 0; i < 100; i++)
      {
        if (students[i].id == tmpStudentId)
        {
          for (int j = i; j < 100; j++)
          {
            students[j] = students[j + 1];
            students[99].id = -1;
          }
        }
      }
      if (backToMenu() == 0)
      {
        break;
      }
      break;
    case 3:
      printf("Pour voir les informations d'un étudiant, il faut l'ID de cet étudiant : ");
      scanf("%d", &tmpStudentId);
      clearInputBuffer();
      system("cls");
      for (int i = 0; i < 100; i++)
      {
        if (students[i].id == tmpStudentId)
        {
          printf("_______________________________________________________\n\n");
          printf("id                   :: %d\n", students[i].id);
          printf("prénom               :: %s\n", students[i].firstName);
          printf("nom de famille       :: %s\n", students[i].lastName);
          printf("âge                  :: %d\n", students[i].age);
          printf("mail                 :: %s\n", students[i].email);
          printf("class                :: %s\n", students[i].className);
          printf("_______________________________________________________\n\n");
        }
      }
      if (backToMenu() == 0)
      {
        break;
      }
      break;
    case 4:
      system("cls");
      for (int i = 0; i < 100; i++)
      {
        if (students[i].id != -1)
        {
          printf("_______________________________________________________\n\n");
          printf("étudiant :: %d\n", i);
          printf("id                   :: %d\n", students[i].id);
          printf("prénom               :: %s\n", students[i].firstName);
          printf("nom de famille       :: %s\n", students[i].lastName);
          printf("âge                  :: %d\n", students[i].age);
          printf("mail                 :: %s\n", students[i].email);
          printf("class                :: %s\n", students[i].className);
          printf("_______________________________________________________\n\n");
        }
      }
      if (backToMenu() == 0)
      {
        break;
      }
      break;
    case 5:
      for (int i = 0; i < 100; i++)
      {
        if (classes[i].id == -1)
        {
          classes[i] = createNewClass(pLastClassId);
          if (backToMenu() == 0)
          {
            break;
          }
        }
      }
      break;
    case 6:
      printf("Pour modifier les informations d'une class, il faut d'abord l'ID de cet étudiant : ");

      scanf("%d", &tmpClassId);
      clearInputBuffer();
      for (int i = 0; i < 100; i++)
      {
        if (classes[i].id == tmpClassId)
        {
          updateStudent(pClasses[i]);
        }
      }
      if (backToMenu() == 0)
      {
        break;
      }
      break;
    case 7:
      printf("Pour supprimer un étudiant, il faut l'ID de cet class avant la suppression : ");
      scanf("%d", &tmpClassId);
      clearInputBuffer();
      for (int i = 0; i < 100; i++)
      {
        if (classes[i].id == tmpClassId)
        {
          for (int j = i; j < 100; j++)
          {
            classes[j] = classes[j + 1];
            classes[99].id = -1;
          }
        }
      }
      if (backToMenu() == 0)
      {
        break;
      }
      break;
    case 8:
      printf("Pour voir les informations d'une class, il faut l'ID de cet class : ");
      scanf("%d", &tmpClassId);
      clearInputBuffer();
      system("cls");
      for (int i = 0; i < 100; i++)
      {
        if (classes[i].id == tmpClassId)
        {
          printf("_______________________________________________________\n\n");
          printf("id                 :: %d\n", classes[i].id);
          printf("nom de class       :: %s\n", classes[i].name);
          printf("_______________________________________________________\n\n");
        }
      }
      if (backToMenu() == 0)
      {
        break;
      }
      break;
    case 9:
      system("cls");
      for (int i = 0; i < 100; i++)
      {
        if (classes[i].id != -1)
        {
          printf("_______________________________________________________\n\n");
          printf("class                :: %d\n", i);
          printf("id                   :: %d\n", classes[i].id);
          printf("nom de class         :: %s\n", classes[i].name);
          printf("_______________________________________________________\n\n");
        }
      }
      if (backToMenu() == 0)
      {
        break;
      }
      break;
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
