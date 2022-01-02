#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header/abr.h"
#include "header/produit.h"

/* 
    cette partie à été realiser par VANDENBERGHE Ilian
*/

ABRS lireProd(ABRS a){
    produit p;
    char nomprec[255];
    char nom[255];
    double prix;
    int cant;
    FILE *fic =fopen("donneeProduit.txt","r");
    while(!feof(fic)){
        fscanf(fic,"%s%lf%d",nom,&prix,&cant);
        if(strcmp(nomprec,nom)!=0){
            a=inserDansABRS(a,creeProduit(nom,prix,cant));
        }
        strcpy(nomprec,nom);
    }
    fclose(fic);
    return a;
}

ABRS ajouterProduit(ABRS a){
    char nom[200];
    double prix;
    int cant;
    printf("quelle est le nom du produit\n");
    scanf("%s",nom);
    printf("quelle est sont prix\n");
    scanf("%lf",&prix);
    printf("combien en vendez vous ?\n");
    scanf("%d",&cant);

    produit p;
    p=creeProduit(nom,prix,cant);

    ABRS b = rechercheProduit(p.nom,a);

    if(strcmp(b->prod.nom,p.nom)==0 && b->prod.prix==p.prix){
        b->prod.stock+=cant;
        
        remove("donneeProduit.txt");
        FILE *fic =fopen("donneeProduit.txt","w");
        fclose(fic);
        newDonne(a);
    }
    else{

        FILE* fic = fopen("donneeProduit.txt","a");

        fprintf(fic,"%s %lf %d\n",nom,prix,cant);
        a=inserDansABRS(a,p);
        fclose(fic);
    }

    return a;
}

ABRS acheterProduit(ABRS a){
    char nom[200];
    int pos;
    printf("quelle est le nom du produit que vous recherche?\n");
    scanf("%s",nom);
    ABRS p = rechercheProduit(nom,a);

    if(strcmp(p->prod.nom,"NULL")==0) printf("le produit que vous chercher n'est pas dans l'arbre\n");
    else{
        if(p->prod.stock>0){
            int quant;
            printf("il restent %d %s en stock. Combien vous en voulez?",p->prod.stock,p->prod.nom);
            scanf("%d",&quant);
            if(quant>p->prod.stock) printf("il n'y en a pas assez\n");
            else{
                p->prod.stock-=quant;
                remove("donneeProduit.txt");
                FILE *fic =fopen("donneeProduit.txt","w");
                fclose(fic);
                newDonne(a);
            }
        }
    }
}

ABRS newDonne(ABRS a){
    if(a!=NULL){
        newDonne(a->left);
        ajouterProduitDonne(a->prod);
        newDonne(a->right);
    }
}

void ajouterProduitDonne(produit p){
    FILE* fic = fopen("donneeProduit.txt","a");

    fprintf(fic,"%s %lf %d\n",p.nom,p.prix,p.stock);
    fclose(fic);
}