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
     INICI (general)
         sub
             def -> és l'iterador que apunta al primer element de la seqüència de mida k
                    amb més nombres senars i més aprop de l'inici en cas d'empat
             why -> l'inicialitzem a seq.end() per si k < mida de seq (postcondició)
         it1
             def -> l'utilitzem per mirar el primer element de cada subllista de mida k (en alguns moments, està a l'element anterior per comparar)
             why -> l'inicialitzem a l'inici de seq per mirar tota la llista (la mirem als bucle)
         it2
             def -> l'utilitzem per mirar el nou element de cada subllista de mida k en cada iteració
             why -> l'inicialitzem a l'inici de seq per mirar tota la llista (bucles)
 
 
 
     BUCLE 1
         Mirarem la primera subseqüència (només) per poder guanyar eficiència (bucle 2)
         Invariant -> 0 <= i <= k (k > 0 segons pre)
          - Inicilitzacions
             i
                 def -> i = 0, fa tantes iteracions com k
             sum
                 def -> va contant quants nombres senars hi ha a cada subseq
                 why -> sum = 0, ja el sumarem
             max
                 def -> maxim nombre de senars en una subseq de mida k
 
         - Cos bucle
             Fem tantes iteracions com k, ja que volem mirar la primera subseq de
             mida k (0 <= i <= k), es compleix la invariant ja que anem mirant la i, i
             aquesta la sumem d'1 en 1.
             it2 ens serveix per mirar el contingut de la subseq. A cada iteració, mirem
             si és senar. Si ho és, augmentem suma en 1.
             Anem sumant i i it2 per mirar al següent element.
 
         - Condició de sortida
             quan i >= k
             com que incrementem i, i arribarà a ser = k -> sortim del bucle i it2 serà el
             (k+1)-èssim element de seq.
 
         - Acabament
             funció fita -> f = k - i (quan f arriba a 0, sortim)
             en cada iteració, augmentem i, fins arribar a k -> k és finit -> surt.
 
     BUCLE 2
         - Inicialitzacions
      ...
 
 
 
 inits: els iteradors apunten al principi de la llista, ja que la busca es de la primera subllista que compleixi les condicions.
 i:
*/


