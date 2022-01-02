#ifndef ______ARBRE_____
#define ______ARBRE_____
#include "produit.h"

typedef struct _Site{
    produit prod;
    struct _Site *left;
    struct _Site *right;
}site,*ABRS;

ABRS lireProd(ABRS a);
ABRS creerNoeudProd(produit p);
ABRS inserDansABRS(ABRS a,produit p);
ABRS ajouterProduit(ABRS a);
ABRS afficheListProd(ABRS a);
ABRS rechercheProduit(char nom[], ABRS a);
ABRS acheterProduit(ABRS a);
ABRS newDonne(ABRS a);

#endif
