#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myheader.h"

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}
int backToMenu(void) {
  int tmpVar;
  printf("\n Si vous pouvez aller "
         "vers la page principale, tapez 0 :: ");
  scanf("%d", &tmpVar);
  return tmpVar;
}
void createNewClass(struct CLASS *pClasses[100], int *pLastClassId) {
  system("cls");
  char tmpName[50];
  bool isValid = false;
  bool alreadyExists = false;
  while (!isValid) {
    printf("S'il te plait, entre le nom de la classe :\n\t==> ");
    fgets(tmpName, sizeof(tmpName), stdin);
    size_t len = strlen(tmpName);
    if (len > 0 && tmpName[len - 1] == '\n') {
      tmpName[len - 1] = '\0';
    }
    alreadyExists = false;
    for (size_t j = 0; j < 100; j++) {
      if (!strcmp(pClasses[j]->name, tmpName)) {
        system("cls");
        printf("Ce nom de classe est deja utilise dans une autre classe.\n\t");
        alreadyExists = true;
        break;
      }
    }

    if (!alreadyExists) {
      for (int i = 0; i < 100; i++) {
        if (pClasses[i]->id == -1) {
          pClasses[i]->id = *pLastClassId;
          *pLastClassId = (*pLastClassId) + 1;
          strcpy_s(pClasses[i]->name, sizeof(pClasses[i]->name), tmpName);
          isValid = true;
          break;
        }
      }
    }
  }
  printf("\nL'operation a reussi.\n");
}

void updateClass(struct CLASS *pClasses[100], struct STUDENT *pStudents[100]) {

  system("cls");

  int tmpClassId;
  bool classExists = false;
  system("cls");
  printf("Pour modifier les informations d'une class, il faut d'abord l'ID "
         "de cet class : ");
  scanf("%d", &tmpClassId);
  clearInputBuffer();

  for (int i = 0; i < 100; i++) {
    if (pClasses[i]->id == tmpClassId) {
      classExists = true;
      char tmpClassNameForUpdateStudents[50];
      strcpy_s(tmpClassNameForUpdateStudents,
               sizeof(tmpClassNameForUpdateStudents), pClasses[i]->name);
      char tmpName[50];
      printf("S'il te plait, entre le nouveau nom de la class :\n\t==> ");
      fgets(tmpName, sizeof(tmpName), stdin);
      size_t len = strlen(tmpName);
      if (len > 0 && tmpName[len - 1] == '\n') {
        tmpName[len - 1] = '\0';
      }
      strcpy_s(pClasses[i]->name, sizeof(pClasses[i]->name), tmpName);
      for (size_t x = 0; x < 100; x++) {
        if (pStudents[x]->id != -1) {
          if (!strcmp(pStudents[x]->className, tmpClassNameForUpdateStudents)) {
            strcpy_s(pStudents[x]->className, sizeof(pStudents[x]->className),
                     pClasses[x]->name);
          } else {
            continue;
          }
        }
      }
    }
  }
  if (!classExists) {
    printf("\nIl n'existe pas de classe avec cet identifiant.\n");
  } else {
    printf("\nL'operation a reussi.\n");
  }
}

void deleteClass(struct CLASS *pClasses[100], struct STUDENT *pStudent[100],
                 int *pLastClassId, int *pLastStudentId) {
  system("cls");
  printf("Pour supprimer une class , il faut l'ID de cet class avant la "
         "suppression : ");
  bool classExists = false;
  int tmpClassId;
  scanf("%d", &tmpClassId);
  clearInputBuffer();
  char tmpClassNameForDeleteStudents[50];
  for (int i = 0; i < 100; i++) {
    if (pClasses[i]->id == tmpClassId) {
      classExists = true;
      strcpy_s(tmpClassNameForDeleteStudents,
               sizeof(tmpClassNameForDeleteStudents), pClasses[i]->name);
      for (int j = i; j < 99; j++) {
        pClasses[j]->id = pClasses[j + 1]->id;
        strcpy_s(pClasses[j]->name, sizeof(pClasses[j]->name),
                 pClasses[j + 1]->name);
        pClasses[99]->id = -1;
      }
      *pLastClassId = *pLastClassId - 1;
      for (size_t x = 0; x < 100; x++) {
        if (pStudent[x]->id != -1) {
          if (!strcmp(pStudent[x]->className, tmpClassNameForDeleteStudents)) {
            for (int y = x; y < 99; y++) {
              pStudent[x]->id = pStudent[x + 1]->id;
              pStudent[x]->age = pStudent[x + 1]->age;
              strcpy_s(pStudent[x]->firstName, sizeof(pStudent[x]->firstName),
                       pStudent[x + 1]->firstName);
              strcpy_s(pStudent[x]->lastName, sizeof(pStudent[x]->lastName),
                       pStudent[x + 1]->lastName);
              strcpy_s(pStudent[x]->email, sizeof(pStudent[x]->email),
                       pStudent[x + 1]->email);
              strcpy_s(pStudent[x]->className, sizeof(pStudent[x]->className),
                       pStudent[x + 1]->className);
              pStudent[99]->id = -1;
            }
            *pLastStudentId = *pLastStudentId - 1;
          } else {
            continue;
          }
        }
      }
      break;
    }
  }
  if (!classExists) {
    printf("\nIl n'existe pas de classe avec cet identifiant.\n");
  } else {
    printf("\nL'operation a reussi.\n");
  }
}

void classInformation(struct CLASS *pClasses[100]) {
  int tmpClassId;
  system("cls");
  printf("Pour voir les informations d'une class, il faut l'ID de cet "
         "class : ");
  scanf("%d", &tmpClassId);
  clearInputBuffer();
  system("cls");
  bool classExists = false;
  for (int i = 0; i < 100; i++) {
    if (pClasses[i]->id == tmpClassId) {
      classExists = true;
      printf("_______________________________________________________\n\n");
      printf("id                 :: %d\n", pClasses[i]->id);
      printf("nom de class       :: %s\n", pClasses[i]->name);
      printf("_______________________________________________________\n\n");
    }
  }
  if (!classExists) {
    printf("\nIl n'existe pas de classe avec cet identifiant.\n");
  } else {
    printf("\nL'operation a reussi.\n");
  }
}

void allClassesInformation(struct CLASS *pClasses[100]) {
  system("cls");
  bool classExists = false;
  for (int i = 0; i < 100; i++) {
    if (pClasses[i]->id != -1) {
      classExists = true;
      printf("_______________________________________________________\n\n");
      printf("class                :: %d\n", i);
      printf("id                   :: %d\n", pClasses[i]->id);
      printf("nom de class         :: %s\n", pClasses[i]->name);
      printf("_______________________________________________________\n\n");
    }
  }
  if (!classExists) {
    printf("\nIl n'y a aucune classe dans cette ecole.\n");
  } else {
    printf("\nL'operation a reussi.\n");
  }
}

int choseOperation(void) {
  int crudOperationNumber;
  int isNumber;
  system("cls");

  printf("################ Bonjour dans mon systeme scolaire "
         "#####################\n\n");
  printf("#\t:: cC ==> 0 :: pour ajouter une classe                           "
         "#\n");
  printf("#\t:: uC ==> 1 :: pour modifier les informations d'une classe       "
         "#\n");
  printf("#\t:: dC ==> 2 :: pour supprimer une classe                         "
         "#\n");
  printf("#\t:: rC ==> 3 :: pour voir les informations d'une classe           "
         "#\n");
  printf("#\t:: aC ==> 4 :: pour voir les informations de toutes les classes  "
         "#\n\n");
  printf("#\t:: cS ==> 5 :: pour ajouter un etudiant                          "
         "#\n");
  printf("#\t:: uS ==> 6 :: pour modifier les informations d'un etudiant      "
         "#\n");
  printf("#\t:: dS ==> 7 :: pour supprimer un etudiant                        "
         "#\n");
  printf("#\t:: rS ==> 8 :: pour voir les informations d'un etudiant          "
         "#\n");
  printf("#\t:: aS ==> 9 :: pour voir les informations de tous les etudiants  "
         "#\n\n");
  printf("#\t:: exit ==> 10 :: pour sortir                                    "
         "#\n\n");
  printf("#####################################################################"
         "####\n\n");

  printf("Votre choix d'operation : ");

  while (true) {
    isNumber = scanf("%d", &crudOperationNumber);
    clearInputBuffer();
    if (isNumber && crudOperationNumber < 11 && crudOperationNumber >= 0) {
      return crudOperationNumber;
      break;
    } else {
      clearInputBuffer();
      system("cls");
      printf("Veuillez entrer un nombre entre 0 et 10.\n\t");
      printf("Votre nombre d'operations :: ");
    }
  }
}

void createNewStudent(struct STUDENT *pStudent[100], int *pLastStudentId,
                      struct CLASS classes[100]) {
  system("cls");

  char tmpFirstName[50];
  char tmpLastName[50];
  char tmpEmail[100];
  char tmpClassName[50];
  int tmpAge;
  for (int i = 0; i < 100; i++) {
    if (pStudent[i]->id == -1) {
      //  id ##################
      pStudent[i]->id = *pLastStudentId;
      *pLastStudentId = (*pLastStudentId) + 1;
      //  first name ##################

      printf("S'il te plait, entre votre prenom:\n\t==> ");
      fgets(tmpFirstName, sizeof(tmpFirstName), stdin);
      size_t len = strlen(tmpFirstName);
      if (len > 0 && tmpFirstName[len - 1] == '\n') {
        tmpFirstName[len - 1] = '\0';
      }
      strcpy(pStudent[i]->firstName, tmpFirstName);

      //  last name ##################

      printf("S'il te plait, entre votre nom:\n\t==> ");
      fgets(tmpLastName, sizeof(tmpLastName), stdin);
      len = strlen(tmpLastName);
      if (len > 0 && tmpLastName[len - 1] == '\n') {
        tmpLastName[len - 1] = '\0';
      }

      strcpy(pStudent[i]->lastName, tmpLastName);

      //  age ##################

      printf("S'il te plait, entre votre age:\n\t==> ");
      scanf("%d", &tmpAge);
      pStudent[i]->age = tmpAge;

      clearInputBuffer();

      //  email ################

      printf("S'il te plait, entre votre email:\n\t==> ");
      fgets(tmpEmail, sizeof(tmpEmail), stdin);
      len = strlen(tmpEmail);
      if (len > 0 && tmpEmail[len - 1] == '\n') {
        tmpEmail[len - 1] = '\0';
      }
      strcpy(pStudent[i]->email, tmpEmail);
      //  class  ################
      printf("S'il te plait, entre votre class:\n\t==> ");
      bool isTheSame = false;
      while (!isTheSame) {
        fgets(tmpClassName, sizeof(tmpClassName), stdin);
        len = strlen(tmpClassName);
        if (len > 0 && tmpClassName[len - 1] == '\n') {
          tmpClassName[len - 1] = '\0';
        }
        for (size_t i = 0; i < 100; i++) {
          if (!strcmp(classes[i].name, tmpClassName)) {
            isTheSame = true;
            break;
          }
        }
        if (!isTheSame) {
          system("cls");
          printf("ce class il n'exists pas dans l'ecole??\n");
          printf("S'il te plait, entre votre class::\n\t");
        }
      }
      strcpy(pStudent[i]->className, tmpClassName);
      break;
      //  end ##################
    }
  }
  printf("\nL'operation a reussi.\n");
}

void updateStudent(struct STUDENT *pStudent[100]) {
  system("cls");
  bool studentExists = false;
  printf("Pour modifier les informations d'un etudiant, il faut d'abord "
         "l'ID de cet etudiant : ");
  int tmpStudentId;
  scanf("%d", &tmpStudentId);
  clearInputBuffer();
  for (int i = 0; i < 100; i++) {
    if (pStudent[i]->id == tmpStudentId) {
      studentExists = true;
      char tmpFirstName[50];
      char tmpLastName[50];
      char tmpEmail[100];
      char tmpClassName[50];
      printf("S'il te plait, entre le nouveau prenom:\n\t==> ");
      fgets(tmpFirstName, sizeof(tmpFirstName), stdin);
      size_t len = strlen(tmpFirstName);
      if (len > 0 && tmpFirstName[len - 1] == '\n') {
        tmpFirstName[len - 1] = '\0';
      }

      strcpy(pStudent[i]->firstName, tmpFirstName);
      printf("S'il te plait, entre le nouveau  nom:\n\t==> ");
      fgets(tmpLastName, sizeof(tmpLastName), stdin);
      len = strlen(tmpLastName);
      if (len > 0 && tmpLastName[len - 1] == '\n') {
        tmpLastName[len - 1] = '\0';
      }

      strcpy(pStudent[i]->lastName, tmpLastName);
      printf("S'il te plait, entre le nouveau  age:\n\t==> ");
      scanf("%d", &pStudent[i]->age);
      clearInputBuffer();

      printf("S'il te plait, entre le nouveau  email:\n\t==> ");
      fgets(tmpEmail, sizeof(tmpEmail), stdin);
      len = strlen(tmpEmail);
      if (len > 0 && tmpEmail[len - 1] == '\n') {
        tmpEmail[len - 1] = '\0';
      }

      strcpy(pStudent[i]->email, tmpEmail);

      printf("S'il te plait, entre le nouveau  class:\n\t==> ");
      fgets(tmpClassName, sizeof(tmpClassName), stdin);
      len = strlen(tmpClassName);
      if (len > 0 && tmpClassName[len - 1] == '\n') {
        tmpClassName[len - 1] = '\0';
      }

      strcpy(pStudent[i]->className, tmpClassName);
      break;
    }
  }
  if (!studentExists) {
    printf("\nIl n'existe pas d'eleve avec cet identifiant.\n");

  } else {
    printf("\nL'operation a reussi.\n");
  }
}

void deleteStudent(struct STUDENT *pStudent[100], int *pLastStudentId) {
  system("cls");

  printf("Pour supprimer un etudiant, il faut l'ID de cet etudiant avant "
         "la suppression : ");
  bool studentExists = false;
  int tmpStudentId;
  scanf("%d", &tmpStudentId);
  clearInputBuffer();
  for (int i = 0; i < 99; i++) {
    if (pStudent[i]->id == tmpStudentId) {
      studentExists = true;
      for (int j = i; j < 99; j++) {
        pStudent[j]->id = pStudent[j + 1]->id;
        pStudent[j]->age = pStudent[j + 1]->age;
        strcpy_s(pStudent[j]->firstName, sizeof(pStudent[j]->firstName),
                 pStudent[j + 1]->firstName);
        strcpy_s(pStudent[j]->lastName, sizeof(pStudent[j]->lastName),
                 pStudent[j + 1]->lastName);
        strcpy_s(pStudent[j]->email, sizeof(pStudent[j]->email),
                 pStudent[j + 1]->email);
        strcpy_s(pStudent[j]->className, sizeof(pStudent[j]->className),
                 pStudent[j + 1]->className);
        pStudent[99]->id = -1;
      }
      *pLastStudentId = *pLastStudentId - 1;
      break;
    }
  }
  if (!studentExists) {
    printf("\nIl n'existe pas d'eleve avec cet identifiant.\n");
  } else {
    printf("\nL'operation a reussi.\n");
  }
}
void studentInformation(struct STUDENT *pStudents[100]) {
  bool studentExists = false;
  system("cls");
  printf("Pour voir les informations d'un etudiant, il faut l'ID de cet "
         "etudiant : ");
  int tmpStudentId;
  scanf("%d", &tmpStudentId);
  clearInputBuffer();
  system("cls");
  for (int i = 0; i < 100; i++) {
    if (pStudents[i]->id == tmpStudentId) {
      studentExists = true;
      printf("_______________________________________________________\n\n");
      printf("id                   :: %d\n", pStudents[i]->id);
      printf("prenom               :: %s\n", pStudents[i]->firstName);
      printf("nom de famille       :: %s\n", pStudents[i]->lastName);
      printf("age                  :: %d\n", pStudents[i]->age);
      printf("mail                 :: %s\n", pStudents[i]->email);
      printf("class                :: %s\n", pStudents[i]->className);
      printf("_______________________________________________________\n\n");
    }
  }
  if (!studentExists) {
    printf("\nIl n'existe pas d'eleve avec cet identifiant.\n");

  } else {
    printf("\nL'operation a reussi.\n");
  }
}
void allStudentsInformation(struct STUDENT *pStudents[100]) {
  bool studentExists = false;
  system("cls");
  for (int i = 0; i < 100; i++) {
    if (pStudents[i]->id != -1) {
      studentExists = true;
      printf("_______________________________________________________\n\n");
      printf("etudiant :: %d\n", i);
      printf("id                   :: %d\n", pStudents[i]->id);
      printf("prenom               :: %s\n", pStudents[i]->firstName);
      printf("nom de famille       :: %s\n", pStudents[i]->lastName);
      printf("age                  :: %d\n", pStudents[i]->age);
      printf("mail                 :: %s\n", pStudents[i]->email);
      printf("class                :: %s\n", pStudents[i]->className);
      printf("_______________________________________________________\n\n");
    }
  }
  if (!studentExists) {
    printf("\nIl n'existe pas d'eleve dans cette ecole.\n");
  } else {
    printf("\nL'operation a reussi.\n");
  }
}