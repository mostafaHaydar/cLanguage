#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 5

char grid[GRID_SIZE][GRID_SIZE] = {
    {'A', 'P', 'P', 'L', 'E'},
    {'B', 'A', 'N', 'A', 'N'},
    {'O', 'R', 'A', 'N', 'G'},
    {'L', 'E', 'M', 'O', 'N'},
    {'G', 'R', 'A', 'P', 'E'}
};

char* words[] = {"APPLE", "BANANA", "ORANGE", "LEMON", "GRAPE"};

void displayGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Bienvenue dans le jeu de mots croisés !\n");
    printf("Voici la grille :\n");
    displayGrid();
    printf("\n");

    // Demander à l'utilisateur de deviner les mots
    printf("Devinez les mots !\n");
    for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
        char guess[GRID_SIZE + 1];
        printf("Entrez votre proposition pour le mot %d : ", i + 1);
        scanf("%s", guess);
        
        // Vérifier si la proposition de l'utilisateur correspond au mot
        if (strcmp(guess, words[i]) == 0) {
            printf("Bravo ! Vous avez trouvé le mot %s.\n", words[i]);
        } else {
            printf("Désolé, ce n'est pas le bon mot.\n");
        }
    }

    return 0;
}



