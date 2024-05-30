#include <stdio.h>
#include <stdlib.h>

void pause() {
  printf("\nentrez 0 pour demarrer le quiz ");
  while (getchar() != '0')
    ;
  getchar();
}

void continuee() {
  printf("\nentrez o pour passer a l'aure question ");
  while (getchar() != 'o')
    ;
  getchar();
}

int main() {
  char name[25];
  int choix;
  int choix1;
  int choix2;
  int choix3;
  int choix4;
  int choix5;
  int choix6;
  int choix7;
  int choix8;
  int choix9;
  int choix10;
  int correct = 0;
  int incorrect = 0;

  printf("\n\n\t\t****** Bienvenue dans ce jeu :) ****** \n");
  printf("\n Entrez votre nom s'il vous plait : ");
  scanf("%s", name);
  system("cls");
  printf("\t============== Salut %s ===================\n", name);
  printf("\nle quiz contien 10 questions  Le joueur doit choisir une réponse. "
         "Si vous choisissez la bonne, vous gagnez ; sinon, vous perdez ! ");
  printf("\n\n\t\t\t BONNE CHANCE !!!!");
  pause();

  printf("\nCombien d'etoiles y a-t-il sur le drapeau americain ?\n");
  printf("1. 30\n");
  printf("2. 60\n");
  printf("3. 50\n");
  printf("4. 40\n");
  printf("Choisissez une reponse : ");
  scanf("%d", &choix);

  switch (choix) {
  case 1:
    printf("Reponse incorrecte :< ");
    incorrect++;

    break;
  case 2:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  case 3:
    printf("Bravo, votre reponse est correcte ! ");
    correct++;
    break;
  case 4:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  default:
    printf("Choix incorrect !\n");
    break;
  }
  ///////////////////////////////////////////////////////////////////////////////////

  continuee();
  system("cls");

  printf("\nQuel est l’animal national du Maroc ?\n");
  printf("1. lion\n");
  printf("2. chat\n");
  printf("3. le kangourou rouge\n");
  printf("4. renard\n");
  printf("Choisissez une reponse : ");
  scanf("%d", &choix1);

  switch (choix1) {
  case 1:
    printf("Bravo, votre reponse est correcte ! ");
    correct++;
    break;
  case 2:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  case 3:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  case 4:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  default:
    printf("Choix incorrect !\n");
    break;
  }

  ///////////////////////////////////////////////////////////////////////////////////

  continuee();
  system("cls");

  printf("\nQuel est le plus petit pays du monde ?\n");
  printf("1. tunisie\n");
  printf("2. vatican\n");
  printf("3. Monaco\n");
  printf("4. Maldives\n");
  printf("Choisissez une reponse : ");
  scanf("%d", &choix2);

  switch (choix2) {
  case 1:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  case 2:
    printf("Bravo, votre reponse est correcte ! ");
    correct++;
    break;
  case 3:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  case 4:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  default:
    printf("Choix incorrect !\n");
    break;
  }

  ///////////////////////////////////////////////////////////////////////////////////

  continuee();
  system("cls");

  printf("\nQuelle langue comprend le plus grand nombre de mots\n");
  printf("1. arab\n");
  printf("2. francais\n");
  printf("3. espagnol\n");
  printf("4. anglais\n");
  printf("Choisissez une reponse : ");
  scanf("%d", &choix3);

  switch (choix3) {
  case 1:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  case 2:
    printf("Reponse incorrecte :< ");
    incorrect++;

    break;
  case 3:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  case 4:
    printf("Bravo, votre reponse est correcte ! ");
    correct++;
    break;
  default:
    printf("Choix incorrect !\n");
    break;
  }

  ///////////////////////////////////////////////////////////////////////////////////

  continuee();
  system("cls");

  printf("\nCombien y a-t-il d'os dans le corps humain ?\n");
  printf("1. 206\n");
  printf("2. 145\n");
  printf("3. 200\n");
  printf("4. 190\n");
  printf("Choisissez une reponse : ");
  scanf("%d", &choix4);

  switch (choix4) {
  case 1:
    printf("Bravo, votre reponse est correcte ! ");
    correct++;
    break;
  case 2:
    printf("Reponse incorrecte :< ");
    incorrect++;

    break;
  case 3:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  case 4:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  default:
    printf("Choix incorrect !\n");
    break;
  }
  ///////////////////////////////////////////////////////////////////////////////////

  continuee();
  system("cls");

  printf("\nQuelle partie du corps est la seule a etre completement developpee "
         "a la naissance ?\n");
  printf("1. cheveux\n");
  printf("2. oreilles\n");
  printf("3. yeux\n");
  printf("4. les sourcils\n");
  printf("Choisissez une reponse : ");
  scanf("%d", &choix5);

  switch (choix5) {
  case 1:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  case 2:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  case 3:
    printf("Bravo, votre reponse est correcte ! ");
    correct++;
    break;
  case 4:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  default:
    printf("Choix incorrect !\n");
    break;
  }

  ///////////////////////////////////////////////////////////////////////////////////

  continuee();
  system("cls");

  printf("\nEn quelle annee Netflix a-t-il ete cree ?\n");
  printf("1. 1997\n");
  printf("2. 2001\n");
  printf("3. 1995\n");
  printf("4. 2008\n");
  printf("Choisissez une reponse : ");
  scanf("%d", &choix6);

  switch (choix6) {
  case 1:
    printf("Bravo, votre reponse est correcte ! ");
    correct++;
    break;
  case 2:
    printf("Reponse incorrecte :< ");
    incorrect++;

    break;
  case 3:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  case 4:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  default:
    printf("Choix incorrect !\n");
    break;
  }
  ///////////////////////////////////////////////////////////////////////////////////

  continuee();
  system("cls");

  printf("\nCombien de cœurs y a-t-il dans une pieuvre ?\n");
  printf("1. 8coeurs\n");
  printf("2. 4 coeurs\n");
  printf("3. 5 coeurs\n");
  printf("4. 3 coeurs\n");
  printf("Choisissez une reponse : ");
  scanf("%d", &choix7);

  switch (choix7) {
  case 1:
    printf("Reponse incorrecte :< ");
    incorrect++;

    break;
  case 2:
    printf("Reponse incorrecte :< ");
    incorrect++;

    break;
  case 3:
    printf("Reponse incorrecte :< ");
    incorrect++;

    break;
  case 4:
    printf("Bravo, votre reponse est correcte ! ");
    correct++;
    break;
  default:
    printf("Choix incorrect !\n");
    break;
  }
  ///////////////////////////////////////////////////////////////////////////////////

  continuee();
  system("cls");

  printf("\nQuel est le muscle humain le plus fort ?\n");
  printf("1. Mâchoire\n");
  printf("2. mains\n");
  printf("3. pieds\n");
  printf("4. aucune des réponses n'est correcte\n");
  printf("Choisissez une reponse :");
  scanf("%d", &choix8);

  switch (choix8) {
  case 1:
    printf("Bravo, votre reponse est correcte ! ");
    correct++;

    break;
  case 2:
    printf("Reponse incorrecte :< ");
    incorrect++;

    break;
  case 3:
    printf("Reponse incorrecte :< ");
    incorrect++;

    break;
  case 4:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  default:
    printf("Choix incorrect !\n");
    break;
  }
  ///////////////////////////////////////////////////////////////////////////////////

  continuee();
  system("cls");

  printf("\nEn quelle annee la Seconde Guerre mondiale a-t-elle pris fin ?\n");
  printf("1. 1946\n");
  printf("2. 1941\n");
  printf("3. 1945\n");
  printf("4. 1943\n");
  printf("Choisissez une reponse :");
  scanf("%d", &choix9);

  switch (choix9) {
  case 1:

    printf("Reponse incorrecte :< ");
    incorrect++;

    break;
  case 2:
    printf("Reponse incorrecte :< ");
    incorrect++;

    break;
  case 3:
    printf("Bravo, votre reponse est correcte ! ");
    correct++;

    break;
  case 4:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  default:
    printf("Choix incorrect !\n");
    break;
  }
  ///////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////

  continuee();
  system("cls");

  printf("\nCombien de pays font partie de l'Union europrenne\n");
  printf("1. 22\n");
  printf("2. 27\n");
  printf("3. 30\n");
  printf("4. 25\n");
  printf("Choisissez une reponse : ");
  scanf("%d", &choix10);

  switch (choix10) {
  case 1:
    printf("Reponse incorrecte :< ");
    incorrect++;

    break;
  case 2:
    printf("Bravo, votre reponse est correcte ! ");
    correct++;

    break;
  case 3:
    printf("Reponse incorrecte :< ");
    incorrect++;

    break;
  case 4:
    printf("Reponse incorrecte :< ");
    incorrect++;
    break;
  default:
    printf("Choix incorrect !\n");
    break;
  }
  system("cls");
  printf("\tle nomre des reponse correct sont :%d\n", correct);
  printf("\tle nomre des reponse incorrect sont :%d\n", incorrect);
  if (correct > incorrect) {
    printf("vous avez gagner dans se quiz !!");
  } else if (correct < incorrect) {
    printf("tu perds, essaie plus fort la prochaine fois");
  } else
    printf("passable !");

  return correct; // Return the number of correct answers
}
