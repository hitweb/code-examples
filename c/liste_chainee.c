//
//  main.c
//  testC
//
//  Created by Brian FRAVAL on 12/12/2017.
//  Copyright © 2017 Brian FRAVAL. All rights reserved.
//

// Liste chaînée
// Creation, Affichage, Somme des éléments, free

#include <stdio.h>
#include <stdlib.h>

typedef float TypeDonnee;

// Declarer une liste chainee
typedef struct Cell {
    TypeDonnee donnee; // Definition des donnees, on peut mettre ce que l'on veut comme donnee
    struct Cell *suivant; // Pointeur sur la structure suivante de meme type que celle que l'on vient de definir
}TypeCellule;

// Declaration d'une liste
TypeCellule *L;

void AfficheDonnee (TypeDonnee donnee)
{
    printf("%f ", donnee); // Ici donnee est de type float
}

TypeDonnee SaisieDonnee(void)
{
    TypeDonnee donnee;
    scanf("%f", &donnee); // Ici donnee est de type float
    
    return donnee;
}

// Insertion en tete de liste
TypeCellule* InsereEnTete(TypeCellule *ancienL, TypeDonnee donnee)
{
    TypeCellule *nouveauL; // Nouvelle tete de liste
    
    // Creation d'une nouvelle Cellule
    nouveauL = (TypeCellule*)malloc(sizeof(TypeCellule));
    
    nouveauL->donnee = donnee;
    nouveauL->suivant = ancienL;
    
    return nouveauL; // Retourne la nouvelle tete de liste
}

TypeCellule* SaisieListeEnvers ()
{
    char choix;
    TypeDonnee donnee;
    
    TypeCellule *L = NULL; // Initialiation d'une liste obligatoire
    
    puts("Voulez-vous entrer une liste non vide ?");
    choix = getchar();
    getchar();
    
    while (choix == 'o')
    {
        puts("Entrez une donnée");
        donnee = SaisieDonnee(); // saisie au clavier
        getchar();
        
        L = InsereEnTete(L, donnee); // Insertion en tete de liste et recuperer la nouvelle liste dans L
        
        puts("Voulez-vous continuer ?");
        
        choix = getchar();
        getchar();
    }
    
    return L;
}

void Affichage (TypeCellule* L)
{
    TypeCellule *p;
    p = L; // On pointe sur le premiere cellule
    
    while (p != NULL) // Tant qu'il y a une cellule
    {
        AfficheDonnee(p->donnee) ; // On affiche la donnee
        p = p->suivant; // On passe a la cellule suivante
    }
    
    puts(""); // Passage a la ligne
}

void AffichageBis(TypeCellule* L)
{
    TypeCellule *p;
    
    // Affichage de la liste avec une boucle for tant qu'il y a une cellule
    for (p = L; p != NULL; p = p->suivant)
        AfficheDonnee(p->donnee);
    puts("");
}




TypeCellule *InsereEnQueue(TypeCellule *L, TypeDonnee donnee)
{
    TypeCellule *p, *nouveau;
    
    nouveau = (TypeCellule*)malloc(sizeof(TypeCellule));
    
    nouveau->donnee = donnee; // Donnee de la nouvelle cellule
    nouveau->suivant = NULL; // La nouvelle derniere cellule
    
    if (L == NULL) // Cas particulier si la liste est vide
    {
        L = nouveau;
    } else {
        // Recherche la derniere cellule
        for (p = L; p->suivant != NULL; p = p->suivant) {}
        
        p->suivant = nouveau; // Chainage
    }
 
    return L;
}

TypeCellule* SaisieListeEndroit()
{
    char choix;
    TypeDonnee donnee;
    
    TypeCellule *L = NULL;
    puts("Voulez-vous entrer une liste non vide ?");
    choix = getchar();
    getchar();
    
    while (choix == 'o')
    {
        puts("Entrez une donnée");
        donnee = SaisieDonnee();
        getchar();
        
        L = InsereEnQueue(L, donnee); // Insertion en queue
        puts("Voulez-vous continuer ?");
        choix = getchar();
        getchar();
    }
    
    return L;
}

void Liberation(TypeCellule **pL) // Passage d'un pointeur par adresse pointeur sur pointeur
{
    TypeCellule *p;
    
    while(*pL != NULL)
    {
        p = *pL; // Memorisation de l'adresse de la cellule
        *pL = (*pL)->suivant; // Cellule suivante
        free(p); // Destruction de la cellule memorisee
    }
    
    *pL = NULL; // On reinitialise la liste a vide
}

// Calcul la somme des éléments d'une liste chaînée
int Somme(TypeCellule *L)
{
    TypeCellule *p;
    int somme = 0;
    
    p = L;
    while (p != NULL)
    {
        somme += p->donnee;
        p = p->suivant;
    }
    
    return somme;
}

// Recherche d'un éléments de la liste chaînée
TypeCellule *Recherche(TypeCellule *L, TypeDonnee n)
{
    TypeCellule *p;
    p = L;
    
    while (p != NULL && p->donnee != n)
        p = p->suivant;

    if (p == NULL)
        return NULL;
    
    return p;
}


int main(int argc, const char * argv[]) {
    printf("Ma premiere liste!\n");
    
    TypeCellule *L;
    int som = 0;
    
    //L = SaisieListeEnvers(); // On recupere l'adresse de la premiere cellule
    L = SaisieListeEndroit();
    
    Affichage(L);
    
    // Calcul la somme des éléments de la chaine
    som = Somme(L);
    printf("%d\n", som);
    
    Liberation(&L);
    
    return 0;
}
