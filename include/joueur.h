#ifndef JOUEUR_H
#define JOUEUR_H

typedef struct {
    int points_de_vie;
    int points_de_vie_max;
    int niveau_oxygene;
    int niveau_oxygene_max;
    int niveau_fatigue;   
    int perles;

    int est_paralyse;
    int penalite_attaques_prochain_tour;
    
    int attaque_minimale;
    int attaque_maximale;
    int defense;
    char inventaire[8][32];
} Plongeur;

// init valeurs de base du plongeur
void init_plongeur(Plongeur *j);

// coût O2 d'une attaque par rapport à la profondeur
int cout_oxygene_attaque(int profondeur);

#endif
