//
//  main.cpp
//  X73814_simplvec.cc
//
//  Created by Júlia Gasull Navarro on 19/9/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

/* 
 simplificar notes d'un vector -> nota més alta de cadascun
 Pre: seq d'estudiants (DNI + nota(i)), DNI != 0
 Post: sortir igual però amb nota màxima
*/

#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

void llegir(vector<Estudiant>& v) {
    int mida;
    cin >> mida;
    v = vector<Estudiant> (mida);
    
    for (int i= 0; i < mida; ++i) {
        int DNI;
        cin >> DNI;
        
        Estudiant alumne(DNI);
        v[i] = alumne;
        
        double nota;
        cin >> nota;
        if (0 <= nota and nota <= 10) v[i].afegir_nota(nota);
    }
    
}


int nova_mida(const vector<Estudiant>& v) {
    int mida = v.size();
    int nova_mida = 0;
    int DNI = -1;
    for (int i = 0; i < mida; ++i) {
        if (v[i].consultar_DNI() != DNI) {
            ++nova_mida;
            DNI = v[i].consultar_DNI();
        }
    }
    return nova_mida;
}


void simplifica(const vector<Estudiant>& v, vector<Estudiant>& u) {
    int it = -1;
    int dni = -1;
    int mida = v.size();
    
    for (int i = 0; i < mida; ++i) {
        int DNI = v[i].consultar_DNI();
        
        if (DNI != dni) {
            dni = DNI;
            ++it;
            Estudiant alumne(DNI);
            u[it] = alumne;
            if (v[i].te_nota()) u[it].afegir_nota(v[i].consultar_nota());
        }
        
        else {
            if (v[i].te_nota()) {
                if (u[it].te_nota()) {
                    double mark = v[i].consultar_nota();
                    if (u[it].consultar_nota() < mark) u[it].modificar_nota(mark);
                }
                else u[it].afegir_nota(v[i].consultar_nota());
            }
        }
    }
}

void escriu(const vector<Estudiant>& u) {
    int mida = u.size();
    for (int i = 0; i < mida; ++i) u[i].escriure();
}


int main () {
    vector<Estudiant> v;
    llegir(v);
    vector<Estudiant> u(nova_mida(v));
    simplifica(v, u);
    escriu(u);
}
