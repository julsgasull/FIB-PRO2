//
//  main.cpp
//  X36902_parentesis.cc
//
//  Created by Júlia Gasull Navarro on 19/10/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//


#include <iostream>
#include <stack>
using namespace std;

bool calcul_exp() {
    stack<char> s;                          //pila s
    
    //llegeix pila (posa valors a pila)
    char p;
    while (cin >> p and p != '.') {
        s.push(p);
    }
    
    
    int par_o_c = 0;                        //parentesis opened closed
    int cla_o_c = 0;                        //claudators opened closed
    int aux;                                //auxiliar
    
    bool par_o = false;                     //bool parentesis opened
    bool cla_o = false;                     //bool claudator opened
    
    while (!s.empty()) {                    //mentre la pila no està buida
        
        aux = s.top();                      //auxiliar = el de dalt
        
        // ()
        if (aux == '(') {                           //si () obert:
            par_o_c--;                                  // -- par
            if (cla_o) return false;                    // ( ] -> no possible
            par_o = false;                              // ja m'ha vingut '(' => ja no l'espero
        }
        else if (aux == ')') {                      //si () tancat:
            par_o_c++;                                  // ++ par
            par_o = true;                               // espero un par obert '('
            cla_o = false;                              // no puc esperar [ )
        }
        
        // []
        else if (aux == '[') {                      //si [] obert:
            cla_o_c--;                                  // -- clau
            if (par_o) return false;                    // [ ) -> no possible
            cla_o = false;                              // ja m'ha vingut '[' => ja no l'espero
            
        }
        else if (aux == ']') {                      //si [] tancat:
            cla_o_c++;                                  // ++ clau
            cla_o = true;                               // espero un clau obert '['
            par_o = false;                              // no puc esperar ( ]
            
            
            
        }
        s.pop();            // vaig treient
        
        if (par_o_c < 0 or cla_o_c < 0) return false; //en el cas de tenir masses oberts al final -> no possible -> false
    }
    
    if (par_o_c != 0 or cla_o_c != 0) return false; //al final hem de tenir tants oberts com tancats
    
    return true; //si tot va bé -> true
}



int main() {
    if (calcul_exp()) cout << "Correcte" << endl;
    else cout << "Incorrecte" << endl;
}
