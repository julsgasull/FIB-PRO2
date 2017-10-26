//
//  main.cpp
//  X39577_mitjanes_select.cc
//
//  Created by Júlia Gasull Navarro on 21/9/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include "Estudiant.hh"

#include <iostream>
#include <vector>
using namespace std;

void modifica(vector<bool>& v, int S) {
    int n;
    for (int i = 0; i < S; ++i) {
        cin >> n;
        v[n-1] = true;
    }
}

void opera(vector<Estudiant>& v, const vector<bool>& assig, int s, int n) {
    
    int midav = v.size();
    for (int i = 0; i < midav; ++i) {
        int dni;
        cin >> dni;
        Estudiant alumne(dni);
        v[i] = alumne;
        double nota = 0;
        
        for (int j = 0; j < n; ++j) {
            double nota2;
            cin >> nota2;
            if (assig[j]) nota += nota2;
        }
        nota /= s;
        v[i].afegir_nota(nota);
    }
}

void escriu(const vector<Estudiant>& u) {
    int mida = u.size();
    for (int i = 0; i < mida; ++i) u[i].escriure();
}

int main() {
    int M, N, S;
    cin >> M >> N >> S;
    vector<bool> assig(N, false);
    modifica(assig, S);
    vector<Estudiant> v(M);
    opera(v, assig, S, N);
    escriu(v);
}
