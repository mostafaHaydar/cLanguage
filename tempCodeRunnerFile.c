#include <stdio.h>
#include <stdbool.h>

// Structure qui represente le compte bancaire
struct Account
{
  char nom[50];
  int num_acc;
  float solde;
};
void clearInputBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}
struct Account creelecompte()
{
  struct Account new_account;

  printf("veuillez enter votre nom : ");
  // scanf("%s", new_account.nom);
  fgets(new_account.nom, sizeof(new_account.nom), stdin);
  clearInputBuffer();

  printf("veuillez enter votre numero de compte : ");
  scanf("%d", &new_account.num_acc);

  printf("veuillez enter votre solde initial : ");
  scanf("%f", &new_account.solde);

  return new_account;
}
void checksolde(struct Account *account)
{
  printf("le solde du compte : %.2f\n", account->solde);
}
void supprimercompte(struct Account *account)
{
  account = 0;
  printf("compte supprimer avec succes.\n");
}
void modifiercompte(struct Account *account)
{
  printf("veuillez enter votre nouveau nom : ");
  scanf("%s", account->nom);

  printf("veuillez enter votre nouveau solde : ");
  scanf("%f", &account->solde);

  printf("votre compte a ete bien modifier .\n");
}
int main()
{
  struct Account accounts[100];
  int num_accounts = 0;

  int choix;
  do
  {
    printf("\n--- //// **gestion bancaire** //// ---\n");
    printf("1. Cree un compte \n");
    printf("2. verifier le solde \n");
    printf("3. supprimer le compte \n");
    printf("4. Modifier le compte \n");
    printf("5. Exit\n");
    printf("veuillez enter votre choix : ");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
      accounts[num_accounts++] = creelecompte();
      break;
    case 2:
      if (num_accounts > 0)
      {
        int acc_num;
        printf("veuillez enter votre numero de compte : ");
        scanf("%d", &acc_num);
        for (int i = 0; i < num_accounts; i++)
        {
          if (accounts[i].num_acc == acc_num)
          {
            checksolde(&accounts[i]);
            break;
          }
          if (i == num_accounts - 1)
            printf("compte anvalid.\n");
        }
      case 3:
        if (num_accounts > 0)
        {
          int acc_num;
          printf("veuillez enter le numero de compte a supprimer : ");
          scanf("%d", &acc_num);
          for (int i = 0; i < num_accounts; i++)
          {
            if (accounts[i].num_acc == acc_num)
            {
              supprimercompte(&accounts[i]);
              break;
            }
            if (i == num_accounts - 1)
              printf("compte non valid .\n");
          }
        }
        else
        {

          printf("Aucun compte disponible.\n");
        }
        break;
      case 4:
        if (num_accounts > 0)
        {
          int acc_num;
          printf("veuillez enter le numero de compte a modifier : ");
          scanf("%d", &acc_num);
          for (int i = 0; i < num_accounts; i++)
          {
            if (accounts[i].num_acc == acc_num)
            {
              modifiercompte(&accounts[i]);
              break;
            }
            if (i == num_accounts - 1)
              printf("compte non valid .\n");
          }
        }
        else
        {
          printf("Aucun compte disponible.\n");
        }
        break;
      case 5:
        printf("Exiting...\n");
        break;
      default:
        printf("Choix invalide. Veuillez réessayer.\n");
      }
    }

  } while (choix != 5);
  return 0;
}