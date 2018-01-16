// exemple d'us de la classe Llista

#include "LlistaIOint.hh"

int main(){
  Llista<int> l, q;
  cout << "Entra llista naturals (acabada per -1): " << endl;
  llegir_llista_int(l,-1);
  q = l;
  // rellenar por algo que tenga sentido
  escriure_llista_int(l);
  escriure_llista_int(q);

  escriure_llista_int_rev(l);
  escriure_llista_int_rev(q);

  q.fi();
  q.retrocedeix();
  q.eliminar();

  escriure_llista_int(l);
  escriure_llista_int(q);

  escriure_llista_int_rev(l);
  escriure_llista_int_rev(q);

  l.l_buida();
  l.afegir(100);
  if (l.dreta_de_tot()) cout << "l actual = NULL" << endl;
  else cout << "l actual = " << l.actual() << endl;
  q = l;
  cout << "l" << endl;
  escriure_llista_int(l);
  cout << "q" << endl;
  escriure_llista_int(q);

  q.retrocedeix();
  q.eliminar();
  cout << "lx" << endl;
  escriure_llista_int(l);
  cout << "q eliminada" << endl;
  escriure_llista_int(q);

  // rellenar por algo que tenga sentido
}
