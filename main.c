#include "main.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int lastUserId = 0;
int *pLastUserId = &lastUserId;
int main(void)
{
  struct USER users[100];
  struct USER *pUsers[100];
  for (int i = 0; i < 100; i++)
  {
    pUsers[i] = &users[i];
  }
  for (int i = 0; i < 100; i++)
  {
    users[i].id = -1;
  }

  int crudOperationNumber;
  int tmpUserId;
  char tmpFirstName[50];
  char tmpLastName[50];
  char tmpEmail[100];
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
      printf("Pour modifier les informations d'un client, il faut d'abord l'ID de ce client : ");
      scanf("%d", &tmpUserId);
      clearInputBuffer();
      for (int i = 0; i < 100; i++)
      {
        if (users[i].id == tmpUserId)
        {
          updateUser(pUsers[i]);
        }
      }
      if (backToMenu() == 0)
      {
        break;
      }
      break;
    case 2:
      printf("Pour supprimer un compte client, il faut l'ID de ce client avant la suppression : ");
      scanf("%d", &tmpUserId);
      clearInputBuffer();
      for (int i = 0; i < 100; i++)
      {
        if (users[i].id == tmpUserId)
        {
          for (int j = i; j < 100; j++)
          {
            users[j] = users[j + 1];
            users[99].id = -1;
          }
        }
      }
      if (backToMenu() == 0)
      {
        break;
      }
      break;
    case 3:
      // system("cls");
      printf("Pour voir les informations d'un client, il faut l'ID de ce client : ");
      scanf("%d", &tmpUserId);
      clearInputBuffer();
      for (int i = 0; i < 100; i++)
      {
        if (users[i].id == tmpUserId)
        {
          printf("id             ::%d\n", users[i].id);
          printf("firstName      ::%s\n", users[i].firstName);
          printf("lastName       ::%s\n", users[i].lastName);
          printf("age            ::%d\n", users[i].age);
          printf("email          ::%s\n", users[i].email);
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
        if (users[i].id != -1)
        {
          printf("user :: %d\n", i);
          printf("id             ::%d\n", users[i].id);
          printf("firstName      ::%s\n", users[i].firstName);
          printf("lastName       ::%s\n", users[i].lastName);
          printf("age            ::%d\n", users[i].age);
          printf("email          ::%s\n", users[i].email);
        }
      }
      if (backToMenu() == 0)
      {
        break;
      }
      break;
    default:
      crudOperationNumber = choseOperation();
      break;
    }
  }

  return 0;
}
