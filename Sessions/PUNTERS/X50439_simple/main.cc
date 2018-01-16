#include "PilaIOint.hh"

int main(){

  Pila<int> p;
  Pila<int> q;


  cout << "Entra pila naturals (acabada per -1): " << endl;
  llegir_pila_int(p,-1);

  q = p;

  escriure_pila_int(p);
  escriure_pila_int(q);

  q.desempilar(); //pop

  escriure_pila_int(p);
  escriure_pila_int(q);


  cout << "FINAL" << endl;
}
