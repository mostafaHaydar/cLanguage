#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct CLASS
{
    int id;
    char name[50];
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
    int isNumber;
    system("cls");

    printf("################ Bonjour dans mon système scolaire ################\n\n");
    printf("\t:: c ==> 0 :: pour ajouter un étudiant ou une classe\n");
    printf("\t:: u ==> 1 :: pour modifier les informations d'un étudiant\n");
    printf("\t:: d ==> 2 :: pour supprimer un étudiant\n");
    printf("\t:: r ==> 3 :: pour voir les informations d'un étudiant\n");
    printf("\t:: a ==> 4 :: pour voir les informations de tous les étudiants\n\n");
    printf("\t:: exit ==> 5 :: pour sortir\n\n");
    printf("Votre choix d'opération : ");

    while (true)
    {
        isNumber = scanf("%d", &crudOperationNumber);
        clearInputBuffer();
        if (isNumber && crudOperationNumber < 6 && crudOperationNumber >= 0)
        {
            return crudOperationNumber;
            break;
        }
        else
        {
            clearInputBuffer();
            system("cls");
            printf("Veuillez entrer un nombre entre 0 et 4.\n");
            printf("Votre nombre d'opérations : ");
        }
    }
}
int backToMenu(void)
{
    int tmpVar;
    printf("\nL'opération a été effectuée avec succès. Si vous pouvez aller vers la page principale, tapez:: 0 ==>");
    scanf("%d", &tmpVar);
    return tmpVar;
}

struct CLASS createNewClass(int *pLastClassId)
{
    struct CLASS class;
    char tmpName[50];
    int tmpAge;
    //  id ##################
    class.id = *pLastClassId;
    *pLastClassId = (*pLastClassId) + 1;

    printf("S'il te plaît, entre votre prénom:\n\t==> ");
    fgets(tmpName, sizeof(tmpName), stdin);
    size_t len = strlen(tmpName);
    if (len > 0 && tmpName[len - 1] == '\n')
    {
        tmpName[len - 1] = '\0';
    }
    strcpy(class.name, tmpName);
    return class;
}

void updateClass(struct CLASS *class)
{
    char tmpName[50];
    printf("S'il te plaît, entre le nouveau prénom:\n\t==> ");
    fgets(tmpName, sizeof(tmpName), stdin);
    size_t len = strlen(tmpName);
    if (len > 0 && tmpName[len - 1] == '\n')
    {
        tmpName[len - 1] = '\0';
    }

    strcpy(class->name, tmpName);
}
