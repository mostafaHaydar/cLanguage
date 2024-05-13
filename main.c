#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// bank management system
void clearInputBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

int operationsOfOurBank(void)
{
  int serviceNumber;
  int isNumber = 0;
  system("cls");
  printf("Bonjour, dans notre banque comment pouvons-nous vous aider ?\n");
  printf("Pour créer votre compte, tapez sur                         : 0\n");
  printf("Pour voir les informations de votre compte, tapez sur      : 1\n");
  printf("Pour modifier le montant, tapez sur                        : 2\n");
  printf("Pour transférer un montant, tapez sur                      : 3\n");
  bool isValid = false;
  while (!isValid)
  {
    printf("votre nombre :: ");
    scanf("%d", &serviceNumber);
    clearInputBuffer();
    if (serviceNumber == 0 ||
        serviceNumber == 1 ||
        serviceNumber == 2 ||
        serviceNumber == 3)
    {
      isValid = true;
      return serviceNumber;
    }
    else
    {
      while (getchar() != '\n')
        ;
      system("cls");
      printf("il n'exists pas un operation avec ce nombre ??\n");
    }
  }
}
struct user
{
  char fullName[50];
  int acountNumber;
  float balance;
};

int main()
{
  int lastAcountNumber = 0;
  char tmpFullName[50];
  struct user newUser[50];
  system("cls");
  int serviceNumber;
  while (
      true)
  {
    serviceNumber = operationsOfOurBank();
    switch (serviceNumber)
    {
    case 0:
      system("cls");
      printf("le nombre de votre operation est :%d", serviceNumber);
      printf("pour cree votre compte il faut dabord un peu de information sur vous.\n");
      printf("votre nom et prenom::");
      fgets(tmpFullName, sizeof(tmpFullName), stdin);
      clearInputBuffer();
      lastAcountNumber = lastAcountNumber + 1;
      newUser[lastAcountNumber].balance = 0;
      newUser[lastAcountNumber].acountNumber = lastAcountNumber;
      strcpy(newUser[lastAcountNumber].fullName, tmpFullName);
      printf("votre nom: %s\n", newUser[lastAcountNumber].fullName);
      printf("votre nombre de compte : %d\n", newUser[lastAcountNumber].acountNumber);
      printf("votre solde: %d\n", newUser[lastAcountNumber].balance);
      printf("pour retour a la principale page tapes a exit : ");
      int exitVar;
      scanf("%d", &exitVar);
      clearInputBuffer();
      if (exitVar == 0)
      {
        break;
      }
      break;
    case 1:
      system("cls");
      printf("le nombre de votre operation est :%d\n", serviceNumber);
      printf("pour voir votre information tapes votre nombre de compte:\n");
      int tmpAcountNumber;
      scanf("%d", &tmpAcountNumber);
      clearInputBuffer();
      for (int i = 0; i <= 50; i++)
      {
        if (newUser[i].acountNumber == tmpAcountNumber)
        {
          printf("votre nom: %s\n", newUser[i].fullName);
          printf("votre nombre de compte : %d\n", newUser[i].acountNumber);
          printf("votre solide: %d\n", newUser[i].balance);
        }
      }
      printf("pour retour a la principale page tapes a exit : ");
      scanf("%d", &exitVar);
      clearInputBuffer();
      if (exitVar == 0)
      {
        break;
      }
      break;
    case 2:
      system("cls");
      printf("le nombre de votre operation est :%d", serviceNumber);
      printf("bonjour pour changes votre");
      break;
    case 3:
      system("cls");
      printf("le nombre de votre operation est :%d", serviceNumber);
      break;
    default:
      serviceNumber = operationsOfOurBank();
      break;
    }
  }
  return 0;
}
