//program.hh

node_llista* copia_node_llista_it (node_llista* m, node_llista* oact, node_llista* &u, node_llista* &a)
/* Pre: cert */
/* Post: si m és NULL, el resultat, u i a són NULL, en cas
       contrari, el resultat apunta al primer node d'una cadena de
       nodes que són còpia de la cadena que té el node apuntat per m
       com a primer, u apunta a l'últim node, a és o bé NULL si oact
       no apunta a cap node de la cadena que comença amb m o bé apunta
       al node còpia del node apuntat per oact */
{
	node_llista* n;
	if (m == NULL)
	{
		u = NULL;
		a = NULL;
		n = NULL;
	}
	else
	{
		n = new node_llista;
		n->info = m->info;
		n->ant = NULL;

		node_llista* p = n;

		if (m == oact) a = p;
		m = m->seg;
		
		while(m != NULL)
		{
			p->seg = new node_llista;
			p->seg->ant = p;
			p->seg->info = m->info;

			if (m == oact) a = p->seg;

			m = m->seg;
			p = p->seg;
		}
		u = p;
		p->seg = NULL;
		if (m == oact) a = NULL;
	}
	return n;
}

Llista& operator=(const Llista& original) 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una còpia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */
{

 /* int longitud;
  node_llista* primer_node;
  node_llista* ultim_node;
  node_llista* act;
*/
	if (this != &original)
	{
		//ESBORRAR p.i.
		node_llista* aux;
		while (primer_node != NULL)
		{
			aux = primer_node->seg;
			delete primer_node;
			primer_node = aux;
		}
		longitud = original.longitud;
		primer_node = copia_node_llista_it(original.primer_node, original.act, ultim_node, act);
	}
	return *this;
}