#include "ArbIOint.hh"
#include <iostream>
using namespace std;

int main()
{
	Arbre<int> a;
	llegir_arbre_int(a, 0);

	cout << "ORIGINAL:" << endl;
	escriure_arbre_int(a);
	cout << endl;

	cout << "l'intento sumar" << endl;
	Arbre<int> b;
	a.arb_sumes(b);
	cout << "sumaat!" << endl;

	cout << "SUMA:" << endl;
	escriure_arbre_int(b);
	cout << endl;



	cout << "you did it!" << endl;
}

