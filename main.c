#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Pour utiliser la fonction srand(time(NULL))

int main() {
    int tentative,nombre_aleatoire,nombre,x;
    
     // Nous utilisons pour initialisation du générateur de nombres 
    srand(time(NULL));
    //  pour donner d un nombre aleatoire entre 100 et 999 car le nombre compse 3 chiffres
    nombre_aleatoire = rand() % 999 +100;

    printf("------------------Enter un nombre entre 100 et 999------------------ \n");
    x=0;
    while(!x){
        printf("votre tentative est :");
        scanf("%d",&tentative);

        if(tentative==nombre_aleatoire){
            printf("Bravoo!vous avez troue le nombre :",nombre_aleatoire);
            x=1;
        }
        else {
            nombre=tentative /100; // dans ce cas dans la premiere chiffre
            if(nombre==nombre_aleatoire /100){
                printf("le premiere chiffre est correct\n");}
            else{
                printf("le premier chiffre est incorrect\n");
            }
            nombre=(tentative /10 )% 10; // dans ce cas dans la deuxieme chiffre
            if(nombre==(nombre_aleatoire /10)%10){
                printf("le deuxieme chiffre est correct\n");}
            else{
                printf("le deuxieme chiffre est incorrect\n");
            }
            nombre=tentative %10; //dans ce cas dans la troixieme chiffre
            if(nombre==nombre_aleatoire % 10){
                printf("le troixieme chiffre est correct\n");}
            else{
                printf("le troixieme chiffre est incorrect\n");
            }
            }
        }

     return 0;
    }

