#ifndef ____produit____
#define ____produit____

typedef struct _produit{
    char *nom;
    double prix;
    int stock;
}produit,*PROD;

produit creeProduit(char nom[], double prix,int cant);
void ajouterProduitDonne(produit p);
void menu();

#endif