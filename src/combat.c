#include <stdio.h>
#include <stdlib.h>
#include "../include/combat.h"
#include "../include/recompenses.h"

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
    if (j->niveau_oxygene < cout) cout = j->niveau_oxygene;
    j->niveau_oxygene -= cout;
    j->niveau_fatigue += 1;

    // Degats base joueur avec randomisation min et max
    int base = rand_intervalle(j->attaque_minimale, j->attaque_maximale);

    // Ajout défense de la créature 
    int degats = base - c->defense;
    if (degats < 1) degats = 1;

    // Effet "Carapace durcie" du Crabe géant : -20% dégâts subis
    if (c->nom[0] == 'C') { // C pour"Crabe Geant"
        printf("   (Effet) %s reduit les degats grace a sa carapace (-20%%)\n", c->nom);
        degats = (degats * 80) / 100;
        if (degats < 1) degats = 1;
    }

    c->points_de_vie_actuels -= degats;
    if (c->points_de_vie_actuels <= 0) {
        c->points_de_vie_actuels = 0;
        c->est_vivant = 0;
    }

    // Affichage des damages et état après attaque
    printf("Vous attaquez %s : -%d PV  | Creature: %d/%d PV  | O2: %d/%d  Fatigue: %d\n",
           c->nom, degats,
           c->points_de_vie_actuels, c->points_de_vie_max,
           j->niveau_oxygene, j->niveau_oxygene_max,
           j->niveau_fatigue);
        
           if (j->niveau_oxygene <= 10) {
        printf("!! Alerte oxygene critique (%d/%d)\n",
               j->niveau_oxygene, j->niveau_oxygene_max);
    }

    return degats;
}

int nombre_attaques_autorisees(int fatigue, int penalite) {
    int base;
    if (fatigue <= 1) base = 3;
    else if (fatigue <= 3) base = 2;
    else base = 1;

    base -= (penalite > 0 ? penalite : 0);
    if (base < 1) base = 1;
    return base;
}

void fin_de_tour_joueur(Plongeur *j, int profondeur) {
    // Conso auto d'oxygene en fonction de la profondeur
    int cout_auto = (profondeur < 50) ? 2 : (profondeur < 150 ? 3 : 5);
    if (j->niveau_oxygene >= cout_auto) j->niveau_oxygene -= cout_auto;
    else j->niveau_oxygene = 0;

    if (j->niveau_oxygene == 0) {
        j->points_de_vie -= 5;
        if (j->points_de_vie < 0) j->points_de_vie = 0;
        printf("!! Asphyxie: -5 PV (O2 = 0)\n");
    }

    if (j->niveau_fatigue < 5) j->niveau_fatigue -= 1;
}


static int creature_frappe_joueur(CreatureMarine *c, Plongeur *j) {
    if (!c || !c->est_vivant) return 0;

    int base = rand_intervalle(c->attaque_minimale, c->attaque_maximale);

    // Requin : +30% degats si PV <= 50%
    if (c->nom[0] == 'R') { // R pour "Requin"
        if (c->points_de_vie_actuels * 2 <= c->points_de_vie_max) {
            base = (base * 13) / 10;
            printf("   (Effet) %s entre en frenesie (+30%% degats)\n", c->nom);
        }
    }

    int def_joueur = j->defense;

    // Poisson-epee : ignore 2 points de DEF
    if (c->nom[0] == 'P') { // P pour "Poisson-epee"
        if (rand_intervalle(1, 100) <= 40) {
            if (def_joueur >= 2) def_joueur -= 2; else def_joueur = 0;
            printf("   (Effet) %s perce votre defense (ignore 2 DEF)\n", c->nom);
    }
}

    int degats = base - def_joueur;
    if (degats < 1) degats = 1;

    j->points_de_vie -= degats;
    if (j->points_de_vie < 0) j->points_de_vie = 0;


    int stress = rand_intervalle(1, 2);
    j->niveau_oxygene -= stress;
    if (j->niveau_oxygene < 0) j->niveau_oxygene = 0;

    printf("> %s attaque !  -%d PV  | Joueur: %d/%d PV  O2:%d/%d\n",
           c->nom, degats,
           j->points_de_vie, j->points_de_vie_max,
           j->niveau_oxygene, j->niveau_oxygene_max);

    return degats;
}


void appliquer_effet_special(CreatureMarine *c, Plongeur *j) {
    if (!c || !c->est_vivant) return;

    // Meduse : -1 nombre d'attaque au prochain tour
    if (c->nom[0] == 'M') { // M pour "Meduse"
        if (rand_intervalle(1, 100) <= 40) {
            j->penalite_attaques_prochain_tour += 1;
            printf("   (Effet) Vous etes affaibli : -1 attaque au prochain tour (Meduse)\n");
        }
    }
}

// Riposte des creatures vivantes, ordre de vitesse decroissante
void attaque_des_creatures(CreatureMarine tab[], int taille, Plongeur *j) {
    int idx[16]; int n = 0;
    for (int i = 0; i < taille && n < 16; i++) {
        if (tab[i].est_vivant) idx[n++] = i;
    }
    if (n == 0) return;

    // Selectionne a chaque tour la creature vivante la plus rapide
    int utilise[16] = {0};
    for (int k = 0; k < n; k++) {
        int best_t = -1, best_v = -1;
        for (int t = 0; t < n; t++) {
            int i = idx[t];
            if (!utilise[t] && tab[i].est_vivant && tab[i].vitesse > best_v) {
                best_v = tab[i].vitesse;
                best_t = t;
            }
        }
        if (best_t == -1) break;
        utilise[best_t] = 1;

        CreatureMarine *c = &tab[idx[best_t]];
        if (!c->est_vivant) continue;

        if (c->nom[0] == 'K') { // K pour "Kraken"
            creature_frappe_joueur(c, j);
            if (rand_intervalle(1, 100) <= 60 && j->points_de_vie > 0) {
                printf("   (Effet) Kraken enchaine une deuxieme attaque !\n");
                creature_frappe_joueur(c, j);
            }
        } else {
            creature_frappe_joueur(c, j);
            appliquer_effet_special(c, j);
        }


        if (j->points_de_vie <= 0) {
            printf(">>> Vous etes KO !\n");
            break;
        }
    }
}

static int existe_creature_vivante(CreatureMarine tab[], int taille) {
    for (int i = 0; i < taille; i++) if (tab[i].est_vivant) return 1;
    return 0;
}
static int premiere_creature_vivante(CreatureMarine tab[], int taille) {
    for (int i = 0; i < taille; i++) if (tab[i].est_vivant) return i;
    return -1;
}

void afficher_interface_combat(CreatureMarine tab[], int taille, Plongeur *j) {
    printf("\n================ COMBAT SOUS-MARIN ================\n");
    printf("Plongeur  PV:%d/%d  O2:%d/%d  Fatigue:%d\n",
           j->points_de_vie, j->points_de_vie_max,
           j->niveau_oxygene, j->niveau_oxygene_max,
           j->niveau_fatigue);
    printf("---------------------------------------------------\n");
    for (int i = 0; i < taille; i++) {
        if (tab[i].est_vivant) {
            printf("[%d] %-12s  PV:%3d/%-3d  ATK:%2d-%-2d  DEF:%2d  VIT:%2d\n",
                   i, tab[i].nom,
                   tab[i].points_de_vie_actuels, tab[i].points_de_vie_max,
                   tab[i].attaque_minimale, tab[i].attaque_maximale,
                   tab[i].defense, tab[i].vitesse);
        }
    }
    printf("===================================================\n");
}

void tour_de_combat(CreatureMarine tab[], int taille, Plongeur *j, int profondeur) {
    if (j->points_de_vie <= 0 || !existe_creature_vivante(tab, taille)) return;

    // Nombre d'attaques max par tour 
    int max_actions = nombre_attaques_autorisees(j->niveau_fatigue,
                                                 j->penalite_attaques_prochain_tour);
    if (max_actions == 0) {
        printf("(Vous etes trop epuise pour attaquer ce tour.)\n");
    }

    // Attaques du joueur 
    for (int a = 0; a < max_actions; a++) {
        int cible = premiere_creature_vivante(tab, taille);
        if (cible == -1) break;
        if (j->points_de_vie <= 0) break;
        attaquer_avec_harpon(j, &tab[cible], profondeur);
        if (!existe_creature_vivante(tab, taille)) break;
    }

    j->penalite_attaques_prochain_tour = 0;

    // Riposte des creatures
    if (j->points_de_vie > 0 && existe_creature_vivante(tab, taille)) {
        attaque_des_creatures(tab, taille, j);
    }

    fin_de_tour_joueur(j, profondeur);
}

void boucle_combat(CreatureMarine tab[], int taille, Plongeur *j, int profondeur) {
    while (j->points_de_vie > 0 && existe_creature_vivante(tab, taille)) {
        afficher_interface_combat(tab, taille, j);
        tour_de_combat(tab, taille, j, profondeur);

        printf("\nAppuyez sur Entrer pour passer au prochain tour...");
        getchar(); 
        getchar(); 

    }

    if (j->points_de_vie <= 0) {
        printf("\n=== DEFAITE : vous avez ete vaincu. ===\n");
    } else {
        printf("\n=== VICTOIRE : toutes les creatures sont vaincues ! ===\n");
        generer_recompense(j);
    }
}
