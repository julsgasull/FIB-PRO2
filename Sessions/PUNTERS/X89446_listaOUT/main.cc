//main.cc

#include "LlistaIOint.hh"

int main()
{
	Llista<int> a;
	
	cout << "Escriu la llista acabada en 0:" << endl;
	llegir_llista_int(a,0);
	cout << endl;
	escriure_llista_int(a);
	cout << endl;

	Llista<int> b;
	int x; cout << "Escriu x:" << endl; cin >> x;
	b = a.reorganitzar_out(x);

	cout << "Llista reorganitzada:" << endl;
	escriure_llista_int(b); cout << endl;

}