#ifndef INVENTAIRE_H
#define INVENTAIRE_H

#include "joueur.h"

void init_inventaire(Plongeur *j);
void ajouter_objet(Plongeur *j, const char *nom_objet);
void afficher_inventaire(Plongeur *j);

#endif
