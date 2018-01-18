#include "LlistaIOint.hh"

int main() {
    Llista<int> a;
    cout << "Escriu la llista acabada amb 0:" << endl;
    llegir_llista_int(a,0); cout << endl;
    escriure_llista_int(a); cout << endl;

    Llista<int> b;
    a.split(b);

    cout << "Llista escala senars:" << endl;
    escriure_llista_int(a); cout << endl;

    cout << "Llista escala parells:" << endl;
    escriure_llista_int(b); cout << endl;
}
