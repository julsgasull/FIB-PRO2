//
//  X19134_CercaParInt.cpp
//  PRO2
//
//  Created by Júlia Gasull Navarro on 1/11/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include "LlistaIOEstudiant.hh"

using namespace std;

int BuscarDNIenLlistaEstudiant(list<Estudiant> &l, int dni){
    int count = 0;
    for(list<Estudiant>::iterator it = l.begin(); it != l.end(); ++it){
        Estudiant est;
        est = *it;
        if(est.consultar_DNI() == dni) ++count;
    }
    return count;
}

int main(){
    list<Estudiant> l;
    LlegirLlistaEstudiant(l);
    int dni;
    cin >> dni;
    int count = BuscarDNIenLlistaEstudiant(l, dni);
    cout << dni << ' ' << count << endl;
}
