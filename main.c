// #include "main.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int choseOperation(void)
{
  int crudOperationNumber;
  bool isValide = false;
  int isNumber;
  system("cls");
  printf("::0:: pour créer un compte.\n");
  printf("::1:: pour modifier un compte.\n");
  printf("::2:: pour supprimer un compte.\n");
  printf("::3:: pour voir un compte.\n");
  printf("::4:: pour voir tous les comptes.\n");
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
    }
  }
}
void clearInputBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}
int backToMenu(void)
{
  int tmpVar;
  printf("le operation effectue avec succes si vous peux aller vers la page principale tapes sur 0");
  scanf("%d", &tmpVar);
  return tmpVar;
}
struct USER
{
  int id;
  char firstName[50];
  char lastName[50];
  int age;
  char email[100];
};

int lastUserId = 0;
int *pLastUserId = &lastUserId;
struct USER createNewUser(int *pLastUserId)
{
  struct USER user;
  char tmpFirstName[50];
  char tmpLastName[50];
  char tmpEmail[50];
  user.id = *pLastUserId;
  *pLastUserId = *pLastUserId + 1;
  printf("sil te plait entre votre prenom::\n");
  fgets(tmpFirstName, sizeof(tmpFirstName), stdin);
  clearInputBuffer();
  strcpy(user.firstName, tmpFirstName);
  printf("sil te plait entre votre nom::\n");
  fgets(tmpLastName, sizeof(tmpLastName), stdin);
  clearInputBuffer();
  strcpy(user.lastName, tmpLastName);
  printf("sil te plait entre votre age::\n");
  scanf("%d", &user.age);
  clearInputBuffer();
  printf("sil te plait entre votre email::\n");
  fgets(tmpEmail, sizeof(tmpEmail), stdin);
  clearInputBuffer();
  strcpy(user.email, tmpEmail);
  return user;
}
// void allUsersInformations(struct USER users[100])
// {
//   for (int i = 0; i < 100; i++)
//   {
//     if (i != -1)
//     {
//       printf("id==>%d", users[i].id);
//     }
//   }

//   return 0;
// }
int main(void)
{
  struct USER users[100];
  for (int i = 0; i < 100; i++)
  {
    users[i].id = -1;
  }

  int crudOperationNumber;
  // crud system
  while (true)
  {
    int crudOperationNumber;
    crudOperationNumber = choseOperation();
    switch (crudOperationNumber)
    {
    case 0:
      for (int i = 0; i < 100; i++)
      {
        if (users[i].id == -1)
        {
          users[i] = createNewUser(pLastUserId);
          if (backToMenu() == 0)
          {
            break;
          }
        }
      }
      break;
    case 1:
      printf("1");
      break;
    case 2:
      printf("2");
      break;
    case 3:
      printf("3");
      break;
    case 4:
      printf("4");
      for (int i = 0; i < 100; i++)
      {
        if (users[i].id != -1)
        {
          printf("id==>%d", users[i].id);
        }
      }
      if (backToMenu() == 0)
      {
        break;
      }
      break;
    default:
      break;
    }
  }

  return 0;
}
