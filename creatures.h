#ifndef CREATURES
#define CREATURES

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


int nombre_aleatoire(int minimum, int maximum);

void init_nouveau_tableau(CreatureMarine new_tab[], int taille_max_creatures);

CreatureMarine nouvelle_creature(int type);

int nombredecreatures(int profondeur);
void creation_du_typeetaffectation(CreatureMarine new_tab[], int taille_max_creatures, int profondeur);

#endif 

void afficher_creatures(CreatureMarine tab[], int taille_max_creatures);
