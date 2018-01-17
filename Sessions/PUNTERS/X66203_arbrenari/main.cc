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
	cout << "maxim " << a.maxim() << endl;

	cout << "a en preordre:" << endl;
	escriure_arbre_int(a);
	cout << endl;
}