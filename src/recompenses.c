#include <stdio.h>
#include <stdlib.h>
#include "recompenses.h"
#include "inventaire.h"

void generer_recompense(Plongeur *j) {
    int r = rand() % 3;

    if (r == 0) {
        printf("\nUne capsule d'oxygene est trouvee.\n");
        ajouter_objet(j, "Capsule O2");
    }
    else if (r == 1) {
        printf("\nUne trousse de soin est trouvee.\n");
        ajouter_objet(j, "Trousse Soin");
    }
    else {
        int p = (rand() % 11) + 5;
        printf("\nVous trouvez %d perles.\n", p);
        j->perles += p;
    }

    printf("Appuyez sur Entree pour continuer.");
    getchar();
    getchar();
}
