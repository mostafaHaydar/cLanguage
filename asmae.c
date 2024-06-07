#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Pour utiliser la fonction srand(time(NULL))

int main() {
    int tentative, nombre_aleatoire, nombre, x;
    
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    //  pour donner d un nombre aleatoire entre 100 et 999 car le nombre compse 3 chiffres
    nombre_aleatoire = rand() % 999 + 100;

    printf("------------------Entrez un nombre entre 100 et 999------------------ \n");
    do {
        printf("Votre tentative est : ");
        if (scanf("%d", &tentative) != 1) {
            printf("Erreur : Vous devez entrer un nombre.\n");
            // Vider le tampon d'entrée pour éviter les boucles infinies
            while (getchar() != '\n');
            continue;
        }
        if (tentative >= 100 && tentative <= 999) {
            x = 1;
        } else {
            printf("Erreur : Entrez un nombre entre 100 et 999\n");
            x = 0;
        }

    } while (!x);
    x = 0;
    while (!x) {
        if (tentative == nombre_aleatoire) {
            printf("++++++++++Bravo! Vous avez trouvé le nombre : %d+++++++++", nombre_aleatoire);
            x = 1;
        } else {
            nombre = tentative / 100; // dans ce cas dans la premiere chiffre
            if (nombre == nombre_aleatoire / 100) {
                printf("--------------le premiere chiffre est correct : %d** \n", nombre);
            } else {
                printf("le premier chiffre est incorrect\n");
            }
            nombre = (tentative / 10) % 10; // dans ce cas dans la deuxieme chiffre
            if (nombre == (nombre_aleatoire / 10) % 10) {
                printf("--------------le deuxieme chiffre est correct: *%d* \n", nombre);
            } else {
                printf("le deuxieme chiffre est incorrect\n");
            }
            nombre = tentative % 10; //dans ce cas dans la troisieme chiffre
            if (nombre == nombre_aleatoire % 10) {
                printf("--------------le troisieme chiffre est correct: **%d\n", nombre);
            } else {
                printf("le troisieme chiffre est incorrect\n");
            }
            printf("Essayez une nouvelle tentative : ");
            if (scanf("%d", &tentative) != 1) {
                printf("Erreur : Vous devez entrer un nombre.\n");
                // Vider le tampon d'entrée pour éviter les boucles infinies
                while (getchar() != '\n');
            }
        }
    }

    return 0;
}


