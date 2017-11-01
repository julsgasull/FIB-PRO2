//
//  main.cpp
//  X36902_parent_piles.cc
//
//  Created by Júlia Gasull Navarro on 19/10/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include <stack>
#include <iostream>
using namespace std;

bool par(){
    char c;
    stack<char> s;
    while (cin >> c and c != '.') {
        //oberts
        if (c == '(' or c == '[') s.push(c);
        
        //tancats
        else {
            if (!s.empty()) {
                if (c != ')' and s.top() == '(') return false;
                if (c != ']' and s.top() == '[') return false;
                s.pop();
               
            }
            else return false;
        }
    }
    return s.empty();
    
}

int main() {
    if(par()) cout << "Correcte" << endl;
    else cout << "Incorrecte" << endl;
}
