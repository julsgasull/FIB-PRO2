//program.hh

void arb_sumes_immersio(node_arbre* n, node_arbre* &m, int &suma) const
/* Pre: cert */
/* Post: n apunta al primer node del p.i. , m apunta al pimer node del
de l'arbre suma , suma te el valor de tots els nodes de l'arbre del p.i.
sumats */
{
	if (n == NULL) suma = 0;
   	else 
   	{
		suma = n->info;
		int suma_e, suma_d;
		node_arbre *me = NULL;
		node_arbre *md = NULL;
		arb_sumes_immersio(n->segE, me, suma_e);
		arb_sumes_immersio(n->segD, md, suma_d);
		suma += suma_e + suma_d;
		m = new node_arbre;
		m->info = suma;
		m->segE = me;
		m->segD = md;
   	}
}

void arb_sumes(Arbre<int> &asum) const
/* Pre: cert */
/* Post: l'arbre asum es l'arbre suma del p.i. */
{
   int suma;
   node_arbre* m = NULL;
   arb_sumes_immersio(primer_node, m, suma);
   asum.primer_node = m;
}