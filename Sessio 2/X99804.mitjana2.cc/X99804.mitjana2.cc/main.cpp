//
//  main.cpp
//  X99804.mitjana2.cc
//
//  Created by Júlia Gasull Navarro on 21/9/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "Estudiant.hh"

using namespace std;


/*
 Entrada:   M(num. d'estudiants), N(num. assignatures), S(num. assignatures selec)
            S valors b1..bs, on bi = assignatura Abi
            M files que comencen pel DNI, amb N notes entre 0 i 10
 
 Sortida:   M files formades pel dni de cada estudiant (ordenades per nota i dni) + nota
            mitjana de l'alumne
*/


// Ordena les notes decreixentment
bool comp (const Estudiant& a, const Estudiant& b){
    if (a.consultar_nota() != b.consultar_nota()){
        return a.consultar_nota() > b.consultar_nota();
    }
    return a.consultar_DNI() < b.consultar_DNI();
}

int main(){
    // Entrada valors M(nº estudiants), N(nº assignatures), S(nº assig. seleccionades)
    int M, N, S;
    cin >> M >> N >> S;
    
    // Vector de bool de les assignatures
    vector<bool> Assig(N, false);
    
    // Entrada valors d'assignatures seleccionades
    int x;
    for (int i = 0; i < S; ++i){
        cin >> x;
        Assig[x-1] = true; // True a les assignatures seleccionades
    }
    
    // Vector d'estudiants que contindrà DNI i mitjana de les assig. selec.
    vector<Estudiant> vEst(M);
    
    // Mitjana de les assignatures seleccionades de cada estudiant
    for (int i = 0; i < M; ++i){
        int dni;
        cin >> dni;
        Estudiant est(dni);
        vEst[i] = est;
        
        double mitj = 0;
        double nota;
        for (int j = 0; j < N; ++j){
            cin >> nota;
            if (Assig[j] == true) mitj += nota;
        }
        mitj /= S;
        
        vEst[i].afegir_nota(mitj);
    }
    
    // Ordenar el vector d'estudiants per nota (decreixent)
    sort(vEst.begin(), vEst.end(), comp);
    
    // Imprimir vector d'estudiants
    for (int i = 0; i < M; ++i){
        vEst[i].escriure();
    }
}
