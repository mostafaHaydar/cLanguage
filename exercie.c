#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tentative, nombre_aleatoire, nombre, x, tentatives_restantes = 5;

    // Initialisatio du générateur de nombres aléatoires
    srand(time(NULL));
    //  pour donner un nombre aléatoire entre 100 et 999 car le nombre compose 3 chiffres
    nombre_aleatoire = rand() % 999 + 100;

    printf("------------------Entrez un nombre entre 100 et 999------------------ \n");
    do {
        printf("Votre tentative est : ");
        if (scanf("%d", &tentative) != 1 || tentative < 100 || tentative > 999) {
            printf("Erreur : Vous devez entrer un nombre entre 100 et 999.\n");
            // Vider le tampon d'entrée pour éviter les boucles infinies
            while (getchar() != '\n');
            continue;
        }

        x = 1; // Réinitialiser x à 1 après une saisie valide

        if (tentative == nombre_aleatoire) {
            printf("++++++++++Bravo! Vous avez trouvé le nombre : %d+++++++++\n", nombre_aleatoire);
            break; // Sortir de la boucle si le nombre est trouvé
        } else {
            nombre = tentative / 100; // dans ce cas dans la première chiffre
            if (nombre == nombre_aleatoire / 100) {
                printf("--------------le premier chiffre est correct : %d** \n", nombre);
            } else {
                printf("le premier chiffre est incorrect\n");
            }
            nombre = (tentative / 10) % 10; // dans ce cas dans la deuxième chiffre
            if (nombre == (nombre_aleatoire / 10) % 10) {
                printf("--------------le deuxième chiffre est correct: *%d* \n", nombre);
            } else {
                printf("le deuxième chiffre est incorrect\n");
            }
            nombre = tentative % 10; // dans ce cas dans la troisième chiffre
            if (nombre == nombre_aleatoire % 10) {
                printf("--------------le troisième chiffre est correct: **%d\n", nombre);
            } else {
                printf("le troisième chiffre est incorrect\n");
            }

            // Décrémenter le nombre de tentatives restantes
            tentatives_restantes--;
            printf("Il vous reste %d tentative(s).\n", tentatives_restantes);

            // Vérifier si le nombre de tentatives restantes est épuisé
            if (tentatives_restantes == 0) {
                printf("Désolé, vous avez épuisé toutes vos tentatives. Le nombre était : %d\n", nombre_aleatoire);
                break; // Sortir de la boucle
            }

            printf("Essayez une nouvelle tentative : ");
             scanf("%d",&tentative);
        }

    } while (!x);

    return 0;
}



