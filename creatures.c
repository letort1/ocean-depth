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

int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

CreatureMarine Kraken{ 1, "Kraken", 120, 120, 25, 40, 15, 10, "aucun", 1};

CreatureMarine Requin{ 2, "Requin", 60, 60, 15, 25, 10, 20, "aucun", 1 };

CreatureMarine Méduse{ 3, "Méduse", 20, 20, 8, 15, 5, 15, "paralysie", 1 };

CreatureMarine Poisson - Épée{ 4, "Poisson-Épée", 70, 70, 10, 20, 8, 25, "saignement", 1 };


CreatureMarine nouvelle_creature(int type) {
	CreatureMarine creature;

    switch (type) {
    case 1:
        creature.nom = "Kraken";
		creature.points_de_vie_max = rand_range(120, 180);
        creature.attaque_minimale = rand_range(25, 35);
        creature.attaque_maximale = rand_range(creature.attaque_minimale, 40);
        creature.defense = rand_range(15, 25);
        creature.vitesse = rand_range(5, 10);
        strcpy(creature.effet_special, "aucun");
		break;
    case 2:
		creature.nom = "Requin";
        creature.points_de_vie_max = rand_range(60, 100);
        creature.attaque_minimale = rand_range(15, 22);
        creature.attaque_maximale = rand_range(creature.attaque_minimale, 25);
        creature.defense = rand_range(5, 10);
        creature.vitesse = rand_range(20, 30);
		strcpy(creature.effet_special, "aucun");
    case 3:
		creature.nom = "Méduse";
        creature.points_de_vie_max = rand_range(20, 40);
        creature.attaque_minimale = rand_range(8, 12);
        creature.attaque_maximale = rand_range(creature.attaque_minimale, 15);
        creature.defense = rand_range(0, 5);
		creature.vitesse = rand_range(5, 15);
    case 4:
		creature.nom = "Poisson-Épée";
        creature.points_de_vie_max = rand_range(70, 90);
        creature.attaque_minimale = rand_range(18, 25);
        creature.attaque_maximale = rand_range(creature.attaque_minimale, 28);
        creature.defense = rand_range(10, 15);
		creature.vitesse = rand_range(15, 25);

    case 5:
		creature.nom = "Crabe Géant";
        creature.points_de_vie_max = rand_range(80, 120);
        creature.attaque_minimale = rand_range(12, 18);
        creature.attaque_maximale = rand_range(creature.attaque_minimale, 20);
		creature.defense = rand_range(25, 40);
    default:
        return Méduse; // Par défaut
    }
}