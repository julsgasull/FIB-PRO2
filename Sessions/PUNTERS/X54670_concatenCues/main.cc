#include "CuaIOint.hh"

int main()
{
	Cua<int> c1, c2;
	cout << "Entra cua 1 naturals (acabada per -1): " << endl;
	llegir_cua_int(c1, -1);
	cout << "Entra cua 2 naturals (acabada per -1): " << endl;
	llegir_cua_int(c2, -1);

	cout << "Cua 1" << endl;
	escriure_cua_int(c1);
	cout << "Cua 2" << endl;
	escriure_cua_int(c2);

	c1.concat(c2);

	cout << "Cua concatenada" << endl;
	escriure_cua_int(c1);
	if (c2.es_buida()) cout << "TOT PERFECTE" << endl;
	else cout << "L'has cagao" << endl;
}
