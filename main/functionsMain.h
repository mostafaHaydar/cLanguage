#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct CLASS {
  int id;
  char name[50];
};

int lastClassId = 0;
int *pLastClassId = &lastClassId;

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

struct CLASS createNewClass(int *pLastClassId) {
  system("cls");

  struct CLASS classS;
  char tmpName[50];

  classS.id = *pLastClassId;
  *pLastClassId = (*pLastClassId) + 1;

  printf("S'il te plait, entre le nom de la classe :\n\t==> ");

  fgets(tmpName, sizeof(tmpName), stdin);
  size_t len = strlen(tmpName);
  if (len > 0 && tmpName[len - 1] == '\n') {
    tmpName[len - 1] = '\0';
  }
  strcpy(classS.name, tmpName);

  return classS;
}

void updateClass(struct CLASS *classS) {
  system("cls");
  char tmpName[50];
  printf("S'il te plait, entre le nouveau nom de la class :\n\t==> ");
  fgets(tmpName, sizeof(tmpName), stdin);
  size_t len = strlen(tmpName);
  if (len > 0 && tmpName[len - 1] == '\n') {
    tmpName[len - 1] = '\0';
  }

  strcpy(classS->name, tmpName);
}

struct STUDENT {
  int id;
  char firstName[50];
  char lastName[50];
  int age;
  char email[100];
  char className[50];
};

int lastStudentId = 0;
int *pLastStudentId = &lastStudentId;

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
      printf("Veuillez entrer un nombre entre 0 et 10.\n");
      printf("Votre nombre d'operations : ");
    }
  }
}
int backToMenu(void) {
  int tmpVar;
  printf("\nL'operation a ete effectuee avec succes.\n Si vous pouvez aller "
         "vers la page principale, tapez:: 0 ");
  scanf("%d", &tmpVar);
  return tmpVar;
}

struct STUDENT createNewStudent(int *pLastStudentId,
                                struct CLASS classes[100]) {
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

  printf("S'il te plait, entre votre prenom:\n\t==> ");
  fgets(tmpFirstName, sizeof(tmpFirstName), stdin);
  size_t len = strlen(tmpFirstName);
  if (len > 0 && tmpFirstName[len - 1] == '\n') {
    tmpFirstName[len - 1] = '\0';
  }
  strcpy(student.firstName, tmpFirstName);

  //  last name ##################

  printf("S'il te plait, entre votre nom:\n\t==> ");
  fgets(tmpLastName, sizeof(tmpLastName), stdin);
  len = strlen(tmpLastName);
  if (len > 0 && tmpLastName[len - 1] == '\n') {
    tmpLastName[len - 1] = '\0';
  }

  strcpy(student.lastName, tmpLastName);

  //  age ##################

  printf("S'il te plait, entre votre age:\n\t==> ");
  scanf("%d", &tmpAge);
  student.age = tmpAge;

  clearInputBuffer();

  //  email ################

  printf("S'il te plait, entre votre email:\n\t==> ");
  fgets(tmpEmail, sizeof(tmpEmail), stdin);
  len = strlen(tmpEmail);
  if (len > 0 && tmpEmail[len - 1] == '\n') {
    tmpEmail[len - 1] = '\0';
  }
  strcpy(student.email, tmpEmail);
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

  strcpy(student.className, tmpClassName);
  //  end ##################
  return student;
}

void updateStudent(struct STUDENT *student) {
  system("cls");

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

  strcpy(student->firstName, tmpFirstName);
  printf("S'il te plait, entre le nouveau  nom:\n\t==> ");
  fgets(tmpLastName, sizeof(tmpLastName), stdin);
  len = strlen(tmpLastName);
  if (len > 0 && tmpLastName[len - 1] == '\n') {
    tmpLastName[len - 1] = '\0';
  }

  strcpy(student->lastName, tmpLastName);
  printf("S'il te plait, entre le nouveau  age:\n\t==> ");
  scanf("%d", &student->age);
  clearInputBuffer();

  printf("S'il te plait, entre le nouveau  email:\n\t==> ");
  fgets(tmpEmail, sizeof(tmpEmail), stdin);
  len = strlen(tmpEmail);
  if (len > 0 && tmpEmail[len - 1] == '\n') {
    tmpEmail[len - 1] = '\0';
  }

  strcpy(student->email, tmpEmail);

  printf("S'il te plait, entre le nouveau  class:\n\t==> ");
  fgets(tmpClassName, sizeof(tmpClassName), stdin);
  len = strlen(tmpClassName);
  if (len > 0 && tmpClassName[len - 1] == '\n') {
    tmpClassName[len - 1] = '\0';
  }

  strcpy(student->email, tmpClassName);
}
