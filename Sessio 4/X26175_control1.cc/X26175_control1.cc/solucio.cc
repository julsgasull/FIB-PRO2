//
//  main.cpp
//  X26175_control1.cc
//  Control - Torn 1 (Tardor 2015)
//  Created by Júlia Gasull Navarro on 15/10/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
    
    int dni = est.consultar_DNI();
    int pos = cerca_dicot(vest, 0, nest-1, dni);
    
    if (vest[pos].consultar_DNI() != dni) {
        b = false; //si hi és (dni son iguals)
        for (int i = nest - 1; i >= pos; i--) {
            vest[i+1] = vest[i];
        }
        ++nest;
        vest[pos] = est;
        
        if (est.te_nota()) {
            int nota = int (est.consultar_nota());
            if (nota == 10) nota = 9;
            ++ intervals[nota];
        }
    }
    
    else b = true;
    
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
    int pos = cerca_dicot(vest, 0, nest - 1, dni);
    
    if (vest[pos].consultar_DNI() == dni) {
        b = true;
        
        if (vest[pos].te_nota()) {
            int nota = vest[pos].consultar_nota();
            if (nota == 10) nota = 9;
            --intervals[nota];
        }
        
        for (int i = pos; i < nest-1; ++i) {
            vest[i] = vest[i+1];
        }
        --nest;
    }
    else b = false;
}
