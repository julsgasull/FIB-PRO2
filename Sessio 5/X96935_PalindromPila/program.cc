//
//  main.cpp
//  X96935_Palindroms_piles.cc
//
//  Created by Júlia Gasull Navarro on 19/10/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//


#include <iostream>
#include <stack>
using namespace std;


int main() {
    
    //quants elements té el "palíndrom"
    int n;
    cin >> n;
    
    //creo pila
    stack<int> pila;
    int s;

    int sp = n/2;                       //meitat del palíndrom
    
    //entro la meitat a la pila
    for (int i = 0; i < sp; ++i) {
        cin >> s;
        pila.push(s);
    }
    
    bool palindrom = true;
    int count = sp;
    
    if (n%2 != 0) cin >> s;             //si imparell, no ens importa el del mig
    
    while (palindrom and count != 0) {
        
        cin >> s;
        if (s != pila.top()) palindrom = false;
        pila.pop();
        -- count;
    }
    
    if (palindrom) cout << "SI" << endl;
    else cout << "NO" << endl;

}
