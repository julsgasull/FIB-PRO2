//
//  Solucio.cc
//  X90633_C1primavera15
//
//  Created by Júlia Gasull Navarro on 5/10/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b){
    b = false;
    
    int dni = est.consultar_DNI();
    int i = cerca_dicot(vest, 0, nest-1, dni);
    
    // El conjunt conté l'estudiant que es vol afegir
    if (vest[i].consultar_DNI() == dni) b = true;
    
    // S'afageix el nou estudiant
    if (not b) {
        for (int j = nest-1; j >= i; --j) vest[j+1] = vest[j];
        vest[i] = est;
        ++nest;
        
        if(est.te_nota()){
            suma_notes += est.consultar_nota();
            ++nest_amb_nota;
        }
    }
}
void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
    b = false;
    int i = cerca_dicot(vest, 0, nest-1, dni);      // i = pos del que volem esborrar o on hauria d'anar
    
    if (i < nest and vest[i].consultar_DNI() == dni) b = true;
    
    if (b) {
        if (vest[i].te_nota()){
            --nest_amb_nota;
            suma_notes -= vest[i].consultar_nota();
            mitjana_estudiants_amb_nota();
        }
        --nest;
        for (int j = i; j < nest; ++j) vest[j] = vest[j+1];
        
    }
        
}
