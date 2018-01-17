//program.hh

bool buscar(const T& x) const
/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
{
	bool trobat = false;
	buscar_immersio(x, primer_node, trobat);

	return trobat;
}


void buscar_immersio(const T&x, node_arbreGen* n, bool &trobat) const
{
	if (n == NULL) trobat = false;
	else if (not trobat) 
	{
		if (n->info != x)
		{
			for (int i = 0; i < n->seg.size(); i++) buscar_immersio(x, n->seg[i], trobat);
		}
		else trobat = true;
	}
}