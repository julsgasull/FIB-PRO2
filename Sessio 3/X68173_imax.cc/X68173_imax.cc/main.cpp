//
//  main.cpp
//  X68173_imax.cc
//
//  Created by Júlia Gasull Navarro on 5/10/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include "Cjt_estudiants.hh"
#include "Estudiant.hh"

int main() {
    Cjt_estudiants c;
    Estudiant est;
    cout << "Entra el conjunt, precedit per la mida: " << endl;
    c.llegir();
    cout << endl << "El teu conjunt es: " << endl;
    c.escriure();
    cout << endl;
    int n;
    cout << "1 - Afegir estudiant" << endl;
    cout << "2 - Modificar estudiant" << endl;
    cout << "3 - Modificar iessim" << endl;
    cout << "4 - Esborrar" << endl;
    cout << "5 - Estudiant nota max" << endl << endl;
    while (cin >> n) {
        if (n == 1) {
            est.llegir();
            c.afegir_estudiant(est);
            cout << endl;
            c.escriure();
            cout << endl;
        }
        else if (n == 2) {
            est.llegir();
            c.modificar_estudiant(est);
            cout << endl;
            c.escriure();
            cout << endl;
        }
        else if (n == 3) {
            int i;
            cin >> i;
            est.llegir();
            c.modificar_iessim(i, est);
            cout << endl;
            c.escriure();
            cout << endl;
        }
        else if (n == 4) {
            int dni;
            cin >> dni;
            c.esborrar_estudiant(dni);
            cout << endl;
            c.escriure();
            cout << endl;
        }
        else if (n == 5) {
            est = c.estudiant_nota_max();
            est.escriure();
        }
        else cout << endl << "Introdueix un numero valid" << endl;
        cout << endl;
        cout << "1 - Afegir estudiant" << endl;
        cout << "2 - Modificar estudiant" << endl;
        cout << "3 - Modificar iessim" << endl;
        cout << "4 - Esborrar" << endl;
        cout << "5 - Estudiant nota max" << endl << endl;
    }
}
