//program.hh -> PILA

node_pila* copia_node_pila_it(node_pila* m) 
    /* Pre: cert */
    /* Post: si m és NULL, el resultat és NULL, en cas contrari, el
       resultat apunta al primer node d'una cadena de nodes que són
       còpia de de la cadena que té el node apuntat per m com a primer */
{
	//si m null -> return null
	node_pila* n;
	if (m == NULL) n = NULL;
	else 
	{
		n = new node_pila;
		n->info = m->info;
		node_pila* p = n;
		m = m->seguent;

		while (m != NULL)
		{
			p->seguent = new node_pila;
			p = p->seguent;
			p->info = m->info;
			m = m->seguent;
		}
		p->seguent = NULL;
	}
	return n;
} 

Pila& operator=(const Pila& original) 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una còpia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */
{
	if (this != &original)
	{
		altura = original.altura;
		while(primer_node != NULL)
		{
			node_pila* aux = primer_node->seguent;
			delete primer_node;
			primer_node = aux;
		}
		primer_node = copia_node_pila_it(original.primer_node);	//copiar
	}
	return *this;
}