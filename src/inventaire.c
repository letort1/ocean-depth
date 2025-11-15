#include <stdio.h>
#include <string.h>
#include "inventaire.h"

void init_inventaire(Plongeur *j) {
    for (int i = 0; i < 8; i++) {
        j->inventaire[i][0] = '\0';
    }
}

void ajouter_objet(Plongeur *j, const char *nom_objet) {
    for (int i = 0; i < 8; i++) {
        if (j->inventaire[i][0] == '\0') {
            strcpy(j->inventaire[i], nom_objet);
            return;
        }
    }
    printf("Inventaire plein.\n");
}

void afficher_inventaire(Plongeur *j) {
    printf("\nInventaire :\n");
    for (int i = 0; i < 8; i++) {
        if (j->inventaire[i][0] == '\0')
            printf("[%d] Vide\n", i + 1);
        else
            printf("[%d] %s\n", i + 1, j->inventaire[i]);
    }
}
