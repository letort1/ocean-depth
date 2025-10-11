#include <stdlib.h>
#include <stdio.h>


typedef struct {
    int id;
    char nom[30];
    int points_de_vie_max;
    int points_de_vie_actuels;
    int attaque_minimale;
    int attaque_maximale;
    int defense;
    int vitesse;
    char effet_special[20];
    int est_vivant;
} CreatureMarine;



CreatureMarine Kraken{ 1, "Kraken", 120, 120, 25, 40, 15, 10, "aucun", 1};


CreatureMarine Requin{ 2, "Requin", 60, 60, 15, 25, 10, 20, "aucun", 1 };

CreatureMarine Méduse{ 3, "Méduse", 20, 20, 8, 15, 5, 15, "paralysie", 1 };

CreatureMarine Poisson - Épée{ 4, "Poisson-Épée", 70, 70, 10, 20, 8, 25, "saignement", 1 };