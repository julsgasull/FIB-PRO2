//
//  p2.cpp
//  PRO2
//
//  Created by Júlia Gasull Navarro on 14/11/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

/*
 -------------------------------------------------------------------------------------
                                         2.1.
 -------------------------------------------------------------------------------------
 */

bool valor(const string &s)
{
    /* Pre: s és l'identificador d'una variable booleana definida al paràmetre implícit. */
    /* Post: El resultat és el valor de la variable amb identificador s al paràetre implícit. */
}

bool avaluar(Arbre<string> &a, const Variables &e)
{
    string s = a.arrel();
    Arbre<string> a1 = a.left();
    Arbre<string> a2 = a.right();
    
    if (s == "not") return not avaluar(a1, e);
    if (s == "or") return avaluar(a1,e) or avaluar(a2,e);
    if (s == "and") return avaluar(a1,e) and avaluar(a2,e);
    if (s == "true") return true;
    if (s == "false") return false;
    
    return e.valor(s);
}




/*
-------------------------------------------------------------------------------------
                                         2.2.
-------------------------------------------------------------------------------------
*/

/*
     Entenent el tractament de l'arrel com el punt en què s'aplica l'operador
     lògic de l'arrel sobre el resultat d'avaluar un subarbre fill (o tots dos):
         La implementació en C++ del problema 2.1 segueix un esquema d'inordre perquè
         l'avaluació en curtcircuit obliga a tenir en compte l'arrel quan aquesta és
         "or" o "and" després de la primera crida recursiva sobre el subarbre fill
         esquerre per decidir si cal continuar l'avaluació de l'expressió del
         subarbre fill dret.
 */


/*
 -------------------------------------------------------------------------------------
                                         2.3.
 -------------------------------------------------------------------------------------
 */

/*
 La implementació del problema 2.1 té 3 casos directes (quan l'arrel no conté un
 operador) i 3 casos recursius (quan l'arrel conté un operador). Els casos directes
 apareixen després dels casos recursius en la solució.
 
 Abans de tractar aquest casos l'algorisme, executa les instruccions de les línies
 27-29.
 
 La precondició del mètode arrel (Línia 27) es compleix gràcies a la precondició
 d'avaluar.
 La precondició de fills (28-29), és a dir que a no sigui buit però a1 i a2 ho
 siguin, es compleix gracies a la pre d'avaluar i al fet que a1 i a2 s'acaben
 de declarar. Per tant, tot just abans d'executar la Línia 31, s conté l'arrel
 d'A i a1 i a2 en contenen el fill esquerre i el fill dret respectivament.
 En aquest context, continuem amb la justificació dels casos directes i la
 justificació dels casos recursius.
 
 Correctesa dels casos recursius.
 
     En aplicació de la hipòtesi d'inducció (h.i.), suposem que les diferents
     crides a avaluar(a1, e) han retornat el resultat d'avaluar l'expressió
     booleana d'a1 en base als valors de les variables d'e. També suposem
     que les diferents crides a avaluar(a2, e) han retornat el resultat
     d'avaluar l'expressió booleana d'a2 en base als valors de les variables
     d'e.
 
     L'algorisme té tres casos recursius:
         a)  L'arrel conté "not". Per satisfer la postcondició, el resultat
             d'avaluar l'expressió ha de ser el resultat de negar el resultat
             d'avaluar l'expressió del fill esquerre d'A gràcies a la Propietat
             2, tal com fa el codi amb la crida a avaluar (Línia 31). Gràcies a
             la precondició d'avaluar sabem que l'arbre d'a1 també estarà ben
             format i per la Propietat 2 no serà buit, complint la precondició
             de la crida a avaluar, que donarà el resultat esperat gràcies a la
             h.i.
         b)  L'arrel conté "or" (Línia 32). Per satisfer la postcondició, el
             resultat d'avaluar l'expressió ha de ser el resultat d'aplicar
             l'operació or al resultat d'avaluar l'expressió del fill esquerre
             d'A i al de l'avaluació del fill dret. Gràcies a la precondició
             d'avaluar sabem que l'arbre d'a1 i el d'a2 també estaran ben formats
             i per la Propietat 1 no serà buit cap d'ells, complint la precondició
             del parell de crides a avaluar (Línia 32), que donaran el resultat
             esperat gracies a la h.i.
         c)  L'arrel conté "and" (Línia 33). La justificació és fàcil d'obtenir a
             partir de la del cas b). 
 
 Correctesa dels casos directes.
 
     Els casos directes comencen a la línia 34. En aquest punt sabem que l'arrel d'A
     no conté un operador gràcies als casos tractats en línies anteriors. Quan l'arrel
     no conté un operador i la Propietat 4 de l'enunciat ens garanteix que l'arbre "a"
     conté un sol node que és fulla d'A. Per tant la Propietat 3 implica que l'arrel
     d'A ha de ser una constant booleana o una variable booleana.
 
     L'algorisme té tres casos directes:
         a)  L'arrel és "true". Aleshores l'expressió és certa i cal retornar true per
             a satisfer la postcondició, tal com es fa.
         b)  L'arrel és "false". Aleshores l'expressió és falsa i cal retornar false
             per a satisfer la postcondició, tal com es fa.
         c)  L'arrel no es ni "true" ni "false". Aleshores l'expressió és una variable
             i cal retornar el seu valor segons el paràmetre e per satisfer la postcondició,
             tal com es fa.
     La crida a e.valor(s) compleix la precondició del mètode gràcies a la precondició
     d'avaluar. 
 
 Acabament. L'algorisme acaba perquè la mida de l'arbre a és una funció fita. D'una
 banda, la mida d'un arbre és més gran o igual que zero. D'una altra banda, la mida
 de l'arbre "a" decreix sempre en cada crida recursiva (l'arbre subministrat en la
 crida recursiva s'ha obtingut amb el mètode fill i per tant ha perdut pel cap baix
 l'arrel A).

 */
