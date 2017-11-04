//
//  PRO2
//
//  Created by Júlia Gasull Navarro on 1/11/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//


#include <iostream>
#include "BinTreeIOParInt.hh"
#include "ParInt.hh"
using namespace std;

pair<int, int> cerca(BinTree<ParInt> t, int n, int &prof) {
    pair<int, int> p_esq = make_pair(-1, -1);
    pair<int, int> p_dre = make_pair(-1, -1);
    
    if (t.empty()) return p_esq;
    else if (t.value().primer() == n) {
        return make_pair(t.value().segon(), prof);
    }
    else {
        p_esq = cerca(t.left(), n, ++prof);
        --prof;
        p_dre = cerca(t.right(), n, ++prof);
        --prof;
        if (p_esq.second < 0) return p_dre;
        else if (p_dre.second < 0) return p_esq;
        else return (p_esq.second < p_dre.second) ? p_esq : p_dre;
    }
}

int main() {
    
    BinTree<ParInt> t;
    read_bintree_parint(t);
    
    int n;
    while (cin >> n) {
        int prof = 0;
        pair<int, int> trobat = cerca(t, n, prof);
        if (trobat.second >= 0) cout << n << ' ' << trobat.first << ' ' << trobat.second << endl;
        else cout << -1 << endl;
    }
    
    
}

