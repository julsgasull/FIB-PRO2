Llista reorganitzar_out(const T& x)
/* Pre: cert */
/* Post: el resultat és una llista que conté els mateixos 
elements que el p.i. tal que tots els més petits o iguals 
que x al p.i. precedeixen als més grans que x al p.i. però 
sempre respectant l'ordre que hi havia entre ells al p.i. 
L'element actual de la llista retornada és el primer dels 
més grans que x, si existeix, sinó es situa a la detra del 
tot. El p.i. no es modifica */
{
    Llista l;
    if (longitud == 0) return l;
    // Construimos dos cadenas de nodos doblemente enlazados:
    // 1) menores iguales que x [l.primer_node ... ult_men]
    // 2) mayores que x  [l.act ...l.ultim_node]
    node_llista* ult_men = NULL;    //ultim dels menors
    l.act = NULL;
    l.ultim_node = NULL; 
    l.primer_node = NULL;

    l.longitud = longitud;

    node_llista* m = primer_node;
    while (m != NULL) {
        if (m->info <= x) { // m pasa a ser el último de los menores o iguales
            if (ult_men == NULL) { // cadena vacía
                ult_men = new node_llista;
                l.primer_node = ult_men;
                l.primer_node->ant = NULL;
            }
            else {
                ult_men->seg = new node_llista;
                (ult_men->seg)->ant = ult_men;
                ult_men = ult_men->seg;
            }
            ult_men->info = m->info;
        }
        else { // m pasa a ser el último de los mayores
            if (l.ultim_node == NULL) { // cadena vacía
                l.ultim_node = new node_llista;
                l.act = l.ultim_node;
                l.act->ant = NULL;
            }
            else {
                l.ultim_node->seg = new node_llista;
                (l.ultim_node->seg)->ant = l.ultim_node;
                l.ultim_node = l.ultim_node->seg;
            }
            l.ultim_node->info = m->info;
        }
        m = m->seg;
    }

    // ajustar los finales de las dos cadenas separadas de nodos
    if (l.primer_node == NULL) l.primer_node = l.act; // no hay menores o iguales que x
    else if (l.act == NULL) l.ultim_node = ult_men;   // no hay mayores que x
    // ambas cadenas son no vacías
    else {
        ult_men->seg = l.act;
        l.act->ant = ult_men;
    }
    l.ultim_node->seg = NULL;

    return l;
}
