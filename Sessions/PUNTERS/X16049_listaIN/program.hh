void reorganitzar_in(const T& x)
/* Pre: p.i. = L */
/* Post: el p.i. conté els mateixos elements que L però
reorganitzats de manera que primer apareixen els més petits
o iguals que x, en el mateix ordre que en L, seguits pels 
més grans que x, en el mateix ordre que en L.
L'element actual del p.i. és el primer del més grans que x, si
existeix, sinó es situa a la dreta de tot */
{
	/* m va recorrent (comença en 1r node)
	9 - 27 - 3 - 14 - 1 - 5 (x = 5)
	3 (primer_node) - 1 - 5(x, ultim_menor) - 9 (act) - 27 - 14 (ultim_node)
	*/

	if (longitud != 0)
	{
		node_llista* m = primer_node; //per anar recorrent

		node_llista* ultim_menor = NULL;	
	 	ultim_node = NULL;
	  	act = NULL;
	  	primer_node = NULL;

	  	while (m != NULL)	//m al final no sera null
	  	{

	  		//menors
	  		if (m->info <= x)	
	  		{
	  			if (primer_node == NULL)
	  			{
	  				primer_node = m;
	  				ultim_menor = m;
	  				primer_node->ant = NULL;
	  			}
	  			else
	  			{
	  				ultim_menor->seg = m;
	  				ultim_menor->seg->ant = ultim_menor;
	  				ultim_menor = ultim_menor->seg;
	  			}
	  		}
		  	//MAJORS
	  		else 				
	  		{
	  			if (act == NULL)
	  			{
	  				act = m;
	  				ultim_node = m;
	  				ultim_node->ant = NULL;
	  			}
	  			else
	  			{
	  				ultim_node->seg = m;
	  				ultim_node->seg->ant = ultim_node;
	  				ultim_node = ultim_node->seg; // o tambe: ultim_node = m
	  			}

	  		}
	  		m = m->seg;
	  	}
	  	if (primer_node == NULL) primer_node = act;
	  	else if (act == NULL) ultim_node = ultim_menor;
	  	else
	  	{
	  	 	ultim_menor->seg = act;
	  		act->ant = ultim_menor;
	  	}
	  	ultim_node->seg = NULL;

	}

}