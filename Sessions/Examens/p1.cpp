//
//  p1.cpp
//  PRO2
//
//  Created by Júlia Gasull Navarro on 11/11/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;

typedef list<int> Li;
typedef list<int>::iterator It;
typedef list<int>::const_iterator CIt;

pair<int, CIt> max_long_esc(const Li& v)
{
    pair<int, CIt> p = {0, v.end()};
    
    if (not v.empty())
    {
        int cont = 1;
        CIt primer = v.begin();
        int anterior = *v.begin();
        CIt i = v.begin();
        ++i;
        while (i != v.end())
        {
            if (anterior <= *i) ++cont;
            else cont = 1;
            
            anterior = *i;
            
            if (cont > p.first) {
                p.first = cont;
                p.second = primer;
            }
            
            if (cont == 1) primer = i;
            ++i;
        }
    }
    return p;
}

/*
     INVARIANT:
         (1)    i: v.begin() <= i <= v.end(). i = posició de l'element que mirem
         (2)    cont: cont es la mida de l'escala que mirem en el moment. si és la màxima de v, el posarem a p.first
         (3)    primer: primer és la posició del primer element de cada escala. si la seva escala és la de longitud màxima, el posarem a p.second
         (4)    anterior: contingut de l'element anterior al que estem mirant
         (5)    p.first: val 0 si v és buida. sino, és la mida de l'escala de long màxima
         (6)    p.second: val v.end() si v és buida. sino, és la posició del primer element de l'escala de long màxima
 
     INICIALITZACIONS:
         - Després de les inicialitzacions -> es compleix invariant.
         - 2 casos:
             (a) v buida:
                 - p.first = 0; (5)
                 - p.second = v.end(); (1) (6)
                 - com que és buida, v.begin() = v.end();
             (b) v no buida:
                 - quan i = v.begin() -> posem que anterior = *i per mirar els següents elements, ja que comparem l'anterior amb l'actual(*i). (1) (4)
                 - a més, primer el posem a v.begin() perquè si només hi han escales de long 1, necessitarem el punter al primer element (el més aprop de v.begin()). (3)
                 - es compleix finalment (5) i (6) ja que posem el cont a 1 (que el posarem a p.first) i  a p.second posem primer.
 
     JUSTIFICACIÓ BUCLE:
         - Suposem que, en una entrada del bucle qualsevol, es compleix l'invariant. Quan se surt, també.
         - (1) es compleix al sortir del bucle, ja que la seva condició és que i = v.begin() a l'inici i mentre l'iterador i es va sumant, no s'arriba a v.end() (i != v.end()).
         - Anterior és la posició d'abans de i, i sempre es compleix excepte quan i = v.begin(), que posem anterior = v.begin() i aquest cas es tracta deiferent.
         - si anterior <= *i, l'escala continua almenys fins a la posició apuntada per i. anem sument la mida (cont) de l'escala mentre això es compleixi.
         - al final sumo i i poso a anterior el contingut de la i tractada (*i).
         - en el cas de posar cont a 0, vol dir que comencem una nova escala i canviem primer per on apunta i. si al final d'aquesta escala, cont > la llargada maxima (guardada a p.first), llavors posem també l'incici d'aquesta escala (primer) a p.second.
 
     COTA:
         La distancia entre i y v.end() decrece en cada iteración.
*/


void llegir(Li &v)
{
    It i = v.begin();
    int x;
    cin >> x;
    while (x != 0)
    {
        v.insert(i,x);
        cin >> x;
    }
}


void escriure(int mida, CIt& i)
{
    /* Pre:
         Si la lista apuntada por it no es vacia, it apunta a un elemento de la lista;
         la lista contiene al menos lon elementos a partir del elemento apuntado por it.
         Si la lista es vacia lon es 0, y it es la posicion end() de la lista. */
    /* Post:
         se escribe por pantalla la sublista que empieza en *it, y contiene los lon
         terminos siguientes de la lista apuntada por it. Si la lista es vacia, no se
         escribe nada. */
    
    for (int j = 0; j < mida; ++j)
    {
        cout << *i << " ";
        ++i;
    }
    cout << endl;
}

int main()
{
    Li v;
    llegir(v);
    pair<int, CIt> p = max_long_esc(v);
    escriure(p.first, p.second);
}
