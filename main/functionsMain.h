#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct CLASS
{
  int id;
  char name[50];
};

int lastClassId = 0;
int *pLastClassId = &lastClassId;

void clearInputBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

struct CLASS createNewClass(int *pLastClassId)
{
  system("cls");

  struct CLASS class;
  char tmpName[50];

  class.id = *pLastClassId;
  *pLastClassId = (*pLastClassId) + 1;

  printf("S'il te plaît, entre le nom de la classe :\n\t==> ");

  fgets(tmpName, sizeof(tmpName), stdin);
  size_t len = strlen(tmpName);
  if (len > 0 && tmpName[len - 1] == '\n')
  {
    tmpName[len - 1] = '\0';
  }
  strcpy(class.name, tmpName);

  return class;
}

void updateClass(struct CLASS *class)
{
  system("cls");
  char tmpName[50];
  printf("S'il te plaît, entre le nouveau nom de la class :\n\t==> ");
  fgets(tmpName, sizeof(tmpName), stdin);
  size_t len = strlen(tmpName);
  if (len > 0 && tmpName[len - 1] == '\n')
  {
    tmpName[len - 1] = '\0';
  }

  strcpy(class->name, tmpName);
}

struct STUDENT
{
  int id;
  char firstName[50];
  char lastName[50];
  int age;
  char email[100];
  char className[50];
};

int lastStudentId = 0;
int *pLastStudentId = &lastStudentId;

int choseOperation(void)
{
  int crudOperationNumber;
  int isNumber;
  system("cls");

  printf("################ Bonjour dans mon système scolaire ################\n\n");

  printf("\t:: cS ==> 0 :: pour ajouter un étudiant\n");
  printf("\t:: uS ==> 1 :: pour modifier les informations d'un étudiant\n");
  printf("\t:: dS ==> 2 :: pour supprimer un étudiant\n");
  printf("\t:: rS ==> 3 :: pour voir les informations d'un étudiant\n");
  printf("\t:: aS ==> 4 :: pour voir les informations de tous les étudiants\n\n");

  printf("\t:: cC ==> 5 :: pour ajouter une classe \n");
  printf("\t:: uC ==> 6 :: pour modifier les informations d'une classe\n");
  printf("\t:: dC ==> 7 :: pour supprimer une classe\n");
  printf("\t:: rC ==> 8 :: pour voir les informations d'une classe\n");
  printf("\t:: aC ==> 9 :: pour voir les informations de toutes les classes\n\n");

  printf("\t:: exit ==> 10 :: pour sortir\n\n");
  printf("Votre choix d'opération : ");

  while (true)
  {
    isNumber = scanf("%d", &crudOperationNumber);
    clearInputBuffer();
    if (isNumber && crudOperationNumber < 11 && crudOperationNumber >= 0)
    {
      return crudOperationNumber;
      break;
    }
    else
    {
      clearInputBuffer();
      system("cls");
      printf("Veuillez entrer un nombre entre 0 et 10.\n");
      printf("Votre nombre d'opérations : ");
    }
  }
}
int backToMenu(void)
{
  int tmpVar;
  printf("\nL'opération a été effectuée avec succès. Si vous pouvez aller vers la page principale, tapez:: 0 ==>");
  scanf("%d", &tmpVar);
  return tmpVar;
}

struct STUDENT createNewStudent(int *pLastStudentId, struct CLASS classes[100])
{
  system("cls");
  struct STUDENT student;
  char tmpFirstName[50];
  char tmpLastName[50];
  char tmpEmail[100];
  char tmpClassName[50];
  int tmpAge;
  //  id ##################
  student.id = *pLastStudentId;
  *pLastStudentId = (*pLastStudentId) + 1;
  //  first name ##################

  printf("S'il te plaît, entre votre prénom:\n\t==> ");
  fgets(tmpFirstName, sizeof(tmpFirstName), stdin);
  size_t len = strlen(tmpFirstName);
  if (len > 0 && tmpFirstName[len - 1] == '\n')
  {
    tmpFirstName[len - 1] = '\0';
  }
  strcpy(student.firstName, tmpFirstName);

  //  last name ##################

  printf("S'il te plaît, entre votre nom:\n\t==> ");
  fgets(tmpLastName, sizeof(tmpLastName), stdin);
  len = strlen(tmpLastName);
  if (len > 0 && tmpLastName[len - 1] == '\n')
  {
    tmpLastName[len - 1] = '\0';
  }

  strcpy(student.lastName, tmpLastName);

  //  age ##################

  printf("S'il te plaît, entre votre âge:\n\t==> ");
  scanf("%d", &tmpAge);
  student.age = tmpAge;

  clearInputBuffer();

  //  email ################

  printf("S'il te plaît, entre votre email:\n\t==> ");
  fgets(tmpEmail, sizeof(tmpEmail), stdin);
  len = strlen(tmpEmail);
  if (len > 0 && tmpEmail[len - 1] == '\n')
  {
    tmpEmail[len - 1] = '\0';
  }
  strcpy(student.email, tmpEmail);
  //  class  ################
  printf("S'il te plaît, entre votre class:\n\t==> ");
  bool isTheSame = false;
  while (!isTheSame)
  {
    fgets(tmpClassName, sizeof(tmpClassName), stdin);
    len = strlen(tmpClassName);
    if (len > 0 && tmpClassName[len - 1] == '\n')
    {
      tmpClassName[len - 1] = '\0';
    }
    for (size_t i = 0; i < 100; i++)
    {
      if (!strcmp(classes[i].name, tmpClassName))
      {
        isTheSame = true;
        break;
      }
    }
    if (!isTheSame)
    {
      system("cls");
      printf("ce class il n'exists pas dans l'ecole??\n");
      printf("S'il te plaît, entre votre class::\n\t");
    }
  }

  strcpy(student.className, tmpClassName);
  //  end ##################
  return student;
}

void updateStudent(struct STUDENT *student)
{
  system("cls");

  char tmpFirstName[50];
  char tmpLastName[50];
  char tmpEmail[100];
  char tmpClassName[50];
  printf("S'il te plaît, entre le nouveau prénom:\n\t==> ");
  fgets(tmpFirstName, sizeof(tmpFirstName), stdin);
  size_t len = strlen(tmpFirstName);
  if (len > 0 && tmpFirstName[len - 1] == '\n')
  {
    tmpFirstName[len - 1] = '\0';
  }

  strcpy(student->firstName, tmpFirstName);
  printf("S'il te plaît, entre le nouveau  nom:\n\t==> ");
  fgets(tmpLastName, sizeof(tmpLastName), stdin);
  len = strlen(tmpLastName);
  if (len > 0 && tmpLastName[len - 1] == '\n')
  {
    tmpLastName[len - 1] = '\0';
  }

  strcpy(student->lastName, tmpLastName);
  printf("S'il te plaît, entre le nouveau  âge:\n\t==> ");
  scanf("%d", &student->age);
  clearInputBuffer();

  printf("S'il te plaît, entre le nouveau  email:\n\t==> ");
  fgets(tmpEmail, sizeof(tmpEmail), stdin);
  len = strlen(tmpEmail);
  if (len > 0 && tmpEmail[len - 1] == '\n')
  {
    tmpEmail[len - 1] = '\0';
  }

  strcpy(student->email, tmpEmail);

  printf("S'il te plaît, entre le nouveau  class:\n\t==> ");
  fgets(tmpClassName, sizeof(tmpClassName), stdin);
  len = strlen(tmpClassName);
  if (len > 0 && tmpClassName[len - 1] == '\n')
  {
    tmpClassName[len - 1] = '\0';
  }

  strcpy(student->email, tmpClassName);
}
