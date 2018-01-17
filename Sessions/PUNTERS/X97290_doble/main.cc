// exemple d'us de la classe Llista

#include "LlistaIOint.hh"

int main(){
  Llista<int> l, q;
  cout << "Entra llista naturals (acabada per -1): " << endl;
  llegir_llista_int(l,-1);
  q = l;
  // rellenar por algo que tenga sentido
  cout << "Linia 12: escriure 1" << endl;
  escriure_llista_int(l);
  cout << "Linia 14: escriure 2" << endl;
  escriure_llista_int(q);

  cout << "Linia 17: escriure 1 invertida" << endl;
  escriure_llista_int_rev(l);
  cout << "Linia 19: escriure 2 invertida" << endl;
  escriure_llista_int_rev(q);

  cout << "Vull esborrar ultim node de 2" << endl;
  q.fi();
  q.retrocedeix();
  q.eliminar();
  cout << "Hem eliminat ultim node de 2" << endl;


  cout << "Linia 29: escriure 1" << endl;
  escriure_llista_int(l);
  cout << "Linia 31: escriure 2" << endl;
  escriure_llista_int(q);

  cout << "Linia 34: escriure 1 invertida" << endl;
  escriure_llista_int_rev(l);
  cout << "Linia 36: escriure 2 invertida" << endl;
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


  cout << "FINAL -> ueeeeee!!!!!!!!!!!!!!" << endl; 
  // rellenar por algo que tenga sentido
}
