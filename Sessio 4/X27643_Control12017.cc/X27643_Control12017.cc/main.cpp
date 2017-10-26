//
//  main.cpp
//  X27643_Control12017.cc
//
//  Created by Júlia Gasull Navarro on 25/10/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include "Cjt_estudiants.hh"
#include "Estudiant.hh"
#include <iostream>
using namespace std;


void Cjt_estudiants::recalcular_pos_max_no_becat()
{
    int pos_nota_max = -1;
    int aux = 0;
    
    for (int i = 0; i < nest; ++i) {
        if (vest[i].te_nota()) {
            if (vest[i].aprovat() and !vest[i].te_beca()) {
            
                if (aux == 0) {
                    pos_nota_max = i;
                    ++aux;
                }
                else if(Estudiant::major_nota_dni(vest[i], vest[pos_nota_max])) pos_nota_max = i;
            }
        }
    }
    i_max_no_becat = pos_nota_max;
    
}




void Cjt_estudiants::esborrar_estudiant(int x, bool& trobat) {
    
    trobat = false;
    
    int i = cerca_dicot(vest, 0, nest-1, x);
    if (vest[i].consultar_DNI() == x) trobat = true;
    
    
    if (trobat) {                   //si l'haig d'esborrar
        if (vest[i].te_beca()) {
            if (i_max_no_becat == -1) --n_bec;
            else vest[i_max_no_becat].modificar_beca(true);
        }
        for (int j = i; j < nest-1; ++j) {
            vest[j] = vest[j+1];
        }
        --nest; //mida del p.i.
        
        recalcular_pos_max_no_becat();
    }
}

