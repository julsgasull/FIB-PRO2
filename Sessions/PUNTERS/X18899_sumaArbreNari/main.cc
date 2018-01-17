//main.cc
#include "ArbNIOint.hh"
#include <iostream>
using namespace std;

int main()
{
	cout << "Escriu l'aritat:" << endl;
	int ari; cin >> ari;

	ArbreNari<int> a(ari);
	cout << "Posa l'arbre en preordre:" << endl;
	llegir_arbre_int(a,0);

	cout << "a en preordre:" << endl;
	escriure_arbre_int(a);
	cout << endl;

	cout << "creo b" << endl;
	ArbreNari<int> b(ari);
	cout << "faig suma" << endl;
	a.arbsuma(b);
	cout << "suma feta" << endl;

	cout << "b sum en preordre:" << endl;
	escriure_arbre_int(b);
	cout << endl;
}


/*
    a =       5           arbre de sumes d'a =       31
            / | \                                  /  |  \
          7   1   3                              10   1   15
        /  \      | \                           /   \     | \ 
       2    1     8  4                         2     1    8  4
*/