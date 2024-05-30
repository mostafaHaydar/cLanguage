#include "myheader.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

int backToMenu(void) {
  int tmpVar;
  printf("\n Si vous pouvez aller "
         "vers la page principale, tapez 0 :: ");
  scanf_s("%d", &tmpVar);
  return tmpVar;
}

void createNewClass(struct CLASS *pClasses[100], int *pLastClassId) {
  system("cls");

  time_t currentTime;
  time(&currentTime);
  struct tm *localTime = localtime(&currentTime);
  char formattedTime[100];
  strftime(formattedTime, sizeof(formattedTime), "%Y-%m-%d %H-%M-%S",
           localTime);

  char tmpName[100];
  bool isValid = false, alreadyExists = false;

  while (!isValid) {
    printf("S'il te plaît, entre le nom de la classe :\n\t==> ");
    fgets(tmpName, sizeof(tmpName), stdin);
    size_t len = strlen(tmpName);

    if (len > 0 && tmpName[len - 1] == '\n')
      tmpName[len - 1] = '\0';

    alreadyExists = false;

    for (size_t j = 0; j < 100; j++) {
      if (!strcmp(pClasses[j]->name, tmpName)) {
        system("cls");
        printf("Ce nom de classe est déjà utilisé dans une autre classe.\n\t");
        alreadyExists = true;
        break;
      }
    }

    if (!isClassNameValid(tmpName)) {
      system("cls");
      printf("Ce nom de classe contient des caractères interdits ou est trop "
             "court ou trop long.(5,100)\n\t");
    }

    if (!alreadyExists && isClassNameValid(tmpName)) {
      for (int i = 0; i < 100; i++) {
        if (pClasses[i]->id == -1) {
          pClasses[i]->id = *pLastClassId;
          *pLastClassId = (*pLastClassId) + 1;
          strcpy_s(pClasses[i]->name, sizeof(pClasses[i]->name), tmpName);
          strcpy_s(pClasses[i]->date, sizeof(pClasses[i]->date), formattedTime);
          isValid = true;
          break;
        }
      }
    }
  }
  printf("\nL'opération a réussi avec succès.\n");
}

void updateClass(struct CLASS *pClasses[100], struct STUDENT *pStudents[100]) {

  system("cls");

  int tmpClassId;
  bool classExists = false;

  printf(
      "Pour modifier les informations d'une classe, il faut d'abord son ID : ");
  scanf_s("%d", &tmpClassId);

  clearInputBuffer();

  for (int i = 0; i < 100; i++) {
    if (pClasses[i]->id == tmpClassId) {
      classExists = true;
      char tmpClassNameForUpdateStudents[100];
      strcpy_s(tmpClassNameForUpdateStudents,
               sizeof(tmpClassNameForUpdateStudents), pClasses[i]->name);
      char tmpName[100];
      bool isClassNameValidBool = false;
      while (!isClassNameValidBool) {
        printf("S'il te plaît, entre le nouveau nom de la classe :\n\t==> ");
        fgets(tmpName, sizeof(tmpName), stdin);
        size_t len = strlen(tmpName);
        if (len > 0 && tmpName[len - 1] == '\n') {
          tmpName[len - 1] = '\0';
        }
        bool isExists = false;
        for (size_t j = 0; j < 100; j++) {
          if (!strcmp(pClasses[j]->name, tmpName) && j != tmpClassId) {
            system("cls");
            printf(
                "Ce nom de classe est déjà utilisé dans une autre classe.\n\t");
            isExists = true;
            break;
          }
        }
        if (!isExists) {
          if (!isClassNameValid(tmpName)) {
            system("cls");
            printf("Ce nom de classe contient des caractères interdits ou est "
                   "trop "
                   "court ou trop long.(5,100)\n\t");
          } else {
            isClassNameValidBool = true;
          }
        }
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
    printf("\nL'opération a réussi avec succès.\n");
  }
}

void deleteClass(struct CLASS *pClasses[100], struct STUDENT *pStudent[100],
                 int *pLastClassId, int *pLastStudentId) {
  system("cls");
  printf("Pour supprimer une classe, il faut l'ID de cette classe avant la "
         "suppression : ");

  bool classExists = false;
  int tmpClassId;
  scanf_s("%d", &tmpClassId);
  clearInputBuffer();
  char tmpClassNameForDeleteStudents[100];
  for (int i = 0; i < 100; i++) {
    if (pClasses[i]->id == tmpClassId) {
      classExists = true;
      strcpy_s(tmpClassNameForDeleteStudents,
               sizeof(tmpClassNameForDeleteStudents), pClasses[i]->name);
      for (int j = i; j < 99; j++) {
        pClasses[j]->id = pClasses[j + 1]->id;
        strcpy_s(pClasses[j]->name, sizeof(pClasses[j]->name),
                 pClasses[j + 1]->name);
        strcpy_s(pClasses[j]->date, sizeof(pClasses[j]->date),
                 pClasses[j + 1]->date);
        pClasses[j]->studentsNumber = pClasses[j + 1]->studentsNumber;

        pClasses[99]->id = -1;
      }
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
          } else {
            continue;
          }
        }
      }
      break;
    }
  }
  if (!classExists)
    printf("\nIl n'existe pas de classe avec cet identifiant.\n");
  else
    printf("\nL'opération a réussi avec succès.\n");
}

void classInformation(struct CLASS *pClasses[100]) {
  int tmpClassId;
  system("cls");
  printf("Pour voir les informations d'une classe, il faut l'ID de cette "
         "classe : ");

  scanf_s("%d", &tmpClassId);
  clearInputBuffer();
  system("cls");
  bool classExists = false;
  for (int i = 0; i < 100; i++) {
    if (pClasses[i]->id == tmpClassId) {
      classExists = true;
      printf("_______________________________________________________\n\n");
      printf("id                 :: %d\n", pClasses[i]->id);
      printf("nom de class       :: %s\n", pClasses[i]->name);
      printf("nombre d'élèves    :: %d\n", pClasses[i]->studentsNumber);
      printf("date               :: %s\n", pClasses[i]->date);
      printf("_______________________________________________________\n\n");
    }
  }
  if (!classExists)
    printf("\nIl n'existe pas de classe avec ce identifiant.\n");
  else
    printf("\nL'opération a réussi avec succès.\n");
}

void allClassesInformation(struct CLASS *pClasses[100]) {
  system("cls");
  bool classExists = false;
  for (int i = 0; i < 100; i++) {
    if (pClasses[i]->id != -1) {
      classExists = true;
      printf("id                   :: %d\n", pClasses[i]->id);
      printf("nom de class         :: %s\n", pClasses[i]->name);
      printf("nombre d'élèves      :: %d\n", pClasses[i]->studentsNumber);
      printf("date                 :: %s\n", pClasses[i]->date);
      printf("_______________________________________________________\n\n");
    }
  }
  if (!classExists) {
    printf("\nIl n'y a aucune classe dans ces écoles.\n");

  } else {
    printf("\nL'opération a réussi avec succès.\n");
  }
}

int choseOperation(void) {
  int crudOperationNumber;
  int isNumber;
  system("cls");

  printf("################ Bonjour, dans mon système scolaire "
         "#####################\n\n");
  printf("#    ##########                                                      "
         "    #\n");
  printf("#    # classe #                                                      "
         "    #\n");
  printf("#    ##########                                                      "
         "    #\n\n");
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
  printf("#    ############                                                    "
         "    #\n");
  printf("#    # étudiant #                                                    "
         "    #\n");
  printf("#    ############                                                    "
         "    #\n\n");
  printf("#\t:: cS ==> 5 :: Pour ajouter un étudiant                          "
         "#\n");
  printf("#\t:: uS ==> 6 :: pour modifier les informations d'un étudiant      "
         "#\n");
  printf("#\t:: dS ==> 7 :: pour supprimer un étudiant                        "
         "#\n");
  printf("#\t:: rS ==> 8 :: pour voir les informations d'un étudiant          "
         "#\n");
  printf("#\t:: aS ==> 9 :: pour voir les informations de tous les étudiant   "
         "#\n\n");
  printf("#\t:: exit ==> 10 :: pour sortir                                    "
         "#\n\n");
  printf("#####################################################################"
         "####\n\n");

  printf("Quelle opération souhaitez-vous effectuer ? : ");

  while (true) {
    isNumber = scanf_s("%d", &crudOperationNumber);
    clearInputBuffer();
    if (isNumber && crudOperationNumber < 11 && crudOperationNumber >= 0) {
      return crudOperationNumber;
    } else {
      system("cls");
      printf("Veuillez entrer un nombre entre 0 et 10.\n\n\t");
      printf("Nombre d'opérations à effectuer :: ");
    }
  }
}

void createNewStudent(struct STUDENT *pStudent[100],
                      struct CLASS *pClasses[100], int *pLastStudentId,
                      struct CLASS classes[100]) {
  system("cls");

  time_t currentTime;
  time(&currentTime);
  struct tm *localTime = localtime(&currentTime);
  char formattedTime[100];
  strftime(formattedTime, sizeof(formattedTime), "%Y-%m-%d %H-%M-%S",
           localTime);

  char tmpFirstName[100];
  char tmpLastName[100];
  char tmpEmail[100];
  char tmpClassName[100];
  int tmpAge;
  for (int i = 0; i < 100; i++) {
    if (pStudent[i]->id == -1) {
      //  id ##################
      pStudent[i]->id = *pLastStudentId;
      *pLastStudentId = (*pLastStudentId) + 1;
      //  first name ##################
      size_t len;
      bool isFirstNameValid = false;
      bool isLastNameValid = false;
      bool isAgeValid = false;
      bool isEmailValidBool = false;
      while (!isFirstNameValid) {
        printf("S'il te plaît, entre ton prénom :\n\t==> ");
        fgets(tmpFirstName, sizeof(tmpFirstName), stdin);
        len = strlen(tmpFirstName);
        if (len > 0 && tmpFirstName[len - 1] == '\n') {
          tmpFirstName[len - 1] = '\0';
        }
        if (isHummanNameValid(tmpFirstName)) {
          strcpy_s(pStudent[i]->firstName, sizeof(pStudent[i]->firstName),
                   tmpFirstName);
          isFirstNameValid = true;
        } else {
          system("cls");
          printf("Ce prénom contient des caractères interdits ou est trop "
                 "court ou trop long.(5,100)\n\t");
        }
      }

      //  last name ##################

      while (!isLastNameValid) {
        printf("S'il te plaît, entre ton nom:\n\t==> ");
        fgets(tmpLastName, sizeof(tmpLastName), stdin);
        len = strlen(tmpLastName);
        if (len > 0 && tmpLastName[len - 1] == '\n') {
          tmpLastName[len - 1] = '\0';
        }

        strcpy_s(pStudent[i]->lastName, sizeof(pStudent[i]->lastName),
                 tmpLastName);

        if (isHummanNameValid(tmpLastName)) {
          strcpy_s(pStudent[i]->lastName, sizeof(pStudent[i]->lastName),
                   tmpLastName);
          isLastNameValid = true;
        } else {
          system("cls");
          printf("Ce nom contient des caractères interdits ou est trop "
                 "court ou trop long.(5,100)\n\t");
        }
      }

      //  age ##################
      while (!isAgeValid) {
        bool isNumber;
        printf("S'il te plaît, entre ton âge:\n\t==> ");
        isNumber = scanf_s("%d", &tmpAge);
        if (isNumber && tmpAge > 15 && tmpAge < 25) {
          pStudent[i]->age = tmpAge;
          isAgeValid = true;
        } else {
          system("cls");
          printf("S'il te plaît, entre un âge valide entre 15 et 25.\n\t");
        }
        clearInputBuffer();
      }
      //  email ################
      while (!isEmailValidBool) {
        printf("S'il te plaît, entre ton email:\n\t==> ");
        fgets(tmpEmail, sizeof(tmpEmail), stdin);
        len = strlen(tmpEmail);
        if (len > 0 && tmpEmail[len - 1] == '\n') {
          tmpEmail[len - 1] = '\0';
        }
        if (isEmailValid(tmpEmail)) {
          strcpy_s(pStudent[i]->email, sizeof(pStudent[i]->email), tmpEmail);
          strcpy_s(pStudent[i]->date, sizeof(pStudent[i]->date), formattedTime);
          isEmailValidBool = true;
        } else {
          system("cls");
          printf("S'il te plaît, entre un email valide.\n\t");
        }
      }

      //  class  ################
      printf("S'il te plaît, entre ta classe:\n\t==> ");
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
          printf("Cette classe n'existe pas dans l'école??\n");
          printf("S'il te plaît, entre ta classe::\n\t");
        }
      }
      strcpy_s(pStudent[i]->className, sizeof(pStudent[i]->className),
               tmpClassName);
      for (size_t j = 0; j < 100; j++) {
        if (!strcmp(tmpClassName, pClasses[j]->name)) {
          pClasses[j]->studentsNumber = pClasses[j]->studentsNumber + 1;
          break;
        }
      }
      break;
    }
  }
  printf("\nL'opération a réussi avec succès.\n");
}

void updateStudent(struct STUDENT *pStudent[100], struct CLASS *pClasses[100]) {

  system("cls");
  bool studentExists = false;
  printf("Pour modifier les informations d'un étudiant, il faut d'abord l'ID "
         "de cet étudiant : ");

  int tmpStudentId;
  scanf_s("%d", &tmpStudentId);
  clearInputBuffer();
  for (int i = 0; i < 100; i++) {
    if (pStudent[i]->id == tmpStudentId) {
      char oldClassName[100];

      strcpy_s(oldClassName, sizeof(oldClassName), pStudent[i]->className);

      studentExists = true;
      char tmpFirstName[100];
      char tmpLastName[100];
      char tmpEmail[100];
      char tmpClassName[100];

      size_t len;
      bool isFirstNameValid = false;
      bool isLastNameValid = false;
      bool isAgeValid = false;

      while (!isFirstNameValid) {
        printf("S'il te plaît, entre le nouveau prénom:\n\t==> ");
        fgets(tmpFirstName, sizeof(tmpFirstName), stdin);
        len = strlen(tmpFirstName);
        if (len > 0 && tmpFirstName[len - 1] == '\n') {
          tmpFirstName[len - 1] = '\0';
        }
        if (isHummanNameValid(tmpFirstName)) {
          strcpy_s(pStudent[i]->firstName, sizeof(pStudent[i]->firstName),
                   tmpFirstName);
          isFirstNameValid = true;
        } else {
          system("cls");
          printf("Ce prénom contient des caractères interdits ou est trop "
                 "court ou trop long.(5,100)\n\t");
        }
      }

      while (!isLastNameValid) {
        printf("S'il te plaît, entre le nouveau nom :\n\t==> ");
        fgets(tmpLastName, sizeof(tmpLastName), stdin);
        len = strlen(tmpLastName);
        if (len > 0 && tmpLastName[len - 1] == '\n') {
          tmpLastName[len - 1] = '\0';
        }

        strcpy_s(pStudent[i]->lastName, sizeof(pStudent[i]->lastName),
                 tmpLastName);

        if (isHummanNameValid(tmpLastName)) {
          strcpy_s(pStudent[i]->lastName, sizeof(pStudent[i]->lastName),
                   tmpLastName);
          isLastNameValid = true;
        } else {
          system("cls");
          printf("Ce nom contient des caractères interdits ou est trop "
                 "court ou trop long.(5,100)\n\t");
        }
      }

      while (!isAgeValid) {
        bool isNumber;
        int tmpAge;
        printf("S'il te plaît, entre le nouvel âge:\n\t==> ");
        isNumber = scanf_s("%d", &tmpAge);
        if (isNumber && tmpAge > 15 && tmpAge < 25) {
          pStudent[i]->age = tmpAge;
          isAgeValid = true;
        } else {
          system("cls");
          printf("S'il te plaît, entre un âge valide entre 15 et 25.\n\t");
        }
        clearInputBuffer();
      }
      bool isEmailValidBool = false;
      while (!isEmailValidBool) {
        printf("S'il te plaît, entre le nouvel email:\n\t==> ");
        fgets(tmpEmail, sizeof(tmpEmail), stdin);
        len = strlen(tmpEmail);
        if (len > 0 && tmpEmail[len - 1] == '\n') {
          tmpEmail[len - 1] = '\0';
        }
        if (isEmailValid(tmpEmail)) {
          strcpy_s(pStudent[i]->email, sizeof(pStudent[i]->email), tmpEmail);
          isEmailValidBool = true;
        } else {
          system("cls");
          printf("S'il te plaît, entre un email valide.\n\t");
        }
      }

      printf("S'il te plaît, entre la nouvelle classe:\n\t==> ");
      bool isTheSame = false;

      while (!isTheSame) {

        fgets(tmpClassName, sizeof(tmpClassName), stdin);
        len = strlen(tmpClassName);
        if (len > 0 && tmpClassName[len - 1] == '\n') {
          tmpClassName[len - 1] = '\0';
        }

        for (size_t x = 0; x < 100; x++) {
          if (!strcmp(pClasses[x]->name, tmpClassName)) {
            isTheSame = true;
            strcpy_s(pStudent[x]->className, sizeof(pStudent[x]->className),
                     tmpClassName);

            if (strcmp(oldClassName, tmpClassName)) {
              for (size_t j = 0; j < 100; j++) {
                if (!strcmp(tmpClassName, pClasses[j]->name)) {
                  pClasses[j]->studentsNumber = pClasses[j]->studentsNumber + 1;
                  break;
                }
              }

              for (size_t j = 0; j < 100; j++) {
                if (!strcmp(oldClassName, pClasses[j]->name)) {
                  pClasses[j]->studentsNumber = pClasses[j]->studentsNumber - 1;
                  break;
                }
              }
            }

            break;
          }
        }

        if (!isTheSame) {
          system("cls");
          printf("Cette classe n'existe pas dans l'école??\n");
          printf("S'il te plaît, entre ta classe::\n\t");
        }
      }
      break;
    }
  }
  if (!studentExists)
    printf("\nIl n'existe pas d'élève avec cet identifiant.\n");
  else
    printf("\nL'opération a réussi avec succès.\n");
}

void deleteStudent(struct STUDENT *pStudent[100], struct CLASS *pClasses[100],
                   int *pLastStudentId) {
  system("cls");

  printf("Pour supprimer un étudiant, il faut l'ID de cet étudiant avant la "
         "suppression : ");

  bool studentExists = false;
  int tmpStudentId;
  char tmpClasseName[100];
  scanf_s("%d", &tmpStudentId);
  clearInputBuffer();
  for (int i = 0; i < 99; i++) {
    if (pStudent[i]->id == tmpStudentId) {
      strcpy_s(tmpClasseName, sizeof(tmpClasseName), pStudent[i]->className);
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
      for (size_t j = 0; j < 100; j++) {
        if (!strcmp(tmpClasseName, pClasses[j]->name)) {
          pClasses[j]->studentsNumber = pClasses[j]->studentsNumber - 1;
          break;
        }
      }
      break;
    }
  }
  if (!studentExists)
    printf("\nIl n'existe pas d'élève avec cet identifiant.\n");
  else
    printf("\nL'opération a réussi avec succès.\n");
}

void studentInformation(struct STUDENT *pStudents[100]) {
  bool studentExists = false;
  system("cls");
  printf("Pour voir les informations d'un étudiant, il faut l'ID de cet "
         "étudiant : ");

  int tmpStudentId;
  scanf_s("%d", &tmpStudentId);
  clearInputBuffer();
  system("cls");
  for (int i = 0; i < 100; i++)
    if (pStudents[i]->id == tmpStudentId) {
      studentExists = true;
      printf("_______________________________________________________\n\n");
      printf("id                   :: %d\n", pStudents[i]->id);
      printf("prénom               :: %s\n", pStudents[i]->firstName);
      printf("nom de famille       :: %s\n", pStudents[i]->lastName);
      printf("âge                  :: %d\n", pStudents[i]->age);
      printf("mail                 :: %s\n", pStudents[i]->email);
      printf("classe               :: %s\n", pStudents[i]->className);
      printf("date                 :: %s\n", pStudents[i]->date);
      printf("_______________________________________________________\n\n");
    }

  if (!studentExists)
    printf("\nIl n'existe pas d'élève avec cet identifiant.\n");
  else
    printf("\nL'opération a réussi avec succès.\n");
}

void allStudentsInformation(struct STUDENT *pStudents[100]) {
  bool studentExists = false;
  system("cls");

  for (int i = 0; i < 100; i++)
    if (pStudents[i]->id != -1) {
      studentExists = true;
      printf("id                   :: %d\n", pStudents[i]->id);
      printf("prénom               :: %s\n", pStudents[i]->firstName);
      printf("nom de famille       :: %s\n", pStudents[i]->lastName);
      printf("âge                  :: %d\n", pStudents[i]->age);
      printf("mail                 :: %s\n", pStudents[i]->email);
      printf("classe               :: %s\n", pStudents[i]->className);
      printf("date                 :: %s\n", pStudents[i]->date);
      printf("_______________________________________________________\n\n");
    }

  if (!studentExists)
    printf("\nIl n'existe pas d'élève dans cette école.\n");
  else
    printf("\nL'opération a réussi avec succès.\n");
}

void getDataFromFileClasses(struct CLASS *pClasses[100], int *pLastClassId) {
  FILE *pFile = NULL;
  pFile = fopen("classes.txt", "r");
  char myString[1000];
  fgets(myString, 1000, pFile);
  fclose(pFile);
  pFile = NULL;

  char subString[100];

  const char delimiter[] = "|";
  const char subDelimiter[] = ":,";

  char *outer_saveptr = NULL;
  char *inner_saveptr = NULL;

  char *token = (char *)strtok_s(myString, delimiter, &outer_saveptr);

  enum dataElements {
    id,
    idVal,
    name,
    namVal,
    studentsNumber,
    studentsNumberVal,
    date,
    dateVal
  };
  enum dataElements state = id;

  int lastClassId = 0;
  int number;

  while (token != NULL) {
    strcpy_s(subString, sizeof(subString), token);
    char *subToken = (char *)strtok_s(subString, subDelimiter, &inner_saveptr);

    state = id;
    while (subToken != NULL) {
      switch (state) {
      case 0:
        // do nothing
        break;
      case 1:
        number = atoi(subToken);
        pClasses[lastClassId]->id = number;
        break;
      case 2:
        // do nothing
        break;
      case 3:
        strcpy_s(pClasses[lastClassId]->name,
                 sizeof(pClasses[lastClassId]->name), subToken);
        break;
      case 4:
        // do nothing
        break;
      case 5:
        number = atoi(subToken);
        pClasses[lastClassId]->studentsNumber = number;
        break;
      case 6:
        // do nothing
        break;
      case 7:
        strcpy_s(pClasses[lastClassId]->date,
                 sizeof(pClasses[lastClassId]->date), subToken);
        lastClassId = lastClassId + 1;
        *pLastClassId = *pLastClassId + 1;
        break;
      }
      state = state + 1;
      subToken = (char *)strtok_s(NULL, subDelimiter, &inner_saveptr);
    }
    token = (char *)strtok_s(NULL, delimiter, &outer_saveptr);
  }
}

void getDataFromFileStudents(struct STUDENT *pStudent[100],
                             int *pLastStudentId) {
  FILE *pFile = NULL;
  pFile = fopen("students.txt", "r");
  char myString[1000];
  fgets(myString, 1000, pFile);
  fclose(pFile);
  pFile = NULL;

  char subString[200];

  const char delimiter[] = "|";
  const char subDelimiter[] = ":,";

  char *outer_saveptr = NULL;
  char *inner_saveptr = NULL;

  char *token = (char *)strtok_s(myString, delimiter, &outer_saveptr);

  enum dataElements {
    id,
    idVal,
    firstName,
    firstNameVal,
    lastName,
    lastNameVal,
    age,
    ageVal,
    email,
    emailVal,
    className,
    classNameVal,
    datee,
    dateeVal
  };
  enum dataElements state = id;

  int lastStudentId = 0;
  int number;

  while (token != NULL) {
    strcpy_s(subString, sizeof(subString), token);
    char *subToken = (char *)strtok_s(subString, subDelimiter, &inner_saveptr);

    state = id;
    while (subToken != NULL) {
      switch (state) {
      case 0:
        // do nothing
        break;
      case 1:
        number = atoi(subToken);
        pStudent[lastStudentId]->id = number;
        break;
      case 2:
        // do nothing
        break;
      case 3:
        strcpy_s(pStudent[lastStudentId]->firstName,
                 sizeof(pStudent[lastStudentId]->firstName), subToken);
        break;
      case 4:
        // do nothing
        break;
      case 5:
        strcpy_s(pStudent[lastStudentId]->lastName,
                 sizeof(pStudent[lastStudentId]->lastName), subToken);
        break;
      case 6:
        // do nothing
        break;
      case 7:
        number = atoi(subToken);
        pStudent[lastStudentId]->age = number;
        break;
      case 8:
        // do nothing
        break;
      case 9:
        strcpy_s(pStudent[lastStudentId]->email,
                 sizeof(pStudent[lastStudentId]->email), subToken);
        break;
      case 10:
        // do nothing
        break;
      case 11:
        strcpy_s(pStudent[lastStudentId]->className,
                 sizeof(pStudent[lastStudentId]->className), subToken);
        break;
      case 12:
        // do nothing
        break;
      case 13:
        strcpy_s(pStudent[lastStudentId]->date,
                 sizeof(pStudent[lastStudentId]->date), subToken);
        lastStudentId = lastStudentId + 1;
        *pLastStudentId = *pLastStudentId + 1;
        break;
      }
      state = state + 1;
      subToken = (char *)strtok_s(NULL, subDelimiter, &inner_saveptr);
    }
    token = (char *)strtok_s(NULL, delimiter, &outer_saveptr);
  }
}

void putDataIntoFileClasses(struct CLASS *pClasses[100]) {
  FILE *pFile = NULL;
  pFile = fopen("classes.txt", "w");
  if (pFile != NULL) {
    fprintf(pFile, "");
    fclose(pFile);
    pFile = NULL;
  }

  fclose(pFile);
  pFile = NULL;

  pFile = fopen("classes.txt", "a");
  if (pFile != NULL) {
    for (int i = 0; i < 100; i++) {
      if (pClasses[i]->id != -1) {
        fprintf(pFile, "id:%d,", pClasses[i]->id);
        fprintf(pFile, "name:%s,", pClasses[i]->name);
        fprintf(pFile, "studentsNumber:%d,", pClasses[i]->studentsNumber);
        fprintf(pFile, "date:%s|", pClasses[i]->date);
      }
    }
  }

  fclose(pFile);
  pFile = NULL;
}

void putDataIntoFileStudents(struct STUDENT *pStudents[100]) {
  FILE *pFile = NULL;
  pFile = fopen("students.txt", "w");
  if (pFile != NULL) {
    fprintf(pFile, "");
    fclose(pFile);
    pFile = NULL;
  }

  fclose(pFile);
  pFile = NULL;
  pFile = fopen("students.txt", "a");
  if (pFile != NULL) {
    for (int i = 0; i < 100; i++) {
      if (pStudents[i]->id != -1) {
        fprintf(pFile, "id:%d,", pStudents[i]->id);
        fprintf(pFile, "firstName:%s,", pStudents[i]->firstName);
        fprintf(pFile, "lastName:%s,", pStudents[i]->lastName);
        fprintf(pFile, "age:%d,", pStudents[i]->age);
        fprintf(pFile, "email:%s,", pStudents[i]->email);
        fprintf(pFile, "className:%s,", pStudents[i]->className);
        fprintf(pFile, "date:%s|", pStudents[i]->date);
      }
    }
  }

  fclose(pFile);
  pFile = NULL;
}

bool isHummanNameValid(char name[100]) {
  char notAllowedChars[] = "123456789#$^&*_#{[]}\\@=+*";
  bool state = true;

  if (strlen(name) < 5 || strlen(name) > 100) {
    state = false;
  }

  if (state) {
    for (size_t i = 0; i < strlen(name); i++) {
      for (size_t j = 0; j < strlen(notAllowedChars); j++) {
        if (name[i] == notAllowedChars[j]) {
          state = false;
          break;
        }
      }
    }
  }
  return state;
}

bool isClassNameValid(char name[100]) {
  char notAllowedChars[] = "#$^&*_#{[]}\\@=+*";
  bool state = true;
  if (strlen(name) < 5 || strlen(name) > 100) {
    state = false;
  }
  if (state) {
    for (size_t i = 0; i < strlen(name); i++) {
      for (size_t j = 0; j < strlen(notAllowedChars); j++) {
        if (name[i] == notAllowedChars[j]) {
          state = false;
          break;
        }
      }
    }
  }
  return state;
}

bool isEmailValid(char email[100]) {
  bool state = false;
  for (size_t i = 0; i < strlen(email); i++) {
    if (email[i] == '@' && i != 0 && i != strlen(email) - 1) {
      state = true;
    }
  }
  return state;
}