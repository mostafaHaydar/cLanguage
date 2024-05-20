#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
    printf("\t:: c ==> 5 :: pour ajouter un class \n");
    printf("\t:: u ==> 6 :: pour modifier les informations d'un class\n");
    printf("\t:: d ==> 7 :: pour supprimer un class\n");
    printf("\t:: r ==> 8 :: pour voir les informations d'un class\n");
    printf("\t:: a ==> 9 :: pour voir les informations de tous les étudiants\n\n");
    printf("\t:: exit ==> 10 :: pour sortir\n\n");
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

int lastClassId = 0;

int *pLastClassId = &lastClassId;
int main(void)
{
    struct CLASS classes[100];
    struct CLASS *pClasses[100];
    for (int i = 0; i < 100; i++)
    {
        pClasses[i] = &classes[i];
    }

    for (int i = 0; i < 100; i++)
    {
        classes[i].id = -1;
    }

    int tmpClassId;

    while (true)
    {
        int crudOperationNumber;
        crudOperationNumber = choseOperation();
        switch (crudOperationNumber)
        {
        case 0:
            for (int i = 0; i < 100; i++)
            {
                if (classes[i].id == -1)
                {
                    classes[i] = createNewClass(pLastClassId);
                    if (backToMenu() == 0)
                    {
                        break;
                    }
                }
            }
            break;
        case 1:
            printf("Pour modifier les informations d'un étudiant, il faut d'abord l'ID de cet étudiant : ");

            scanf("%d", &tmpClassId);
            clearInputBuffer();
            for (int i = 0; i < 100; i++)
            {
                if (classes[i].id == tmpClassId)
                {
                    updateStudent(pClasses[i]);
                }
            }
            if (backToMenu() == 0)
            {
                break;
            }
            break;
        case 2:
            printf("Pour supprimer un étudiant, il faut l'ID de cet étudiant avant la suppression : ");
            scanf("%d", &tmpClassId);
            clearInputBuffer();
            for (int i = 0; i < 100; i++)
            {
                if (classes[i].id == tmpClassId)
                {
                    for (int j = i; j < 100; j++)
                    {
                        classes[j] = classes[j + 1];
                        classes[99].id = -1;
                    }
                }
            }
            if (backToMenu() == 0)
            {
                break;
            }
            break;
        case 3:
            printf("Pour voir les informations d'un étudiant, il faut l'ID de cet étudiant : ");
            scanf("%d", &tmpClassId);
            clearInputBuffer();
            system("cls");
            for (int i = 0; i < 100; i++)
            {
                if (classes[i].id == tmpClassId)
                {
                    printf("id                 ::%d\n", classes[i].id);
                    printf("nom de class       ::%s\n", classes[i].name);
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
                if (classes[i].id != -1)
                {
                    printf("class :: %d\n", i);
                    printf("id                   ::%d\n", classes[i].id);
                    printf("nom de class         ::%s\n", classes[i].name);
                }
            }
            if (backToMenu() == 0)
            {
                break;
            }
            break;
        case 5:
            system("cls");
            exit(1);
            break;
        default:
            crudOperationNumber = choseOperation();
            break;
        }
    }
    return 0;
}
