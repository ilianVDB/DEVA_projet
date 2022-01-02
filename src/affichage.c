#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/abr.h"
#include "header/produit.h"

/* 
    cette partie à été realiser par GALFANO Nathan
*/

ABRS rechercheProduit(char nom[], ABRS a){
    ABRS c=malloc(sizeof(site));
    ABRS b=malloc(sizeof(site));
    b->prod= creeProduit("NULL",0,0);
    if(a!=NULL){
        if(strcmp(nom,a->prod.nom)==0){
            printf("\n %s  prix : %lf quantite : %d\n",a->prod.nom,a->prod.prix, a->prod.stock);
            b= a;
        }
            c=rechercheProduit(nom,a->left);
            if(strcmp(c->prod.nom,"NULL") != 0) b=c;
            c=rechercheProduit(nom,a->right);
            if(strcmp(c->prod.nom,"NULL") != 0) b=c;
    }
    
    return b;
}

ABRS afficheListProd(ABRS a){
    if(a!=NULL){
        afficheListProd(a->left);
        if(a->prod.stock!=0){
            printf("|");
            printf("%s",a->prod.nom);
            for(int i=0;i+strlen(a->prod.nom)<10;i++){
                printf(" ");
            }
            printf("|");
            printf(" prix : %lf",a->prod.prix);
            printf("|");
            printf(" quantite : %d\n",a->prod.stock);
        }
        afficheListProd(a->right);
    }
}

void menu(){
    ABRS a=NULL;
    a=lireProd(a);
    int wtd;
    while(wtd!=4){
        printf("\n\n\n1. afficher la liste des produit en vente\n2. ajouter un produit a vendre\n3. acheter produit\n4. sortir\nquevoulez vous faire?\n");
        scanf("%d",&wtd);
        switch(wtd){
            case 1:
                afficheListProd(a);
            break;

            case 2:
                ajouterProduit(a);
            break;

            case 3:
                acheterProduit(a);
            break;

            case 4:
            break;
        }
    }

    printf("merci d'avoir utiliser notre site internet\n");
}
