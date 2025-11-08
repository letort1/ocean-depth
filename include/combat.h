#ifndef COMBAT_H
#define COMBAT_H
#include "creatures.h"
#include "joueur.h"

int attaquer_avec_harpon(Plongeur *j, CreatureMarine *c, int profondeur);

int nombre_attaques_autorisees(int fatigue, int penalite);
void fin_de_tour_joueur(Plongeur *j, int profondeur);

void attaque_des_creatures(CreatureMarine tab[], int taille, Plongeur *j);
void appliquer_effet_special(CreatureMarine *c, Plongeur *j);

void afficher_interface_combat(CreatureMarine tab[], int taille, Plongeur *j);
void tour_de_combat(CreatureMarine tab[], int taille, Plongeur *j, int profondeur);
void boucle_combat(CreatureMarine tab[], int taille, Plongeur *j, int profondeur);

#endif
