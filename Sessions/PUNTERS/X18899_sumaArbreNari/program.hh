//program.hh

void arbsuma(ArbreNari& asum) const
/* Pre: asum es buit */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
{
	int sum;
	node_arbreNari* m = NULL;
	arbsuma_immersio(primer_node, sum, m);
	asum.primer_node = m;
}

void arbsuma_immersio(node_arbreNari* n, int &sum, node_arbreNari* &m) const
/* Pre: asum es buit */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
{
	if (n == NULL)
	{
		sum = 0;
		m = NULL;
	}
	else
	{
		m = new node_arbreNari;
		m->seg = vector<node_arbreNari*>(n->seg.size());
		
		sum = n->info;
		int sumi;
		node_arbreNari* mi;

		for (int i = 0; i < N; i++)
		{
			arbsuma_immersio(n->seg[i], sumi, mi);
			sum += sumi;
			m->seg[i] = mi;
		}
		m->info = sum;
	}
}