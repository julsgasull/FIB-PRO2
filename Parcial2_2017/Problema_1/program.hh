void split (Llista<int>& l){
/* Pre: p.i. = P i no és una llista buida, l és buida */
/* Post: p.i. està formada per les escales senars de P i l està formada
        per les escales parells de P, respectant l'ordre original del elements;
        el punt d'interès de cada llista queda al seu respectiu principi */

    node_llista* ant;
    bool creixent = true;
    int cont = 0;

    ant = primer_node;
    act = primer_node->seg;

    while (act != NULL and creixent)
    {
        if (ant->info > act->info) creixent = false;
        else 
        {
            ant = act;
            act = act->seg;
        }
        ++cont;
    }

    if (act != NULL)
    {
        ultim_node = ant;
        l.primer_node = l.ultim_node = ant = act;
        act = act->seg;

        longitud = cont;
        l.longitud = 1;
        bool senar = false;

        while (act != NULL) 
        {
            if (senar) 
            { // ant pertany a una escala senar
                if (ant->info <= act->info)
                { // act i ant pertanyen a la mateixa escala
                    ++longitud;
                    ultim_node = act;
                }
                else 
                { // act i ant NO pertanyen a la mateixa escala
                    senar = false;
                    ++l.longitud;
                    act->ant = l.ultim_node;
                    act->ant->seg = act;
                    l.ultim_node = act;
                }
            }
            else 
            { // ant pertant a una escala parell
                if (ant->info <= act->info)
                { // act i ant pertanyen a la mateixa escala
                    ++l.longitud;
                    l.ultim_node = act;
                }
                else 
                { // act i ant NO pertanyen a la mateixa escala
                    senar = true;
                    ++longitud;
                    act->ant = ultim_node;
                    act->ant->seg = act;
                    ultim_node = act;
                }
            } // avancem el bucle
            ant = act;
            act = act->seg;
        } // instruccions posteriors al bucle
        ultim_node->seg = l.ultim_node->seg = NULL;
        l.act = l.primer_node;
    }
    act = primer_node;
}
