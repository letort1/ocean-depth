#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../include/creatures.h"
#include "../include/joueur.h"
#include "../include/combat.h"

int main() {
#define TAILLE_MAX_CREATURES 5
    int profondeur = 0;
    CreatureMarine new_tab[TAILLE_MAX_CREATURES];

    srand(time(NULL));
    init_nouveau_tableau(new_tab, TAILLE_MAX_CREATURES);

    printf("Quelle doit etre la profondeur actuelle ? ");
    scanf("%d", &profondeur);

    creation_du_typeetaffectation(new_tab, TAILLE_MAX_CREATURES, profondeur);


    afficher_creatures(new_tab, TAILLE_MAX_CREATURES);

    Plongeur joueur;
    init_plongeur(&joueur);


    boucle_combat(new_tab, TAILLE_MAX_CREATURES, &joueur, profondeur);

    return 0;
}
