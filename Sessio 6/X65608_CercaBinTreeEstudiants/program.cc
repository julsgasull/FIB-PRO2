//
//  PRO2
//
//  Created by Júlia Gasull Navarro on 1/11/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//


#include <iostream>
#include "BinTreeIOEst.hh"
#include "Estudiant.hh"
using namespace std;

pair<int, int> cerca(BinTree<Estudiant> t, int n, int &prof) {
    pair<int, int> p_esq = make_pair(-1, -1);
    pair<int, int> p_dre = make_pair(-1, -1);
    
    if (t.empty()) return p_esq;
    else if (t.value().consultar_DNI() == n) {
        if (t.value().te_nota()) return make_pair(t.value().consultar_nota(), prof);
        return make_pair(-1, prof);
    }
    else {
        p_esq = cerca(t.left(), n, ++prof);
        --prof;
        p_dre = cerca(t.right(), n, ++prof);
        --prof;
        if (p_esq.second < 0) return p_dre;
        else if (p_dre.second < 0) return p_esq;
        else return (p_esq.second <= p_dre.second) ? p_esq : p_dre;
    }
}

int main() {
    
    BinTree<Estudiant> t;
    read_bintree_est(t);
    
    int n;
    while (cin >> n) {
        
        cout << n << ' ';
        
        int prof = 0;
        pair<int, int> trobat = cerca(t, n, prof);
        
        if (trobat.second < 0) cout << -1 << endl;
        else if (trobat.first < 0) cout << trobat.second << ' ' << -1 << endl;
        else cout << trobat.second << ' ' << trobat.first << endl;
    }
    
    
}

