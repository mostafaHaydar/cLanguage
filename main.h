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