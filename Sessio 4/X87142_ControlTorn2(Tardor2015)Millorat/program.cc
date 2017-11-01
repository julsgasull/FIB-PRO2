//
//  solucio.cc
//  X84760_control2.cc
//
//  Created by Júlia Gasull Navarro on 15/10/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
    int dni = est.consultar_DNI();
    int pos = cerca_dicot(vest, 0, nest - 1, dni);
    
    if (vest[pos].consultar_DNI() != dni) {
        b = false;
        
        for (int i = nest - 1; i >= pos; --i) {
            vest[i+1] = vest[i];
        }
        ++nest;
        vest[pos] = est;
        recalcular_posicio_imax();
    }
    else b = true;
}

void Cjt_estudiants::eliminar_estudiants_sense_nota() {
    vector<Estudiant> aux(nest);
    int quants = 0;
    
    for (int i = 0; i < nest; ++i) {
        if (vest[i].te_nota()) {
            aux[quants] = vest[i];
            ++quants;
        }
    }
    
    nest = quants;
    for (int i = 0; i < nest; ++i) {
        vest[i] = aux[i];
    }
    recalcular_posicio_imax();
}
