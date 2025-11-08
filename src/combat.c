#include <stdio.h>
#include <stdlib.h>
#include "../include/combat.h"

static int rand_intervalle(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int attaquer_avec_harpon(Plongeur *j, CreatureMarine *c, int profondeur) {
    if (!c || !c->est_vivant) {
        printf("La creature est deja vaincue.\n");
        return 0;
    }
    if (j->niveau_oxygene <= 0) {
        printf("Oxygene insuffisant !\n");
        return 0;
    }

    // Consommation de l'oxygene avec augmentation de la fatigue
    int cout = cout_oxygene_attaque(profondeur);
    if (j->niveau_oxygene < cout) cout = j->niveau_oxygene; // evite negatif
    j->niveau_oxygene -= cout;
    j->niveau_fatigue += 1;

    // Degats base joueur avec randomisation min et max
    int base = rand_intervalle(j->attaque_minimale, j->attaque_maximale);

    // Ajout défense de la créature 
    int degats = base - c->defense;
    if (degats < 1) degats = 1;

    c->points_de_vie_actuels -= degats;
    if (c->points_de_vie_actuels <= 0) {
        c->points_de_vie_actuels = 0;
        c->est_vivant = 0;
    }

    // Affichage temporaire des resultats
    printf("Vous attaquez %s : -%d PV  | Creature: %d/%d PV  | O2: %d/%d  Fatigue: %d\n",
           c->nom, degats,
           c->points_de_vie_actuels, c->points_de_vie_max,
           j->niveau_oxygene, j->niveau_oxygene_max,
           j->niveau_fatigue);

    return degats;
}
