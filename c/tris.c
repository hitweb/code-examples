//
//  main.c
//  testC.algos_tri
//
//  Created by Brian FRAVAL on 13/12/2017.
//  Copyright © 2017 Brian FRAVAL. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// Comparaison des algos de tris, du plus lent au plus rapide
//
// tri par bulles
// tri par selection
// tri par insertion
// tri rapide (quicksort)
//

/**
 *   Renvoie l'indice du plus grand élément du tableau
 *
 *   int tab[] :: tableau dans lequel on effectue la recherche
 *   int taille :: taille du tableau
 *
 *   return int l'indice du plus grand élément
 **/
int max(int tab[], int taille)
{
    // on considère que le plus grand élément est le premier
    int i=0, indice_max=0;
    
    while(i < taille)
    {
        if(tab[i] > tab[indice_max])
            indice_max = i;
        i++;
    }
    
    return indice_max;
}


/**
 *   Échange deux éléments d'un tableau
 *
 *   int tab[] :: tableau dans lequel on effectue l'échange
 *   int x :: indice du premier élément
 *   int y :: indice du second élément
 *
 *   return void
 **/
void echanger(int tab[], int x, int y)
{
    int tmp;
    
    tmp = tab[x];
    tab[x] = tab[y];
    tab[y] = tmp;
}

void tri_a_bulle(int *t, int const size)
{
    int en_desordre = 1;
    
    for (int i = 0; i < size && en_desordre; ++i)
    {
        en_desordre = 0;
        for (int j = 1; j < size - i; ++j)
        {
            if (t[j-1] > t[j])
            {
                int temp = t[j-1];
                t[j-1] = t[j];
                t[j] = temp;
                en_desordre = 1;
            }
        }
    }
}


/**
 *   Trie le tableau donné selon l'algorithme de tri par sélection
 *
 *   int tab[] :: tableau à trier
 *   int taille :: taille du tableau
 *
 *   return void
 **/
void tri_selection(int tab[], int taille)
{
    int indice_max;
    
    // à chaque tour de boucle, on va déplacer le plus grand élément
    // vers la fin du tableau, on diminue donc à chaque fois sa taille
    // car le dernier élément est obligatoirement correctement
    // placé (et n'a donc plus besoin d'être parcouru/déplacé)
    
    for(; taille > 1 ; taille--) // tant qu'il reste des éléments non triés
    {
        indice_max = max(tab, taille);
        echanger(tab, taille-1, indice_max); // on échange le dernier élément avec le plus grand
    }
}

/**
 *   Trie le tableau donné selon l'algorithme de tri par sélection
 *
 *   VERSION RÉCURSIVE
 *
 *   int tab[] :: tableau à trier
 *   int taille :: taille du tableau
 *
 *   return void
 **/
void tri_selection_recursif(int tab[], int taille)
{
    // un tableau d'un seul élément ou moins n'a pas besoin d'être trié
    if(taille <= 1)
        return;
    
    echanger(tab, taille-1, max(tab, taille)); // on échange le dernier élément avec le plus grand
    
    // on rappelle la fonction en diminuant la taille du tableau
    // on peut faire cela car on est certain que le dernier élément
    // est le plus grand (donc plus besoin de le déplacer)
    return tri_selection_recursif(tab, taille-1);
}




void tri_insertion(int *t, int n)
{
    int i, j;
    int elementInsere;
    
    for (i = 1; i < n; i++) {
        /* Stockage de la valeur en i */
        elementInsere = t[i];
        /* Décale les éléments situés avant t[i] vers la droite
         jusqu'à trouver la position d'insertion */
        for (j = i; j > 0 && t[j - 1] > elementInsere; j--) {
            t[j] = t[j - 1];
        }
        /* Insertion de la valeur stockée à la place vacante */
        t[j] = elementInsere;
    }
}


void quickSort(int tableau[], int debut, int fin)
{
    int gauche = debut-1;
    int droite = fin+1;
    const int pivot = tableau[debut];
    
    /* Si le tableau est de longueur nulle, il n'y a rien à faire. */
    if(debut >= fin)
        return;
    
    /* Sinon, on parcourt le tableau, une fois de droite à gauche, et une
     autre de gauche à droite, à la recherche d'éléments mal placés,
     que l'on permute. Si les deux parcours se croisent, on arrête. */
    while(1)
    {
        do droite--; while(tableau[droite] > pivot);
        do gauche++; while(tableau[gauche] < pivot);
        
        if(gauche < droite)
            echanger(tableau, gauche, droite);
        else break;
    }
    
    /* Maintenant, tous les éléments inférieurs au pivot sont avant ceux
     supérieurs au pivot. On a donc deux groupes de cases à trier. On utilise
     pour cela... la méthode quickSort elle-même ! */
    quickSort(tableau, debut, droite);
    quickSort(tableau, droite+1, fin);
}


void affiche(int *tableau, int tailleTableau)
{
    int i;
    
    for (i = 0 ; i < tailleTableau ; i++)
    {
        printf("%d\n", tableau[i]);
    }
}

int main(int argc, const char * argv[]) {

    // Initialisation du tableau
    int tableau[10];
    int i = 10;
   
    tableau[0] = 10;
    tableau[1] = 23;
    tableau[2] = 505;
    tableau[3] = 80;
    tableau[4] = 18;
    tableau[5] = 58;
    tableau[6] = 68;
    tableau[7] = 8;
    tableau[8] = 88;
    tableau[9] = 108;
    
    // Autre forme d'initiation
    //int tableau[10] = {10,23,505,80,18,58,68,8,88,108}, i = 10;
    
    
    affiche(tableau, i);
    
    // Tri par bulles - Le plus lent
    // printf("\nAffichage le tableau triee (tri par bulles) :\n");
    // tri_a_bulle(tableau, i);
    // affiche(tableau, i);
    
    // Tri par selection - Un peu plus rapide
    // printf("\nAffichage le tableau triee (tri selection) :\n");
    // tri_selection_recursif(tableau, i);
    // affiche(tableau, i);
    
    // Tri par insertion - Plus rapide
    // printf("\nAffichage le tableau triee (tri insertion) :\n");
    // tri_insertion(tableau, i);
    // affiche(tableau, i);
    
    // Tri QuickSort - Le plus rapide
    printf("\nAffichage le tableau triee (tri quicksort) :\n");
    quickSort(tableau, 0, i);
    affiche(tableau, i);
    return 0;
}
