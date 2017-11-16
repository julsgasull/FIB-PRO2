//
//  senars.cpp
//  PRO2
//
//  Created by Júlia Gasull Navarro on 16/11/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//


/*------------------------------ Exercici 1.2 --------------------------------*/
#include <iostream>
#include <list>
using namespace std;

void mes_senars(const list<int> &seq, int k, list<int>::const_iterator &sub)
{
    sub = seq.end();
    if (k <= seq.size())
    {
        list<int>::const_iterator it1 = seq.begin();        // +-: iterador al primer de seq amb més senars
        list<int>::const_iterator it2 = seq.begin();        // +-: iterador a l'últim de seq amb més senars
        
        
        /*-------------------- primer cas ----------------------*/
        int i = 0;      //1r sublist: size
        int sum = 0;    //nº sanars 1r subllista
        
        while (i < k) {
            if (*it2 % 2 != 0) ++sum;
            ++it2;
            ++i;
        }
        int max = sum;
        sub = it1;
        //it2 acaba apuntant al (k+1)-èssim de la llista
        
        /*-------------------- resta --------------------------*/
        
        while (it2 != seq.end() and max < k)
        {
            if (*it1 % 2 != 0) --sum;
            if (*it2 % 2 != 0) ++sum;
            
            ++it1;
            ++it2;
            
            if (sum > max)
            {
                max = sum;
                sub = it1;
            }
        }
        
    }
 
}

int main()
{
    int k;
    cin >> k;
    
    list<int> seq;
    list<int>::iterator it = seq.end();
    int n;
    cin >> n;
    while (n != 0)
    {
        seq.insert(it, n);
        cin >> n;
    }
    list<int>::const_iterator sub;
    mes_senars(seq, k, sub);
    cout << *sub << endl;
}


/*------------------------------ Exercici 1.2 --------------------------------*/

/*
     INICIALITZACIONS
         
 
     CONDICIÓ DE SORTIDA
 
     COS DEL BUCLE
 
     ACABAMENT
 
 
 
 inits: els iteradors apunten al principi de la llista, ja que la busca es de la primera subllista que compleixi les condicions.
 i:
*/


