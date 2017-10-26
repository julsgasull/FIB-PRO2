//
//  main.cpp
//  X23571_control1(4).cc
//
//  Created by Júlia Gasull Navarro on 15/10/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include "Cjt_estudiants.hh"

int Cjt_estudiants::posicio_nota(double nota_b) const {
    Estudiant est(0);
    est.afegir_nota(nota_b);
    int i = cerca_dicot_per_nota_dni(vest, 0, nest-1, est);
    return i;
}

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &trobat) {
    int dni = est.consultar_DNI();
    int posdni = cerca_lineal_per_dni(vest, 0, nest - 1, dni);
    int pos = cerca_dicot_per_nota_dni(vest, 0, nest - 1, est);
    
    if (posdni >= nest and dni > 0 and nest != MAX_NEST) {
        trobat = false;
        
        for (int i = nest - 1; i >= pos; --i) vest[i+1] = vest[i];
        vest[pos] = est;
        ++nest;
    
        if (not est.te_nota()) ++primer_est_amb_nota;
    }
    else trobat = true;
}

void Cjt_estudiants::escriure_i(double nota_i, double nota_s) const {
    int i = posicio_nota(nota_i);
    int s = posicio_nota(nota_s);
    
    for (int j = i; j < s; ++j) {
        vest[j].escriure();
    }
    
    while (s < nest and vest[s].consultar_nota() == nota_s) vest[s++].escriure();
}
