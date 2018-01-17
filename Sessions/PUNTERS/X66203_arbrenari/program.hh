//program.hh


T maxim() const
/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */
{
	T max = 0;
	maxim_immersio(primer_node, max);
	return max;
}


void maxim_immersio(node_arbreNari* n, T &max) const
{
	//cas base
	if (n == NULL) max = 0;
	
	//cas recursiu
	else
	{
		max = n->info;
		for (int i = 0; i < N; i++)
		{
			T maxi;
			maxim_immersio(n->seg[i], maxi);
			if (maxi > max) max = maxi;
		}
	}
}