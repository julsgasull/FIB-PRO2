pair<bool,int> distancia(string omega) const
{
	pair<bool, int> p;

	p.second = -1;
	distancia_minima(primer_node, omega, p.second);
	
	if (p.second > -1) p.first = true;
	else p.first = false;

	return p;
}

void distancia_minima(Node* n, string omega, int &dist_min) const
{
	if (n != NULL)
	{
		if (n->info.ciudad == omega and (dist_min == -1 or n->info.kms_recorridos < dist_min))
		{
			dist_min = n->info.distancia;
		}
		else
		{
			for (int i = 0; i < n->seg.size(); i++)
			{
				distancia_minima(n->seg[i], omega, dist_min);
			}
		}
	}
}

/*
void existeix_ciutat(Node* n, string omega, bool &trobat) const
{
	if (n != NULL)
	{
		if (n->info.ciudad == omega) trobat = true;
		else
		{
			int i = 0;
			while (i < n->seg.size() and not trobat)
			{
				existeix_ciutat(n->seg[i], omega, trobat);
				i++;
			}
		}
	}
}
*/