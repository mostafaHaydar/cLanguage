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

void createNewClass(int *pLastClassId) {
  system("cls");

  current =
      (struct CLASS_LINKED_LISTS *)malloc(sizeof(struct CLASS_LINKED_LISTS));

  if (first == NULL) {
    first = current;
  }

  if (previous != NULL) {
    previous->next = current;
  }

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

    // check class name if alreay used by another class

    struct CLASS_LINKED_LISTS *tmpCurrent = first;
    while (tmpCurrent != NULL) {
      if (!strcmp(tmpCurrent->name, tmpName)) {
        system("cls");
        printf("Ce nom de classe est déjà utilisé dans une autre classe.\n\t");
        alreadyExists = true;
        break;
      }
      tmpCurrent = tmpCurrent->next;
    }

    if (!isClassNameValid(tmpName)) {
      system("cls");
      printf("Ce nom de classe contient des caractères interdits ou est trop "
             "court ou trop long.(5,100)\n\t");
    }

    if (!alreadyExists && isClassNameValid(tmpName)) {
      current->id = *pLastClassId;

      *pLastClassId = (*pLastClassId) + 1;
      strcpy_s(current->name, sizeof(current->name), tmpName);
      current->studentsNumber = 0;
      strcpy_s(current->date, sizeof(current->date), formattedTime);
      isValid = true;
      break;
    }
  }
  current->next = NULL;
  previous = current;
  printf("\nL'opération a réussi avec succès.\n");
}

void updateClass() {

  system("cls");

  current = first;

  int tmpClassId;
  bool classExists = false;

  printf(
      "Pour modifier les informations d'une classe, il faut d'abord son ID : ");
  scanf_s("%d", &tmpClassId);

  clearInputBuffer();
  while (current != NULL) {
    if (current->id == tmpClassId) {
      classExists = true;
      char tmpClassNameForUpdateStudents[100];
      strcpy_s(tmpClassNameForUpdateStudents,
               sizeof(tmpClassNameForUpdateStudents), current->name);
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

        // check class name if alreay used by another class

        struct CLASS_LINKED_LISTS *tmpCurrent = first;
        while (tmpCurrent != NULL) {
          if (!strcmp(tmpCurrent->name, tmpName)) {
            system("cls");
            printf(
                "Ce nom de classe est déjà utilisé dans une autre classe.\n\t");
            isExists = true;
            break;
          }
          tmpCurrent = tmpCurrent->next;
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

      strcpy_s(current->name, sizeof(current->name), tmpName);

      current_s = first_s;
      while (current_s != NULL) {
        if (!strcmp(current_s->className, tmpClassNameForUpdateStudents)) {
          strcpy_s(current_s->className, sizeof(current_s->className),
                   current->name);
        } else {
          continue;
        }
        current_s = current_s->next;
      }
    }
    current = current->next;
  }

  if (!classExists) {
    printf("\nIl n'existe pas de classe avec cet identifiant.\n");
  } else {
    printf("\nL'opération a réussi avec succès.\n");
  }
}

void deleteClass() {

  system("cls");
  printf("Pour supprimer une classe, il faut l'ID de cette classe avant la "
         "suppression : ");

  bool classExists = false;
  int tmpClassId;
  scanf_s("%d", &tmpClassId);
  clearInputBuffer();
  char tmpClassNameForDeleteStudents[100];
  current = first;
  previous = NULL;
  while (current != NULL) {
    if (current->id == tmpClassId) {
      classExists = true;
      strcpy_s(tmpClassNameForDeleteStudents,
               sizeof(tmpClassNameForDeleteStudents), current->name);

      previous->next = current->next;
      free(current);
      current = NULL;

      current_s = first_s;
      while (current_s != NULL) {
        if (!strcmp(current_s->className, tmpClassNameForDeleteStudents)) {
          previous_s->next = current_s->next;
          free(current_s);
        } else {
          continue;
        }
        current_s = current_s->next;
      }
      break;
    }
    previous = current;
    current = current->next;
  }

  if (!classExists)
    printf("\nIl n'existe pas de classe avec cet identifiant.\n");
  else
    printf("\nL'opération a réussi avec succès.\n");
}

void classInformation() {
  int tmpClassId;
  system("cls");
  printf("Pour voir les informations d'une classe, il faut l'ID de cette "
         "classe : ");

  scanf_s("%d", &tmpClassId);
  clearInputBuffer();
  system("cls");
  bool classExists = false;

  current = first;

  while (current != NULL) {
    if (current->id == tmpClassId) {
      classExists = true;
      printf("_______________________________________________________\n\n");
      printf("id                 :: %d\n", current->id);
      printf("nom de class       :: %s\n", current->name);
      printf("nombre d'élèves    :: %d\n", current->studentsNumber);
      printf("date               :: %s\n", current->date);
      printf("_______________________________________________________\n\n");
    }
    current = current->next;
  }
  if (!classExists)
    printf("\nIl n'existe pas de classe avec ce identifiant.\n");
  else
    printf("\nL'opération a réussi avec succès.\n");
}

void allClassesInformation() {
  system("cls");
  bool classExists = false;
  current = first;

  while (current != NULL) {
    classExists = true;
    printf("_______________________________________________________\n\n");
    printf("id                 :: %d\n", current->id);
    printf("nom de class       :: %s\n", current->name);
    printf("nombre d'élèves    :: %d\n", current->studentsNumber);
    printf("date               :: %s\n", current->date);
    printf("_______________________________________________________\n\n");
    current = current->next;
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

  printf("####################################################"
         "######################\n");
  printf("################ Bonjour, dans mon système scolaire "
         "######################\n");
  printf("####################################################"
         "######################\n");
  printf(
      "#                                                                      "
      "  #\n");
  printf(
      "#                                                                      "
      "  #\n");
  printf("#    ##########                                                      "
         "    #\n");
  printf("#    # classe #                                                      "
         "    #\n");

  printf("#    ##########                                                      "
         "    #\n");
  printf(
      "#                                                                      "
      "  #\n");
  printf("#\t:: cC ==> 0 :: pour ajouter une classe                           "
         "#\n");
  printf("#\t:: uC ==> 1 :: pour modifier les informations d'une classe       "
         "#\n");
  printf("#\t:: dC ==> 2 :: pour supprimer une classe                         "
         "#\n");
  printf("#\t:: rC ==> 3 :: pour voir les informations d'une classe           "
         "#\n");
  printf("#\t:: aC ==> 4 :: pour voir les informations de toutes les classes  "
         "#\n");
  printf(
      "#                                                                      "
      "  #\n");
  printf("#    ############                                                    "
         "    #\n");
  printf("#    # étudiant #                                                    "
         "    #\n");
  printf("#    ############                                                    "
         "    #\n");
  printf(
      "#                                                                      "
      "  #\n");
  printf("#\t:: cS ==> 5 :: Pour ajouter un étudiant                          "
         "#\n");
  printf("#\t:: uS ==> 6 :: pour modifier les informations d'un étudiant      "
         "#\n");
  printf("#\t:: dS ==> 7 :: pour supprimer un étudiant                        "
         "#\n");
  printf("#\t:: rS ==> 8 :: pour voir les informations d'un étudiant          "
         "#\n");
  printf("#\t:: aS ==> 9 :: pour voir les informations de tous les étudiant   "
         "#\n");
  printf(
      "#                                                                      "
      "  #\n");
  printf(
      "#                                                                      "
      "  #\n");
  printf("#\t:: exit ==> 10 :: pour sortir                                    "
         "#\n");
  printf(
      "#                                                                      "
      "  #\n");
  printf(
      "#                                                                      "
      "  #\n");
  printf(
      "######################################################################"
      "####\n\n\t");

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

void createNewStudent(int *pLastStudentId) {
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

  current_s = (struct STUDENT_LINKED_LISTS *)malloc(
      sizeof(struct STUDENT_LINKED_LISTS));

  if (first_s == NULL) {
    first_s = current_s;
  }
  if (previous_s != NULL) {
    previous_s->next = current_s;
  }

  current_s->id = *pLastStudentId;
  *pLastStudentId = (*pLastStudentId) + 1;

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
      strcpy_s(current_s->firstName, sizeof(current_s->firstName),
               tmpFirstName);
      isFirstNameValid = true;
    } else {
      system("cls");
      printf("Ce prénom contient des caractères interdits ou est trop "
             "court ou trop long.(5,100)\n\t");
    }
  }
  while (!isLastNameValid) {
    printf("S'il te plaît, entre ton nom:\n\t==> ");
    fgets(tmpLastName, sizeof(tmpLastName), stdin);
    len = strlen(tmpLastName);
    if (len > 0 && tmpLastName[len - 1] == '\n') {
      tmpLastName[len - 1] = '\0';
    }

    if (isHummanNameValid(tmpLastName)) {
      strcpy_s(current_s->lastName, sizeof(current_s->lastName), tmpLastName);
      isLastNameValid = true;
    } else {
      system("cls");
      printf("Ce nom contient des caractères interdits ou est trop "
             "court ou trop long.(5,100)\n\t");
    }
  }

  while (!isAgeValid) {
    bool isNumber;
    printf("S'il te plaît, entre ton âge:\n\t==> ");
    isNumber = scanf_s("%d", &tmpAge);
    if (isNumber && tmpAge > 15 && tmpAge < 25) {
      current_s->age = tmpAge;
      isAgeValid = true;
    } else {
      system("cls");
      printf("S'il te plaît, entre un âge valide entre 15 et 25.\n\t");
    }
    clearInputBuffer();
  }

  while (!isEmailValidBool) {
    printf("S'il te plaît, entre ton email:\n\t==> ");
    fgets(tmpEmail, sizeof(tmpEmail), stdin);
    len = strlen(tmpEmail);
    if (len > 0 && tmpEmail[len - 1] == '\n') {
      tmpEmail[len - 1] = '\0';
    }
    if (isEmailValid(tmpEmail)) {
      strcpy_s(current_s->email, sizeof(current_s->email), tmpEmail);
      strcpy_s(current_s->date, sizeof(current_s->date), formattedTime);
      isEmailValidBool = true;
    } else {
      system("cls");
      printf("S'il te plaît, entre un email valide.\n\t");
    }
  }

  printf("S'il te plaît, entre ta classe:\n\t==> ");
  bool isTheSame = false;
  while (!isTheSame) {
    fgets(tmpClassName, sizeof(tmpClassName), stdin);
    len = strlen(tmpClassName);
    if (len > 0 && tmpClassName[len - 1] == '\n') {
      tmpClassName[len - 1] = '\0';
    }

    struct CLASS_LINKED_LISTS *tmpCurrent = first;
    while (tmpCurrent != NULL) {
      if (!strcmp(tmpCurrent->name, tmpClassName)) {
        tmpCurrent->studentsNumber = tmpCurrent->studentsNumber + 1;
        isTheSame = true;
        break;
      }
      tmpCurrent = tmpCurrent->next;
    }

    if (!isTheSame) {
      system("cls");
      printf("Cette classe n'existe pas dans l'école??\n");
      printf("S'il te plaît, entre ta classe::\n\t");
    }
  }

  strcpy_s(current_s->className, sizeof(current_s->className), tmpClassName);

  current_s->next = NULL;
  previous_s = current_s;
  printf("\nL'opération a réussi avec succès.\n");
}

void updateStudent() {

  system("cls");
  bool studentExists = false;
  printf("Pour modifier les informations d'un étudiant, il faut d'abord l'ID "
         "de cet étudiant : ");

  int tmpStudentId;
  scanf_s("%d", &tmpStudentId);
  clearInputBuffer();

  current_s = first_s;

  while (current_s != NULL) {
    if (current_s->id == tmpStudentId) {
      char oldClassName[100];

      strcpy_s(oldClassName, sizeof(oldClassName), current_s->className);

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
          strcpy_s(current_s->firstName, sizeof(current_s->firstName),
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

        strcpy_s(current_s->lastName, sizeof(current_s->lastName), tmpLastName);

        if (isHummanNameValid(tmpLastName)) {
          strcpy_s(current_s->lastName, sizeof(current_s->lastName),
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
          current_s->age = tmpAge;
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
          strcpy_s(current_s->email, sizeof(current_s->email), tmpEmail);
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

        current = first;
        while (current != NULL) {
          if (!strcmp(current->name, tmpClassName)) {
            isTheSame = true;

            strcpy_s(current_s->className, sizeof(current_s->className),
                     tmpClassName);

            if (strcmp(oldClassName, tmpClassName)) {

              current->studentsNumber = current->studentsNumber + 1;

              struct CLASS_LINKED_LISTS *tmpCurrent = first;
              while (tmpCurrent) {
                if (!strcmp(oldClassName, tmpCurrent->name)) {
                  tmpCurrent->studentsNumber = tmpCurrent->studentsNumber - 1;
                  break;
                }
                tmpCurrent = tmpCurrent->next;
              }
            }
            break;
          }
          current = current->next;
        }

        if (!isTheSame) {
          system("cls");
          printf("Cette classe n'existe pas dans l'école??\n");
          printf("S'il te plaît, entre ta classe::\n\t");
        }
      }
      break;
    }
    current_s = current_s->next;
  }
  if (!studentExists)
    printf("\nIl n'existe pas d'élève avec cet identifiant.\n");
  else
    printf("\nL'opération a réussi avec succès.\n");
}

void deleteStudent() {

  system("cls");

  printf("Pour supprimer un étudiant, il faut l'ID de cet étudiant avant la "
         "suppression : ");

  bool studentExists = false;
  int tmpStudentId;
  char tmpClasseName[100];
  scanf_s("%d", &tmpStudentId);
  clearInputBuffer();

  current_s = first_s;
  previous_s = NULL;

  current = first;

  while (current_s != NULL) {
    if (current_s->id == tmpStudentId) {
      strcpy_s(tmpClasseName, sizeof(tmpClasseName), current_s->className);
      studentExists = true;
      previous_s->next = current_s->next;

      while (current != NULL) {
        if (!strcmp(tmpClasseName, current->name)) {
          current->studentsNumber = current->studentsNumber - 1;
          break;
        }
        current = current->next;
      }
      break;
    }
    current_s = current_s->next;
    previous_s = current_s;
  }

  if (!studentExists)
    printf("\nIl n'existe pas d'élève avec cet identifiant.\n");
  else
    printf("\nL'opération a réussi avec succès.\n");
}

void studentInformation() {

  bool studentExists = false;
  system("cls");
  printf("Pour voir les informations d'un étudiant, il faut l'ID de cet "
         "étudiant : ");

  int tmpStudentId;
  scanf_s("%d", &tmpStudentId);
  clearInputBuffer();
  system("cls");

  current_s = first_s;
  while (current_s != NULL) {
    if (current_s->id == tmpStudentId) {
      studentExists = true;
      printf("_______________________________________________________\n\n");
      printf("id                   :: %d\n", current_s->id);
      printf("prénom               :: %s\n", current_s->firstName);
      printf("nom de famille       :: %s\n", current_s->lastName);
      printf("âge                  :: %d\n", current_s->age);
      printf("mail                 :: %s\n", current_s->email);
      printf("classe               :: %s\n", current_s->className);
      printf("date                 :: %s\n", current_s->date);
      printf("_______________________________________________________\n\n");
    }
    current_s = current_s->next;
  }

  if (!studentExists)
    printf("\nIl n'existe pas d'élève avec cet identifiant.\n");
  else
    printf("\nL'opération a réussi avec succès.\n");
}

void allStudentsInformation() {
  bool studentExists = false;
  system("cls");

  current_s = first_s;
  while (current_s != NULL) {
    studentExists = true;
    printf("_______________________________________________________\n\n");
    printf("id                   :: %d\n", current_s->id);
    printf("prénom               :: %s\n", current_s->firstName);
    printf("nom de famille       :: %s\n", current_s->lastName);
    printf("âge                  :: %d\n", current_s->age);
    printf("mail                 :: %s\n", current_s->email);
    printf("classe               :: %s\n", current_s->className);
    printf("date                 :: %s\n", current_s->date);
    printf("_______________________________________________________\n\n");
    current_s = current_s->next;
  }

  if (!studentExists)
    printf("\nIl n'existe pas d'élève dans cette école.\n");
  else
    printf("\nL'opération a réussi avec succès.\n");
}

void getDataFromFileClasses(int *pLastClassId) {

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
    current =
        (struct CLASS_LINKED_LISTS *)malloc(sizeof(struct CLASS_LINKED_LISTS));

    if (first == NULL) {
      first = current;
    }
    if (previous != NULL) {
      previous->next = current;
    }
    while (subToken != NULL) {
      switch (state) {
      case 0:
        // do nothing
        break;
      case 1:
        number = atoi(subToken);
        current->id = number;
        break;
      case 2:
        // do nothing
        break;
      case 3:
        strcpy_s(current->name, sizeof(current->name), subToken);
        break;
      case 4:
        // do nothing
        break;
      case 5:
        number = atoi(subToken);
        current->studentsNumber = number;
        break;
      case 6:
        // do nothing
        break;
      case 7:
        strcpy_s(current->date, sizeof(current->date), subToken);
        *pLastClassId = *pLastClassId + 1;
        break;
      }
      state = state + 1;
      subToken = (char *)strtok_s(NULL, subDelimiter, &inner_saveptr);
    }
    current->next = NULL;
    previous = current;
    token = (char *)strtok_s(NULL, delimiter, &outer_saveptr);
  }
}

void getDataFromFileStudents(int *pLastStudentId) {
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
    current_s = (struct STUDENT_LINKED_LISTS *)malloc(
        sizeof(struct STUDENT_LINKED_LISTS));

    if (first_s == NULL) {
      first_s = current_s;
    }
    if (previous_s != NULL) {
      previous_s->next = current_s;
    }
    while (subToken != NULL) {
      switch (state) {
      case 0:
        // do nothing
        break;
      case 1:
        number = atoi(subToken);
        current_s->id = number;
        break;
      case 2:
        // do nothing
        break;
      case 3:
        strcpy_s(current_s->firstName, sizeof(current_s->firstName), subToken);
        break;
      case 4:
        // do nothing
        break;
      case 5:
        strcpy_s(current_s->lastName, sizeof(current_s->lastName), subToken);
        break;
      case 6:
        // do nothing
        break;
      case 7:
        number = atoi(subToken);
        current_s->age = number;
        break;
      case 8:
        // do nothing
        break;
      case 9:
        strcpy_s(current_s->email, sizeof(current_s->email), subToken);
        break;
      case 10:
        // do nothing
        break;
      case 11:
        strcpy_s(current_s->className, sizeof(current_s->className), subToken);
        break;
      case 12:
        // do nothing
        break;
      case 13:
        strcpy_s(current_s->date, sizeof(current_s->date), subToken);
        lastStudentId = lastStudentId + 1;
        *pLastStudentId = *pLastStudentId + 1;
        break;
      }
      state = state + 1;
      subToken = (char *)strtok_s(NULL, subDelimiter, &inner_saveptr);
    }
    current_s->next = NULL;
    previous_s = current_s;
    token = (char *)strtok_s(NULL, delimiter, &outer_saveptr);
  }
}

void putDataIntoFileClasses() {
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

  current = first;
  previous = NULL;
  if (pFile != NULL) {

    while (current != NULL) {

      fprintf(pFile, "id:%d,", current->id);
      fprintf(pFile, "name:%s,", current->name);
      fprintf(pFile, "studentsNumber:%d,", current->studentsNumber);
      fprintf(pFile, "date:%s|", current->date);

      previous = current;
      current = current->next;
      free(previous);
      previous = NULL;
    }
  }

  fclose(pFile);
  pFile = NULL;
}

void putDataIntoFileStudents() {
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

    current_s = first_s;
    previous_s = NULL;

    while (current_s != NULL) {

      fprintf(pFile, "id:%d,", current_s->id);
      fprintf(pFile, "firstName:%s,", current_s->firstName);
      fprintf(pFile, "lastName:%s,", current_s->lastName);
      fprintf(pFile, "age:%d,", current_s->age);
      fprintf(pFile, "email:%s,", current_s->email);
      fprintf(pFile, "className:%s,", current_s->className);
      fprintf(pFile, "date:%s|", current_s->date);

      previous_s = current_s;
      current_s = current_s->next;
      free(previous_s);
      previous_s = NULL;
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