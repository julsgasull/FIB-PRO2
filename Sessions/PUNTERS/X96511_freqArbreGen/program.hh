
int freq(const T& x) const
/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
{
	int freq = 0;
	freq_immersio(x, primer_node, freq);

	return freq;
}


void freq_immersio(const T&x, node_arbreGen* n, int &freq) const
{
	if (n != NULL) 
	{
		if (n->info == x) ++freq;
		for (int i = 0; i < n->seg.size(); i++) freq_immersio(x, n->seg[i], freq);
	}
}