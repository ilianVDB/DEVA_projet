#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/abr.h"
#include "header/produit.h"

/* 
    cette partie à été realiser par ALKHABBASH Mohamed
*/

produit creeProduit(char nomp[], double prix,int cant){
    produit p;
    p.nom=malloc(strlen(nomp)*sizeof(char));
    strcpy(p.nom,nomp);
    p.prix=prix;
    p.stock=cant;
    return p;
}

ABRS creerNoeudProd(produit p){
    ABRS newNoeud = (ABRS)malloc(sizeof(site));
    if(newNoeud){
        newNoeud->prod = p;
        newNoeud->left=NULL;
        newNoeud->right=NULL;
    }
    return newNoeud;
}

ABRS inserDansABRS(ABRS a,produit p){
    if(a == NULL){
        ABRS newNoeud = creerNoeudProd(p);
        a=newNoeud;
    }
    else{
        if(a->prod.prix > p.prix){
            a->left=inserDansABRS(a->left,p);
        }
        if(a->prod.prix < p.prix){
             a->right=inserDansABRS(a->right,p);
        }
    }
    return a;
}