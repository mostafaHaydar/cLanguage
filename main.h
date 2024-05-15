#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct USER
{
  int id;
  char firstName[50];
  char lastName[50];
  int age;
  char email[100];
};

void clearInputBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

int choseOperation(void)
{
  int crudOperationNumber;
  bool isValide = false;
  int isNumber;
  system("cls");
  printf("################ Bonjour dans mon système CRUD ################\n\n");
  printf("\t:: c==> 0 :: pour créer un compte.\n");
  printf("\t:: u==> 1 :: pour modifier un compte.\n");
  printf("\t:: d==> 2 :: pour supprimer un compte.\n");
  printf("\t:: s==> 3 :: pour voir un compte.\n");
  printf("\t:: d==> 4 :: pour voir tous les comptes.\n\n");
  printf("Votre nombre d'opérations : ");

  while (!isValide)
  {
    isNumber = scanf("%d", &crudOperationNumber);
    clearInputBuffer();
    if (isNumber && (crudOperationNumber == 0 ||
                     crudOperationNumber == 1 ||
                     crudOperationNumber == 2 ||
                     crudOperationNumber == 3 ||
                     crudOperationNumber == 4))
    {
      return crudOperationNumber;
      break;
    }
    else
    {
      while (getchar() != '\n')
        ;
      system("cls");
      printf("Veuillez entrer un nombre entre 0 et 4.\n");
      printf("Votre nombre d'opérations : ");
    }
  }
}
int backToMenu(void)
{
  int tmpVar;
  printf("\nL'opération a été effectuée avec succès. Si vous pouvez aller vers la page principale, tapez:: 0 .");
  scanf("%d", &tmpVar);
  return tmpVar;
}
struct USER createNewUser(int *pLastUserId)
{
  struct USER user;
  char tmpFirstName[50];
  char tmpLastName[50];
  char tmpEmail[100];
  user.id = *pLastUserId;
  *pLastUserId = (*pLastUserId) + 1;

  printf("S'il te plaît, entre votre prénom:\n\t==> ");
  fgets(tmpFirstName, sizeof(tmpFirstName), stdin);
  size_t len = strlen(tmpFirstName);
  if (len > 0 && tmpFirstName[len - 1] == '\n')
  {
    tmpFirstName[len - 1] = '\0';
  }
  strcpy(user.firstName, tmpFirstName);

  printf("S'il te plaît, entre votre nom:\n\t==> ");
  fgets(tmpLastName, sizeof(tmpLastName), stdin);
  len = strlen(tmpLastName);
  if (len > 0 && tmpLastName[len - 1] == '\n')
  {
    tmpLastName[len - 1] = '\0';
  }

  strcpy(user.lastName, tmpLastName);

  printf("S'il te plaît, entre votre âge:\n\t==> ");
  scanf("%d", &user.age);
  clearInputBuffer();

  printf("S'il te plaît, entre votre email:\n\t==> ");
  fgets(tmpEmail, sizeof(tmpEmail), stdin);
  len = strlen(tmpEmail);
  if (len > 0 && tmpEmail[len - 1] == '\n')
  {
    tmpEmail[len - 1] = '\0';
  }
  strcpy(user.email, tmpEmail);

  return user;
}

void updateUser(struct USER *user)
{

  char tmpFirstName[50];
  char tmpLastName[50];
  char tmpEmail[100];

  printf("S'il te plaît, entre le nouveau prénom:\n\t==> ");
  fgets(tmpFirstName, sizeof(tmpFirstName), stdin);
  size_t len = strlen(tmpFirstName);
  if (len > 0 && tmpFirstName[len - 1] == '\n')
  {
    tmpFirstName[len - 1] = '\0';
  }

  strcpy(user->firstName, tmpFirstName);
  printf("S'il te plaît, entre le nouveau  nom:\n\t==> ");
  fgets(tmpLastName, sizeof(tmpLastName), stdin);
  len = strlen(tmpLastName);
  if (len > 0 && tmpLastName[len - 1] == '\n')
  {
    tmpLastName[len - 1] = '\0';
  }

  strcpy(user->lastName, tmpLastName);
  printf("S'il te plaît, entre le nouveau  âge:\n\t==> ");
  scanf("%d", user->age);
  clearInputBuffer();

  printf("S'il te plaît, entre le nouveau  email:\n\t==> ");
  fgets(tmpEmail, sizeof(tmpEmail), stdin);
  len = strlen(tmpEmail);
  if (len > 0 && tmpEmail[len - 1] == '\n')
  {
    tmpEmail[len - 1] = '\0';
  }
  strcpy(user->email, tmpEmail);
}
