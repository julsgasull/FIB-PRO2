//
//  main.cpp
//  X68213_biblio.cc
//
//  Created by Júlia Gasull Navarro on 23/10/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int categoria;

void cas1(vector<stack <string> > &mostradors) {
    string nom;
    cin >> nom;
    cin >> categoria;
    --categoria;
    mostradors[categoria].push(nom);
}

void cas2(vector<stack <string> > &mostradors) {
    int q;
    cin >> q;
    cin >> categoria;
    --categoria;
    if (q <= mostradors[categoria].size()) {
        while (q > 0) {
            mostradors[categoria].pop();
            -- q;
        }
    }
    
}

void cas3(vector<stack <string> > mostradors) {
    cin >> categoria;
    cout << "Pila de la categoria " << categoria << endl;
    --categoria;
    while (not mostradors[categoria].empty()) {
        cout << mostradors[categoria].top() << endl;
        mostradors[categoria].pop();
    }
    cout << endl;
}

int main(){
    
    int n;                                      // número de categoria
    cin >> n;
    vector<stack <string> > mostradors(n);        // creo un vector de piles que contenen strings (mida n)
    
    
    int m;                                          // mètode: entre -1 i -4
    string nom;                                     // nom del llibre
    
    while (cin >> m and m != -4) {                  // si m'entra -4, acabo
        
        if (m == -1) {                              // afegim a la pila
            cas1(mostradors);
        }
        else if (m == -2) {                         // treiem de la pila
            cas2(mostradors);
        }
        else {                                      // m == -3
                                                    // escrivim la pila
            cas3(mostradors);
        }
        
    }
}
