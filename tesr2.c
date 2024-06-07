#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#define CMAX 10
#define MAX_CLIENTS 30
#define MAX_COMPTES 30

typedef struct {
    int code_client;
    char name[CMAX];
    char prenom[CMAX];
} Client;

typedef struct {
    int code_client;
    int code_cmpt;
    float solde;
} Compte;

Client clients[MAX_CLIENTS];
Compte comptes[MAX_COMPTES];
int nb_clients = 0;
int nb_comptes = 0;

void menu();
void sous_menu(int a);
void gestion_client(int b);
void gestion_compte(int b);

int main() {
    menu();
    return 0;
}

void menu() {
    int choix;
    printf("--------------------------Menu Principal------------------------\n");
    printf("1- Gestion des clients\n");
    printf("2- Gestion des comptes\n");
    printf("3- Gestion des opérations\n");
    printf("4- Quitter le programme\n");
    printf("Choisir une option : ");
    scanf("%d", &choix);
    sous_menu(choix);
}

void sous_menu(int a) {
    int choix_sous_menu;
    if (a == 1) {
        printf("------------------------Sous Menu Clients-----------------------\n");
        printf("1- Ajouter un client\n");
        printf("2- Modifier un client\n");
        printf("3- Supprimer un client\n");
        printf("4- Retour\n");
        printf("Choisir une option : ");
        scanf("%d", &choix_sous_menu);
        gestion_client(choix_sous_menu);
    } else if (a == 2) {
        printf("-----------------------Sous Menu Comptes------------------------\n");
        printf("1- Ajouter un compte\n");
        printf("2- Rechercher un compte\n");
        printf("3- Afficher la liste des comptes\n");
        printf("4- Supprimer un compte\n");
        printf("5- Retour\n");
        printf("Choisir une option : ");
        scanf("%d", &choix_sous_menu);
        gestion_compte(choix_sous_menu);
    } else if (a == 3) {
        // Gérer les opérations
    } else if (a == 4) {
        printf("Programme terminé.\n");
        exit(0);
    } else {
        printf("Choix invalide.\n");
    }
}

void gestion_client(int b) {
    if (b == 1) {
        Client client;
        printf("Entrez le code client : ");
        scanf("%d", &client.code_client);
        printf("Nom : ");
        scanf("%s", client.name);
        printf("Prénom : ");
        scanf("%s", client.prenom);
        clients[nb_clients++] = client;
        printf("Client ajouté avec succès.\n");
    } else if (b == 2) {
        // Modifier un client
    } else if (b == 3) {
        // Supprimer un client
    } else if (b == 4) {
        menu();
    } else {
        printf("Choix invalide.\n");
    }
}

void gestion_compte(int b) {
    if (b == 1) {
        Compte compte;
        printf("Entrez le code client associé au compte : ");
        scanf("%d", &compte.code_client);
        printf("Entrez le numéro de compte : ");
        scanf("%d", &compte.code_cmpt);
        compte.solde = 0;
        comptes[nb_comptes++] = compte;
        printf("Compte ajouté avec succès.\n");
    } else if (b == 2) {
        // Rechercher un compte
    } else if (b == 3) {
        printf("-------------------Liste des Comptes-------------------\n");
        for (int i = 0; i < nb_comptes; i++) {
            printf("Client : %d, Compte : %d, Solde : %.2f\n", comptes[i].code_client, comptes[i].code_cmpt, comptes[i].solde);
        }
    } else if (b == 4) {
        // Supprimer un compte
    } else if (b == 5) {
        menu();
    } else {
        printf("Choix invalide.\n");
    }
}

