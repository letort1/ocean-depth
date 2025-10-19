#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int nombre_aleatoire(int minimum, int maximum) {
    return rand() % (maximum - minimum + 1) + minimum;
}
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


int id_compteur = 0;
void init_nouveau_tableau(CreatureMarine new_tab[], int taille_max_creatures) {
    for (int i = 0; i < taille_max_creatures; i++) {
        new_tab[i].est_vivant = 0;
    }
}


CreatureMarine nouvelle_creature(int type) {
	CreatureMarine creature;
    creature.id = id_compteur++;
    switch (type) {
    case 1:
        strcpy_s(creature.nom, 30, "Kraken");
		creature.points_de_vie_max = nombre_aleatoire(120, 180);
        creature.attaque_minimale = nombre_aleatoire(25, 30);
        creature.attaque_maximale = nombre_aleatoire(30, 40);
        creature.defense = nombre_aleatoire(15, 25);
        creature.vitesse = nombre_aleatoire(5, 10);
        creature.est_vivant = 1;
        creature.points_de_vie_actuels = creature.points_de_vie_max;
		break;
    case 2:
		strcpy_s(creature.nom , 30, "Requin");
        creature.points_de_vie_max = nombre_aleatoire(60, 100);
        creature.attaque_minimale = nombre_aleatoire(15, 22);
        creature.attaque_maximale = nombre_aleatoire(creature.attaque_minimale, 25);
        creature.defense = nombre_aleatoire(5, 10);
        creature.vitesse = nombre_aleatoire(20, 30);
		strcpy_s(creature.effet_special,20, "attaques multiples");
        creature.est_vivant = 1;
        creature.points_de_vie_actuels = creature.points_de_vie_max;
        break;
    case 3:
        strcpy_s(creature.nom ,30, "Méduse");
        creature.points_de_vie_max = nombre_aleatoire(20, 40);
        creature.attaque_minimale = nombre_aleatoire(8, 12);
        creature.attaque_maximale = nombre_aleatoire(creature.attaque_minimale, 15);
        creature.defense = nombre_aleatoire(0, 5);
		creature.vitesse = nombre_aleatoire(5, 15);
        strcpy_s(creature.effet_special ,20, "paralysie");
        creature.est_vivant = 1;
        creature.points_de_vie_actuels = creature.points_de_vie_max;
        break;
    case 4:
		strcpy_s(creature.nom ,30, "Poisson-Épée");
        creature.points_de_vie_max = nombre_aleatoire(70, 90);
        creature.attaque_minimale = nombre_aleatoire(18, 25);
        creature.attaque_maximale = nombre_aleatoire(creature.attaque_minimale, 28);
        creature.defense = nombre_aleatoire(10, 15);
		creature.vitesse = nombre_aleatoire(15, 25);
        creature.est_vivant = 1;
        creature.points_de_vie_actuels = creature.points_de_vie_max;
        break;

    case 5:
		strcpy_s ( creature.nom ,30, "Crabe Géant");
        creature.points_de_vie_max = nombre_aleatoire(80, 120);
        creature.attaque_minimale = nombre_aleatoire(12, 18);
        creature.attaque_maximale = nombre_aleatoire(creature.attaque_minimale, 20);
		creature.defense = nombre_aleatoire(25, 40);
        creature.est_vivant = 1;
        creature.points_de_vie_actuels = creature.points_de_vie_max;
        break;
    }

	return creature;
}



int nombredecreatures (int profondeur)
{
    if (profondeur < 20) {
        return nombre_aleatoire(1, 3);
    }
    else if (profondeur < 60) {
        return nombre_aleatoire(2, 4);
    }
    else {
        return nombre_aleatoire(3, 4);
    }
}


// NOUVELLE LIGNE :
void creation_du_typeetaffectation(CreatureMarine new_tab[], int taille_max_creatures, int profondeur){
    int nombrecreaturesgénérées = nombredecreatures(profondeur);
    int type;
    for (int i = 0; i < nombrecreaturesgénérées; i++) {
        int tirage = nombre_aleatoire(0, 100);
        if (profondeur < 20) {
            if (tirage < 50) type = 3;
            else if (tirage < 90) type = 4;
            else type = 2;
     }
        else if (profondeur < 60) {
            if (tirage < 25) type = 4;
            else if (tirage < 60) type = 2;
            else if (tirage < 95) type = 1;
            else type = 1;
    }
        else {
            if (tirage < 40) type = 5;
            else if (tirage < 75) type = 3;
            else type = 4;
    }
    int index_libre = -1;
    for (int j = 0; j < taille_max_creatures; j++) {
        if (new_tab[j].est_vivant == 0) {
            index_libre = j;
            break;
        }
    }
    if (index_libre == -1) {
        printf("ERREUR: Le banc est plein. Impossible d'ajouter de nouvelles créatures.\n");
        break;
    }
    new_tab[index_libre] = nouvelle_creature(type);
}
}




int main() {
    #define TAILLE_MAX_CREATURES 5
    
    CreatureMarine new_tab[TAILLE_MAX_CREATURES];
    

    srand(time(NULL));

    init_nouveau_tableau(new_tab, TAILLE_MAX_CREATURES);


    //int profondeur;
    //printf("Entrez la profondeur actuelle (0-100): ");
    //scanf("%d", &profondeur);
    
    

    return 0;
}