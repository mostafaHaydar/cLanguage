#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction pour générer un nombre aléatoire entre min et max
int genererNombreAleatoire(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Fonction pour vérifier la validité de la tentative
int estTentativeValide(int tentative) {
    return (tentative >= 100 && tentative <= 999);
}

int main() {
    int tentative, nombre_aleatoire,nombre;
    
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    
    // Génération du nombre aléatoire
    nombre_aleatoire = genererNombreAleatoire(100, 999);

    printf("------------------Entrez un nombre entre 100 et 999------------------ \n");
    
    while (1) {
        printf("Votre tentative est : ");
        if (scanf("%d", &tentative) != 1 || !estTentativeValide(tentative)) {
            printf("Erreur : Veuillez entrer un nombre valide entre 100 et 999.\n");
            while (getchar() != '\n'); // Vider le tampon d'entrée
            continue;
        }

        if (tentative == nombre_aleatoire) {
            printf("++++++++++Bravo! Vous avez Ttrouver le nombre : %d     +++++++++\n", nombre_aleatoire);
            break;
        } else {
            // Afficher les indices pour aider l'utilisateur à trouver le nombre
            printf("Indices :\n");
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

            printf("++Essayez une nouvelle tentative++\n");
        }  
    }

    return 0;
}
