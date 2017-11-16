//
//  mitjana.cpp
//  PRO2
//
//  Created by Júlia Gasull Navarro on 16/11/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include "BinTree.hh"
#include "BinTreeIOint.hh"
using namespace std;

/* Pre: t no és buit, t = T */
/* Post: el resultat és la màxima de les mitjanes de tots els subarbres no buits de T*/
void mm_i(const BinTree<double> &t, double &suma, int &n, double &mitjana)
{
    mitjana = 0;
    
    if (t.empty())
    {
        n = 0;
        suma = 0;
    }
    else
    {
        double mitj_max;
        double x = t.value();
        int ne, nd; //mides
        double maxe, maxd, se, sd; //mitjanes maximes, sumes
        mm_i(t.left(), se, ne, maxe);
        /* HI: el resultat és la màxima de les mitjanes del subarbre esquerre de T*/
        mm_i(t.right(), sd, nd, maxd);
        /* HI: el resultat és la màxima de les mitjanes de tots els subarbres no buits de T*/
        n = nd + ne + 1;
        suma = se + sd + x;
        mitjana = suma/double(n);
        mitj_max = max(maxe, maxd);
        if (mitj_max > mitjana) mitj_max = mitjana;
        mitjana = mitj_max;
    }
}


/* Pre: t no és buit, t = T */
/* Post: el resultat és la màxima de les mitjanes de tots els subarbres no buits de T*/
double mitjana_maxima(BinTree<double> &t)
{
    double mitjana;
    double suma;
    int n;
    mm_i(t, suma, n, mitjana);
    return mitjana;
}
