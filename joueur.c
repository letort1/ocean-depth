#include "joueur.h"

void init_plongeur(Plongeur *j) {
    j->points_de_vie_max   = 100;
    j->points_de_vie       = 100;
    j->niveau_oxygene_max  = 100;
    j->niveau_oxygene      = 100;
    j->niveau_fatigue      = 0;
    j->perles              = 0;

    j->attaque_minimale    = 15;
    j->attaque_maximale    = 25;
    j->defense             = 0;
}

int cout_oxygene_attaque(int profondeur) {
    if (profondeur < 50)    return 2;
    if (profondeur < 150)   return 3;
    return 4;
}
