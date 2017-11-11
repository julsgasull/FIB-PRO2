//
//  program.cc
//  PRO2
//
//  Created by Júlia Gasull Navarro on 11/11/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    pair<char, string> p;
    map<string, int> m;
    
    while (cin >> p.first and cin >> p.second)
    {
        if (p.first == 'a') ++m[p.second];
        else cout << m[p.second] << endl;
    }
}
