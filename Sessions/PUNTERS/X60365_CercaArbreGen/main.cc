//main.cc

#include "ArbGIOint.hh"

int main()
{
	ArbreGen<int> a;
	cout << "Posa els valors de l'arbre general en preordre" << endl;
	llegir_arbre_int(a,0);

	cout << "Escrivim l'arbre general en preordre" << endl;
	escriure_arbre_int(a);
	cout << endl;

	int x; cin >> x;
	if (a.buscar(x)) cout << "trobat" << endl;
	else cout << "no trobat" << endl;

}