//
//  main.cpp
//  X45504_Contol22015.cc
//
//  Created by Júlia Gasull Navarro on 26/10/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include "ListaPalabras.hh"

void ListaPalabras::anadir_palabra(const Palabra &p) {
    int i;
    bool b;
    buscar_palabra_posicion(p, b, i);
    if (not b) {
        if (i == 0) {
            ++nparaules;
            paraules[i].par = p;
            paraules[i].freq = 1;
            npar_long[p.long_pal()-1] = 1;
            suma_frec_long[p.long_pal()-1] = 1;
        }
        
        else {
            bool trobat = false;
            int s = 0;
            while (not trobat and s < i) {
                if (p.menor_igual(paraules[s].par)) trobat = true;
                else ++s;
            }
            for(int j = i-1; j >= s; --j) paraules[j+1] = paraules[j];
            ++nparaules;
            paraules[s].par = p;
            paraules[s].freq = 1;
            ++npar_long[p.long_pal()-1];
            ++suma_frec_long[p.long_pal()-1];
        }
    }
    else {
        ++paraules[i].freq;                 //incremento frequència
        ++suma_frec_long[p.long_pal() - 1];
    }
}

void ListaPalabras::borrar_palabra(const Palabra &p) {
    //hem de buscar si hi és. sino no fem res
    int i;
    bool b;
    buscar_palabra_posicion(p, b, i);
    
    if(b) {
        if(paraules[i].freq > 1) {
            --paraules[i].freq;
            --suma_frec_long[p.long_pal() - 1];
        }
        else {              //freq=1 -> eliminar //// no pot ser <1 ja que sino no hi seria
            --nparaules;
            --suma_frec_long[paraules[i].par.long_pal() - 1];
            --npar_long[paraules[i].par.long_pal() - 1];
            for(int j = i; j < nparaules ; ++j) {
                paraules[j] = paraules[j+1];
            }
            
        }
    }
}

void ListaPalabras::buscar_palabra_posicion(const Palabra &p, bool &b, int &i) const {
    b = false;
    i = 0;
    while (not b and i < nparaules) {
        if(p.iguales(paraules[i].par)) {
            b = true;
        }
        else ++i;
    }
}
