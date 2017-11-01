//
//  main.cpp
//  X38371_estad.cc
//
//  Created by Júlia Gasull Navarro on 24/10/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

void calcular (queue<int> &cua, int &n, int &min, int &max, int &sum, double &media){
    // Si la cua s'ha buidat, inicialitzem els valors com al principi
    if (cua.empty()){
        min = n;
        max = n;
        sum = 0;
        media = 0;
    }
    
    // Si la cua no esta buida, calculem el nou max i min
    else {
        if (n < min) min = n;
        if (n > max) max = n;
    }
    
    // Afegim l'element a la cua i calculem la mitjana
    cua.push(n);
    sum += n;
    media = double(sum)/cua.size();
}

void recalcular (queue<int> cua, int &min, int &max, int &sum, double &media){
    int size = int(cua.size());
    sum = 0;
    media = 0;
    while(not cua.empty()){
        int n = cua.front();
        if (n < min) min = n;
        if (n > max) max = n;
        sum += n;
        cua.pop();
    }
    media = double(sum)/size;
}

void escriure (int min, int max, double media){
    cout << "min " << min << "; max " << max << "; media " << media << endl;
}


int main(){
    queue<int> cua; // Cua on afegim o esborrem elements
    
    int n;
    cin >> n;       // Nombres que van entran a la cua
    
    int min = n;
    int max = n;
    int sum = 0;
    double media = 0;
    bool es_min, es_max;
    
    while (n >= -1001 and n <= 1000){
        // Afegim enter
        if (n != -1001) {
            calcular(cua, n, min, max, sum, media);
            escriure(min, max, media);
        }
        
        // Esborrar enter
        else {
            if (cua.empty()) cout << '0' << endl; // Cua buida
            else {
                // Mirem si l'element a esborrar es el min o el max
                if (cua.front() == min) es_min = true;
                else es_min = false;
                if (cua.front() == max) es_max = true;
                else es_max = false;
                
                cua.pop();  // Esborrem el l'element mes antic de la cua (primer)
                
                /* Tornem a mirar si la cua esta buida, si no ho esta recalculem
                 el min, el max i la mitjana*/
                if (cua.empty()) cout << '0' << endl;
                else {
                    if (es_min) min = cua.front();  // Si hem esborrat el min, li assignem el primer element
                    if (es_max) max = cua.front();  // Si hem esborrat el max, li assignem el primer element
                    recalcular(cua, min, max, sum, media);
                    escriure(min, max, media);
                }
            }
        }
        cin >> n;
    }
}

